#include"common.h"
#include"shop.h"

/*
���ܣ�����Ա�ĵ��ȡ���ѯ�ͷ������
���ߣ������
����޸ģ�2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_6_0
������pagestate:ҳ����;u:�û���Ϣ
����ֵ����
���ܣ��̵���ܺ���
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_6_0(int *pagestate,USER *u)//�̵���ܺ���
{
	int i;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_6_0(u);
	while(1)//����� 
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//�ϲ˵��������
		{
			return;//������Ϸ��˵�����return��mainpage����ת������ҳ��
		}
		for(i=0;i<9;i++)//����Ƿ�������Ʒ 
		{
			if (mouse_press(20+200*(i%3),110+110*(i/3),210+200*(i%3),210+110*(i/3))==1)
			{
				if(s_2_6_1(u,i,pagestate)==1)//��Ʒ�һ�����
				{
					return;
				}
			}
		}	
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_6_1
������pagestate:ҳ����;u:�û���Ϣ;order:����Ʒ��˳��
����ֵ��Ĭ��Ϊ1
���ܣ�����Ʒ���жһ�
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_6_1(USER *u,int order,int *pagestate)//��Ʒ�һ����ܺ���
{
	USER_STR tempuser_str;//���ĺ���û���Ϣ�ݸ�
	FILE *fp; 
	long int price[9]={100,300,600,800,500,1000,10000,40000,500000};
	memset(&tempuser_str,'\0',sizeof(USER_STR));
	clrmous(MouseX, MouseY);	
	if(u->score<price[order])//������ֲ����Զһ�����Ʒ 
	{
		g_2_6_2();//���ֲ�����ʾ����
		delay(1234);
		return 1;
	}
	if(u->goods[order]>=200000)//���������Ƿ�ﵽ����
	{
		g_2_6_4();
		delay(1234);
		return 1;
	}
	else //�����㹻 
	{
		g_2_6_1(u,order);
	}
	delay(300);
	while(1)
	{	
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//�ϲ˵��������
		{
			return 1;
		}
		
		if (mouse_press(320,300,415,352)==1)//�����ȷ�ϡ���ť,���жһ����޸��û���Ϣ�ļ�
		{
			if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,(sizeof(USER_STR))*(u->usercode),SEEK_SET);//�����һ�����û�������Ϣ
			u->score-=price[order];
			u->goods[order]+=1;
			USER_ntoa(u,&tempuser_str);
			fwrite(&tempuser_str,sizeof(USER_STR),1,fp);//����д�����ݿ� 
			free(fp);
			fclose(fp);
			clrmous(MouseX, MouseY);
			g_2_6_3();//��ʾ�һ��ɹ� 
			delay(1234); 
			return 1;
		}
		if (mouse_press(440,180,460,200)==1)
		{
			delay(300);
			return 1;
		}
	}
} 




