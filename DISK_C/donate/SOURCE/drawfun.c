#include"drawfun.h"
#include"common.h"

/*
���ܣ���ͼ����ع��ܺ���
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������Linex
�������ݣ�int x1,int y1,int x2, int y2,unsigned char color
����ֵ����
���ܣ������߹��ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Linex(int x1,int y1,int x2, int y2,unsigned char color)      
{
  int i;
  if(x1>=639||x2>=639||y1>=479||y2>=479)
	{
		return;
	}

  if(x1<=0||x2<=0||y1<=0||y2<=0) 
	{
		return;
	}

  if(y1!=y2||x1>x2)     //y1Ҫ��֤��y2���
	{
		return;
	}

  for(i=x1;i<=x2;i++)
	{
		putpixel(i,y1,color);
	}
  return;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������Liney
�������ݣ�int x1,int y1,int x2, int y2,unsigned char color
����ֵ����
���ܣ������߹��ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Liney(int x1,int y1,int x2, int y2,unsigned char color)
{
  int i;
  if(x1>=639||x2>=639||y1>=479||y2>=479)
	{
		return;
	}

  if(x1<=0||x2<=0||y1<=0||y2<=0)
	{
		return;
	}

//x1Ҫ��֤��x2���
  if(x1!=x2||y1>y2)   
	{
		return;
	}

  for(i=y1;i<=y2;i++)
	{
		return;
	}
  return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������LineThick
�������ݣ�int x1,int y1,int x2, int y2,unsigned char color��int thick,int mode
����ֵ����
���ܣ������������ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
{
	int i;
	if(thick<=1)
	{
		return;
	}
	if(mode==1)//��������
	{
		for(i=-thick/2;i<=thick/2;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=679&&x2+i<=679)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	else 
		if(mode==2)//��������
		{
			for(i=-thick/2;i<=thick/2;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	else 
		if(mode==3)//������
		{	
			for(i=-thick;i<=0;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	else 
		if(mode==4)//������
		{
			for(i=0;i<=thick;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	if(mode==5)//������
	{
		for(i=-thick;i<=0;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	if(mode==6)//������
	{
		for(i=0;i<=thick;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������FrameSha
�������ݣ�int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick
����ֵ����
���ܣ����������Ӱ���ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick)
{
	Frame(x1+5,y1+5, x2+5,y2+5,shacolor,thick);
	Frame(x1,y1, x2,y2,precolor,thick);
	return;
}

void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick)
{
	if(x1<=0||x1>=640||x2<=0||x2>=640||y1<=0||y1>=480||y2<=0||y2>=480)
	{
		return;
	}
	if(x1>=x2||y1>=y2)
	{
		return;
	}
	bar(x1,y1,x2,y1+thick);
	bar(x1,y2-thick,x2,y2);
	bar(x1,y1,x1+thick,y2);
	bar(x2-thick,y1,x2,y2);
	return;
}
