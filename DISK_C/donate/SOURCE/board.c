#include"common.h"
#include"board.h"
#include"shubiao.h"

/*
功能：公示板功能
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_10_0
参数传递：pagestate:页面编号
返回值：无
功能：下拉菜单功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_10_0(int *pagestate)
{
	int num = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	g_2_10_0();
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if(s_2_0(pagestate)==1)//将pagestate作为地址传入s_2_0，如果点击了上方菜单则s_2_0返回1 
		{
			return;
		}
		
		if (MouseX > 562 && MouseX < 639 && MouseY>19 && MouseY < 50)
		{
			if (mouse_press(562,19,639,50) == 2)
			{
				MouseS = 1;
				if (num == 0)//防止被重复标亮
				{
					lightbutton_board(562,19,639,50,LIGHTCYAN,LIGHTGRAY, 1);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(562,19,639,50) == 1)
			{
				MouseS = 0;
				delay(500);
				s_2_10_1(pagestate);
				return;
			}
		}
		
		if (MouseX > 562 && MouseX < 639 && MouseY>50 && MouseY < 80)
		{
			if (mouse_press(562,50,639,80) == 2)
			{
				MouseS = 1;
				if (num == 0)//防止被重复标亮
				{
					lightbutton_board(562,50,639,80,LIGHTCYAN,LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(562,50,639,80) == 1)
			{
				MouseS = 0;
				delay(500);
				s_2_10_2(pagestate);
				return;
			}
		}
		
		if (num != 0)
		{
			MouseS = 0;
			if (num == 1)
			{
				recoverbutton_board(1);
			}
			if (num == 2)
			{
				recoverbutton_board(2);
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
函数名：s_2_10_1
参数传递：pagestate:页面编号
返回值：无
功能：数据统计功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_10_1(int *pagestate)
{
	int debug;
	FILE* fp_user;
	FILE* fp_pro;
	FILE* fp_record;
	RECORD_STR *record_str_temp;
	RECORD *record_temp;
	USER_STR *user_str_temp;
	USER *user_temp;
	int people=0,peo_times=0,pro_num=0,max_user=0;//注册人数；捐赠人次；项目数量；最多的次数
	char peo[8]={'0'},p_t[8]={'0'},p_n[8]={'0'},m_u[8]={'0'},r_u[8]={'0'};//outtext不能直接输出数字
	char ri_user[20]={'0'},m_user[20]={'0'};//保存用户名
	char username[30][20];//遍历保存用户名，本软件注册用户应该不会超过30位
	int one_people_times[30]={0};//遍历时保存每位用户的次数，本软件注册用户应该不会超过30位
	int i=0,j=0;
	long int sum[9]={0};//收到的物资数，没包括钱
	long int richest_user=0;
	char sum_str[9][11]={'0'}; 
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	
/**************************USER相关数据**************************/
	if((fp_user=fopen("DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp_user, 0, SEEK_END);//跳转至文件末尾
	people=ftell(fp_user)/sizeof(USER_STR);
	for (i=0;i<people;i++)
	{
		if ((user_str_temp = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in board.c");
			delay(3000);
			exit(1);
		}
		fseek(fp_user, i * sizeof(USER_STR), SEEK_SET);
		fread(user_str_temp, sizeof(USER_STR), 1, fp_user);
		/*USER_aton(user_temp,user_str_temp);//用user_temp导出*/
		strcpy(username[i],user_str_temp->userid);//用二维数组username来储存姓名，以完成maxuser的比较
	}
	free(fp_user);
	if (fclose(fp_user) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}

/**************************PRO相关数据**************************/	
	if((fp_pro=fopen("DATABASE\\PRO.dat","rb+"))==NULL)
	{
		printf("cannot open file PRO.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp_pro, 0, SEEK_END);//跳转至文件末尾
	pro_num=ftell(fp_pro)/sizeof(PRO_STR);
	free(fp_pro);
	if (fclose(fp_pro) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
	
/**************************RECORD相关数据**************************/	
	if((fp_record=fopen("DATABASE\\RECORD.dat","rb+"))==NULL)
	{
		printf("cannot open file RECORD.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp_record, 0, SEEK_END);//跳转至文件末尾
	peo_times=ftell(fp_record)/sizeof(RECORD_STR);
	for (i=0;i<peo_times;i++)
	{
		if ((record_str_temp = (RECORD_STR*)malloc(sizeof(RECORD_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in board.c");
			delay(3000);
			exit(1);
		}
		fseek(fp_record, i * sizeof(RECORD_STR), SEEK_SET);
		fread(record_str_temp, sizeof(RECORD_STR), 1, fp_record);
		
		
		if (strcmp(record_str_temp->userid,"ADMIN") != 0)
			//管理员的调度记录不予以考虑
		{
			RECORD_aton(record_temp,record_str_temp);//用record_temp导出
			for(j=1;j<9;j++)
			{
				sum[(record_temp->protype)+2] += record_temp->amount[j];
				//+2是因为对应关系是这样
			}
			if((record_temp->amount[0]) >= richest_user) 
			{
				richest_user = record_temp->amount[0];//比较得到土豪
				strcpy(ri_user,record_temp->userid);
			}
			for (j=0;j<people;j++)
			{
				if(strcmp(username[j],record_temp->userid) == 0)//找到对应用户
				{
					one_people_times[j] += 1;
				}
			}
		}
		
	}
	for(j=1;j<9;j++)//sum[0]是收到的物资总数量
	{
		sum[0] += sum[j];
	}
	for (j=0;j<30;j++)
	{
		if(one_people_times[j]>max_user)
		{
			max_user = one_people_times[j];//比较得到次数最多者
			strcpy(m_user,username[j]);
		}
	}
	free(fp_record);
	if (fclose(fp_record) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
	
	setbkcolor(LIGHTCYAN);
	settextstyle(0,0,2);
	setcolor(LIGHTBLUE);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
	puthz(240,5,"数据统计",32,40,8);
	
	puthz(2,35,"自平台创建以来，共有",24,25,8);
	outtextxy(270,35,itoa(people,peo,10));
	puthz(320,35,"人注册",24,25,8);
	
	puthz(2,80,"总计捐款",24,25,8);
	outtextxy(120,80,itoa(peo_times,p_t,10));
	puthz(180,75,"人次，共发起项目",24,25,8);
	outtextxy(410,80,itoa(pro_num,p_n,10));
	puthz(450,80,"个",24,25,8);
	
	puthz(2,130,"各类物资总计",24,25,8);
	outtextxy(170,130,ltoa(sum[0],sum_str[0],10));
	puthz(320,130,"件，其中包括：",24,25,8);
	
	puthz(2,180,"公共",24,25,8);
	outtextxy(60,180,ltoa(sum[1],sum_str[1],10));
	puthz(90,180,"件",24,25,8);
	
	puthz(140,180,"儿童",24,25,8);
	outtextxy(200,180,ltoa(sum[2],sum_str[2],10));
	puthz(230,180,"件",24,25,8);
	
	puthz(280,180,"老人",24,25,8);
	outtextxy(340,180,ltoa(sum[3],sum_str[3],10));
	puthz(370,180,"件",24,25,8);
	
	puthz(420,180,"扶贫",24,25,8);
	outtextxy(480,180,ltoa(sum[4],sum_str[4],10));
	puthz(510,180,"件",24,25,8);
	
	puthz(2,230,"救灾",24,25,8);
	outtextxy(60,230,ltoa(sum[1],sum_str[1],10));
	puthz(90,230,"件",24,25,8);
	
	puthz(140,230,"抗疫",24,25,8);
	outtextxy(200,230,ltoa(sum[1],sum_str[1],10));
	puthz(230,230,"件",24,25,8);
	
	puthz(280,230,"教育",24,25,8);
	outtextxy(340,230,ltoa(sum[1],sum_str[1],10));
	puthz(370,230,"件",24,25,8);
	
	puthz(420,230,"环保",24,25,8);
	outtextxy(480,230,ltoa(sum[1],sum_str[1],10));
	puthz(510,230,"件",24,25,8);
	
	puthz(2,280,"捐赠次数最多的是用户",24,25,8);
	outtextxy(260,280,m_user);
	puthz(310,280,"，",24,25,8);
	puthz(2,320,"达",24,25,8);
	outtextxy(30,320,itoa(max_user,m_u,10));
	puthz(120,320,"次",24,25,8);
	
	puthz(2,360,"单次金额最多的是用户",24,25,8);
	outtextxy(260,360,ri_user);
	puthz(310,360,"，",24,25,8);
	puthz(2,400,"达",24,25,8);
	outtextxy(30,400,ltoa(richest_user,r_u,10));
	puthz(250,400,"元",24,25,8);
	
	delay(200);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if (MouseX > 605 && MouseX < 635 && MouseY>5 && MouseY < 35)
		{
			if (mouse_press(605,5,635,35) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(605,5,635,35) == 1)
			{
				*pagestate=21;
				delay(500);
				cleardevice();
				return;
			}
		}
		
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_10_2
参数传递：pagestate:页面编号
返回值：无
功能：使用说明功能函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_10_2(int *pagestate)
{
	FILE *fp;
	char in[200]={'0'};//一行肯定不到100字
	int row=0;
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
	puthz(270,5,"使用说明",32,30,8);
	
	setbkcolor(LIGHTCYAN);
	if((fp=fopen("DATABASE\\INSTRUCT.txt","r+"))==NULL)
	{
		printf("cannot open file INSTRUCT.txt");
		delay(3000);
		exit(1);
	}

	while(fscanf(fp,"%[^\n]",in)!=EOF)
	{ 
		fgetc(fp);
		outputhz(5,45+row*30,600,75+row*30,in,8);
		memset(in,'\0',200);
		row++;
	}

	free(fp);
	if (fclose(fp) != 0)
	{
		printf("\n cannot close ABOUT.");
		delay(3000);
		exit(1);
	}
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (MouseX > 605 && MouseX < 635 && MouseY>5 && MouseY < 35)
		{
			if (mouse_press(605,5,635,35) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(605,5,635,35) == 1)
			{
				*pagestate=21;
				delay(500);
				cleardevice();
				return;
			}
		}
		
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：lightbutton_board
参数传递：x,y,x1,y1,color1,color2,flag
返回值：无
功能：界面按钮点亮
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_board(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(50);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	
	if(flag==1)
	{
		puthz(567,22,"数据统计",16,16,8);
	}
	if(flag==2)
	{
		puthz(567,52,"使用说明",16,16,8);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：recoverbutton_board
参数传递：status
返回值：无
功能：界面按钮恢复
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverbutton_board(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);

	switch (status)
	{
		case 1:
			bar(562,19,639,50);
			rectangle(562,19,639,50);
			puthz(567,22,"数据统计",16,16,8);
			break;
		case 2:
			bar(562,50,639,80);
			rectangle(562,50,639,80);
			puthz(567,52,"使用说明",16,16,8);
			break;
	}
}