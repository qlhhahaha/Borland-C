#include"login.h"
#include"common.h"

/*
功能：登陆相关功能函数
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_1
参数传递：pagestate:页面编号
返回值：无
功能：首页面功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1(int *pagestate)
{
	clrmous(MouseX, MouseY);
	delay(100);
	g_1();//欢迎页面1绘图函数
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if (MouseX >30 && MouseX < 180 && MouseY>300 && MouseY < 360)
		{
			if (mouse_press(30,300,180,360) == 2)//身份选择未点击
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(30,300,180,360) == 1)//身份选择点击
			{
				MouseS = 0;
				*pagestate=4;
				delay(50);
				return;
				//切换至身份选择界面
			}
		}
		
		if (MouseX >460 && MouseX < 610 && MouseY>300 && MouseY < 360)
		{
			if (mouse_press(460,300,610,360) == 2)//关于我们未点击
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(460,300,610,360) == 1)//关于我们点击
			{
				MouseS = 0;
				*pagestate=3;
				delay(50);
				return;
				//切换至关于我们界面
			}
		}
		
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=1;//退出
			delay(500);
			cleardevice();
			return;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_0_2
参数传递：pagestate:页面编号
返回值：无
功能：关于我们功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_0_2(int *pagestate)
{
	FILE *about;
	char ab[200]={'0'};//一行肯定不到100字
	int len=0,row=0;
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
	
	if((about=fopen("DATABASE\\ABOUT.txt","r+"))==NULL)
	{
		printf("cannot open file ABOUT.txt");
		delay(3000);
		exit(1);
	}
	/*while(fgets(ab,200,about) != NULL)//读取该行文字成功时
	{
		len = strlen(ab);
		ab[len-1] = '\0';  //去掉换行符
		outputhz(5,5+row*30,500,35+row*30,ab,WHITE);
		memset(ab,'\0',len);
		row++;
	}*/
	while(fscanf(about,"%[^\n]",ab)!=EOF)
	{ 
		fgetc(about);
		outputhz(5,5+row*30,600,35+row*30,ab,WHITE);
		memset(ab,'\0',200);
		row++;
	}
/*
ab用来存储一行的内容。
此code运用了fscanf的方式，一行一行的读取txt文件，在while中做处理。
其中的%[^\n]属于正则表达式，代表不遇到换行符就一直读下去，
直到遇到换行符\n，fscanf函数就退出。
退出后进入while，执行fgetc函数，读取一个字符，
文件句柄向后移动一个字符，相当于跳过了\n换行符，下一次就从下一行开始读了。
*/
	free(about);
	if (fclose(about) != 0)
	{
		printf("\n cannot close ABOUT.");
		delay(3000);
		exit(1);
	}
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=0;
			delay(500);
			cleardevice();
			return;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_1_1
