#include"common.h"
#include"mainpage.h"

/*
���ܣ���ҳ����ƣ������¼�ɹ�֮���ҳ���л��Ϳ���
���ߣ������
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2
�������ݣ�pagestate:ҳ���ţ�u
����ֵ����
���ܣ���������ѭ����ҳ��ָ�����ҳ���л�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void s_2(int *pagestate,USER* u)/*���˵�ҳ�溯��,ע��˴���pagestate��ָ�룬��main��Ĳ�ͬ
usercode�����ﴫ������Ϊ����mainpageҳ�浼����ǰ�û�����Ϣ
����һ���ṹ����������������ʹ��*/
{	
	long int prosite=0,recordsite=0;//��¼��Ŀ���ļ����λ��
	/*int exit_save=0;//��¼����˳�ȷ�Ͽ�֮ǰ��ҳ��ֵ*/
	*pagestate=21;//��½�����Ĭ�ϵ����ı���ҳ��
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	/*init_public();//��ʼ���������ʳ�*/
	/*create_admin();//����һ������Ա��Ϣ*/
	while(1)
	{
		switch(*pagestate)
		{
			case 21:
			s_2_1(pagestate);//�򿪰��ı���ҳ��
			break;
			
			case 220:
			prosite=s_2_2_0(pagestate);//����Ҫ����ҳ��
			break;
			
			case 222:
			s_2_2_2(pagestate,u);//������Ŀ��
			break;
			
			case 224:
			s_2_2_4(pagestate,prosite);//����Ŀ����ҳ��
			break;
			
			case 225:
			s_2_2_5(pagestate,prosite,u);//����д����
			break;
			
			case 230:
			s_2_3_0(pagestate,u);//�򿪷�������ҳ��
			break;
			
			case 240:
			recordsite=s_2_4_0(pagestate,u,0);//�򿪾�����¼ҳ��
			break;
			
			case 242:
			s_2_4_2(pagestate,recordsite,0);//������¼����ҳ�� 
			break;
			
			case 250:
			s_2_5_0(pagestate);//�򿪰�������ҳ��
			break;
			
			case 260:
			s_2_6_0(pagestate,u);//�򿪻����̳�ҳ��
			break;
			
			case 270:
			s_2_7_0(pagestate,u);//�򿪸�����Ϣҳ��
			break;
			
			case 280:
			s_2_8_0(pagestate);//ע����¼���ص���½ҳ��*/
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
��������s_2_0
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ��Ϸ���פ�˵������ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_0(int *pagestate)//�Ϸ���פ�˵������ܺ���
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
				*pagestate=21;//ת�����ı���ҳ��
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
				*pagestate=220;//ת����Ҫ����ҳ��
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
				*pagestate=230;//ת����������ҳ��
				return 1;
			}
		}
		
		if (MouseX > 241 && MouseX < 320 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(241,0,320,19) == 2)
			{
				MouseS = 1;	
			}
			if (mouse_press(241,0,320,19)==1)//�򿪲�ѯ��ʽ�ĵ���
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
				*pagestate=250;//ת����������ҳ��
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
				*pagestate=260;//ת�������̳�ҳ��
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
				*pagestate=270;//ת��������Ϣҳ��
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
		return 0;//ʲô��û�� 
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_8
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ�ȷ���Ƿ��˳��ĵ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_8(int *pagestate)//ȷ���Ƿ��˳��ĵ���
{
	void *pic=NULL;
	getimage(139,140,455,360,pic);
	g_2_8();//���ƴ˵���
	if (mouse_press(223,180,381,240)==1)
	{
		exit(0);
	}
	if (mouse_press(223,260,381,320)==1)
	{
		setcolor(RED);
		bar(139,140,455,360);
		putimage(139,140,pic,0);//�رյ���
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������usercode_import
�������ݣ�pagestate:ҳ����  USER* us
����ֵ����
���ܣ�����usercode���û���Ϣ��������еĽṹ��
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
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//ÿ��������һ���û�
		fread(u, sizeof(USER), 1, fp);		  //����Ϣ����u
		if (u->usercode==usercode)
		{
			memset(us,'\0',sizeof(USER));              //������
			//��USER.dat���ҵ�usercode��Ӧ�ĵ�����˺ţ��浽us��
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
��������init_public
�������ݣ���
����ֵ����
���ܣ�Ϊ������Ŀ�س�ʼ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void init_public(void)//Ϊ������Ŀ�س�ʼ��
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
��������create_admin
�������ݣ���
����ֵ����
���ܣ�//����һ���µĹ���Ա��Ϣ
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void create_admin(void)//����һ���µĹ���Ա��Ϣ
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
	puthz(190,210,"����Ա��Ϣ�����ɹ�",32,35,8);
	delay(5000);
	return ;
}