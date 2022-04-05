#ifndef _FORGETP_H
#define _FORGETP_H

#include"login.h"
#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"
void s_1_4(int *pagestate);	
//忘记密码界面

void lightbutton_forget(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_forget(int status);
//灭亮函数

int forgetpass_complete(char* u, char* ph, char* np, char* cp);
//检查是否可以更改新密码

#endif