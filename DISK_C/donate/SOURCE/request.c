#include"common.h"
#include"request.h"
#include "input.h"

/*
���ܣ�����������
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_3_0
�������ݣ�pagestate:ҳ���ţ�USER *u
����ֵ����
���ܣ���������ҳ�湦��������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_3_0(int *pagestate,USER *u)
{
	int num = 0;
	int len[4]={0};
	int count=0; //������¼�Ƿ�ѡ�������Ķ�ѡ��
	int state[5] = {0};       //���������жϲ���
	char PRONAME[50] = { '\0' };//��Ŀ��
	char PLACE[50]= { '\0' };	//��ַ
	char MANNAME[20] = { '\0' };//����
	char DES[400] = { '\0' };//����˵��
	PRO pro;
	pro.protype=8;//��ʼ��Ϊ8������δѡ��״̬
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_3_0();
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 150 && MouseX < 570 && MouseY>5 && MouseY < 45)
		{
			if (mouse_press(150,5,570,45) == 2)//��Ŀ���ƿ�δ���
			{
				MouseS = 2;
				if (num == 0 && state[1] == 0)//��ֹ���ظ�����
				{
					lightbutton_request(150,5,570,45, LIGHTCYAN, LIGHTGRAY, 0);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(150,5,570,45) == 1)//��Ŀ���ƿ���
			{
				MouseS = 0;
				lightbutton_request(150,5,570,45, LIGHTCYAN, LIGHTGRAY, 0);
				/*PRONAME[0] = '\0';*/
				memset(PRONAME, '0', 50);
				/*inputadmin_new(PRONAME,155,10,20,LIGHTGRAY);*/
				len[0]=0;
				len[0]=hz_input(155,10,565,40,PRONAME,len[0]);
				if(strlen(PRONAME) != 0)
					state[1] = 1;	
				else 
					state[1] = 0;
				continue;
			}
		}
		
		if (MouseX > 150 && MouseX < 570 && MouseY>50 && MouseY < 90)
		{
			if (mouse_press(150,50,570,90) == 2)//��ַ��δ���
			{
				MouseS = 2;
				if (num == 0 && state[2] == 0)//��ֹ���ظ�����
				{
					lightbutton_request(150,50,570,90, LIGHTCYAN, LIGHTGRAY, 0);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(150,50,570,90) == 1)//��ַ����
			{
				MouseS = 0;
				lightbutton_request(150,50,570,90, LIGHTCYAN, LIGHTGRAY, 0);
				/*PLACE[0] = '\0';*/
				memset(PLACE, '0', 50);
				/*inputadmin_new(PLACE,155,55,20,LIGHTGRAY);*/
				len[1]=0;
				len[1]=hz_input(155,55,565,85,PLACE,len[1]);
				if(strlen(PLACE) != 0)
					state[2] = 1;
				else 
					state[2] = 0;
				continue;
			}
		}
		
		if (MouseX > 150 && MouseX < 320 && MouseY>95 && MouseY < 135)
		{
			if (mouse_press(150,95,320,135) == 2)//��������δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(150,110,250,150) == 1)//�������͵��
			{
				MouseS = 0;
				s_2_3_1(&pro,PRONAME,PLACE,MANNAME,DES);//�ٻ��������Ͳ˵�
				continue;
			}
		}
		
		if (MouseX > 320 && MouseX < 430 && MouseY>95 && MouseY < 135)
		{
			if (mouse_press(320,95,430,135) == 2)//ѡ������δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(320,95,430,135) == 1)//ѡ�����ʵ��
			{
				if (pro.protype == 8)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(160,190,490,300);
					puthz(180,205,"����ѡ���������࣡",24,30,8);
					delay(1500);
					s_2_3_4(PRONAME,PLACE,MANNAME,DES);
					continue;
				}
				MouseS = 0;
				s_2_3_2(&pro,PRONAME,PLACE,MANNAME,DES);//�ٻ�ѡ�����ʽ���
				continue;
			}
		}
		
		if (MouseX > 465 && MouseX < 630 && MouseY>145 && MouseY < 185)
		{
			if (mouse_press(465,145,630,185) == 2)//������������δ���
			{
				MouseS = 2;
				if (num == 0 && state[3] == 0)//��ֹ���ظ�����
				{
					lightbutton_request(465,145,630,185, LIGHTCYAN, LIGHTGRAY, 0);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(465,145,630,185) == 1)//��������������
			{
				MouseS = 0;
				lightbutton_request(465,145,630,185, LIGHTCYAN, LIGHTGRAY, 0);
				/*MANNAME[0] = '\0';*/
				memset(MANNAME, '0', 20);
				/*inputadmin_new(MANNAME,470,150,6,LIGHTGRAY);*/
				len[2]=0;
				len[2]=hz_input(470,150,625,180,MANNAME,len[2]);
				if(strlen(MANNAME) != 0)
					state[3] = 1;	
				else 
					state[3] = 0;
				continue;
			}
		}
		
		if (MouseX > 10 && MouseX < 630 && MouseY>200 && MouseY < 400)
		{
			if (mouse_press(10,200,630,400) == 2)//����δ���
			{
				MouseS = 2;
				if (num == 0 && state[4] == 0)//��ֹ���ظ�����
				{
					lightbutton_request(10,200,630,400, LIGHTCYAN, LIGHTGRAY, 0);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(10,200,630,400) == 1)//������
			{
				MouseS = 0;
				lightbutton_request(10,200,630,400, LIGHTCYAN, LIGHTGRAY, 0);
				/*DES[0] = '\0';*/
				memset(DES, '0', 400);
				/*inputadmin_des(DES,15,205,150,LIGHTGRAY);*/
				len[3]=0;
				len[3]=hz_input(15,205,625,395,DES,len[3]);
				if(strlen(DES) != 0)
					state[4] = 1;	
				else 
					state[4] = 0;
				continue;
			}
		}
		
		if (MouseX > 90 && MouseX < 110 && MouseY>420 && MouseY < 440)
		{
			if (mouse_press(90,420,110,440) == 2)//�����Ķ�δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(90,420,110,440) == 1)//�����Ķ����
			{
				read_judge(&count);//�򹴣����ı�count��ֵ
				continue;
			}
		}
		
		if (MouseX > 115+105 && MouseX < 115+105+60 && MouseY>420 && MouseY < 420+30)
		{
			if (mouse_press(115+105,420,115+105+60,420+30) == 2)//������δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(115+105,420,115+105+60,420+30) == 1)//��������
			{
				s_2_3_3(pagestate,PRONAME,PLACE,MANNAME,DES);//�����������
				continue;
			}
		}
		
		if (MouseX > 420 && MouseX < 539 && MouseY>410 && MouseY < 460)
		{
			if (mouse_press(420,410,539,460) == 2)					//δ��������
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_request(420,410,539,460, LIGHTCYAN, LIGHTGRAY, 1);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(420,410,539,460) == 1)
			{	
				MouseS = 0;
				if (request_judge(&count,PRONAME,PLACE,MANNAME,DES,&pro,u)==1)//�ɹ������򷵻�1
				{
					achieve_change(u,8);//��¼�ɾ�
					cleardevice();
					g_2_3_4();
					delay(3000);
					*pagestate =220 ;
					return;
				}
				else
				{
					continue;
				}
			}
		}
		
		if (mouse_press(605,5,635,35) == 1)//���ؿ���
		{
			MouseS = 0;
			*pagestate = 21;//�л�������
			delay(500);
			cleardevice();
			return;
		}
		
		if (num != 0)
		{
			MouseS = 0;
			if (state[1] == 0)
			{
				recoverbutton_request(1);
			}
			if (state[2] == 0)
			{
				recoverbutton_request(2);
			}
			if (state[3] == 0)
			{
				recoverbutton_request(3);
			}
			if (state[4] == 0)
			{
				recoverbutton_request(4);
			}
			if (num == 5)
			{
				recoverbutton_request(5);
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
��������s_2_3_1
�������ݣ�PRO *pro,char *PRONAME,char *PLACE,char *MANNAME,char *DES
����ֵ����
���ܣ�����ѡ���ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_3_1(PRO *pro,char *PRONAME,char *PLACE,char *MANNAME,char *DES)
{
	g_2_3_1();//��ԭ��ͼ�λ����ϻ�������ѡ�񵯳��˵�
	delay(100);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 215 && MouseX < 250 && MouseY>100 && MouseY < 120)
		{
			if (mouse_press(215,100,250,120) == 2)//��ͯ
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(215,100,250,120) == 1)
			{
				MouseS = 0;
				pro->protype=0;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		
		if (MouseX > 215 && MouseX < 250 && MouseY>125 && MouseY < 145)
		{
			if (mouse_press(215,125,250,145) == 2)//����
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(215,125,250,145) == 1)
			{
				MouseS = 0;
				pro->protype=1;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		
		if (MouseX > 215 && MouseX < 250 && MouseY>150 && MouseY < 170)
		{
			if (mouse_press(215,150,250,170) == 2)//��ƶ
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(215,150,250,170) == 1)
			{
				MouseS = 0;
				pro->protype=2;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		
		if (MouseX > 255 && MouseX < 290 && MouseY>100 && MouseY < 120)
		{
			if (mouse_press(255,100,290,120) == 2)//����
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(255,100,290,120) == 1)
			{
				MouseS = 0;
				pro->protype=3;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		
		if (MouseX > 255 && MouseX < 290 && MouseY>125 && MouseY < 145)
		{
			if (mouse_press(255,125,290,145) == 2)//����
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(255,125,290,145) == 1)
			{
				MouseS = 0;
				pro->protype=4;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		
		if (MouseX > 255 && MouseX < 290 && MouseY>150 && MouseY < 170)
		{
			if (mouse_press(255,150,290,170) == 2)//����
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(255,150,290,170) == 1)
			{
				MouseS = 0;
				pro->protype=5;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		
		if (MouseX > 235 && MouseX < 270 && MouseY>175 && MouseY < 195)
		{
			if (mouse_press(235,175,270,195) == 2)//����
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(235,175,270,195) == 1)
			{
				MouseS = 0;
				pro->protype=6;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
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
��������s_2_3_2
�������ݣ�PRO *pro,char *PRONAME,char *PLACE,char *MANNAME,char *DES
����ֵ����
���ܣ���������ѡ���ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_3_2 (PRO *pro,char *PRONAME,char *PLACE,char *MANNAME,char *DES)
{
	int num = 0;
	int count=0; //������¼�Ƿ�ѡ�������Ķ�ѡ��
	int state[15] = {0};
	long int amount[2][9];
	int i,j;
	for(i=0;i<2;i++)//Ĭ��Ϊ0����д��ʹ������Ʒ����Ϊ0 
	{
		for(j=0;j<9;j++)
		{
			pro->amount[i][j]=0L;
		}
	}
	for(i=0;i<2;i++)//Ĭ��Ϊ0����д��ʹ������Ʒ����Ϊ0 
	{
		for(j=0;j<9;j++)
		{
			amount[i][j]=0L;
		}
	}
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	g_2_3_2(pro->protype);
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 115 && MouseX < 320 && MouseY>70 && MouseY < 102)//��Ʒ1
		{
			if (mouse_press(115,70,320,102) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[6] == 0)
				{
					lightbutton_request(115,70,320,102, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 6;
				}
				continue;
			}
			else if (mouse_press(115,70,320,102) == 1)
			{
				MouseS = 0;
				lightbutton_request(115,70,320,102, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][0] =0L;
				inputnumber(&amount[0][0],120,75,10,LIGHTGRAY);
				if(strlen(&amount[0][0]) != 0)
					state[6] = 1;	
				else 
					state[6] = 0;
				continue;
			}
		}
		
		if (MouseX > 115 && MouseX < 320 && MouseY>142 && MouseY < 174)//��Ʒ2
		{
			if (mouse_press(115,142,320,174) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[7] == 0)
				{
					lightbutton_request(115,142,320,174, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 7;
				}
				continue;
			}
			else if (mouse_press(115,142,320,174) == 1)
			{
				MouseS = 0;
				lightbutton_request(115,142,320,174, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][1] =0L;
				inputnumber(&amount[0][1],120,147,10,LIGHTGRAY);
				if(strlen(&amount[0][1]) != 0)
					state[7] = 1;	
				else 
					state[7] = 0;
				continue;
			}
		}
		
		if (MouseX > 115 && MouseX < 320 && MouseY>214 && MouseY < 246)//��Ʒ3
		{
			if (mouse_press(115,214,320,246) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[8] == 0)
				{
					lightbutton_request(115,214,320,246, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 8;
				}
				continue;
			}
			else if (mouse_press(115,214,320,246) == 1)
			{
				MouseS = 0;
				lightbutton_request(115,214,320,246, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][2] =0L;
				inputnumber(&amount[0][2],120,219,10,LIGHTGRAY);
				if(strlen(&amount[0][2]) != 0)
					state[8] = 1;	
				else 
					state[8] = 0;
				continue;
			}
		}
		
		if (MouseX > 115 && MouseX < 320 && MouseY>306 && MouseY < 338)//��Ʒ4
		{
			if (mouse_press(115,306,320,338) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[9] == 0)
				{
					lightbutton_request(115,306,320,338, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 9;
				}
				continue;
			}
			else if (mouse_press(115,306,320,338) == 1)
			{
				MouseS = 0;
				lightbutton_request(115,306,320,338, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][3] =0L;
				inputnumber(&amount[0][3],120,311,10,LIGHTGRAY);
				if(strlen(&amount[0][3]) != 0)
					state[9] = 1;	
				else 
					state[9] = 0;
				continue;
			}
		}
		
		if (MouseX > 115 && MouseX < 320 && MouseY>398 && MouseY < 430)//��Ʒ5
		{
			if (mouse_press(115,398,320,430) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[10] == 0)
				{
					lightbutton_request(115,398,320,430, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 10;
				}
				continue;
			}
			else if (mouse_press(115,398,320,430) == 1)
			{
				MouseS = 0;
				lightbutton_request(115,398,320,430, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][4] =0L;
				inputnumber(&amount[0][4],120,403,10,LIGHTGRAY);
				if(strlen(&amount[0][4]) != 0)
					state[10] = 1;	
				else 
					state[10] = 0;
				continue;
			}
		}
		
		if (MouseX > 435 && MouseX < 630 && MouseY>70 && MouseY < 102)//��Ʒ6
		{
			if (mouse_press(435,70,630,102) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[11] == 0)
				{
					lightbutton_request(435,70,630,102, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 11;
				}
				continue;
			}
			else if (mouse_press(435,70,630,102) == 1)
			{
				MouseS = 0;
				lightbutton_request(435,70,630,102, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][5] =0L;
				inputnumber(&amount[0][5],440,75,10,LIGHTGRAY);
				if(strlen(&amount[0][5]) != 0)
					state[11] = 1;	
				else 
					state[11] = 0;
				continue;
			}
		}
		
		if (MouseX > 435 && MouseX < 630 && MouseY>142 && MouseY < 174)//��Ʒ7
		{
			if (mouse_press(435,142,630,174) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[12] == 0)
				{
					lightbutton_request(435,142,630,174, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 12;
				}
				continue;
			}
			else if (mouse_press(435,142,630,174) == 1)
			{
				MouseS = 0;
				lightbutton_request(435,142,630,174, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][6] =0L;
				inputnumber(&amount[0][6],440,147,10,LIGHTGRAY);
				if(strlen(&amount[0][6]) != 0)
					state[12] = 1;	
				else 
					state[12] = 0;
				continue;
			}
		}
		
		if (MouseX > 435 && MouseX < 630 && MouseY>214 && MouseY < 246)//��Ʒ8
		{
			if (mouse_press(435,214,630,246) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[13] == 0)
				{
					lightbutton_request(435,214,630,246, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 12;
				}
				continue;
			}
			else if (mouse_press(435,214,630,246) == 1)
			{
				MouseS = 0;
				lightbutton_request(435,214,630,246, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][7] =0L;
				inputnumber(&amount[0][7],440,219,10,LIGHTGRAY);
				if(strlen(&amount[0][7]) != 0)
					state[13] = 1;	
				else 
					state[13] = 0;
				continue;
			}
		}
		
		if (MouseX > 435 && MouseX < 630 && MouseY>306 && MouseY < 338)//��Ʒ9
		{
			if (mouse_press(435,306,630,338) == 2)
			{
				MouseS = 2;
				if (num == 0 && state[14] == 0)
				{
					lightbutton_request(435,306,630,338, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 14;
				}
				continue;
			}
			else if (mouse_press(435,306,630,338) == 1)
			{
				MouseS = 0;
				lightbutton_request(435,306,630,338, LIGHTCYAN, LIGHTGRAY, 0);
				pro->amount[0][8] =0L;
				inputnumber(&amount[0][8],440,311,10,LIGHTGRAY);
				if(strlen(&amount[0][8]) != 0)
					state[14] = 1;	
				else 
					state[14] = 0;
				continue;
			}
		}
			
		if (MouseX > 380 && MouseX < 500 && MouseY>390 && MouseY < 460)
		{
			if (mouse_press(380,390,500,460) == 2)					//δ���ȷ�Ͽ�
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(380,390,500,460) == 1)
			{
				if( amount[0][0]==0 && amount[0][1]==0 && amount[0][2]==0 &&
					amount[0][3]==0 && amount[0][4]==0 && amount[0][5]==0 &&
					amount[0][6]==0 && amount[0][7]==0 && amount[0][8]==0)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(160,190,490,300);
					puthz(180,205,"����տ���Ҳ����Ŀ",24,30,8);
					puthz(210,245,"����թ����Ϊ��",24,30,8);
					delay(1500);
					cleardevice();
					g_2_3_2(pro->protype);
					continue;
				}
				MouseS = 0;
				for(i=0;i<9;i++)
				{
					pro->amount[0][i]=amount[0][i];
				}
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		if (num != 0)
		{
			MouseS = 0;
			for(i=6;i<15;i++)
			{
				if (state[i] == 0) recoverbutton_request(i);
				num = 0;
			}
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_3_3
�������ݣ�int *pagestate,char *PRONAME,char *PLACE,char *MANNAME,char *DES
����ֵ����
���ܣ������Ķ�����Ĺ��ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_3_3 (int *pagestate,char *PRONAME,char *PLACE,char *MANNAME,char *DES)
{
	clrmous(MouseX, MouseY);
	cleardevice();
	delay(100);
	g_2_3_3();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 240 && MouseX < 400 && MouseY>425 && MouseY < 475)
		{
			if (mouse_press(240,425,400,475) == 2)					//δ��������Ķ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(240,425,400,475) == 1)
			{
				MouseS = 0;
				s_2_3_4(PRONAME,PLACE,MANNAME,DES);
				return;
			}
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

