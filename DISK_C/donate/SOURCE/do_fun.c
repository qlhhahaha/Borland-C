#include"common.h"
#include"do_fun.h"

/*
���ܣ���Ҫ�������ܵ���غ���
���ߣ������
����޸ģ�2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������fsize_init
������fp:�ļ�ָ�룬order:�����˳��
����ֵ���ļ�ָ��frell(fp)�յ�λ��
���ܣ��õ���orderΪ˳���ǵ��ļ��յ�
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int fsize_init(FILE *fp,int order)
{
	long int fsize;
	switch(order)
	{
		case 1:
		{
			setfillstyle(1,RED);
			bar(605,181,631,206);
			puthz(606,182,"��",24,24,WHITE);
			fseek(fp,0L,SEEK_END);
			fsize=ftell(fp);
			fseek(fp,0L,SEEK_SET);
		}
		break;
		
		case -1:
		{
			setfillstyle(1,RED);
			bar(605,181,631,206);
			puthz(606,182,"��",24,24,WHITE);
			fseek(fp,0,SEEK_SET);
			fsize=ftell(fp);
			fseek(fp,0L,SEEK_END);
		}
		break;
		
		default:
		printf("error:illegal order");
		exit(0);
	}
	return fsize;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������info_output
������fp:�ļ�ָ��,fsize:�ļ��յ�;state����p��ģʽ�����״̬����r��ģʽ��������ɸѡ
	��u��ģʽ���û�״̬;type:��Ŀor��¼������;name:��r��ģʽ�µ��û���;allorder:����Ŀ
	���ļ��еĴ���showorder:����Ŀ�����������Ŀ�еĴ���;order:���˳��;mode:����ģʽ
����ֵ�����������Ϣ��������δͨ��ɸѡ���򷵻�1�����򷵻�0
���ܣ���ȡ�ļ���Ϣ���ж��Ƿ����
��ע��ÿ����һ�Σ��ļ�ָ��fp������order�����ƶ�fsize���ֽ�
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int info_output(FILE *fp,long int fsize,int state,int type,char *name,int *allorder,int *showorder,int order,char mode)
{
	int i,page,row;
	long int prosize;
	char leixing[7][5]={"��ͯ","����","��ƶ","����","����","����","����"};
	PRO *pro;
	PRO_STR *pro_str;
	RECORD *rec;
	RECORD_STR *rec_str;
	USER *user;
	USER_STR *user_str;
	//void *temp,*temp_str;
	switch(mode)//�����ڴ�
	{
		case 'p':
		{
			pro=(PRO*)malloc(sizeof(PRO));
			pro_str=(PRO_STR*)malloc(sizeof(PRO_STR));
			prosize=sizeof(PRO_STR);
			break;
		}
		case 'r':
		{
			rec=(RECORD*)malloc(sizeof(RECORD));
			rec_str=(RECORD_STR*)malloc(sizeof(RECORD_STR));
			prosize=sizeof(RECORD_STR);
			break;
		}
		case 'u':
		{
			user=(USER*)malloc(sizeof(USER));
			user_str=(USER_STR*)malloc(sizeof(USER_STR));
			prosize=sizeof(USER_STR);
			break;
		}
		default:
		{
			printf("mode error!!!");
			break;
		}
	}
	switch(order)//��ȡ�ļ�
	{
		case 1:
		{
			switch(mode)
			{
				case 'p':
				fread(pro_str,prosize,1,fp);//��ָ���ļ���Ϣ������ת�ṹ��,ÿ�ζ�һ��PRO�ṹ��
				*allorder+=1;
				break;
				
				case 'r':
				fread(rec_str,prosize,1,fp);//��ָ���ļ���Ϣ������ת�ṹ��,ÿ�ζ�һ��PRO�ṹ��
				*allorder+=1;
				break;
				
				case 'u':
				fread(user_str,prosize,1,fp);//��ָ���ļ���Ϣ������ת�ṹ��,ÿ�ζ�һ��PRO�ṹ��
				*allorder+=1;
				break;
				
				default:
				printf("mode error!!~");
				break;
			}
			break;	
		}
		case -1:
		{
			fseek(fp,-prosize,SEEK_CUR);//��Ҫ������Ŀ����β�ƶ�������ͷ
			switch(mode)
			{
				case 'p':
				fread(pro_str,prosize,1,fp);
				//��ָ���ļ���Ϣ������ת�ṹ��,ÿ�ζ�һ��PRO�ṹ�壬�����ָ���Ƶ�����β
				break;
				
				case 'r':
				fread(rec_str,prosize,1,fp);
				break;
				
				case 'u':
				fread(user_str,prosize,1,fp);
				break;
				
				default:
				printf("mode error!!~");
				break;
			}
			fseek(fp,-prosize,SEEK_CUR);//��λ����һ����Ŀ���ݵ�β
			*allorder+=1;
			break;
		}
		default:
			printf("order error~~~");
			break;
	}
	setfillstyle(1,RED);
	setcolor(WHITE);
	settextstyle(0,0,4);
	switch(mode)//����
	{
		case 'p':
		{
			PRO_aton(pro,pro_str);
			if(type!=7 && type!=pro->protype)//����ɸѡ,�����Ŀ���಻����������ֱ�ӽ�����һ������
			{
				free(pro);
				free(pro_str);
				return 1;//��������PRO���ݿ⣬���ͷ��ϵĲ�չʾ
			}
			if((pro->state)!=state)//������ɸѡ,���������������������ֱ�ӽ�����һ������
			{
				free(pro);
				free(pro_str);
				return 1;
			}
			row=*showorder%10;
			page=*showorder/10;
			bar(1,110+41*(row-1),279,108+41*row);//����ԭ������
			outputhz(3,110+41*(row-1)+4,295,110+41*(row-1)+4+40,pro_str->proname,WHITE);
			bar(281,110+41*(row-1),420,108+41*row);
			progress_draw(283,110+10+41*(row-1),20,pro);//���ƽ�����
			setfillstyle(1,RED);
			setcolor(WHITE);
			settextstyle(0,0,4);
			bar(422,110+41*(row-1),494,108+41*row);
			puthz(425,110+41*(row-1)+4,leixing[atoi(pro_str->protype)],32,35,WHITE);
			bar(496,110+41*(row-1),603,108+41*row);
			switch(pro->state)//�жϲ���ʾ��Ŀ�����״��
			{
				case 1:
				puthz(499,110+41*(row-1)+4,"�����",32,35,WHITE);
				break;
						
				case 0:
				puthz(499,110+41*(row-1)+4,"������",32,35,WHITE);
				break;
										
				default:
				printf("the state of procode:[%d] is error",pro->procode);
				break;
			}
			
			free(pro);
			free(pro_str);
			break;
		}
		
		case 'r':
		{
			RECORD_aton(rec,rec_str);//���ַ�����ʽ����Ϣת����������ʽ 
			if((rec->procode)==-2)
			{
				free(rec);
				free(rec_str);
				return 1;//�˼�¼�ѱ�ɾ��
			}
			if(type!=7 && type!=rec->protype)//����ɸѡ
			{
				free(rec);
				free(rec_str);
				return 1;//��������RECORD���ݿ⣬���ͷ��ϵĲ�չʾ
			}
			if(state!=1 && strcmp(name,rec->userid))//������ɸѡ 
			{
				free(rec);
				free(rec_str);
				return 1;
			}
			
			row=*showorder%10;
			page=*showorder/10;
			bar(1,110+41*(row-1),420-40,108+41*row);//����ԭ������
			outputhz(3,110+41*(row-1)+4,300,110+41*(row-1)+4+40,rec_str->proname,WHITE);	
			bar(422-40,110+41*(row-1),494-40,108+41*row);
			puthz(425-40,110+41*(row-1)+4,leixing[rec->protype],32,34,WHITE);
			bar(496-40,110+41*(row-1),603,108+41*row);
			settextstyle(0,0,3);
			outtextxy(499-38,110+41*(row-1)+8,rec_str->userid);
			if(strlen(rec_str->userid)>6)
			{
				settextstyle(0,0,2);
				bar(603-22,110+41*(row-1),603,108+41*row);
				outtextxy(603-24,110+12+41*(row-1),".");
				outtextxy(603-17,110+12+41*(row-1),".");
				outtextxy(603-10,110+12+41*(row-1),".");
			}
			free(rec);
			free(rec_str);
			break;
		}
		
		case 'u':
		{
			USER_aton(user,user_str);
			if(state==-1 && user->times>=0)//״̬ɸѡ,�����Ŀ���಻����������ֱ�ӽ�����һ������
			{
				free(user);
				free(user_str);
				return 1;
			}
			if(state==1 && user->times<0)
			{
				free(user);
				free(user_str);
				return 1;
			}
			row=*showorder%10;
			page=*showorder/10;
			bar(1,110+41*(row-1),420,108+41*row);//����ԭ������
			outtextxy(3,110+41*(row-1)+4,user_str->userid);//��ʾ������
			bar(422,110+41*(row-1),494,108+41*row);
			outtextxy(425,110+41*(row-1)+4,user_str->usercode);
			bar(496,110+41*(row-1),603,108+41*row);
			switch(state)
			{
				case 1:
				puthz(499,110+41*(row-1)+4,"����",32,35,WHITE);
				break;
							
				case -1:
				puthz(499,110+41*(row-1)+4,"���",32,35,WHITE);
				break;
							
				default:
				printf("the state of procode is error");
				break;
			}
			free(user);
			free(user_str);
			break;
		}
		
		default:
		printf("mode error");
		break;
	}
	return 0;
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������blank_draw
������order��˳��;row:��ҳ������Ϣ����;state:ģʽ
����ֵ�������еĸ���
���ܣ���һҳ�����Ϣ����󣬶�ʣ�µ�λ��ʹ�ÿհ׽������
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int blank_draw(int order,int row,int state)
{
	int i=0,j=0,time=0;
	if(state==2)
	{
		j=40;
	}
	for(i=row+1;i<10;i++)//�����ҳӦ�пհ��У��򽫿հ�������λ�õ��������
	{
		setfillstyle(1,RED);
		bar(1,110+41*(i-1),420-j,108+41*i);
		bar(422-j,110+41*(i-1),494-j,108+41*i);
		bar(496-j,110+41*(i-1),603,108+41*i);
		time+=1;
	}
	if(state==0 || state==2)
	{		
		g_2_0_0(state);//�����ұ߲˵�
	}
	else
	{
		ga_3_0(state);	
	}
	setfillstyle(1,RED);
	bar(605,181,631,206);
	switch(order)
	{
		case 1:
		puthz(606,182,"��",24,24,WHITE);
		break;
			
		case -1:
		puthz(606,182,"��",24,24,WHITE);
		break;
			
		default:
		printf("order error");
		break;
	}
	return time;
}
/*------------------------------------------------------------------
��������progress_draw
������x��y�����ƽ����������Ͻ�����
	height���������ĸ߶�
	pro����Ҫ����ٷֱȲ����ƽ���������Ŀ
����ֵ�����ȵİٷֱȣ�int�ͣ�
���ܣ����������ܺ���
��ע����x��y��height��Ϊ0ʱ����������ƽ������������ذٷֱ�
-------------------------------------------------------------------*/
int progress_draw(int x,int y,int height,PRO *pro)
{
	int i,propor;//propor:��ɵİٷֶ�
	char propor_str[7];
	long long int sumscore,nowscore,temp;//��¼���ʰ�Ȩ�ػ��ۺ��ֵ
	
	sumscore=-3*(pro->amount[0][0]);
	nowscore=-3*(pro->amount[1][0]);
	for(i=0;i<9;i++)
	{
		sumscore+=4*(pro->amount[0][i]);
		nowscore+=4*(pro->amount[1][i]);
	}
	temp=(nowscore*100)/sumscore;
	propor=(int)temp;
	if(propor==0 && nowscore!=0)//����ѵ����ʹ��٣�propor��Ϊ0������Ϊ1
	{
		propor=1;
	}
	if(x!=0 && y!=0 && height!=0)
	{
		setcolor(WHITE);
		rectangle(x,y,x+100+1,y+height+1);
		setfillstyle(1,BLUE);
		bar(x+1,y+1,x+100,y+height);
		setfillstyle(1,GREEN);
		if(propor!=0)
		{	
			bar(x+1,y+1,x+propor,y+height);
		}
		itoa(propor,propor_str,10);
		settextstyle(0,0,2);
		outtextxy(x+105+15,y+12,"%");
		if(propor==100)
		{
			settextstyle(0,0,1);
		}
		outtextxy(x+105,y-5,propor_str);
	}
	return propor;
}