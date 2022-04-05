#ifndef_drawfun_h
#define_drawfun_h
#define LENGTH 640
#define WIDTH  480
void Linex(int x1,int y1,int x2,int y2,unsigned char color);//平行x轴直线
void Liney(int x1,int y1,int x2,int y2,unsigned char color);//平行y轴直线
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode);//画出粗线条
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick);//框加影子
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick);//框
#endif