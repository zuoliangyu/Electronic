#ifndef _OLED_GUI_H_
#define _OLED_GUI_H_

#define ICON_SIZE	16
#define PLAY_MODE_SIZE	20
#define BAT_SIZE 30

#define PLAY_MODE_NUM	5


typedef unsigned char P_M[PLAY_MODE_SIZE];

extern P_M list_play;
extern P_M list_loop;
extern P_M single_music;
extern P_M single_loop;
extern P_M random_play;

extern const unsigned char stops[ICON_SIZE];

extern unsigned char lastSongIcon[ICON_SIZE];
extern unsigned char rewindDownIcon[ICON_SIZE];
extern unsigned char playIcon[ICON_SIZE];
extern unsigned char speedIcon[ICON_SIZE];
extern unsigned char nextSong[ICON_SIZE];

extern unsigned char bat_full[BAT_SIZE];
//extern unsigned char bat_full[];//这里最好不要这么写，因为bat_full
//的定义中也没有申明数组的大小。除非定义冲写出了大小，编译器不一定能找到
//extern unsigned char *bat_full;//不能这样使用，注意两者的区别
extern unsigned char bat_4[BAT_SIZE];
extern unsigned char bat_3[BAT_SIZE];
extern unsigned char bat_2[BAT_SIZE];
extern unsigned char bat_1[BAT_SIZE];
extern unsigned char bat_0[BAT_SIZE];


#endif

