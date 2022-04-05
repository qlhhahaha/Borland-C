#ifndef _drawtwo_h
#define _drawtwo_h

#include"picture.h"
#include"drawfun.h"
#include"database.h"
#include"message.h"

void ga_0(void);//管理员的上方常驻菜单栏绘制
void ga_3_0(int state);//管理员右菜单栏
void ga_1_1_1(int pubtype);
void ga_3_1(USER *temp,USER_STR *temp_str);
void g_1_5_0(void);
void g_2_0(void);
void g_2_0_0(int state);
void g_2_2_0(void);
void g_2_2_1(int *state);
void g_2_2_2(void);
void g_2_2_3(int pubtype);
void g_2_2_4(PRO *ptemp,PRO_STR *ptemp_str);
void g_2_2_5(PRO *ptemp,char mode);
void g_2_4_0(void);
void g_2_4_1(void);
void g_2_4_2(long int recordsite);
void g_2_6_0(USER *u);
void g_2_6_1(USER *u,int order);
void g_2_6_2(void);
void g_2_6_3(void);
void g_2_6_4(void);
void g_2_7_0(USER *u);
void g_2_7_1(int type);
void g_2_8(void);
#endif