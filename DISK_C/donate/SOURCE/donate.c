#include"common.h"
#include"donate.h"
#include"user.h"


/*
���ܣ���Ҫ��������
���ߣ������
����޸ģ�2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_0
������pagestate:ҳ����
����ֵ���������Ŀ���ļ��еĴ���
���ܣ�ʹ�û����Բ鿴������Ŀ�����ṩ���С���ҳ��ɸѡ����
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int s_2_2_0(int *pagestate)//��Ҫ����ҳ�湦�ܺ���
{
	PRO temp;
	PRO_STR temp_str;
	static int order=1,type=7,state=0;
	int row=0,page=0,showorder=0,allorder=0,i;
	long int prosize,fsize,prosite[50][10]={0},ltoi;
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
	g_2_0();//�����Ϸ���פ�˵�
	g_2_2_0();//���Ʊ����
	fsize=fsize_init(fp,order);
	
	while(1)
	{
		g_2_0_0(0);//�����ұ߲˵�
		puthz(5,22,"�Ƕ��򹫹�ļ��",24,28,WHITE);
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
					if(s_2_0(pagestate)==1)//�ϲ˵��������
					{
						free(fp);
						fclose(fp);
						order=1;
						type=7;
						state=0;
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
						if(s_2_2_1(&type,&state,pagestate,0)==1)//����ģ�飬�����s_2_2_1�������Ϸ��˵���رա�����
						{
							free(fp);
							fclose(fp);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//����Ƿ�����������Ŀ
					{
						*pagestate=222;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;
					}
					for(i=0;i<=row;i++)//����Ƿ�������Ŀ
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)//prosite:�жϱ�ҳ�Ƿ���ʾ����Ŀ
						{
							*pagestate=224;//ת����Ŀ����ҳ��
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
				line(280,21,280,479);

				while(1)//�����
				{
					newmouse(&MouseX,&MouseY,&press);
					if(s_2_0(pagestate)==1)//�ϲ˵��������
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
						delay(100);
						if(s_2_2_1(&type,&state,pagestate,0)==1)//����ģ��
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//����Ƿ�����������Ŀ
					{
						*pagestate=222;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;//return��mainpage���ٽ��빫��ҳ��Ĺ��ܺ���
					}
					for(i=0;i<=row;i++)//����Ƿ�������Ŀ
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=224;//ת����Ŀ����ҳ��
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
							return ltoi;
						}	
					}
				}
			}
			break;
			
			default:
			{
				printf("error:illegal order");
				exit(0);
				break;
			}
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

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_1
������pagestate:ҳ����
����ֵ�����������˰�ť�򷵻�1
���ܣ���Ҫ����������ɸѡ����
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_2_1(int *type,int *state,int *pagestate,int who)//����ɸѡ����
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	switch(who)
	{
		case 0:
		{
			g_2_0();
			break;
		}
		case 1:
		{
			ga_0();
			break;
		}
		default:
		{
			printf("error!!! who are open the function now????");
			break;
		}
	}
	g_2_2_1(state);//��������ѡ��ҳ��
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(who==0 && s_2_0(pagestate)==1)//����Ϸ��˵���return��mainpage
		{
			return 1;
		}
		if(who==1 && sa_0(pagestate)==1)//����Ϸ��˵���return��mainpage
		{
			return 1;
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
			return 1;
		}
		if(mouse_press(424,342,537,402)==1)//�ı���������ɸѡ
		{
			switch (*state)
			{
				case 0:
					*state=1;
					break;
				
				case 1:
					*state=0;
					break;
				
				default:
					printf("the value of *state error");
					break;
			}
			return 1;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_2
������pagestate:ҳ���ţ�u���û�����Ϣ
����ֵ����
���ܣ�������Ŀ������ѡ��
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_2(int *pagestate,USER *u)//������Ŀ����ѡ�񵯴�
{
	int i;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_2_2();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)
		{
			return;
		}
		for(i=0;i<7;i++)//�������ĳ�����
		{
			if(mouse_press(66+179*(i%3),90+126*(i/3),179+179*(i%3),150+126*(i/3))==1)
			{
				if(s_2_2_3(pagestate,i,u)==1)
				{
					return;
				}
			}
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_3
������pagestate:ҳ���ţ�pubtype:����Ĺ������ʳص����ࣻu���û�����Ϣ
����ֵ�������������ϲ˵���ȷ�ϣ��򷵻�1
���ܣ��򹫹���Ŀ�ؽ��о���
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_2_3(int *pagestate,int pubtype,USER *u)//������Ŀ��д
{
	char tempid[20];
	RECORD temp2;//������¼�ݸ�
	RECORD_STR temp2_str;
	long int input[9]={0},stock[9]={0},judge=0;
	char stock_str[9][11];
	FILE *fp;
	int i,judge1=0;
	clrmous(MouseX, MouseY);
	g_2_0();
	g_2_2_3(pubtype);
	if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)//��ȡ������Ʒ��
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,9*11*pubtype*sizeof(char),SEEK_SET);//ֻ��ȡ��Ӧ����
	fread(stock_str[0],sizeof(char),9*11,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	setfillstyle(1,WHITE);
	settextstyle(0,0,2);	
	delay(200);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)
		{
			return 1;
		}
		for(i=0;i<9;i++)//��������
		{
			if (mouse_press(10+(i%2)*300,30+(i/2)*92,290+(i%2)*300,90+(i/2)*92)==1)
			{
				input[i] = 0L;
				setfillstyle(1,7);
				bar(75+(i%2)*300,60+(i/2)*92,280+(i%2)*300,84+(i/2)*92);
				inputnumber(&input[i],80+(i%2)*300,60+(i/2)*92,5,7);
				judge=1;
			}
		}
		
		
		if (mouse_press(320,390,440,450)==1)//ȷ�Ͼ���������д����Ϣд���ļ�
		{
			for(i=0;i<9;i++)//�����Ƿ񽫳������
			{
				stock[i]=atol(stock_str[i]);
				if(stock[i]+input[i]>=2000000000)//�������
				{
					input[i]=2000000000-stock[i];
					judge1=1;
				}
				if(input[i]>0)
				{
					judge=1;
				}
				stock[i]=0;
			}
			if(judge==0)//�ж���û�о趫��
			{
				setfillstyle(1,8);
				bar(180,200,480,250);
				puthz(190,210,"�۲���ɶ�����谡",32,35,WHITE);
				delay(2000);
				*pagestate=220;
				return 1;
			}
			//ȷʵ���˶�����������һ��
			if(judge1==1)
			{
				judge1=2;
				for(i=0;i<9;i++)
				{
					if(input[i]!=0)
					{
						judge1=1;
					}
				}
			}
			if(judge1==2)
			{
				setfillstyle(1,8);//������ɣ�������л���ڣ������ӳٺ�ص�"��Ҫ����"ҳ��
				bar(180,200,450,400);
				setfillstyle(1,WHITE);
				bar(185,205,445,395);
				puthzlimit(195,215,385,"����ʧ�ܣ�",24,26,4,8);
				puthzlimit(195,245,385,"���������ʲֿ�������",24,26,4,8);
				delay(2000);
				return 1;
			}
			judge=-3*input[0];//Judge���ڼƷ�
			for(i=0;i<9;i++)
			{
				stock[i]=atol(stock_str[i]);
				stock[i]+=input[i];
				ltoa(stock[i],stock_str[i],10);
				judge+=4*input[i];
			}
			
			if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,9*11*pubtype*sizeof(char),SEEK_SET);
			fwrite(stock_str[0],sizeof(char),9*11,fp);
			fclose(fp);
			fp=NULL;//��ɶԹ�����Ŀ�ص��޸� 
			
			s_2_2_5_1(u,judge);//���ĸ�����Ϣ�еĻ������������
			achieve_change(u,7);//��¼�ɾ�
			
			//д������¼�ݸ�
			temp2.procode=-1;//������Ŀ��procodeΪ-1
			strcpy(temp2.userid,u->userid);
			strcpy(temp2.proname,"�������ʳ�");
			temp2.protype=pubtype;
			for(i=0;i<9;i++)
			{
				temp2.amount[i]=input[i];
			}
			RECORD_ntoa(&temp2,&temp2_str);//�ݸ�д������
			if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,0,SEEK_END);
			fwrite(&temp2_str,sizeof(RECORD_STR),1,fp);
			fclose(fp);
			
			setfillstyle(1,8);//������ɣ�������л���ڣ������ӳٺ�ص�"��Ҫ����"ҳ��
			bar(180,200,450,400);
			setfillstyle(1,WHITE);
			bar(185,205,445,395);
			puthzlimit(195,215,385,"��л�������У�",24,26,4,8);
			puthzlimit(195,245,385,"����һ��ƽ��������",24,26,4,8);
			if(judge1==1)
			{
				puthzlimit(195,275,385,"���ֳ����������ʽ��˻أ�",24,26,4,8);
			}
			delay(2000);
			*pagestate=220;
			return 1;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_4
������pagestate:ҳ���ţ�prosite������Ŀ���ļ��еĴ���
����ֵ����
���ܣ��û��鿴��Ŀ����
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_4(int *pagestate,long int prosite)//��Ŀ����ҳ��
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
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)
		{
			return;
		}
		if (mouse_press(10,370,70,470)==1 && temp.state==0)//����������������Ŀδ����������дҳ��
		{
			*pagestate=225;
			return;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_5
������pagestate:ҳ���ţ�prosite������Ŀ���ļ��еĴ���u���û�����Ϣ
����ֵ����
���ܣ��û�����Ŀ���о���
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_5(int *pagestate,long int prosite,USER *u)//��д�������ҳ��
{
	long int input[9]={0},judge=0;//input:��ת����;judge:�����ж�
	int i,judge1=0;
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
	
	clrmous(MouseX, MouseY);
	g_2_2_5(&temp1,'u');//����ҳ��
	delay(200);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)
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
		
		if (mouse_press(320,390,435,440)==1)//ȷ�Ͼ���������д����Ϣд���ļ�
		{
			judge=0;
			for(i=0;i<9;i++)//��Ҫ�������Ʒ�����ӵ���ʱ��Ŀ������
			{	
				if(input[i]<=(temp1.amount[0][i]-temp1.amount[1][i]))//�ж����
				{
					temp1.amount[1][i]+=input[i];
				}	
				else
				{
					input[i]=temp1.amount[0][i]-temp1.amount[1][i];
					temp1.amount[1][i]=temp1.amount[0][i];
					judge1=1;
				}
				judge+=input[i];
			}
			
			if(judge==0)//���������ȫ��Ϊ0
			{
				if(judge1==1)//���˶�����Ҫ��Ķ��Ѿ�������
				{
					setfillstyle(1,8);
					bar(180,200,530,250);
					puthz(190,210,"���������Ѿ�������",32,35,WHITE);
					delay(2000);
					return;
				}
				else
				{
					setfillstyle(1,8);
					bar(180,200,480,250);
					puthz(190,210,"�۲���ɶ�����谡",32,35,WHITE);
					delay(2000);
					return;
				}
			}
			judge=0;
			for(i=0;i<9;i++)//�ж��Ƿ�������������������
			{
				if(temp1.amount[1][i]!=temp1.amount[0][i])
				{
					judge=1;
				}
			}
			if(judge==0)
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
			strcpy(temp2.userid,u->userid);
			strcpy(temp2.proname,temp1.proname);
			temp2.protype=temp1.protype;
			judge=-3*input[0];//�������������
			for(i=0;i<9;i++)
			{
				temp2.amount[i]=input[i];
				judge+=4*input[i];
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
			
			s_2_2_5_1(u,judge);
			//���û���Ϣд���µĻ��ֺ;�����������Ϣ
			achieve_change(u,temp1.protype);//��¼�ɾ�
			setfillstyle(1,8);//������ɣ�������л���ڣ������ӳٺ�ص�"��Ҫ����"ҳ��
			bar(180,200,450,400);
			setfillstyle(1,WHITE);
			bar(185,205,445,395);
			if(judge1==1)
			{
				puthzlimit(195,215,385,"����ֻ��ȡ�����裬������Ŀ���貿�ֵ����ʽ�������ȡ����л�������У�����һ��ƽ��������",24,26,4,8);
				delay(3000);
			}
			else
			{
				puthzlimit(195,215,385,"��л�������У�",24,26,4,8);
				puthzlimit(195,245,385,"����һ��ƽ��������",24,26,4,8);
				delay(3000);
			}
			
			*pagestate=220;
			return;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_2_5_1
������u���û���Ϣ��judge:�û�����������
����ֵ����
���ܣ����û��Ļ��֡��������������޸�
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_5_1(USER *u,long int judge)//���û���Ϣд���µĻ��ֺ;�����������Ϣ�Ĺ��ܺ���
{
	FILE *fp;
	USER_STR us;
	memset(&us,'\0',sizeof(USER_STR));
	if(u->score-2000000000+judge>0)//����Ƿ�����
	{
		u->score=2000000000;
	}
	(u->score)+=judge;
	if(u->times!=20000)//����Ƿ�����
	{
		(u->times)+=1;
	}
	USER_ntoa(u,&us);
	if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,(u->usercode)*sizeof(USER_STR),SEEK_SET);
	fwrite(&us,sizeof(USER_STR),1,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	return;
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������inputnumber
������number�����������������Ϣ��ָ�룻x1��y1��������λ�ã�
	maxnum����������λ����color:��������ɫ
����ֵ����
���ܣ�ͨ�������������֣���ʵʱ��ʾ�����
��ע������Ĭ��Ϊ��ɫ
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputnumber(long int* number,int x1,int y1,int maxnum,int color)//�����������ֵĳ���������ָ�룬�����xy��������ַ����ƣ���������ɫ
{
	char temp[30];
	int i=0,j;//i���ڼ���
	long int k;
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
		if (i < maxnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//��t��Ϊ�����ʱ
			{
				if (t>=48 && t<=57)//�ж�������Ƿ�Ϊ����
				{
					*(temp + i) = t;
					*(temp + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1-1,temp + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(temp + i) = '\0';
					*(temp+ i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
				break;
			}
		}
		else if (i >= maxnum)
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
					*(temp + i) = '\0';
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
	*number=atol(temp);
}
