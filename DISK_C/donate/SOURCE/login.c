#include"login.h"
#include"common.h"

/*
���ܣ���½��ع��ܺ���
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_1
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ���ҳ�湦�ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1(int *pagestate)
{
	clrmous(MouseX, MouseY);
	delay(100);
	g_1();//��ӭҳ��1��ͼ����
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if (MouseX >30 && MouseX < 180 && MouseY>300 && MouseY < 360)
		{
			if (mouse_press(30,300,180,360) == 2)//���ѡ��δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(30,300,180,360) == 1)//���ѡ����
			{
				MouseS = 0;
				*pagestate=4;
				delay(50);
				return;
				//�л������ѡ�����
			}
		}
		
		if (MouseX >460 && MouseX < 610 && MouseY>300 && MouseY < 360)
		{
			if (mouse_press(460,300,610,360) == 2)//��������δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(460,300,610,360) == 1)//�������ǵ��
			{
				MouseS = 0;
				*pagestate=3;
				delay(50);
				return;
				//�л����������ǽ���
			}
		}
		
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=1;//�˳�
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
��������s_0_2
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ��������ǹ��ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_0_2(int *pagestate)
{
	FILE *about;
	char ab[200]={'0'};//һ�п϶�����100��
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
	/*while(fgets(ab,200,about) != NULL)//��ȡ�������ֳɹ�ʱ
	{
		len = strlen(ab);
		ab[len-1] = '\0';  //ȥ�����з�
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
ab�����洢һ�е����ݡ�
��code������fscanf�ķ�ʽ��һ��һ�еĶ�ȡtxt�ļ�����while��������
���е�%[^\n]����������ʽ�������������з���һֱ����ȥ��
ֱ���������з�\n��fscanf�������˳���
�˳������while��ִ��fgetc��������ȡһ���ַ���
�ļ��������ƶ�һ���ַ����൱��������\n���з�����һ�ξʹ���һ�п�ʼ���ˡ�
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
��������s_1_1
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ����ѡ���ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_1(int *pagestate)
{
	cleardevice();
	clrmous(MouseX, MouseY);
	delay(100);
	g_1_1();//���ѡ��ҳ��1_1��ͼ����
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
				//�л������˵�¼����
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
				//�л��������¼����
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
				//�л�������Ա��½����
			}
		}

		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=0;//���ر���ҳ��
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
��������s_1_1
�������ݣ�pagestate:ҳ���� USER *u
����ֵ����
���ܣ����˼������¼���ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_2_1(int *pagestate,USER *u)
{
	int num=0;
	int state1 = 0;//�������ݼ��飬������Ϊ1��û����Ϊ0
	int state2 = 0;
	int lg_complete=0;//���ڼ���login_complete�ķ���ֵ�������ظ����ú�����ɱ���
	memset(u,'\0',sizeof(USER));   //���𴦴�������u����
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	g_1_2();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX >135 && MouseX < 540 && MouseY>100 && MouseY < 150)
		{
			if (mouse_press(135,100,540,150) == 2)//�û�����δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;
				//��������
			}

			else if (mouse_press(135,100,540,150) == 1)//�û�������
			{
				MouseS = 0;
				lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				u->userid[0] = '\0';
				inputadmin(u->userid,135,110,11, LIGHTGRAY);//������ַ����������xy��������ַ����ƣ���������ɫ
				//���뺯��
				if(strlen(u->userid) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		
		if (MouseX >135 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(130,250,540,300) == 2)//�����δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(130,250,540,300) == 1)//�������
			{
				MouseS = 0;
				lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password,135,260,10, LIGHTGRAY);
				//���뺯��
				if(strlen(u->password) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
			}
		}
		
		if (MouseX >250 && MouseX < 360 && MouseY>310 && MouseY < 330)
		{
			if (mouse_press(250,310,360,330) == 2)//��������δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(250,310,360,330) == 1)//����������
			{
				MouseS = 0;
				*pagestate=9;
				delay(50);
				return;
				//�л��������������
			}
		}
		
		if (MouseX > 110 && MouseX < 260 && MouseY>370 && MouseY < 450)
		{
			if (mouse_press(110,370,260,450) == 2)//��¼��δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110,370,260,450, LIGHTCYAN, DARKGRAY, 2);//��������
					num = 3;
				}
				continue;
			}
			else if (mouse_press(110,370,260,450) == 1)//��¼����
			{
				MouseS = 0;
				lg_complete=login_complete(u->userid, u->password,pagestate);
				if (lg_complete==0)//�˺�����������
				{
					continue;
				}
				
				if (lg_complete==1) //��Ϣ��ȷ
				{
					if (input_uinfo(u)==1)  //����Ϣ���ļ��д���uָ��
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
				
				if (lg_complete==2)//�˺ű�ban
				{
					return;
				}
				
			}
		}
		
		if (MouseX > 380 && MouseX < 530 && MouseY>370 && MouseY < 450)
		{
			if (mouse_press(380,370,530,450) == 2)//ע���δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(380,370,530,450, LIGHTCYAN, DARKGRAY, 3);//��������
					num = 4;
				}
				continue;
			}
			else if (mouse_press(380,370,530,450) == 1)//ע�����
			{
				MouseS = 0;
				*pagestate = 7;
				delay(50);
				return;
			}
		}

		if (mouse_press(605,5,635,35) == 1)//���ؿ���
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
				recoverbutton_login(1);//�ָ���ť��ɫ
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
��������s_1_2_2
�������ݣ�pagestate:ҳ���� 
����ֵ����
���ܣ�����Ա��¼���ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_2_2(int *pagestate)
{
	int num=0;
	int state = 0;
	char A[15] = { '\0' };	//����Ա�˺�
	char P[10] = { '\0' };	//����Ա����
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
			if (mouse_press(135,100,540,150) == 2)//�û�����δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;
				//��������
			}
			else if (mouse_press(135,100,540,150) == 1)//����Ա����
			{
				MouseS = 0;
				lightbutton_login(135,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				A[0] = '\0';
				inputadmin(A, 135,110, 5, LIGHTGRAY);
				//���뺯��
				if(strlen(A) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		if (MouseX >135 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(135,250,540,300) == 2)//�����δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(135,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(135,250,540,300) == 1)//�������
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
				//���뺯��
			}
		}
		if (MouseX > 230 && MouseX < 390 && MouseY>370 && MouseY < 450)
		{
			if (mouse_press(230,370,390,450) == 2)//��¼��δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(230,370,390,450, LIGHTCYAN, LIGHTGRAY, 4);//��������
					num = 5;
				}
				continue;
			}
			else if (mouse_press(230,370,390,450) == 1)//��¼����
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
				//����Ƿ���¼�����ݿ�Ĺ���Ա������
			}
		}
		
		if (mouse_press(605,5,635,35) == 1)//���ؿ���
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
				recoverbutton_login(1);//�ָ���ť��ɫ
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
��������lightbutton_login
�������ݣ�int x, int y, int x1, int y1, int color1, int color2, int flag
����ֵ����
���ܣ���½ҳ���������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
		case 1:
			break;
		case 2:
			puthz(130,390, "��½", 32, 80, WHITE);
			break;
		case 3:
			puthz(400,390, "ע��", 32, 80, WHITE);
			break;
		case 4:
			puthz(250,390, "��½", 32, 80, WHITE);
			break;
		default:
			closegraph();
			printf("something runs wrong in lightbutton");
			exit(1);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������recoverbutton_login
�������ݣ�int status
����ֵ����
���ܣ���½ҳ��ָ�����
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
			puthz(130,390,"��½",32,80,WHITE);
			break;
		case 4:
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(380,370,530,450);
			puthz(400,390,"ע��",32,80,WHITE);
			break;
		case 5:
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			bar(230,370,390,450);
			puthz(250,390,"��½",32,80,WHITE);
			break;	
	}
}

