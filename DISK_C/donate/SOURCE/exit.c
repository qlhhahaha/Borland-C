#include"common.h"
#include"exit.h"

/*
功能：退出账号功能
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_8_0
参数传递：pagestate:页面编号
返回值：无
功能：退出功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_8_0 (int *pagestate)
{
	clrmous(MouseX, MouseY);
	delay(100);
	g_2_8_0();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 200 && MouseX < 290 && MouseY>245 && MouseY < 285)
			{
				if (mouse_press(200,245,290,285) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(200,245,290,285) == 1)
				{
					*pagestate=290;
					clrmous(MouseX,MouseY);
					delay(1000);
					cleardevice();
					return ;
				}
			}
			
		if (MouseX > 350 && MouseX < 440 && MouseY>245 && MouseY < 285)
			{
				if (mouse_press(350,245,440,285) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(350,245,440,285) == 1)
				{
					MouseS = 0;
					delay(500);
					*pagestate=21;
					return ;
				}
			}
		
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}