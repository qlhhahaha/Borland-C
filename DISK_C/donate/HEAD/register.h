#ifndef _register_h
#define _register_h

#include"login.h"
#include"drawone.h"
#include"drawtwo.h"
#include"loginfun.h"

void random_str(char* str);
void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag); 
//color1为边框色,color2为填充色
void recoverbutton_register(int status);
void s_1_3(int *pagestate);

#endif
