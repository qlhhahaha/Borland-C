#include"loginfun.h"
#include"common.h"

/*
功能：登陆注册相关的一些功能函数
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：admin_judge
参数传递：adm:管理员信息（账号和密码），char* pass
返回值：无
功能：管理员登录时的判断函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int admin_judge(char* admin, char* pass)
{
	if (strlen(admin) == 0)
	{
		puthz(550,120, "未输入", 16, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		puthz(550,260, "未输入", 16, 17, RED);
		return 0;
	}
	if ((strcmp(admin, "qlh") == 0
		|| strcmp(admin, "lhy") == 0)
		&&strcmp(pass, "aia1905") == 0)
	{
		puthz(300,440, "登录成功", 16, 20, RED);
		return 1;
	}
	else 
		if(strcmp(admin, "qlh") != 0
		&& strcmp(admin, "lhy") != 0)
		{
			puthz(550,110, "管理员信息有误", 16, 20, RED);
			return 0;
		}
		if( strcmp(pass, "aia1905")!= 0)
		{
			puthz(550,260, "密码错误", 16, 20, RED);
			return 0;
		}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：login_complete
参数传递：char* u, char* p,int *pagestate
返回值：无
功能：用户登陆时的账号密码输入判断
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int login_complete(char* u, char* p,int *pagestate)
{
	int state1 = 1;//是否输入的变量
	int state2 = 1;
	int j_r=0;
	while (1)
	{
		judge(u, &state1, 550, 120);
		judge(p, &state2, 550, 270);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			j_r=judge_rightpassword(u, p,pagestate);
			if (j_r==0)//账号密码有问题
			{
				return 0;
			}
			if (j_r==1)//信息正确
			{
				return 1;
			}
			if (j_r==2)//账号被ban
			{
				return 2;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：judge_rightpassword
参数传递：char* name, char* pass,int *pagestate
返回值：无
功能：用户登陆时的账号密码判断
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int judge_rightpassword(char* name, char* pass,int *pagestate)	
{
	int len=0,i=0;
	FILE* fp;
	USER_STR* us;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+")) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER_STR);
	for (i = 0; i < len; i++)
	{
		if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER_STR), SEEK_SET);
		fread(us, sizeof(USER_STR), 1, fp);//fp读到u中
		if (strcmp(name, us->userid) == 0)//用户名匹配
		{
			if	 (strcmp(pass, us->password) != 0)//密码不配
			{
				puthz(550,260, "密码错误", 16, 17, RED);
				if (us != NULL)
				{
					free(us);
					us = NULL;
				}
				break;
			}
			else if (strcmp(pass, us->password) == 0)//密码匹配
			{
				if(judge_ban(atoi(us->times))==1)//如果该账号没被ban
				{
					puthz(300,440, "登录成功", 16, 17, RED);
					if (us != NULL)
					{
						free(us);
						us = NULL;
					}
					delay(1000);
					if (fclose(fp) != 0)
					{
						printf("\n cannot close DATABASE");
						delay(3000);
						exit(1);
					}
					return 1;
					//切换界面
				}
				else//被ban
				{
					g_1_2_1();//绘制提示页面，然后重回登陆页面
					MouseS = 0;
					*pagestate=5;
					clrmous(MouseX, MouseY);
					delay(3000);
					cleardevice();
					return 2;
				}	
			}
		}
		if (us != NULL)
		{
			free(us);
			us = NULL;
		}
	}
	if (i == len)
	{
		puthz(550,110, "账号未注册", 16, 17, RED);//走到最后一位
	}

	if (us != NULL)
	{
		free(us);
		us = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE");
		delay(3000);
		exit(1);
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：judge_ban
参数传递：int times
返回值：无
功能：用户登陆时的账号封禁状态
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int judge_ban(int times)
{
	if (times<0)//如果该账号被ban
	{
		return 0;
	}
	else if (times>=0)
	{
		return 1;
	}

}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：register_complete
参数传递：char*u,char *p,char* cp, char* ph, char* vc,char* rdvc
返回值：无
功能：用户注册时的账号密码判断
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int register_complete(char*u,char *p,char* cp, char* ph, char* vc,char* rdvc)//rdvc为randomvc
{
	int i;
	int state = 0;//是否输入的变量
	int state1 = 1;//确认密码是否一致的变量
	int state2 = 1;//验证码是否一致的变量
	while (1)
	{
		judge(u, &state, 547, 90);
		judge(p, &state, 547, 150);
		judge(cp, &state, 547, 210);
		judge(ph, &state, 547, 270);
		judge(vc, &state, 547, 330);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			if (judge_sameuser(u,1)==0)          //  重名则返回0，未重名返回1
			{
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2= checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if(judge_sameuser(u,2)!=0)//用户名没有重名
			{
				puthz(135, 60, "可用的用户名", 16, 20, RED);
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2 = checkright_verificationcode(rdvc, vc, 547, 330);
				if (state1 != 0 || state2 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 )
				{
					input_database(u,p,ph);
					//写入数据库
					puthz(280,420, "注册成功", 16, 20, RED);
					delay(2000);
					return 1;//返回
				}
			}
		}
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：judge
参数传递：char* str, int* p, int x, int y
返回值：无
功能：输入判断
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "未输入", 16, 20, RED);
	}
	else
	{
		*p = 0;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：input_database
参数传递：char* name, char* code, char* phone
返回值：无
功能：将当前用户信息保存到文件
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void input_database(char* name, char* code, char* phone)
{
	FILE* fp;
	USER* u;
	USER_STR* us;
	int len;
	int i;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)//建立数据库
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	len = ftell(fp) / sizeof(USER_STR);//计算出USER结构体的个数，即已注册用户的个数
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in loginfun.c");
		delay(3000);
		exit(1);
	}
	if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
	{
		printf("memoryallocation runs wrong in loginfun.c");
		delay(3000);
		exit(1);
	}
	
	memset(u,'\0',sizeof(USER));
	memset(us,'\0',sizeof(USER_STR));
	strcpy(u->userid, name);
	strcpy(u->password, code);
	strcpy(u->phone, phone);
	u->score=0;
	u->times=0;
	u->achi=0;
	u->usercode=len;
	for(i=0;i<9;i++) *(u->goods+i)=0;
	USER_ntoa(u,us);//将USER转化为USER_STR 
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(us, sizeof(USER_STR), 1, fp);//把用户信息写入文件
	if (us != NULL || u!=NULL)
	{
		free(us);
		us = NULL;
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：judge_sameuser
参数传递：new_user,flag
返回值：1/0
功能：判断账户是否出现重名,
	flag为1判断是否注册，
	flag为2 3判断找回密码中是否存在
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int judge_sameuser(char* new_user,int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* us;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER_STR);//ftell用于给出fp当前的位置
	for (i = 0; i < len; i++)
	{
		if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER_STR), SEEK_SET);
		fread(us, sizeof(USER_STR), 1, fp);
		//遍历每一个结构体
		if (strcmp(us->userid, new_user) == 0)
		{
			switch (flag)
			{
				case 1: 
					puthz(135, 60, "用户已被注册", 16, 20, RED);
					break;
				case 2:
					puthz(450, 110, "账号存在", 16, 20, RED);
					break;
				case 3:
					puthz(540, 110, "账号存在", 16, 20, RED);
					break;
				default:
					printf("something wrong");
					delay(3000);
					exit(1);
			}
			if (us != NULL)
			{
				free(us);
				us = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close DATABASE.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(us);
		us = NULL;
	}
	if (us != NULL)
	{
		free(us);
		us = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
	return 1;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：checkright_confirmedpassword
参数传递：char* str1, char* str2, int x, int y
返回值：1/0
功能：检测两次密码输入是否一致
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "两次不一致", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：checkright_verificationcode
参数传递：char* str1, char* str2, int x, int y
返回值：1/0
功能：检测验证码是否一致
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int checkright_verificationcode(char* str1, char* str2,int x,int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "验证码错误", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：inputadmin
参数传递：char* id, int x1, int y1, int charnum, int color
返回值：无
功能：输入函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int i = 0;//i用于计数
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);//画光标线
	while (1)
	{
		t = bioskey(0); //用t记录键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//当t不为特殊键时
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标  
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：inputpassword
参数传递：char* id, int x1, int y1, int charnum, int color
返回值：无
功能：输入密码函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (1)
	{
		t = bioskey(0);//读取键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033表示Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//输出*字符
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：recoverhz
参数传递：int x, int y,int color
返回值：无
功能：汉字覆盖函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverhz(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：input_uinfo
参数传递：USER* u
返回值：1/0
功能：把当前用户的信息从文件读取到程序的结构体中
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int input_uinfo(USER* u)
{
	int i;
	int len;
	FILE* fp;
	USER_STR* us;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER_STR);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER_STR), SEEK_SET);//每次往后移一个用户
		fread(us, sizeof(USER_STR), 1, fp);		  //将信息读入us
		if (strcmp(us->userid, u->userid) == 0)//找到当前账号信息，给到u
		{
			USER_aton(u,us);
			if (us!= NULL)
			{
				free(us);
				us = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close DATABASE");
				exit(1);
			}
			delay(2000);
			return 1;
		}
		if (us != NULL)
		{
			free(us);
			us = NULL;
		}
	}
	if (us != NULL)
	{
		free(us);
		us = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE");
		exit(1);
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：id_phone
参数传递：id,ph,pass,againpass
返回值：1/0
功能：判断账号与电话号是否匹配，
	并判断两次输入的密码是否相同，
	若匹配且相同则写入新密码。
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int id_phone(char* id, char* ph, char* np, char* cp)
{
	int str;
	int len;//用于计算用户个数
	int i,j;//用于计数
	FILE* fp;
	USER* us;
	if ((fp = fopen("database\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER_STR);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(2000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER_STR), SEEK_SET);//每次往后移一个用户
		fread(us, sizeof(USER_STR), 1, fp);//将信息读入us
		if (strcmp(id, us->userid) == 0)
		{
			if (strcmp(ph, us->phone) != 0)
			{
				puthz(140,205, "电话不匹配", 16, 20, RED);
				break;
			}
			else if (strcmp(ph, us->phone) == 0)
			{
				if (strcmp(np, cp) == 0)//两次输入密码相同
				{
					us->password[0] = '\0';
					strcpy(us->password, np);
					fseek(fp, i * sizeof(USER_STR), SEEK_SET);
					fwrite(us, sizeof(USER_STR), 1, fp);//修改完后一定要记得写入数据
					puthz(420,415,"修改成功",16,20,RED);
					if (us != NULL)
					{
						free(us);
						us = NULL;
					}
					if (fclose(fp) != 0)
					{
						printf("\n cannot close Database");
						exit(1);
					}
					delay(2000);
					return 1;
				}
			}
		}
		if (us != NULL)
		{
			free(us);
			us = NULL;
		}
	}

	if (us != NULL)
	{
		free(us);
		us = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	return 0;
}