参数传递：pagestate:页面编号
返回值：无
功能：身份选择功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_1(int *pagestate)
{
	cleardevice();
	clrmous(MouseX, MouseY);
	delay(100);
	g_1_1();//身份选择页面1_1绘图函数
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if (MouseX >240 && MouseX < 400 && MouseY>170 && MouseY < 220)
		{
			if (mouse_press(240,170,400,220) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(240,170,400,220) == 1)
			{
				MouseS = 0;
				*pagestate=5;
				delay(50);
				return;
				//切换至个人登录界面
			}
		}
		
		if (MouseX >240 && MouseX < 400 && MouseY>260 && MouseY < 310)
		{
			if (mouse_press(240,260,400,310) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(240,260,400,310) == 1)
			{
				MouseS = 0;
				*pagestate=5;
				delay(50);
				return;
				//切换至团体登录界面
			}
		}
		
		if (MouseX >240 && MouseX < 400 && MouseY>350 && MouseY < 400)
		{
			if (mouse_press(240,350,400,400) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(240,350,400,400) == 1)
			{
				MouseS = 0;
				*pagestate=6;
				delay(50);
				return;
				//切换至管理员登陆界面
			}
		}

		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=0;//返回标题页面
			delay(500);
			cleardevice();
			return;
		}
		
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_1_1
参数传递：pagestate:页面编号 USER *u
返回值：无
功能：个人及团体登录功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_2_1(int *pagestate,USER *u)
{
	int num=0;
	int state1 = 0;//输入内容检验，输入了为1，没输入为0
	int state2 = 0;
	int lg_complete=0;//用于检验login_complete的返回值，避免重复调用函数造成崩溃
	memset(u,'\0',sizeof(USER));   //将别处传过来的u清零
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	g_1_2();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX >135 && MouseX < 540 && MouseY>100 && MouseY < 150)
		{
			if (mouse_press(135,100,540,150) == 2)//用户名框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;
				//标亮函数
			}

			else if (mouse_press(135,100,540,150) == 1)//用户名框点击
			{
				MouseS = 0;
				lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				u->userid[0] = '\0';
				inputadmin(u->userid,135,110,11, LIGHTGRAY);//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
				//输入函数
				if(strlen(u->userid) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		
		if (MouseX >135 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(130,250,540,300) == 2)//密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//标亮函数
					num = 2;
				}
				continue;
			}
			else if (mouse_press(130,250,540,300) == 1)//密码框点击
			{
				MouseS = 0;
				lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password,135,260,10, LIGHTGRAY);
				//输入函数
				if(strlen(u->password) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
			}
		}
		
		if (MouseX >250 && MouseX < 360 && MouseY>310 && MouseY < 330)
		{
			if (mouse_press(250,310,360,330) == 2)//忘记密码未点击
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(250,310,360,330) == 1)//忘记密码点击
			{
				MouseS = 0;
				*pagestate=9;
				delay(50);
				return;
				//切换至忘记密码界面
			}
		}
		
		if (MouseX > 110 && MouseX < 260 && MouseY>370 && MouseY < 450)
		{
			if (mouse_press(110,370,260,450) == 2)//登录框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110,370,260,450, LIGHTCYAN, DARKGRAY, 2);//标亮函数
					num = 3;
				}
				continue;
			}
			else if (mouse_press(110,370,260,450) == 1)//登录框点击
			{
				MouseS = 0;
				lg_complete=login_complete(u->userid, u->password,pagestate);
				if (lg_complete==0)//账号密码有问题
				{
					continue;
				}
				
				if (lg_complete==1) //信息正确
				{
					if (input_uinfo(u)==1)  //将信息从文件中传到u指针
					{
						*pagestate = 8;
						delay(500);
						return;
					}
					else
					{
						printf("something wrong");
						delay(3000);
						exit(1);
					}
				}
				
				if (lg_complete==2)//账号被ban
				{
					return;
				}
				
			}
		}
		
		if (MouseX > 380 && MouseX < 530 && MouseY>370 && MouseY < 450)
		{
			if (mouse_press(380,370,530,450) == 2)//注册框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(380,370,530,450, LIGHTCYAN, DARKGRAY, 3);//标亮函数
					num = 4;
				}
				continue;
			}
			else if (mouse_press(380,370,530,450) == 1)//注册框点击
			{
				MouseS = 0;
				*pagestate = 7;
				delay(50);
				return;
			}
		}

		if (mouse_press(605,5,635,35) == 1)//返回框点击
			{
				MouseS = 0;
				*pagestate = 0;
				delay(500);
				cleardevice();
				return;
			}
			
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 3 || num == 4 )
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_1_2_2
参数传递：pagestate:页面编号 
返回值：无
功能：管理员登录功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_2_2(int *pagestate)
{
	int num=0;
	int state = 0;
	char A[15] = { '\0' };	//管理员账号
	char P[10] = { '\0' };	//管理员密码
	int state1 = 0;
	int state2 = 0;
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	g_1_2_0();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX >135 && MouseX < 540 && MouseY>100 && MouseY < 150)
		{
			if (mouse_press(135,100,540,150) == 2)//用户名框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;
				//标亮函数
			}
			else if (mouse_press(135,100,540,150) == 1)//管理员框点击
			{
				MouseS = 0;
				lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				A[0] = '\0';
				inputadmin(A, 135,110, 5, LIGHTGRAY);
				//输入函数
				if(strlen(A) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		if (MouseX >135 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(135,250,540,300) == 2)//密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//标亮函数
					num = 2;
				}
				continue;
			}
			else if (mouse_press(135,250,540,300) == 1)//密码框点击
			{
				MouseS = 0;
				lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);
				P[0] = '\0';
				inputpassword(P, 135,260, 8, LIGHTGRAY);
				if(strlen(P) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
				//输入函数
			}
		}
		if (MouseX > 230 && MouseX < 390 && MouseY>370 && MouseY < 450)
		{
			if (mouse_press(230,370,390,450) == 2)//登录框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(230,370,390,450, LIGHTCYAN, LIGHTGRAY, 4);//标亮函数
					num = 5;
				}
				continue;
			}
			else if (mouse_press(230,370,390,450) == 1)//登录框点击
			{
				MouseS = 0;
				if (admin_judge(A, P))
				{
					delay(2000);
					*pagestate=10;
					return;
				}
				else
				{
					continue;
				}
				continue;
				//检查是否与录入数据库的管理员身份相符
			}
		}
		
		if (mouse_press(605,5,635,35) == 1)//返回框点击
			{
				MouseS = 0;
				*pagestate = 0;
				delay(500);
				cleardevice();
				return;
			}

		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 5)
			{
				recoverbutton_login(5);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}
 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：lightbutton_login
参数传递：int x, int y, int x1, int y1, int color1, int color2, int flag
返回值：无
功能：登陆页面点亮函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
		case 1:
			break;
		case 2:
			puthz(130,390, "登陆", 32, 80, WHITE);
			break;
		case 3:
			puthz(400,390, "注册", 32, 80, WHITE);
			break;
		case 4:
			puthz(250,390, "登陆", 32, 80, WHITE);
			break;
		default:
			closegraph();
			printf("something runs wrong in lightbutton");
			exit(1);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：recoverbutton_login
参数传递：int status
返回值：无
功能：登陆页面恢复函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverbutton_login(int status)
{
	clrmous(MouseX, MouseY);	
	setfillstyle(SOLID_FILL, WHITE);

	switch (status)
	{
		case 1:
			bar(135,100,540,150);
			rectangle(135,100,540,150);
			break;
		case 2:
			bar(135,250,540,300);
			rectangle(135,250,540,300);
			break;
		case 3:
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(110,370,260,450);
			puthz(130,390,"登陆",32,80,WHITE);
			break;
		case 4:
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(380,370,530,450);
			puthz(400,390,"注册",32,80,WHITE);
			break;
		case 5:
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(230,370,390,450);
			puthz(250,390,"登陆",32,80,WHITE);
			break;	
	}
}

