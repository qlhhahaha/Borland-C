#include"common.h"
#include"forgetp.h"


/*
���ܣ��������빦��
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_1_4
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ��������빦�ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_4(int *pagestate)
{
	int num=0;
	char U[15] = { '\0' };//�û���
	char P[15] = { '\0' };//11λ���绰����
	char NP[15] = { '\0' };//������
	char CP[15] = { '\0' };//ȷ������
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_1_4();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 135 && MouseX < 540 && MouseY>80 && MouseY < 120)
		{
			if (mouse_press(135,80,540,120) == 2)//�û�����δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_forget(135,80,540,120, LIGHTCYAN, LIGHTGRAY, 0);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;

				//��������
			}
			else if (mouse_press(135,80,540,120) == 1)//�û�������
			{
				MouseS = 0;
				lightbutton_forget(135,80,540,120, LIGHTCYAN, LIGHTGRAY, 0);
				U[0] = '\0';
				inputadmin(U,135,85,11,LIGHTGRAY);
				if(strlen(U) != 0)
					state1 = 1;	
				else 
					state1 = 0;
				continue;
				//���뺯��
			}
		}
		if (MouseX > 135 && MouseX < 540 && MouseY>160 && MouseY < 200)
		{
			if (mouse_press(135,160,540,200) == 2)//�绰��δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_forget(135,160,540,200,LIGHTCYAN, LIGHTGRAY, 0);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(135,160,540,200) == 1)
			{
				MouseS = 0;
				lightbutton_forget(135,160,540,200, LIGHTCYAN, LIGHTGRAY, 0);
				P[0] = '\0';
				inputadmin(P,135,165,11,LIGHTGRAY);
				if(strlen(P) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
				//���뺯��
			}
		}
		if (MouseX > 135 && MouseX < 540 && MouseY>240 && MouseY < 280)
		{
			if (mouse_press(135,240,540,280) == 2)//�������δ���
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_forget(135,240,540,280, LIGHTCYAN, LIGHTGRAY, 0);//��������
					num = 3;
				}
				continue;
			}
			else if (mouse_press(135,240,540,280) == 1)//���������
			{
				MouseS = 0;
				lightbutton_forget(135,240,540,280, LIGHTCYAN, LIGHTGRAY, 0);
				NP[0] = '\0';
				inputpassword(NP,135,245,10,LIGHTGRAY);
				if(strlen(NP) != 0)
					state3 = 1;
				else 
					state3 = 0;
				continue;
				//���뺯��
			}
		}
		if (MouseX > 135 && MouseX < 540 && MouseY>320 && MouseY <360)
		{
			if (mouse_press(135,320,540,360) == 2)//ȷ�������δ���
			{
				MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightbutton_forget(135,320,540,360, LIGHTCYAN, LIGHTGRAY, 0);//��������
					num = 4;
				}
				continue;
			}
			else if (mouse_press(135,320,540,360) == 1)//ȷ���������
			{
				MouseS = 0;
				lightbutton_forget(135,320,540,360, LIGHTCYAN, LIGHTGRAY, 0);
				CP[0] = '\0';
				inputpassword(CP,145,325,10,LIGHTGRAY);
				if(strlen(CP) != 0)
					state4 = 1;
				else 
					state4 = 0;
				continue;
				//���뺯��

			}
		}
		
		if (MouseX > 240 && MouseX < 410 && MouseY>380 && MouseY < 450)
		{
			if (mouse_press(240,380,410,450) == 2)//�޸Ŀ�δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_forget(240,380,410,450, LIGHTCYAN, DARKGRAY, 1);//��������
					num = 5;
				}
				continue;
			}
			else if (mouse_press(240,380,410,450) == 1)//�޸Ŀ���
			{
				MouseS = 0;
				if (forgetpass_complete(U, P, NP, CP)==1)
				{
					*pagestate = 5;
					return;
				}
				else
				{
					continue;
				}
				//����Ƿ�����޸����벢¼�����ݿ�
				//�л�����¼����
			}
		}
		
	
			if (mouse_press(605,5,635,35) == 1)//���ؿ���
			{
				MouseS = 0;
				*pagestate = 5;//�л���¼����
				delay(500);
				cleardevice();
				return;
			}
	
		
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_forget(1);
			}
			if (state2 == 0)
			{
				recoverbutton_forget(2);
			}
			if (state3 == 0)
			{
				recoverbutton_forget(3);
			}
			if (state4 == 0)
			{
				recoverbutton_forget(4);
			}
			if (num == 5)
			{
				recoverbutton_forget(5);//�ָ���ť��ɫ
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
��������lightbutton_forget
�������ݣ�int x, int y, int x1, int y1, int color1, int color2, int flag
����ֵ����
���ܣ���������ҳ���������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_forget(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	
	if(flag==1)
	{
		puthz(270,390, "�޸�", 48,50, BLACK);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������recoverbutton_forget
�������ݣ�int status
����ֵ����
���ܣ���������ҳ��ָ�����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverbutton_forget(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);

	switch (status)
	{
		case 1:
			bar(135,80,540,120);
			rectangle(135,80,540,120);
			break;
		case 2:
			bar(135,160,540,200);
			rectangle(135,160,540,200);
			break;
		case 3:
			bar(135,240,540,280);
			rectangle(135,240,540,280);
			break;
		case 4:
			bar(135,320,540,360);
			rectangle(135,320,540,360);
			break;
		case 5:
			setfillstyle(1, LIGHTGRAY);
			bar(240,380,410,450);
			rectangle(240,380,410,450);
			puthz(270,390,"�޸�",48,50,WHITE);
			break;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������forgetpass_complete
�������ݣ�char* id, char* ph, char* np, char* cp
����ֵ����
���ܣ����������������ݼ��麯��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int forgetpass_complete(char* id, char* ph, char* np, char* cp)
{
	int st1 = 1;//�û����Ƿ�����ı���
	int st2 = 1;//�ֻ����Ƿ�����ı���
	int st3 = 1;//�������Ƿ�����ı���
	int st4 = 1;//ȷ�������Ƿ�����ı���
	int state1 = 1;//ȷ�������Ƿ�һ�µı���
	while (1)
	{
		judge(id, &st1, 170, 85); //�ж��Ƿ�����,δ�����=1
		judge(ph, &st2, 170, 165);
		judge(np, &st3, 170, 245);
		judge(cp, &st4, 170, 325);
		if (st1 == 1 || st2 == 1 || st3 == 1 || st4 == 1)
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 && st4 == 0)
		{
			if (judge_sameuser(id,3)==1)//�û���������
			{
				puthz(540,85, "�û�������", 16, 20, RED);
				break;
			}
			else if (judge_sameuser(id,3)==0)//�û�������
			{
				state1= checkright_confirmedpassword(np, cp, 140,285);
				if (state1!=0)
				{
					break;
				}	
				else if (state1==0)
				{
					if (id_phone(id, ph, np, cp)==1)//д�����ݿ�
					{
						return 1;//���ص�¼����
					}
					else break;
				}
			}
		}
	}
	return 0;
}
