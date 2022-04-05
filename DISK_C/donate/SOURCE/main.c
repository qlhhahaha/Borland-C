#include"common.h"
#include"main.h"
#include"exit.h"


/*
功能：主函数，负责各个页面的切换控制
作者：钱力晖
最后修改：2020/10/29
*/

void main(void)
{
	//int debug;
	int gdriver=VGA, gmode=VGAHI;
	int pagestate=0;//作为页面特征值，用于页面转换
	USER u;
	ADMIN adm;
	memset(&adm,'\0',sizeof(ADMIN));
	memset(&u,'\0',sizeof(USER));
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	cleardevice();
	mouseinit();

	while (1)
	{
		switch (pagestate)
		{
			case 0:		//初始化选择界面
			{
				s_1(&pagestate);    //会改变pagestate的值进入
				memset(&u,'\0',sizeof(USER));
				break;           //也即回到界面就成为无登录状态*/
			}

			case 1:		//退出按钮
			{
				delay(500);//延时0.5s，防止下次进入时鼠标崩溃
				closegraph();
				exit(0);//点击关闭框时正常退出
			}

			/*case 2:		//使用说明界面
			{
				s_0_1(&pagestate);
				break;
			}*/

			case 3:		//关于我们界面
			{
				s_0_2(&pagestate);
				break;
			}

			case 4:		//身份选择界面
			{
				s_1_1(&pagestate);
				break;
			}

			case 5:		//个人及团体登录界面
			{
				memset(&u,'\0',sizeof(USER));
				s_1_2_1(&pagestate,&u);
				break;
			}

			case 6:		//管理员登陆函数
			{
				s_1_2_2(&pagestate);
				/*pagestate=10;
				strcpy(adm.userid,"lihaoyu");
				strcpy(adm.password,"123456");*/
				break;
			}

			case 7:		//个人及团体注册函数
			{
				s_1_3(&pagestate);
				break;
			}

			case 8:	//主页面函数
			{
				s_2(&pagestate,&u);
				break;
			}
			
			case 9:	//忘记密码页面函数
			{
				s_1_4(&pagestate);
				break;
			} 
			case 10:	//管理员功能函数
			{
				s_1_2_0(&pagestate,&adm);
				break;
			}
			case 282:	//管理员功能函数
			{
				pagestate=0;
				break;
			}
		}
	}
}

