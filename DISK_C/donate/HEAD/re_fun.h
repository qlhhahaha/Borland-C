#ifndef _re_fun_h
#define _re_fun_h

#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"
#include"donate.h"
#include"mainpage.h"
#include"message.h"
#include "input.h"

void read_judge(int *count);
int request_judge(int *count,char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u);
void request_save(char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u);
void lightbutton_request(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_request(int status);
/*void hz_method(char* id, int x1, int y1, int charnum);*/
void s_2_3_4(char *PRONAME,char *PLACE,char *MANNAME,char *DES);
void outputhz(int x1,int y1,int x2,int y2,char *s,int color);
int outputLetterNum2(char ch,int x,int y,int color);
#endif