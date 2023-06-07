#include "stm32f4xx.h"
#include "math.h"

#define TIMER_TICKS_PER_SECOND 84000000 // 定义计时器的时钟频率

void TIM2_IRQHandler(void);           // 定义定时器2的输入捕获中断服务函数
float getFrequency(uint16_t capture); // 定义根据捕获周期计算频率的函数

// 标志位和两次捕获的时间值，需要使用volatile修饰
volatile uint8_t is_capture_done = 0;
volatile uint16_t capture1 = 0;
volatile uint16_t capture2 = 0;
volatile float frequency = -1;

int main()
{
    // 配置输入引脚为输入捕获模式
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef gpio_init;
    gpio_init.GPIO_Pin = GPIO_Pin_5;
    gpio_init.GPIO_Mode = GPIO_Mode_AF;
    gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &gpio_init);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);

    // 配置定时器2为输入捕获模式
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseInitTypeDef timer_init;
    timer_init.TIM_Period = 0xFFFF;
    timer_init.TIM_Prescaler = 0;
    timer_init.TIM_CounterMode = TIM_CounterMode_Up;
    timer_init.TIM_ClockDivision = 0;
    TIM_TimeBaseInit(TIM2, &timer_init);
    TIM_ICInitTypeDef ic_init;
    ic_init.TIM_Channel = TIM_Channel_1;
    ic_init.TIM_ICPolarity = TIM_ICPolarity_Rising;
    ic_init.TIM_ICSelection = TIM_ICSelection_DirectTI;
    ic_init.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    ic_init.TIM_ICFilter = 0;
    TIM_ICInit(TIM2, &ic_init);
    TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE); // 使能定时器2的输入捕获中断
    NVIC_EnableIRQ(TIM2_IRQn);              // 使能定时器2的中断控制器
    TIM_Cmd(TIM2, ENABLE);

    // 主循环
    while (1)
    {
        if (is_capture_done)
        {
            frequency = getFrequency(capture2 - capture1);
            is_capture_done = 0;
        }
    }
}

// 定时器2的输入捕获中断服务函数，用于获取两次上升沿的时间戳
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)
    {
        if (!is_capture_done)
        {                                     // 第一次捕获到上升沿
            capture1 = TIM_GetCapture1(TIM2); // 获取时间戳
            is_capture_done = 1;
        }
        else
        {                                     // 第二次捕获到上升沿
            capture2 = TIM_GetCapture1(TIM2); // 获取时间戳
            is_capture_done = 2;
        }
        TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
    }
}

// 根据捕获周期计算频率的函数
float getFrequency(uint16_t capture)
{
    float period_ticks = (float)capture;                          // 获取捕获周期
    float period_seconds = period_ticks / TIMER_TICKS_PER_SECOND; // 将周期转化为秒数
    return 1.0f / period_seconds;                                 // 计算频率并返回
}
