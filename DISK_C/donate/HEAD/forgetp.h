#ifndef _FORGETP_H
#define _FORGETP_H

#include"login.h"
#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"
void s_1_4(int *pagestate);	
//�����������

void lightbutton_forget(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_forget(int status);
//��������

int forgetpass_complete(char* u, char* ph, char* np, char* cp);
//����Ƿ���Ը���������

#endif