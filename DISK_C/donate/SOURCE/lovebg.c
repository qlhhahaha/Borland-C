#include"common.h"
#include"lovebg.h"

/*
功能：爱心背景功能
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_1
参数传递：pagestate:页面编号
返回值：无
功能：爱心背景的功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_1 (int *pagestate)
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_1();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//将pagestate作为地址传入s_2_0，如果点击了上方菜单则s_2_0返回1 
		{
			return;
		}
	}
}
