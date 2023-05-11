/* **********************************
 *	躲方块游戏
 *	by 邓君卓 208200611
 *	验证如下功能：
 *	1.重写按键事件处理函数
 *	2.按需关闭SimplePage框架的绘制功能
 *	3.按需调整防抖强度
 * ********************************** */

#include "main.h"
#include "flappy_208200611.h"
#include "SimplePage_208200611.h"

#define obcnt_max 3
#define startspeed 15

extern u32 AntiVibLen;
u8 me_ypos;
u8 me_lasty;
u8 me_xpos;
u8 spdfactor;
int lastt_stamp;
GOBJ_Obs obstacles[obcnt_max];
u8 obsindex = -1;
u32 tfactor;
u8 died = false, first = true;

UserInputHandler Flappy_ihan = { KeyUp, KeyDown, NoOperation, NoOperation,
		NoOperation, Flappy_Init, NVIC_SystemReset };

u8 randpos();
inline u8 randpos() {
	return NativeTimestampMs() % 7;
}

void Flappy_Init() {
	AntiVibLen = 50;
	OLED_Clear();
	obstacles[0].enabled = false;
	obstacles[1].enabled = false;
	obstacles[2].enabled = false;
	died = false;
	me_ypos = 4;
	me_xpos = 20;
	tfactor = 0;
	spdfactor = 15;
	obsindex = 0;
	for (int i = 0; i < obcnt_max; i++) {
		obstacles[i].enabled = false;
	}
}

void KeyUp() {
	if (me_ypos <= 0)
		me_ypos = 0;
	else
		me_ypos--;
}

void KeyDown() {
	if (me_ypos >= 7)
		me_ypos = 7;
	else
		me_ypos++;
}

void NoOperation() {

}

u8 UpdateObstacle(GOBJ_Obs *obj) {
	if (!obj->enabled)
		return;
	obj->x--;
	if (obj->x <= 2) { // reset obstale
		obj->x = 127 - 8;
		obj->y = randpos();
		obj->w = 8;
		obj->h = 2;
		return true;
	}
	return false;
}

u8 CheckHit(GOBJ_Obs *obj);
inline u8 CheckHit(GOBJ_Obs *obj) {
	return (me_xpos >= obj->x && me_xpos <= obj->x + obj->w)
			&& (me_ypos >= obj->y && me_ypos < obj->y + obj->h);
}

void Flappy_Update(SimplePage *page) {
	if (first) {
		Flappy_Init();
		first = false;
		return;
	}
	if (died)
		return;
	int now = NativeTimestampMs();
	if (lastt_stamp == now)
		return;
	lastt_stamp = now;
	tfactor++;
	if ((spdfactor > 2) && lastt_stamp % 3000 == 0) {
		spdfactor--;
	}

	if (obsindex < obcnt_max && ((lastt_stamp) % 800 == 0)) {
		obstacles[obsindex].x = 127 - 8;
		obstacles[obsindex].y = randpos();
		obstacles[obsindex].w = 8;
		obstacles[obsindex].h = 2;
		obstacles[obsindex].enabled = true;
		obsindex++;
	}

	if ((lastt_stamp / 10) % spdfactor == 0) {
		for (int i = 0; i < obcnt_max; i++) {
			if (!obstacles[i].enabled)
				continue;
			if (UpdateObstacle(&obstacles[i])) {
				if (CheckHit(&obstacles[i])) {
					died = true;
				}
				break;
			}
			if (CheckHit(&obstacles[i])) {
				died = true;
				break;
			}
		}
	}
	if (died) {
		OLED_ShowString(Center("Game Over"), 4, true, "Game Over");
	} else {
		if (me_lasty != me_ypos) {
			OLED_ShowChar(me_xpos, me_lasty, false, ' ');
			me_lasty = me_ypos;
		}
		OLED_ShowChar(me_xpos, me_ypos, false, '`');
		for (int i = 0; i < obcnt_max; i++) {
			if (!obstacles[i].enabled)
				continue;
			if (obstacles[i].lastx != obstacles[i].x
					|| obstacles[i].lasty != obstacles[i].y) {
				OLED_ShowChar(obstacles[i].lastx, obstacles[i].lasty, false,
						' ');
				obstacles[i].lastx = obstacles[i].x;
				obstacles[i].lasty = obstacles[i].y;
			}
			OLED_ShowChar(obstacles[i].x, obstacles[i].y, true, ' ');
		}
	}
}
