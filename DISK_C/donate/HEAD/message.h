#ifndef _request_h
#define _request_h

#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"
#include"donate.h"
#include"mainpage.h"
#include"database.h"

void s_2_5_0(int *pagestate);
void s_2_5_1(int *pagestate);
void lightbutton_message(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_message(int status);
int message_judge(char *NAME,char *TEXT);
void message_make(char *NAME,char *TEXT);
void inputadmin_new(char* id, int x1, int y1, int charnum, int color);
void inputadmin_des(char* id, int x1, int y1, int charnum, int color);
void outputinfo(char* id, int x1, int y1);
void outputinfo_des(char* des, int x1, int y1);
void outputinfo_pro_des(char* des, int x1, int y1);
#endif