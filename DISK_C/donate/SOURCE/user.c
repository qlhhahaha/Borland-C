#include"common.h"
#include"user.h"


/*
���ܣ��û�������Ϣ
���ߣ������
����޸ģ�2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_7_0
������pagestate:ҳ����;u:�û���Ϣ
����ֵ����
���ܣ���ʾ������Ϣҳ��
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_7_0(int *pagestate,USER *u)
{
	int i;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_7_0(u);
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//��pagestate��Ϊ��ַ����s_2_0�����������Ϸ��˵���s_2_0����1 
		{
			return;
		}
		
		if (MouseX > 450 && MouseX < 580 && MouseY>40 && MouseY < 80)
		{
			if (mouse_press(450,40,580,80) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(450,40,580,80) == 1)
			{
				MouseS = 0;
				*pagestate=280;
				break;
			}
		}
		
		for(i=0;i<12;i++)
		{
			if (MouseX > 50+200*(i%3) && MouseX < 190+200*(i%3) && MouseY>260+50*(i/3) && MouseY < 300+50*(i/3))
			{
				if (mouse_press(50+200*(i%3),260+50*(i/3),190+200*(i%3),300+50*(i/3)) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(50+200*(i%3),260+50*(i/3),190+200*(i%3),300+50*(i/3)) == 1)
				{
					MouseS = 0;
					s_2_7_1(pagestate,i,u->achi);//�򿪳ɾ�����
					return;;
				}
			}
		}
		
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
} 

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_7_1
������pagestate:ҳ����;type:�˳ɾ͵ı��;achi:�û��ĳɾ���Ϣ
����ֵ����
���ܣ���ʾһ���ɾ͵�����
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_7_1(int *pagestate,int type,int achi)
{
	int i,judge=1;
	clrmous(MouseX, MouseY);
	for(i=0;i<type;i++)
	{
		judge*=2;
	}
	if((achi/judge)%2==0)//�û�δ��ɴ˳ɾ�
	{
		g_2_7_1(12);
	}
	else
	{
		g_2_7_1(type);
	}
	delay(100);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//��pagestate��Ϊ��ַ����s_2_0�����������Ϸ��˵���s_2_0����1 
		{
			return;
		}
		if (MouseX > 460 && MouseX < 480 && MouseY>200 && MouseY < 220)
		{
			if (mouse_press(460,200,480,220) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(460,200,480,220) == 1)
			{
				MouseS = 0;
				return;
			}
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������achieve_change
������u:�û���Ϣ��type:����
����ֵ����
���ܣ����û��ĳɾ�״̬�����жϣ����û�����Ҫ�������Ӧ�ɾ�
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void achieve_change(USER *u,int type)//type:��ǰ��Ŀ�����ͣ���0��ʼ������������ĿΪ7����������Ϊ8
{
	FILE *fp;
	USER_STR u_str;
	/*
	1����é®/1�����ڷ�������ɹ���
	��һ�η����������
	2��������/2�����ڽ��о����ǹ�����дUSER��
	��һ�ν��о���
	3���³�˫/4��ͬ��
	�ۼƾ�������
	4�ȱ�Ϊ��/8��ͬ��
	�ۼƾ���ʮ��
	5�������/16��ͬ��
	�ۼƾ�����ʮ��
	6��������/32��ͬ��
	�ۼƾ���һ�ٴ�
	7�������/64��ͬ��
	���ֻ��۳���10000000
	8���޽�/128��ͬ��
	�Կ���or������Ŀ���о���
	9��ʥ֮��/256��ͬ��
	������or��ͯ��Ŀ���о���
	10ɭ������/512��ͬ��
	�Ի�����Ŀ�����о���
	11Я�ֲ���/1024��ͬ��
	�Է�ƶor������Ŀ���о���
	12ѡ��־�/2048��ͬ��
	�Թ�����Ŀ���о���
	*/
	
	if(type==8 && (u->achi/1)%2==0)
	{
		u->achi+=1;
	}
	if((u->achi/2)%2==0 && u->times>=1)//�û�û����ɳɾ͵��Ѿ��ﵽ�ɾ͵�Ҫ��
	{
		u->achi+=2;
	}
	if((u->achi/4)%2==0 && u->times>=2)
	{
		u->achi+=4;
	}
	if((u->achi/8)%2==0 && u->times>=10)
	{
		u->achi+=8;
	}
	if((u->achi/16)%2==0 && u->times>=50)
	{
		u->achi+=16;
	}
	if((u->achi/32)%2==0 && u->times>=100)
	{
		u->achi+=32;
	}
	if((u->achi/64)%2==0 && u->score>=10000000)
	{
		u->achi+=64;
	}
	if(type==3 || type==4)
	{
		if((u->achi/128)%2==0 )
		{
			u->achi+=128;
		}
	}
	if(type==0 || type==1)
	{
		if((u->achi/256)%2==0 )
		{
			u->achi+=256;
		}
	}
	if(type==6)
	{
		if((u->achi/512)%2==0 )
		{
			u->achi+=512;
		}
	}
	if(type==2 || type==5)
	{
		if((u->achi/1024)%2==0 )
		{
			u->achi+=1024;
		}
	}
	if(type==7)
	{
		if((u->achi/2048)%2==0 )
		{
			u->achi+=2048;
		}
	}
	USER_ntoa(u,&u_str);
	if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,(u->usercode)*sizeof(USER_STR),SEEK_SET);
	fwrite(&u_str,sizeof(USER_STR),1,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	return;
}


