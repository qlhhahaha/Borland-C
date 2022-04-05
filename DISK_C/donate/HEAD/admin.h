#ifndef _admin_h
#define _admin_h
#include"database.h"
#include"drawone.h"
#include"drawtwo.h"
#include"common.h"
#include"drawfun.h"
#include"trans.h"
#include"do_fun.h"
#include"search.h"

void s_1_2_0(int *pagestate,ADMIN *adm);//主循环
int sa_0(int *pagestate);//管理员上方菜单栏
long int sa_1_0(int *pagestate);//管理员的项目列表
void sa_1_1(int *pagestate);//管理员的公共项目功能函数
int sa_1_1_1(int *pagestate,int pubtype);
void sa_1_2(int *pagestate,long int prosite);//管理员项目详情
void sa_1_3(int *pagestate,long int prosite);//管理员调配物资界面
long int sa_3_0(int *pagestate);//用户信息列表
void sa_3_1(int *pagestate,long int usersite);
void s_2_8_1 (int *pagestate);
#endif
