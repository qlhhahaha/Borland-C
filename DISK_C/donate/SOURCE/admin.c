#include"common.h"
#include"admin.h"

/*
���ܣ�����Ա�ĵ��ȡ���ѯ�ͷ������
���ߣ������
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_1_2_0
�������ݣ�pagestate:ҳ���ţ�adm:����Ա��Ϣ���˺ź����룩
����ֵ����
���ܣ�����Ա��¼�ɹ������ҳ��������ͣѭ�������pagestate�Ծ���������һ������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_2_0(int *pagestate,ADMIN *adm)//����Ա��������
{
	USER u;//α�û���Ϣ��ֻ����װID��ADMIN��
	long int prosite=0,recordsite=0,usersite=0;//��¼��Ŀ���ļ����λ��
	*pagestate=10;//��½�����Ĭ�ϵ���Ŀ��Ϣ��
	strcpy(u.userid,"ADMIN");
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	while(1)
	{
		switch(*pagestate)
		{
			case 10:
			{
				prosite=sa_1_0(pagestate);//��Ŀ��Ϣ���
				break;
			}
			case 12://����Ա��Ŀ����ҳ��
			{
				sa_1_2(pagestate,prosite);
				break;
			}
			case 13://����Ա��������
			{
				sa_1_3(pagestate,prosite);
				break;
			}
			case 240://����Ա�鿴������¼
			{
				recordsite=s_2_4_0(pagestate,&u,1);
				break;
			}
			case 242:
			{
				s_2_4_2(pagestate,recordsite,1);//������¼����ҳ�� 
				break;
			}
			case 30:
			{
				usersite=sa_3_0(pagestate);//�û���Ϣ���
				break;
			}
			case 31:
			{
				sa_3_1(pagestate,usersite);//�û���Ϣ���
				break;
			}
			case 4:
			{
				clrmous(MouseX, MouseY);
				exit(0);
				break;
			}
			case 281:
			{
				s_2_8_1(pagestate);//����Ա���˳����� 
				break;
			}
			case 282:
			{
				return;
			}
			default:
			{
				printf("pagestate of s_1_2_0 error");
				delay(5000);
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_0
�������ݣ�pagestate:ҳ�����
����ֵ��int�ͣ�������������κ�һ���ϲ˵����еĹ��ܣ������᷵��1����û�е���򷵻�0
���ܣ�����Ա���ϲ˵��������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int sa_0(int *pagestate)//����Ա���Ϸ��˵���
{
	if (MouseX > 321 && MouseX < 400 && MouseY>0 && MouseY < 19)
		{
			if (mouse_press(321,0,400,19) == 2)
			{
				MouseS = 1;
				
			}
			if (mouse_press(321,0,400,19)==1)
			{
				MouseS = 0;
				*pagestate=10;//ת����Ŀ��Ϣ���
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
				*pagestate=240;//ת��������¼
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
				*pagestate=30;//ת���û���Ϣ���
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
				*pagestate=281;//�˳�����
				return 1;
			}
		}
		if (MouseX > 0 && MouseX < 639 && MouseY>21 && MouseY < 479)
		{
			MouseS = 0;
		}
		return 0;//ʲô��û�� 
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_1_0
������pagestate:ҳ����룬adm:��ǰ����Ա����Ϣ
����ֵ��long int�ͣ����������Ŀ���ļ��еĴ���
���ܣ�����Ŀ��һ����˳����ʾ���ṩ��ҳ��ɸѡ����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int sa_1_0(int *pagestate)//����Ա���ʵ���ҳ�湦�ܺ���
{
	PRO temp;
	PRO_STR temp_str;
	static int order=1,type=7,state=0;
	int row=0,page=0,showorder=0,allorder=0,i;
	long int prosize,fsize,ltoi,prosite[50][10]={0};
	FILE *fp;
	/* 
		PRO temp:��ת�ṹ��
		PRO_STR temp_s:��ת�ṹ����ַ�����ʽ 
		order��1��˳�� -1������
		type:ɸѡ����Ŀ���ͣ�type=7ʱΪȫ������
		state:ɸѡ��Ŀ����������state=0ʱ���δ�����Ŀ��state=1ʱ����������Ŀ
		row��page��һ����Ŀ�ڱ������ʾ��������ҳ��
		prosite[page][row]����pageҳ��row�е���Ŀ���ļ��еĴ���(��0��ʼ)
		showorder��ɸѡ���������Ŀ�ļ�����
		allorder��ɸѡǰ��Ŀ�ļ�����
		prosize��ÿ����Ŀ�Ĵ�С
		i:����ͨ�ļ�����
		fp:����ͨ���ļ�ָ��
		fsize:�ļ���С
	*/
	prosite[0][0]=-1;//�����жϱ�ҳ�Ƿ���ʾ����Ŀ����δ��ʾ���ֵΪ-1���䣬����ʾ�����ֵ������
	prosize=sizeof(PRO_STR);
	fp=NULL;
	if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	clrmous(MouseX, MouseY);
	delay(200);
	cleardevice();
	ga_0();
	g_2_2_0();//���Ʊ����
	fsize=fsize_init(fp,order);
	while(1)
	{
		g_2_0_0(0);//�����ұ߲˵�
		puthz(200,22,"�������ʳ�",24,28,WHITE);
		switch(order)//������
		{
			case 1://����
			{
				while(ftell(fp)<fsize)//������������
				{
					if(info_output(fp,fsize,state,type,NULL,&allorder,&showorder,order,'p')==1)
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
				
				blank_draw(order,row,0);
				setcolor(BLUE);
				line(280,68,280,479);				
				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//�ϲ˵��������
					{
						free(fp);
						fclose(fp);
						order=1;
						type=7;
						state=0;
						return 0;//������Ϸ��˵�����return��s_1_2_0����ת������ҳ��
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
							break;
						}
						if(page==0)//��ǰ�Ѿ��ǵ�һҳ
						{
							showorder=0;//�ض�������ҳ�׸���Ŀ
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0,SEEK_SET);
							delay(100);
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
						return 0;//������s_1_2_0����prosite��ֵ0
					}
					if (mouse_press(605,241,639,366)==1)//�����������ɸѡ����ť
					{
						if(s_2_2_1(&type,&state,pagestate,1)==1)//����ģ�飬�����s_2_2_1�������Ϸ��˵���رա�����
						{
							free(fp);
							fclose(fp);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//����Ƿ�����������Ŀ
					{
						sa_1_1(pagestate);
						return 0;
					}
					for(i=0;i<=row;i++)//����Ƿ�������Ŀ
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)//prosite:�жϱ�ҳ�Ƿ���ʾ����Ŀ
						{
							*pagestate=12;//ת����Ŀ����ҳ��
							free(fp);
							fclose(fp);
							delay(100);
							return prosite[page][i];
						}	
					}
				}
			}
			break;//�˳�switch�������½���switch
			//----------------------------------------------------------------------------
			case -1://����
			{
				setcolor(WHITE);
				settextstyle(0,0,4);
				while(ftell(fp)>fsize)//������������
				{
					if(info_output(fp,fsize,state,type,NULL,&allorder,&showorder,order,'p')==1)
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
				blank_draw(order,row,0);
				setcolor(BLUE);
				line(280,68,280,479);
				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//�ϲ˵��������
					{
						free(fp);
						fclose(fp);
						order=1;
						type=7;
						state=0;
						return 0;
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
							break;
						}
						if(page==0)//��ǰ�Ѿ��ǵ�һҳ
						{
							showorder=0;//�ض�������ҳ�׸���Ŀ
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0L,SEEK_END);
							delay(100);
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
						delay(100);
						if(s_2_2_1(&type,&state,pagestate,1)==1)//����ģ��
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//����Ƿ�����������Ŀ
					{
						sa_1_1(pagestate);
						return 0;
					}
					for(i=0;i<=row;i++)//����Ƿ�������Ŀ
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=12;//ת����Ŀ����ҳ��
							free(fp);
							fclose(fp);
							fp=NULL;
							if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)
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
							ltoi=(fsize/sizeof(PRO_STR))-1-prosite[page][i];
							delay(100);
							return i;
						}	
					}
				}
			}
			break;
			
			default:
			printf("error:illegal order");
			exit(0);
		}
		if(page>=20)
		{
			setfillstyle(1,BLUE);
			bar(200,200,400,250);
			puthz(210,210,"û�и����ˡ�",32,34,WHITE);
			return 0;
		}
	}	
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_1_1
������pagestate:ҳ�����
����ֵ����
���ܣ�������Ŀ����ѡ�񵯴�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_1_1(int *pagestate)//������Ŀ����ѡ�񵯴�
{
	int i;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	ga_0();
	g_2_2_2();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(sa_0(pagestate)==1)//�ϲ˵��������
			{
				return ;
			}
		for(i=0;i<7;i++)
		{
			if(mouse_press(66+179*(i%3),90+126*(i/3),179+179*(i%3),150+126*(i/3))==1)
			{
				if(sa_1_1_1(pagestate,i)==1)
				{
					return;
				}
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_1_1_1
������pagestate:ҳ����룻pubtype:Ҫ�򿪵Ĺ������ʳص�����
����ֵ��int�ͣ��������ˡ�ȷ�ϡ����ϲ˵����򷵻�1
���ܣ�����Ա�鿴������������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int sa_1_1_1(int *pagestate,int pubtype)//�������ʳ�����
{
	clrmous(MouseX, MouseY);
	ga_0();
	ga_1_1_1(pubtype);//����������Ϣҳ�� 
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(sa_0(pagestate)==1)//�ϲ˵��������
		{
			return 1;
		}
		if(mouse_press(320,390,440,450)==1)
		{
			*pagestate=10;
			return 1;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_1_2
������pagestate:ҳ���ţ�prosite:����Ŀ���ļ��еĴ���
����ֵ����
���ܣ�����Ա��Ŀ�����飬���ɽ������ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_1_2(int *pagestate,long int prosite)//��Ŀ����ҳ��
{
	PRO temp;
	PRO_STR temp_str;
	FILE *fp;
	if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,prosite*sizeof(PRO_STR),SEEK_SET);
	fread(&temp_str,sizeof(PRO_STR),1,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	PRO_aton(&temp,&temp_str);
	clrmous(MouseX, MouseY);
	g_2_2_4(&temp,&temp_str);//���ƴ�ҳ��
	if(temp.state==0)//ֻ�д���Ŀδ���ʱ�Ż���ƾ�����ť
	{
		bar(10,370,70,470);
		puthzlimit(16,376,70,"����",48,50,2,8);
	}
	if(temp.state==1)
	{
		bar(10,370,70,470);
		puthzlimit(16,376,70,"ɾ��",48,50,2,8);
	}
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(sa_0(pagestate)==1)
		{
			return;
		}
		if (mouse_press(10,370,70,470)==1 && temp.state==0)//����������������Ŀδ����������дҳ��
		{
			*pagestate=13;
			return;
		}
		if (mouse_press(10,370,70,470)==1 && temp.state==1)//���ɾ��
		{
			*pagestate=10;
			temp.state=2;
			PRO_ntoa(&temp,&temp_str);
			if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,prosite*sizeof(PRO_STR),SEEK_SET);
			fwrite(&temp_str,sizeof(PRO_STR),1,fp);
			free(fp);
			fclose(fp);
			fp=NULL;
			setfillstyle(1,BLUE);
			bar(200,150,450,200);
			puthz(210,165,"���������վ",32,33,WHITE);
			delay(2000);
			return;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_1_3
������pagestate:ҳ����;prosite������Ŀ���ļ��еĴ���
����ֵ����
���ܣ�����Ա����Ŀ���е���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_1_3(int *pagestate,long int prosite)//��д����ҳ��
{
	long int pubamount[9]={0},type;//��¼������Ŀ������Ʒ���� 
	char pub_str[9][11];
	long int input[9]={0},judge1=0;//input:��ת����;judge1:�����ж�
	int i,judge2=0;
	PRO temp1;
	PRO_STR temp1_str;
	RECORD temp2;
	RECORD_STR temp2_str;
	char tempid[15];
	FILE *fp;
	
	if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)//����pro��Ϣ
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,prosite*sizeof(PRO_STR),SEEK_SET);
	fread(&temp1_str,sizeof(PRO_STR),1,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	PRO_aton(&temp1,&temp1_str);
	type=temp1.protype;
	if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)//��ȡ�������ʳ����� 
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,9*11*type*sizeof(char),SEEK_SET);
	fread(pub_str,sizeof(char),9*11,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	for(i=0;i<9;i++)
	{
		pubamount[i]=atol(pub_str[i]);
	}
	
	clrmous(MouseX, MouseY);
	g_2_2_5(&temp1,'a');
	delay(200);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(sa_0(pagestate)==1)
		{
			return;
		}
		for(i=0;i<9;i++)//��input����������
		{
			if (mouse_press(10+(i%2)*300,30+(i/2)*92,290+(i%2)*300,62+(i/2)*92)==1)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1,BLUE);
				bar(110+(i%2)*300,30+(i/2)*92,290+(i%2)*300,62+(i/2)*92);
				inputnumber(&input[i],110+(i%2)*300,35+(i/2)*92,6,BLUE);
				newmouse(&MouseX, &MouseY, &press);
			}
		}
		
		if (mouse_press(320,390,570,460)==1)//ȷ�Ͼ���������д����Ϣд���ļ�
		{
			judge1=0;
			for(i=0;i<9;i++)//��Ҫ�������Ʒ�����ӵ���ʱ��Ŀ������
			{	
				if(input[i]>(temp1.amount[0][i]-temp1.amount[1][i]))//�ж����
				{//���
					input[i]=temp1.amount[0][i]-temp1.amount[1][i];
				}	
				if(pubamount[i]<input[i])//�鿴Ҫ��������������Ƿ񳬳��˿�� 
				{//�������
					input[i]=pubamount[i];
					judge2=1;
				}
				temp1.amount[1][i]+=input[i];
				judge1+=input[i];
			}
			if(judge1==0)//���������ȫ��Ϊ0
			{
				setfillstyle(1,8);
				bar(180,200,480,250);
				if(judge2==1)
				{
					puthz(190,210,"��治�㣬�޷����",32,35,WHITE);
				}
				else
				{
					puthz(190,210,"����������ĿΪ��",32,35,WHITE);
				}
				delay(2000);
				return;
			}
			
			judge1=0;
			for(i=0;i<9;i++)//�ж��Ƿ�������������������
			{
				if(temp1.amount[1][i]!=temp1.amount[0][i])
				{
					judge1=1;
				}
			}
			if(judge1==0)
			{
				temp1.state=1;
			}
			PRO_ntoa(&temp1,&temp1_str);
			
			if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,prosite*sizeof(PRO_STR),SEEK_SET);
			fwrite(&temp1_str,sizeof(PRO_STR),1,fp);//����ʱ��Ŀ��������ԭ�ļ�
			free(fp);
			fclose(fp);
			fp=NULL;
			
			temp2.procode=temp1.procode;//����������¼�ݸ�
			strcpy(temp2.userid,"ADMIN");
			strcpy(temp2.proname,temp1.proname);
			temp2.protype=temp1.protype;
			for(i=0;i<9;i++)
			{
				temp2.amount[i]=input[i];
			}
			RECORD_ntoa(&temp2,&temp2_str);
			//�ݸ�д���ˣ�
			
			if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,0,SEEK_END);
			fwrite(&temp2_str,sizeof(RECORD_STR),1,fp);//д�������¼
			free(fp);
			fclose(fp);
			fp=NULL;
			
			for(i=0;i<9;i++)
			{
				pubamount[i]-=input[i];
				ltoa(pubamount[i],pub_str[i],10);
			}
			
			if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)//��д������Ŀ��
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,9*11*type*sizeof(char),SEEK_SET);
			fwrite(pub_str,sizeof(char),9*11,fp);
			free(fp);
			fclose(fp);
			
			setfillstyle(1,8);
			bar(180,200,450,400);
			setfillstyle(1,WHITE);
			bar(185,205,445,395);
			puthzlimit(195,210,385,"�����Ѵӹ������ʳص�������Ŀ",24,26,4,8);
			if(judge2==1)
			{
				puthzlimit(195,265,385,"�������ʳ�����棬��ֻ�������п������",24,26,4,8);
				delay(1000);
			}
			delay(3000);
			*pagestate=10;
			return;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_3_0
