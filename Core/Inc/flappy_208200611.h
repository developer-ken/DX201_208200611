/* **********************************
 *	躲方块游戏
 *	by 邓君卓 208200611
 *	验证如下功能：
 *	1.重写按键事件处理函数
 *	2.按需关闭SimplePage框架的绘制功能
 *	3.按需调整防抖强度
 * ********************************** */

#ifndef _H_FLAPPY_
#define _H_FLAPPY_
#include "main.h"
#include "SimplePage_208200611.h"

struct gameobj_obstacle typedef GOBJ_Obs;
struct gameobj_obstacle {
	char x, y, h, w;
	char lastx, lasty;
	u8 enabled;
};
void KeyUp();
void KeyDown();
void NoOperation();
void Flappy_Init();
void Flappy_Update(SimplePage*);
#endif
