#ifndef _MY_DEF_H_
#define _MY_DEF_H_

#ifndef NULL
#define NULL 0
#endif

typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

//注意*(a)，而不是*a
#define countof(a)	(sizeof(a)/sizeof(*(a)))
#define BufferSize(x)	(countof(x) - 1)

//function pointer define
typedef void (*fnDef)(void);


#endif
