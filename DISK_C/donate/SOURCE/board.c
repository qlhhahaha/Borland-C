#include"common.h"
#include"board.h"
#include"shubiao.h"

/*
���ܣ���ʾ�幦��
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_10_0
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ������˵����ܺ���
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
		
		if(s_2_0(pagestate)==1)//��pagestate��Ϊ��ַ����s_2_0�����������Ϸ��˵���s_2_0����1 
		{
			return;
		}
		
		if (MouseX > 562 && MouseX < 639 && MouseY>19 && MouseY < 50)
		{
			if (mouse_press(562,19,639,50) == 2)
			{
				MouseS = 1;
				if (num == 0)//��ֹ���ظ�����
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
				if (num == 0)//��ֹ���ظ�����
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
��������s_2_10_1
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ�����ͳ�ƹ��ܺ���
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
	int people=0,peo_times=0,pro_num=0,max_user=0;//ע�������������˴Σ���Ŀ���������Ĵ���
	char peo[8]={'0'},p_t[8]={'0'},p_n[8]={'0'},m_u[8]={'0'},r_u[8]={'0'};//outtext����ֱ���������
	char ri_user[20]={'0'},m_user[20]={'0'};//�����û���
	char username[30][20];//���������û����������ע���û�Ӧ�ò��ᳬ��30λ
	int one_people_times[30]={0};//����ʱ����ÿλ�û��Ĵ����������ע���û�Ӧ�ò��ᳬ��30λ
	int i=0,j=0;
	long int sum[9]={0};//�յ�����������û����Ǯ
	long int richest_user=0;
	char sum_str[9][11]={'0'}; 
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	
/**************************USER�������**************************/
	if((fp_user=fopen("DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp_user, 0, SEEK_END);//��ת���ļ�ĩβ
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
		/*USER_aton(user_temp,user_str_temp);//��user_temp����*/
		strcpy(username[i],user_str_temp->userid);//�ö�ά����username�����������������maxuser�ıȽ�
	}
	free(fp_user);
	if (fclose(fp_user) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}

/**************************PRO�������**************************/	
	if((fp_pro=fopen("DATABASE\\PRO.dat","rb+"))==NULL)
	{
		printf("cannot open file PRO.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp_pro, 0, SEEK_END);//��ת���ļ�ĩβ
	pro_num=ftell(fp_pro)/sizeof(PRO_STR);
	free(fp_pro);
	if (fclose(fp_pro) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
	
/**************************RECORD�������**************************/	
	if((fp_record=fopen("DATABASE\\RECORD.dat","rb+"))==NULL)
	{
		printf("cannot open file RECORD.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp_record, 0, SEEK_END);//��ת���ļ�ĩβ
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
			//����Ա�ĵ��ȼ�¼�����Կ���
		{
			RECORD_aton(record_temp,record_str_temp);//��record_temp����
			for(j=1;j<9;j++)
			{
				sum[(record_temp->protype)+2] += record_temp->amount[j];
				//+2����Ϊ��Ӧ��ϵ������
			}
			if((record_temp->amount[0]) >= richest_user) 
			{
				richest_user = record_temp->amount[0];//�Ƚϵõ�����
				strcpy(ri_user,record_temp->userid);
			}
			for (j=0;j<people;j++)
			{
				if(strcmp(username[j],record_temp->userid) == 0)//�ҵ���Ӧ�û�
				{
					one_people_times[j] += 1;
				}
			}
		}
		
	}
	for(j=1;j<9;j++)//sum[0]���յ�������������
	{
		sum[0] += sum[j];
	}
	for (j=0;j<30;j++)
	{
		if(one_people_times[j]>max_user)
		{
			max_user = one_people_times[j];//�Ƚϵõ����������
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
	puthz(240,5,"����ͳ��",32,40,8);
	
	puthz(2,35,"��ƽ̨��������������",24,25,8);
	outtextxy(270,35,itoa(people,peo,10));
	puthz(320,35,"��ע��",24,25,8);
	
	puthz(2,80,"�ܼƾ��",24,25,8);
	outtextxy(120,80,itoa(peo_times,p_t,10));
	puthz(180,75,"�˴Σ���������Ŀ",24,25,8);
	outtextxy(410,80,itoa(pro_num,p_n,10));
	puthz(450,80,"��",24,25,8);
	
	puthz(2,130,"���������ܼ�",24,25,8);
	outtextxy(170,130,ltoa(sum[0],sum_str[0],10));
	puthz(320,130,"�������а�����",24,25,8);
	
	puthz(2,180,"����",24,25,8);
	outtextxy(60,180,ltoa(sum[1],sum_str[1],10));
	puthz(90,180,"��",24,25,8);
	
	puthz(140,180,"��ͯ",24,25,8);
	outtextxy(200,180,ltoa(sum[2],sum_str[2],10));
	puthz(230,180,"��",24,25,8);
	
	puthz(280,180,"����",24,25,8);
	outtextxy(340,180,ltoa(sum[3],sum_str[3],10));
	puthz(370,180,"��",24,25,8);
	
	puthz(420,180,"��ƶ",24,25,8);
	outtextxy(480,180,ltoa(sum[4],sum_str[4],10));
	puthz(510,180,"��",24,25,8);
	
	puthz(2,230,"����",24,25,8);
	outtextxy(60,230,ltoa(sum[1],sum_str[1],10));
	puthz(90,230,"��",24,25,8);
	
	puthz(140,230,"����",24,25,8);
	outtextxy(200,230,ltoa(sum[1],sum_str[1],10));
	puthz(230,230,"��",24,25,8);
	
	puthz(280,230,"����",24,25,8);
	outtextxy(340,230,ltoa(sum[1],sum_str[1],10));
	puthz(370,230,"��",24,25,8);
	
	puthz(420,230,"����",24,25,8);
	outtextxy(480,230,ltoa(sum[1],sum_str[1],10));
	puthz(510,230,"��",24,25,8);
	
	puthz(2,280,"���������������û�",24,25,8);
	outtextxy(260,280,m_user);
	puthz(310,280,"��",24,25,8);
	puthz(2,320,"��",24,25,8);
	outtextxy(30,320,itoa(max_user,m_u,10));
	puthz(120,320,"��",24,25,8);
	
	puthz(2,360,"���ν���������û�",24,25,8);
	outtextxy(260,360,ri_user);
	puthz(310,360,"��",24,25,8);
	puthz(2,400,"��",24,25,8);
	outtextxy(30,400,ltoa(richest_user,r_u,10));
	puthz(250,400,"Ԫ",24,25,8);
	
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
��������s_2_10_2
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ�ʹ��˵�����ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_10_2(int *pagestate)
{
	FILE *fp;
	char in[200]={'0'};//һ�п϶�����100��
	int row=0;
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
	puthz(270,5,"ʹ��˵��",32,30,8);
	
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
��������lightbutton_board
�������ݣ�x,y,x1,y1,color1,color2,flag
����ֵ����
���ܣ����水ť����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_board(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(50);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	
	if(flag==1)
	{
		puthz(567,22,"����ͳ��",16,16,8);
	}
	if(flag==2)
	{
		puthz(567,52,"ʹ��˵��",16,16,8);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������recoverbutton_board
�������ݣ�status
����ֵ����
���ܣ����水ť�ָ�
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
			puthz(567,22,"����ͳ��",16,16,8);
			break;
		case 2:
			bar(562,50,639,80);
			rectangle(562,50,639,80);
			puthz(567,52,"ʹ��˵��",16,16,8);
			break;
	}
}