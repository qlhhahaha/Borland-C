#ifndef _board_h
#define _board_h

#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"
#include"donate.h"
#include"mainpage.h"
#include"database.h"
#include"trans.h"

void s_2_10_0(int *pagestate);
void s_2_10_1(int *pagestate);
void s_2_10_2(int *pagestate);
void lightbutton_board(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_board(int status);
#endif