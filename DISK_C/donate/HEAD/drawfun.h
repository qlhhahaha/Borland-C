#ifndef_drawfun_h
#define_drawfun_h
#define LENGTH 640
#define WIDTH  480
void Linex(int x1,int y1,int x2,int y2,unsigned char color);//ƽ��x��ֱ��
void Liney(int x1,int y1,int x2,int y2,unsigned char color);//ƽ��y��ֱ��
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode);//����������
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick);//���Ӱ��
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick);//��
#endif