������pagestate:ҳ����
����ֵ��long int�ͣ�������û����ļ��еĴ���
���ܣ�����Ա�鿴�����û��ĺ������ṩɸѡ��������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int sa_3_0(int *pagestate)
{
	USER temp;
	USER_STR temp_str;
	static int order=1,state=1;
	int row=0,page=0,showorder=0,allorder=0,i;
	long int prosize,fsize,prosite[50][10]={0},ltoi;
	FILE *fp;
	/* 
		USER temp:��ת�ṹ��
		USER_STR temp_str:��ת�ṹ����ַ�����ʽ 
		order��1��˳�� -1������
		type:ɸѡ����Ŀ���ͣ�type=7ʱΪȫ������
		state:ɸѡ��Ŀ����������state=0ʱ���δ�����Ŀ��state=1ʱ����������Ŀ
		row��page��һ����Ŀ�ڱ������ʾ��������ҳ��
		prosite[page][row]����pageҳ��row�е���Ŀ���ļ��еĴ���(��0��ʼ)
		showorder��ɸѡ���������Ŀ�ļ�����
		allorder��ɸѡǰ��Ŀ�ļ�����
		prosize��ÿ����Ŀ�Ĵ�С
		i:����ͨ�ļ�����
		fp:����ͨ���ļ�ָ��
		fsize:�ļ���С
	*/
	prosite[0][0]=-1;//�����жϱ�ҳ�Ƿ���ʾ����Ŀ����δ��ʾ���ֵΪ-1���䣬����ʾ�����ֵ������
	prosize=sizeof(USER_STR);
	fp=NULL;
	if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	clrmous(MouseX, MouseY);
	delay(200);
	cleardevice();
	ga_0();//�����Ϸ���פ�˵�
	g_2_2_0();//���Ʊ����
	fsize=fsize_init(fp,order);

	while(1)
	{
		ga_3_0(state);//���ƹ���Ա�Ҳ˵���
		switch(order)//������
		{
			case 1://����
			{
				while(ftell(fp)<fsize)//������������
				{
					if(info_output(fp,fsize,state,0,NULL,&allorder,&showorder,order,'u')==1)
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
				blank_draw(order,row,state);

				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//�ϲ˵��������
					{
						free(fp);
						fclose(fp);
						order=1;
						state=1;
						delay(100);
						return 0;//������Ϸ��˵�����return��mainpage����ת������ҳ��
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
							break;
						}
						if(page==0)//��ǰ�Ѿ��ǵ�һҳ
						{
							showorder=0;//�ض�������ҳ�׸���Ŀ
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0,SEEK_SET);
							delay(100);
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
						return 0;
					}
					if (mouse_press(605,241,639,366)==1)//�����״̬ɸѡ��ť
					{
						
						state*=-1;
						free(fp);
						fclose(fp);
						return 0;
					}
					for(i=0;i<=row;i++)//����Ƿ������û�
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)//prosite:�жϱ�ҳ�Ƿ���ʾ����Ŀ
						{
							*pagestate=31;//ת����Ŀ����ҳ��
							free(fp);
							fclose(fp);
							delay(100);
							return prosite[page][i];
						}	
					}
				}
			}
			break;//�˳�switch�������½���switch
			//----------------------------------------------------------------------------
			case -1://����
			{
				while(ftell(fp)>fsize)//������������
				{
					if(info_output(fp,fsize,state,0,NULL,&allorder,&showorder,order,'u')==1)
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
				blank_draw(order,row,state);

				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//�ϲ˵��������
					{
						free(fp);
						fclose(fp);
						order=1;
						state=1;
						delay(100);
						return 0;//������Ϸ��˵�����return��mainpage����ת������ҳ��
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
							delay(100);
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
						state*=-1;
						free(fp);
						fclose(fp);
						return 0;
					}
					if (mouse_press(0,21,604,68)==1)//����Ƿ�����������Ŀ
					{
						*pagestate=222;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;//return��mainpage���ٽ��빫��ҳ��Ĺ��ܺ���
					}
					for(i=0;i<=row;i++)
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=31;//ת���û�����ҳ��
							free(fp);
							fclose(fp);
							fp=NULL;
							if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)
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
							ltoi=(fsize/sizeof(USER_STR))-1-prosite[page][i];
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
		if(page>=20)
		{
			setfillstyle(1,BLUE);
			bar(200,200,400,250);
			puthz(210,210,"û�и����ˡ�",32,34,WHITE);
			return 0;
		}
	}	
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������sa_3_1
������pagestate:ҳ���ţ�usersite�����û����ļ��еĴ���
����ֵ����
���ܣ�����Ա�鿴�û���Ϣ�����ɽ��н��ͷ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_3_1(int *pagestate,long int usersite)//�û�����
{
	FILE *fp;
	USER temp;
	USER_STR temp_str;
	if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,usersite*sizeof(USER_STR),SEEK_SET);
	fread(&temp_str,sizeof(USER_STR),1,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	USER_aton(&temp,&temp_str);
	clrmous(MouseX, MouseY);
	ga_3_1(&temp,&temp_str);//���ƴ�ҳ��
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(sa_0(pagestate)==1)
		{
			return;
		}
		if (mouse_press(10,370,70,470)==1)
		{
			if(temp.times>=0)//�û���ǰΪ������ʹ�䶳��
			{
				temp.times+=1;
				(temp.times)*=-1;
			}
			else//�û���ǰΪ���ᣬʹ����
			{
				(temp.times)*=-1;
				temp.times-=1;
			}
			USER_ntoa(&temp,&temp_str);
			if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,usersite*sizeof(USER_STR),SEEK_SET);
			fwrite(&temp_str,sizeof(USER_STR),1,fp);
			free(fp);
			fclose(fp);
			fp=NULL;
			setfillstyle(1,8);
			bar(180,200,480,250);
			puthz(190,210,"�����ɹ�������",32,35,WHITE);
			delay(2000);
			return;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_8_1
������pagestate��ҳ����
����ֵ����
���ܣ�����Ա�˳���½��ȷ�Ͻ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_8_1(int *pagestate)
{
	clrmous(MouseX, MouseY);
	delay(100);
	g_2_8_0();

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 200 && MouseX < 290 && MouseY>245 && MouseY < 285)
			{
				if (mouse_press(200,245,290,285) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(200,245,290,285) == 1)
				{
					*pagestate=282;
					delay(500);
					clrmous(MouseX,MouseY);
					cleardevice();
					return;
				}
			}
			
		if (MouseX > 350 && MouseX < 440 && MouseY>245 && MouseY < 285)
			{
				if (mouse_press(350,245,440,285) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(350,245,440,285) == 1)
				{
					MouseS = 0;
					*pagestate=10;
					clrmous(MouseX,MouseY);
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