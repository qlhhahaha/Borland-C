#include"common.h"
#include"search.h"


/*
���ܣ���ѯ����
���ߣ������
����޸ģ�2020/10/29
*/


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_4_0
������pagestate:ҳ����;u:�û���Ϣ;who:����˹��ܵ�ģʽ����ͨ�û�or����Ա��
����ֵ������ļ�¼���ļ��еĴ���
���ܣ�ʹ�û����Բ鿴����¼Ŀ�����ṩ���С���ҳ��ɸѡ����
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int s_2_4_0(int *pagestate,USER *u,int who)//������¼ҳ�湦�ܺ���
{
	RECORD temp;
	RECORD_STR temp_str; 
	static int order=1,type=7,whodoit=1;
	int row=0,page=0,showorder=0,allorder=0,i;
	FILE *fp;
	long int fsize,prosize,prosite[50][10]={0},ltoi;
	/* 
		PRO temp:��ת�ṹ��
		order��1��˳�� -1������
		type:ɸѡ����Ŀ���ͣ�type=7ʱΪȫ������
		row��page��һ����Ŀ�ڱ������ʾ��������ҳ��
		prosite[page][row]����pageҳ��row�е���Ŀ���ļ��еĴ���(��0��ʼ����)
		showorder��ɸѡ���������Ŀ�ļ�����
		allorder��ɸѡǰ��Ŀ�ļ�����
		prosize��ÿ����Ŀ�Ĵ�С
		i:����ͨ�ļ�����
		fp:����ͨ���ļ�ָ��
		fsize:�ļ���С
		whodoit:�Ƿ�ɸѡ������ID�ļǺţ���Ϊ-1��ֻ��ʾ��ǰ�û��ľ�����¼����Ϊ1����ʾ�����˵ľ�����¼ 
	*/
	prosite[0][0]=-1;
	prosize=sizeof(RECORD_STR);
	fp=NULL;
	if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	if(who==1)
	{
		ga_0();//���ƹ���Ա�Ϸ���פ�˵���
	}
	else
	{
		g_2_0();//�����Ϸ���פ�˵�
	}
	g_2_4_0();//���Ʊ����
	fsize=fsize_init(fp,order);
	while(1)
	{
		g_2_0_0(2);//�����ұ߲˵�
		switch(order)//������
		{
			case 1://����
			{
				while(ftell(fp)<fsize)//������������
				{
					if(info_output(fp,fsize,whodoit,type,u->userid,&allorder,&showorder,order,'r')==1)
					{
						continue;
					}
					row=showorder%10;
					page=showorder/10;
					prosite[page][row]=allorder-1;//��¼��ʾ��ҳ���ϵ���Ŀ���ļ��еĴ��򣨴�0��ʼ��
					showorder+=1;//�����showorder��ʵ���Ѿ��������һ����Ŀ
					
					
					if(row>=9)//��ҳ����ʾ���,ֹͣѭ�������������
					{
						break;
					}			
				}
				blank_draw(order,row,2);

				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(who==0)//�ϲ˵��������
					{
						if(s_2_0(pagestate)==1)
						{
							free(fp);
							fclose(fp);
							order=1;
							whodoit=1;
							type=7;
							delay(100);
							return 0;//������Ϸ��˵�����return��mainpage����ת������ҳ��
						}
					}
					if(who==1)
					{
						if(sa_0(pagestate)==1)
						{
							free(fp);
							fclose(fp);
							order=1;
							whodoit=1;
							type=7;
							delay(100);
							return 0;//������Ϸ��˵�����return��mainpage����ת������ҳ��
						}
					}
					if (mouse_press(605,21,639,116)==1)//�����"��һҳ"��ť
					{
						delay(100);
						if(page>0)
						{
							showorder=(page-1)*10;//�ض�������һҳ�׸���Ŀ
							ltoi=prosite[showorder/10][0];
							allorder=(int)ltoi;
							fseek(fp,prosize*allorder,SEEK_SET);
							delay(200);
							break;
						}
						if(page==0)//��ǰ�Ѿ��ǵ�һҳ
						{
							showorder=0;//�ض�������ҳ�׸���Ŀ
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0,SEEK_SET);
							break;
						}
						if(page<0)
						{
							printf("error!!!!why the page<0???");//��������
							delay(5000);
						}
					}
					if (mouse_press(605,367,639,479)==1)//���������һҳ����ť
					{
						delay(100);
						break;//�˳����ѭ��
					}
					if (mouse_press(605,117,639,240)==1)//�������˳��or����ť�����ı�����ʽ
					{
						order=-1;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;//������mainpage����prosite��ֵ0
					}
					if (mouse_press(605,241,639,366)==1)//�����������ɸѡ����ť
					{
						if(s_2_4_1(&type,&whodoit,pagestate,who)==1)//����ģ�飬�����s_2_4_1�������Ϸ��˵���رա�����
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					for(i=0;i<=row;i++)//����Ƿ�����һ����¼ 
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=242;//ת����¼����ҳ��
							free(fp);
							fclose(fp);
							delay(100);
							return prosite[page][i];
						}	
					}	
				}
			}
			break;//�˳�switch�������½���switch
			
			case -1://����
			{
				while(ftell(fp)>fsize)//������������
				{
					if(info_output(fp,fsize,whodoit,type,u->userid,&allorder,&showorder,order,'r')==1)
					{
						continue;
					}
					row=showorder%10;
					page=showorder/10;
					prosite[page][row]=allorder-1;//��¼��ʾ��ҳ���ϵ���Ŀ���ļ��еĴ��򣨴�0��ʼ��
					showorder+=1;
					
					if(row>=9)//��ҳ����ʾ���,ֹͣѭ�������������
					{
						break;
					}			
				}
				blank_draw(order,row,2);

				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(who==0)//�ϲ˵��������
					{
						if(s_2_0(pagestate)==1)
						{
							free(fp);
							fclose(fp);
							order=1;
							whodoit=1;
							type=7;
							delay(100);
							return 0;//������Ϸ��˵�����return��mainpage����ת������ҳ��
						}
					}
					if(who==1)
					{
						if(sa_0(pagestate)==1)
						{
							free(fp);
							fclose(fp);
							order=1;
							whodoit=1;
							type=7;
							delay(100);
							return 0;//������Ϸ��˵�����return��mainpage����ת������ҳ��
						}
					}
					if (mouse_press(605,21,639,116)==1)//�����"��һҳ"��ť
					{
						delay(100);
						if(page>0)
						{
							showorder=(page-1)*10;//�ض�������һҳ�׸���Ŀ
							ltoi=prosite[showorder/10][0];
							allorder=(int)ltoi;
							fseek(fp,-1*prosize*allorder,SEEK_END);
							delay(200);
							break;
						}
						if(page==0)//��ǰ�Ѿ��ǵ�һҳ
						{
							showorder=0;//�ض�������ҳ�׸���Ŀ
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0L,SEEK_END);
							break;
						}
						if(page<0)
						{
							printf("error!!!!why the page<0???");//��������
						}
					}
					if (mouse_press(605,367,639,479)==1)//���������һҳ����ť
					{
						delay(100);
						break;
					}
					if (mouse_press(605,117,639,240)==1)//�������˳��or����ť�����ı�����ʽ
					{
						order=1;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;
					}
					if (mouse_press(605,241,639,366)==1)//�����������ɸѡ����ť
					{
						if(s_2_4_1(&type,&whodoit,pagestate,who)==1)//����ģ�飬�����s_2_4_1�������Ϸ��˵���رա�����
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					for(i=0;i<=row;i++)//����Ƿ�����һ����¼ 
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=242;//ת����¼����ҳ��
							free(fp);
							fclose(fp);
							fp=NULL;
							if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
							{
								printf("CAN`T OPEN FILE");
								delay(500);
								exit(0);
							}
							fseek(fp,0,SEEK_END);
							fsize=ftell(fp);
							free(fp);
							fclose(fp);
							fp=NULL;
							ltoi=(fsize/sizeof(RECORD_STR))-1-prosite[page][i];
							delay(100);
							return ltoi;
						}	
					}
				}
			}
			break;
			
			default:
			printf("error:illegal order");
			exit(0);
		}
		if(page>=50)
		{
			setfillstyle(1,BLUE);
			bar(200,200,400,250);
			puthz(210,210,"û�и����ˡ�",32,34,WHITE);
			return 0;
		}
	}
}	

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_4_1
������type:�����ɸѡ;whodoit:�����ߵ�ɸѡ;pagestate:ҳ����;who:�����ģʽ
����ֵ��������˰�ť�򷵻�1
���ܣ��ı������¼��ɸѡ״̬
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_4_1(int *type,int *whodoit,int *pagestate,int who)//����ɸѡ����
{
	clrmous(MouseX, MouseY);
	delay(300);
	cleardevice();
	if(who==1)
	{
		ga_0();//���ƹ���Ա�Ϸ���פ�˵���
	}
	else
	{
		g_2_0();//�����Ϸ���פ�˵�
	}
	g_2_4_1();//��������ѡ��ҳ��
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(who==0)//����Ϸ��˵���return��mainpage
		{
			if(s_2_0(pagestate)==1)
			{
				return 1;
			}
		}
		if(who==1)
		{
			if(sa_0(pagestate)==1)
			{
				return 1;
			}
		}
		if(mouse_press(66,90,179,150)==1)//ѡ���ͯ
		{
			*type=0;
			return 1;
		}
		if(mouse_press(245,90,358,150)==1)//ѡ������
		{
			*type=1;
			return 1;
		}
		if(mouse_press(424,90,537,150)==1)//ѡ���ƶ
		{
			*type=2;
			return 1;
		}
		if(mouse_press(66,216,179,276)==1)//ѡ�����
		{
			*type=3;
			return 1;
		}
		if(mouse_press(245,216,358,276)==1)//ѡ����
		{
			*type=4;
			return 1;
		}
		if(mouse_press(424,216,537,276)==1)//ѡ�����
		{
			*type=5;
			return 1;
		}
		if(mouse_press(66,342,179,402)==1)//ѡ�񻷱�
		{
			*type=6;
			return 1;
		}
		if(mouse_press(245,342,358,402)==1)//ѡ��ȫ��
		{
			*type=7;
			*whodoit=1;
			return 1;
		}
		if(mouse_press(424,342,537,402)==1)//���������ɸѡ��ť���ı�whodoit��ֵ
		{
			*whodoit=-1;
			return 1;
		} 
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_4_2
������pagestate:ҳ����;recordsite:�˼�¼���ļ��еĴ���;who:ģʽ
����ֵ����
���ܣ�ʹ�û����Բ鿴������Ŀ�����ṩ���С���ҳ��ɸѡ����
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_4_2(int *pagestate,long int recordsite,int who)//������¼����ҳ�� 
{
	RECORD temp;
	RECORD_STR temp_str;
	FILE *fp;
	cleardevice;
	//clrmous(MouseX, MouseY);
	if(who==1)
	{
		ga_0();//���ƹ���Ա�Ϸ���פ�˵���
	}
	else
	{
		g_2_0();//�����Ϸ���פ�˵�
	}
	g_2_4_2(recordsite);
	if(who==1)
	{
		setfillstyle(1,WHITE);
		bar(10,370,70,470);
		puthzlimit(16,376,70,"ɾ��",48,50,2,8);
	}
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(who==0 && s_2_0(pagestate)==1)//����Ϸ��˵���return��mainpage
		{
			return ;
		}
		if(who==1 && sa_0(pagestate)==1)
		{
			return ;
		}
		if (mouse_press(10,370,70,470)==1 && who==1)//���ɾ��
		{
			*pagestate=240;
			if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,recordsite*sizeof(RECORD_STR),SEEK_SET);
			fread(&temp_str,(long int)sizeof(RECORD_STR),1,fp);
			RECORD_aton(&temp,&temp_str);
			
			temp.procode=-2;//���ɾ��
			RECORD_ntoa(&temp,&temp_str);
			fseek(fp,recordsite*sizeof(RECORD_STR),SEEK_SET);
			fwrite(&temp_str,(long int)sizeof(RECORD_STR),1,fp);
			free(fp);
			fclose(fp);
			fp=NULL;
			setfillstyle(1,BLUE);
			bar(200,150,450,200);
			puthz(210,165,"���������վ",32,33,WHITE);
			delay(2000);
			return ;
		}
	}
}

