#ifndef _request_h
#define _request_h

#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"
#include"donate.h"
#include"mainpage.h"
#include"message.h"
#include "input.h"
#include "re_fun.h"

void s_2_3_0 (int *pagestate,USER *u);
void s_2_3_1 (PRO *pro,char *PRONAME,char *PLACE,char *MANNAME,char *DES);	
void s_2_3_2 (PRO *pro,char *PRONAME,char *PLACE,char *MANNAME,char *DES);
void s_2_3_3 (int *pagestate,char *PRONAME,char *PLACE,char *MANNAME,char *DES);

#endif