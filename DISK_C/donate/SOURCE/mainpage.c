#include"common.h"
#include"mainpage.h"

/*
功能：主页面控制，负责登录成功之后的页面切换和控制
作者：李浩宇
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2
参数传递：pagestate:页面编号，u
返回值：无
功能：利用无限循环和页面指针控制页面切换
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void s_2(int *pagestate,USER* u)/*主菜单页面函数,注意此处的pagestate是指针，与main里的不同
usercode在这里传进来是为了在mainpage页面导出当前用户的信息
并用一个结构体存起来，方便后续使用*/
{	
	long int prosite=0,recordsite=0;//记录项目在文件里的位置
	/*int exit_save=0;//记录点击退出确认框之前的页面值*/
	*pagestate=21;//登陆进入后，默认到爱心背景页面
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	/*init_public();//初始化公共物资池*/
	/*create_admin();//创建一个管理员信息*/
	while(1)
	{
		switch(*pagestate)
		{
			case 21:
			s_2_1(pagestate);//打开爱心背景页面
			break;
			
			case 220:
			prosite=s_2_2_0(pagestate);//打开我要捐助页面
			break;
			
			case 222:
			s_2_2_2(pagestate,u);//公共项目池
			break;
			
			case 224:
			s_2_2_4(pagestate,prosite);//打开项目详情页面
			break;
			
			case 225:
			s_2_2_5(pagestate,prosite,u);//打开填写界面
			break;
			
			case 230:
			s_2_3_0(pagestate,u);//打开发起请求页面
			break;
			
			case 240:
			recordsite=s_2_4_0(pagestate,u,0);//打开捐助记录页面
			break;
			
			case 242:
			s_2_4_2(pagestate,recordsite,0);//捐助记录详情页面 
			break;
			
			case 250:
			s_2_5_0(pagestate);//打开爱心留言页面
			break;
			
			case 260:
			s_2_6_0(pagestate,u);//打开互助商城页面
			break;
			
			case 270:
			s_2_7_0(pagestate,u);//打开个人信息页面
			break;
			
			case 280:
			s_2_8_0(pagestate);//注销登录，回到登陆页面*/
			break;
			
			case 290:
			*pagestate=0;
			return;
			
			case 2100:
			s_2_10_0(pagestate);
			break;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_0
参数传递：pagestate:页面编号
返回值：无
功能：上方常驻菜单栏功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_0(int *pagestate)//上方常驻菜单栏功能函数
{
	while(1)
	{
		if (MouseX > 0 && MouseX < 80 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(0,0,80,19) == 2)
			{
				MouseS = 1;
			}
			if (mouse_press(0,0,80,19)==1)
			{
				MouseS = 0;
				*pagestate=21;//转到爱心背景页面
				return 1;
			}
		}
	
		if (MouseX > 81 && MouseX < 160 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(81,0,160,19) == 2)
			{
				MouseS = 1;
			}
			if (mouse_press(81,0,160,19)==1)
			{
				MouseS = 0;
				*pagestate=220;//转到我要捐助页面
				return 1;
			}
		}
		
		if (MouseX > 161 && MouseX < 240 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(161,0,240,19) == 2)
			{
				MouseS = 1;
				
			}
			if (mouse_press(161,0,240,19)==1)
			{
				MouseS = 0;
				*pagestate=230;//转到发起请求页面
				return 1;
			}
		}
		
		if (MouseX > 241 && MouseX < 320 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(241,0,320,19) == 2)
			{
				MouseS = 1;	
			}
			if (mouse_press(241,0,320,19)==1)//打开查询方式的弹窗
			{
				MouseS = 0;
				*pagestate=240;
				return 1;
			}
		}
		
		if (MouseX > 321 && MouseX < 400 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(321,0,400,19) == 2)
			{
				MouseS = 1;
				
			}
			if (mouse_press(321,0,400,19)==1)
			{
				MouseS = 0;
				*pagestate=250;//转到爱心留言页面
				return 1;
			}
		}
		
		if (MouseX > 401 && MouseX < 480 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(401,0,480,19) == 2)
			{
				MouseS = 1;
				
			}
			if (mouse_press(401,0,480,19)==1)
			{
				MouseS = 0;
				*pagestate=260;//转到互助商城页面
				return 1;
			}
		}
		
		if (MouseX > 481 && MouseX < 560 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(481,0,560,19) == 2)
			{
				MouseS = 1;
			}
			if (mouse_press(481,0,560,19)==1)
			{
				MouseS = 0;
				*pagestate=270;//转到个人信息页面
				return 1;
			}
		}
		
		if (MouseX > 561 && MouseX < 639 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(561,0,639,19) == 2)
			{
				MouseS = 1;	
			}
			if (mouse_press(561,0,639,19)==1)
			{
				MouseS = 0;
				*pagestate=2100;
				return 1;
			}
		}
		
		if (MouseX > 0 && MouseX < 639 && MouseY>21 && MouseY < 479)
		{
			MouseS = 0;
		}
		return 0;//什么都没点 
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_8
参数传递：pagestate:页面编号
返回值：无
功能：确认是否退出的弹窗
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_8(int *pagestate)//确认是否退出的弹窗
{
	void *pic=NULL;
	getimage(139,140,455,360,pic);
	g_2_8();//绘制此弹窗
	if (mouse_press(223,180,381,240)==1)
	{
		exit(0);
	}
	if (mouse_press(223,260,381,320)==1)
	{
		setcolor(RED);
		bar(139,140,455,360);
		putimage(139,140,pic,0);//关闭弹窗
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：usercode_import
参数传递：pagestate:页面编号  USER* us
返回值：无
功能：利用usercode将用户信息导入程序中的结构体
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void usercode_import(USER* us,int usercode)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);		  //将信息读入u
		if (u->usercode==usercode)
		{
			memset(us,'\0',sizeof(USER));              //先重置
			//在USER.dat中找到usercode对应的的这个账号，存到us中
			strcpy(us->userid,u->userid);
			strcpy(us->password,u->password); 
			strcpy(us-> phone,u->phone); 
	
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close DATABASE");
				exit(1);
			}
			delay(2000);
			return ;
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE");
		exit(1);
	}
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：init_public
参数传递：无
返回值：无
功能：为公共项目池初始化
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void init_public(void)//为公共项目池初始化
{
	char public[11];
	FILE *fp;
	int i;
	public[0]='0';
	for(i=1;i<11;i++)
	{
		public[i]='\0';
	}
	if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,0,SEEK_SET);
	for(i=0;i<7*9;i++)
	{
		fwrite(public,sizeof(char),11,fp);
	}
	
	free(fp);
	fclose(fp);
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：create_admin
参数传递：无
返回值：无
功能：//创建一个新的管理员信息
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void create_admin(void)//创建一个新的管理员信息
{
	FILE *fp;
	ADMIN temp;
	char admin_id[15]="Rick";
	char admin_password[10]="123456";
	memset(&temp,'\0',25*sizeof(char));
	strcpy(temp.userid,admin_id);
	stpcpy(temp.password,admin_password);
	if((fp=fopen("c:\\donate\\DATABASE\\ADMIN.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,0,SEEK_END);
	fwrite(&temp,sizeof(char),25,fp);
	free(fp);
	fclose(fp);
	setfillstyle(1,WHITE);
	bar(180,200,480,250);
	puthz(190,210,"管理员信息创建成功",32,35,8);
	delay(5000);
	return ;
}