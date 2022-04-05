#include"drawfun.h"
#include"common.h"

/*
功能：绘图的相关功能函数
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：Linex
参数传递：int x1,int y1,int x2, int y2,unsigned char color
返回值：无
功能：画横线功能函数
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

  if(y1!=y2||x1>x2)     //y1要保证和y2相等
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
函数名：Liney
参数传递：int x1,int y1,int x2, int y2,unsigned char color
返回值：无
功能：画竖线功能函数
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

//x1要保证和x2相等
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
函数名：LineThick
参数传递：int x1,int y1,int x2, int y2,unsigned char color，int thick,int mode
返回值：无
功能：画粗线条功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
{
	int i;
	if(thick<=1)
	{
		return;
	}
	if(mode==1)//左右拉伸
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
		if(mode==2)//上下拉伸
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
		if(mode==3)//上拉伸
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
		if(mode==4)//下拉伸
		{
			for(i=0;i<=thick;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	if(mode==5)//左拉伸
	{
		for(i=-thick;i<=0;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	if(mode==6)//右拉伸
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
函数名：FrameSha
参数传递：int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick
返回值：无
功能：给框加上阴影功能函数
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
