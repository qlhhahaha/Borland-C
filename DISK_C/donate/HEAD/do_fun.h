#ifndef _do_fun_h
#define _do_fun_h

#include"drawone.h"
#include"drawtwo.h"
#include"mainpage.h"

long int fsize_init(FILE *fp,int order);//初始化fsize
int info_output(FILE *fp,long int fsize,int state,int type,char *name,int *allorder,int *showorder,int order,char mode);
int blank_draw(int order,int row,int state);
int progress_draw(int x,int y,int height,PRO *pro);
//输出表格中单个项目信息
#endif