#ifndef _donate_h
#define _donate_h

#include"drawone.h"
#include"drawtwo.h"
#include"mainpage.h"

long int s_2_2_0 (int *pagestate);	
int s_2_2_1(int *type,int *state,int *pagestate,int who);
void s_2_2_2(int *pagestate,USER *u);
int s_2_2_3(int *pagestate,int pubtype,USER *u);
void s_2_2_4(int *pagestate,long int prosite);
void s_2_2_5(int *pagestate,long int prosite,USER *u);
void s_2_2_5_1(USER *u,long int judge);
void inputnumber(long int* number,int x1,int y1,int maxnum,int color);


#endif
