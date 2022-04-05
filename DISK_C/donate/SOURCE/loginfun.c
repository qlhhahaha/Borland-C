#include"loginfun.h"
#include"common.h"

/*
���ܣ���½ע����ص�һЩ���ܺ���
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������admin_judge
�������ݣ�adm:����Ա��Ϣ���˺ź����룩��char* pass
����ֵ����
���ܣ�����Ա��¼ʱ���жϺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int admin_judge(char* admin, char* pass)
{
	if (strlen(admin) == 0)
	{
		puthz(550,120, "δ����", 16, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		puthz(550,260, "δ����", 16, 17, RED);
		return 0;
	}
	if ((strcmp(admin, "qlh") == 0
		|| strcmp(admin, "lhy") == 0)
		&&strcmp(pass, "aia1905") == 0)
	{
		puthz(300,440, "��¼�ɹ�", 16, 20, RED);
		return 1;
	}
	else 
		if(strcmp(admin, "qlh") != 0
		&& strcmp(admin, "lhy") != 0)
		{
			puthz(550,110, "����Ա��Ϣ����", 16, 20, RED);
			return 0;
		}
		if( strcmp(pass, "aia1905")!= 0)
		{
			puthz(550,260, "�������", 16, 20, RED);
			return 0;
		}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������login_complete
�������ݣ�char* u, char* p,int *pagestate
����ֵ����
���ܣ��û���½ʱ���˺����������ж�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int login_complete(char* u, char* p,int *pagestate)
{
	int state1 = 1;//�Ƿ�����ı���
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
			if (j_r==0)//�˺�����������
			{
				return 0;
			}
			if (j_r==1)//��Ϣ��ȷ
			{
				return 1;
			}
			if (j_r==2)//�˺ű�ban
			{
				return 2;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������judge_rightpassword
�������ݣ�char* name, char* pass,int *pagestate
����ֵ����
���ܣ��û���½ʱ���˺������ж�
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
		fread(us, sizeof(USER_STR), 1, fp);//fp����u��
		if (strcmp(name, us->userid) == 0)//�û���ƥ��
		{
			if	 (strcmp(pass, us->password) != 0)//���벻��
			{
				puthz(550,260, "�������", 16, 17, RED);
				if (us != NULL)
				{
					free(us);
					us = NULL;
				}
				break;
			}
			else if (strcmp(pass, us->password) == 0)//����ƥ��
			{
				if(judge_ban(atoi(us->times))==1)//������˺�û��ban
				{
					puthz(300,440, "��¼�ɹ�", 16, 17, RED);
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
					//�л�����
				}
				else//��ban
				{
					g_1_2_1();//������ʾҳ�棬Ȼ���ػص�½ҳ��
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
		puthz(550,110, "�˺�δע��", 16, 17, RED);//�ߵ����һλ
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
��������judge_ban
�������ݣ�int times
����ֵ����
���ܣ��û���½ʱ���˺ŷ��״̬
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int judge_ban(int times)
{
	if (times<0)//������˺ű�ban
	{
		return 0;
	}
	else if (times>=0)
	{
		return 1;
	}

}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������register_complete
�������ݣ�char*u,char *p,char* cp, char* ph, char* vc,char* rdvc
����ֵ����
���ܣ��û�ע��ʱ���˺������ж�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int register_complete(char*u,char *p,char* cp, char* ph, char* vc,char* rdvc)//rdvcΪrandomvc
{
	int i;
	int state = 0;//�Ƿ�����ı���
	int state1 = 1;//ȷ�������Ƿ�һ�µı���
	int state2 = 1;//��֤���Ƿ�һ�µı���
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
			if (judge_sameuser(u,1)==0)          //  �����򷵻�0��δ��������1
			{
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2= checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if(judge_sameuser(u,2)!=0)//�û���û������
			{
				puthz(135, 60, "���õ��û���", 16, 20, RED);
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2 = checkright_verificationcode(rdvc, vc, 547, 330);
				if (state1 != 0 || state2 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 )
				{
					input_database(u,p,ph);
					//д�����ݿ�
					puthz(280,420, "ע��ɹ�", 16, 20, RED);
					delay(2000);
					return 1;//����
				}
			}
		}
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������judge
�������ݣ�char* str, int* p, int x, int y
����ֵ����
���ܣ������ж�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "δ����", 16, 20, RED);
	}
	else
	{
		*p = 0;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������input_database
�������ݣ�char* name, char* code, char* phone
����ֵ����
���ܣ�����ǰ�û���Ϣ���浽�ļ�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void input_database(char* name, char* code, char* phone)
{
	FILE* fp;
	USER* u;
	USER_STR* us;
	int len;
	int i;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)//�������ݿ�
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	len = ftell(fp) / sizeof(USER_STR);//�����USER�ṹ��ĸ���������ע���û��ĸ���
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
	USER_ntoa(u,us);//��USERת��ΪUSER_STR 
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	fwrite(us, sizeof(USER_STR), 1, fp);//���û���Ϣд���ļ�
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
��������judge_sameuser
�������ݣ�new_user,flag
����ֵ��1/0
���ܣ��ж��˻��Ƿ��������,
	flagΪ1�ж��Ƿ�ע�ᣬ
	flagΪ2 3�ж��һ��������Ƿ����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int judge_sameuser(char* new_user,int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* us;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+")) == NULL)//�������ݿ�
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER_STR);//ftell���ڸ���fp��ǰ��λ��
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
		//����ÿһ���ṹ��
		if (strcmp(us->userid, new_user) == 0)
		{
			switch (flag)
			{
				case 1: 
					puthz(135, 60, "�û��ѱ�ע��", 16, 20, RED);
					break;
				case 2:
					puthz(450, 110, "�˺Ŵ���", 16, 20, RED);
					break;
				case 3:
					puthz(540, 110, "�˺Ŵ���", 16, 20, RED);
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
��������checkright_confirmedpassword
�������ݣ�char* str1, char* str2, int x, int y
����ֵ��1/0
���ܣ�����������������Ƿ�һ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "���β�һ��", 16, 17, RED);
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
��������checkright_verificationcode
�������ݣ�char* str1, char* str2, int x, int y
����ֵ��1/0
���ܣ������֤���Ƿ�һ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int checkright_verificationcode(char* str1, char* str2,int x,int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "��֤�����", 16, 17, RED);
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
��������inputadmin
�������ݣ�char* id, int x1, int y1, int charnum, int color
����ֵ����
���ܣ����뺯��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{
	int i = 0;//i���ڼ���
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//����ˮƽ����ʹ�ֱ������ı����뷽ʽ
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);//�������
	while (1)
	{
		t = bioskey(0); //��t��¼��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//��t��Ϊ�����ʱ
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
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
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��  
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������inputpassword
�������ݣ�char* id, int x1, int y1, int charnum, int color
����ֵ����
���ܣ��������뺯��
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
		t = bioskey(0);//��ȡ��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033��ʾEsc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//���*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
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
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������recoverhz
�������ݣ�int x, int y,int color
����ֵ����
���ܣ����ָ��Ǻ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverhz(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������input_uinfo
�������ݣ�USER* u
����ֵ��1/0
���ܣ��ѵ�ǰ�û�����Ϣ���ļ���ȡ������Ľṹ����
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
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER_STR);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER_STR), SEEK_SET);//ÿ��������һ���û�
		fread(us, sizeof(USER_STR), 1, fp);		  //����Ϣ����us
		if (strcmp(us->userid, u->userid) == 0)//�ҵ���ǰ�˺���Ϣ������u
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
��������id_phone
�������ݣ�id,ph,pass,againpass
����ֵ��1/0
���ܣ��ж��˺���绰���Ƿ�ƥ�䣬
	���ж���������������Ƿ���ͬ��
	��ƥ������ͬ��д�������롣
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int id_phone(char* id, char* ph, char* np, char* cp)
{
	int str;
	int len;//���ڼ����û�����
	int i,j;//���ڼ���
	FILE* fp;
	USER* us;
	if ((fp = fopen("database\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER_STR);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((us = (USER_STR*)malloc(sizeof(USER_STR))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(2000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER_STR), SEEK_SET);//ÿ��������һ���û�
		fread(us, sizeof(USER_STR), 1, fp);//����Ϣ����us
		if (strcmp(id, us->userid) == 0)
		{
			if (strcmp(ph, us->phone) != 0)
			{
				puthz(140,205, "�绰��ƥ��", 16, 20, RED);
				break;
			}
			else if (strcmp(ph, us->phone) == 0)
			{
				if (strcmp(np, cp) == 0)//��������������ͬ
				{
					us->password[0] = '\0';
					strcpy(us->password, np);
					fseek(fp, i * sizeof(USER_STR), SEEK_SET);
					fwrite(us, sizeof(USER_STR), 1, fp);//�޸����һ��Ҫ�ǵ�д������
					puthz(420,415,"�޸ĳɹ�",16,20,RED);
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