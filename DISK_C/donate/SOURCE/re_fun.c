#include"common.h"
#include"re_fun.h"
#include "input.h"

/*
���ܣ���������ҳ���һЩ���ܺ���
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������lightbutton_request
�������ݣ�x,y,x1,y1,color1,color2,flag
����ֵ����
���ܣ����水ť����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_request(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(50);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	
	if(flag==1)
	{
		puthz(435,415, "����", 48,40, GREEN);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������recoverbutton_request
�������ݣ�status
����ֵ����
���ܣ����水ť�ָ�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverbutton_request(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);

	switch (status)
	{
		case 1:
			bar(150,5,570,45);
			rectangle(150,5,570,45);
			break;
		case 2:
			bar(150,50,570,90);
			rectangle(150,50,570,90);
			break;
		case 3:
			bar(465,145,630,185);
			rectangle(465,145,630,185);
			break;
		case 4:
			bar(10,200,630,400);
			rectangle(10,200,630,400);
			break;
		case 5:
			setfillstyle(1, LIGHTGRAY);
			bar(420,410,539,460);
			puthz(435,415,"����",48,40,8);
			break;
		case 6:
			bar(115,70,320,102);
			rectangle(115,70,320,102);
			break;	
		case 7:
			bar(115,142,320,174);
			rectangle(115,142,320,174);
			break;	
		case 8:
			bar(115,214,320,246);
			rectangle(115,214,320,246);
			break;
		case 9:
			bar(115,306,320,338);
			rectangle(115,306,320,338);
			break;
		case 10:
			bar(115,398,320,430);
			rectangle(115,398,320,430);
			break;
		case 11:
			bar(435,70,630,102);
			rectangle(435,70,630,102);
			break;	
		case 12:
			bar(435,142,630,174);
			rectangle(435,142,630,174);
			break;	
		case 13:
			bar(435,214,630,246);
			rectangle(435,214,630,246);
			break;
		case 14:
			bar(435,306,630,338);
			rectangle(435,306,630,338);
			break;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������read_judge
�������ݣ�status
����ֵ����
���ܣ��жϻ���״̬��������Ӧ����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void read_judge(int *count)
{
	delay(200);//������pressֵ�����������
	//count��0��1֮���л�
	if(*count == 0)
	{
		clrmous(MouseX, MouseY);
		setcolor(RED);
		line(95,425,100,435);
		line(100,435,108,422);
		*count = 1;
		return ;
	}
	else 
	{
		clrmous(MouseX, MouseY);
		setcolor(LIGHTGREEN);//ͨ����ɫ��ͬ�ķ������ù���������ʧ�ˣ�һ���������
		line(95,425,100,435);
		line(100,435,108,422);
		*count = 0;
		return ;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������request_judge
�������ݣ�int *count,char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u
����ֵ��1/0
���ܣ��жϷ��������״̬
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int request_judge(int *count,char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u)
{
	int i;
	int state = 0;//�Ƿ�����ı���
	while (1)
	{
		judge(PRONAME, &state,572,10);
		judge(PLACE, &state,572,55);
		judge(MANNAME, &state,470,130);
		judge(DES, &state,100,180);
		if (pro->protype==8)
		{
			puthz(20,140,"��ѡ�����ͣ�",16,17,RED);
		}
		if (*count==0)
		{
			puthz(100,440,"��ͬ�����",16,17,RED);
		}
		if (state == 1||*count==0||pro->protype==8)
		{
			break;
		}
		else if (state == 0 && (*count)==1 && pro->protype!=8)
		{
			request_save(PRONAME,PLACE,MANNAME,DES,pro,u);//д�����ݿ�
			return 1;//����
		}
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������request_save
�������ݣ�char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u
����ֵ��1/0
���ܣ�������Ŀ�ɹ��󱣴���Ŀ���ļ�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void request_save(char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u)
{
	FILE* fp;
	PRO_STR* pros;
	int len;
	int debug;
	
	int protype;
	long int amount[2][9];
	int i;
	
	if((fp=fopen("DATABASE\\PRO.dat","rb+"))==NULL)
	{
		printf("cannot open file PRO.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	len=ftell(fp)/sizeof(PRO_STR);//�����PRO_STR�ṹ��ĸ��������Ѵ�����Ŀ�ĸ���
	/*if ((pro=(PRO*)malloc(sizeof(PRO)))==NULL)
	{
		printf("memoryallocation runs wrong in request.c");
		delay(3000);
		exit(1);
	}*/
	if ((pros=(PRO_STR*)malloc(sizeof(PRO_STR)))==NULL)
	{
		printf("memoryallocation runs wrong in request.c");
		delay(3000);
		exit(1);
	}
	
	for (i=0;i<9;i++)
	{
		amount[0][i]=pro->amount[0][i];
		amount[1][i]=pro->amount[1][i];
	}
	protype=pro->protype;
	strcpy(pro->proname,PRONAME);
	strcpy(pro->place,PLACE);
	pro->protype=protype;
	strcpy(pro->call,u->phone);
	strcpy(pro->manname,MANNAME);
	strcpy(pro->userid,u->userid);
	pro->procode=len;
	for (i=0;i<9;i++)
	{
		pro->amount[0][i]=amount[0][i];
		pro->amount[1][i]=amount[1][i];
	}
	strcpy(pro->descri,DES);
	pro->state=0;//amount��protype������Ӧ������ֱ�Ӹ�ֵ��pro��
	PRO_ntoa(pro,pros);//��PROת��ΪPRO_STR
	debug=fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	fwrite(pros, sizeof(PRO_STR), 1, fp);//���û���Ϣд���ļ�
	if (pros != NULL || pro != NULL)
	{
		free(pros);
		pros = NULL;
		free(pro);
		pro = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_3_4
�������ݣ�char *PRONAME,char *PLACE,char *MANNAME,char *DES
����ֵ����
���ܣ�ҳ��ָ����ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_3_4(char *PRONAME,char *PLACE,char *MANNAME,char *DES)
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_3_0();
	
	/*outputinfo(PRONAME,155,10);
	outputinfo(PLACE,155,55);
	outputinfo(MANNAME,470,150);
	outputinfo_des(DES,15,205);*/
	outputhz(155,10,565,40,PRONAME,WHITE);
	outputhz(155,55,565,85,PLACE,WHITE);
	outputhz(470,150,625,180,MANNAME,WHITE);
	outputhz(15,205,625,395,DES,WHITE);
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������outputhz
�������ݣ�int x1,int y1,int x2,int y2,char *s,int color
����ֵ����
���ܣ���ʾ���ֺ��ַ�������  ֻ�ṩ16*16�ĺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputhz(int x1,int y1,int x2,int y2,char *s,int color)   //��ʾ���ֺ��ַ�������  ֻ�ṩ16*16�ĺ���
{
	FILE *hzk_p;                                       //���庺�ֿ��ļ�ָ��
	unsigned char quma,weima;                 //���庺�ֵ������λ��
	unsigned long offset;                          //���庺�����ֿ��е�ƫ����
	unsigned char mask[] = {0x180,0x140,0x120,0x110,0x108,0x104,0x102,0x101};  //�������飬������ʾ���ֵ����е�����
	int i,j,pos;			 
	char mat[32];   //16*16�ĺ�����Ҫ32���ֽڵ��������洢
	int y0=y1;
	int x0=x1;
	           
	hzk_p = fopen("./HZK/HZ16", "rb");               //ʹ�����·��
	 if(hzk_p==NULL)
	 {
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		outtextxy(10,10,"Can't open hzk16 file!Press any1 key1 to quit...");
		getch();
		exit(1);
	}
	while(*s!=NULL)
	{
		while (x1<x2 && y1<y2 && (*s!=NULL))   //�綨��Χ
		{
			/*ʶ��ո񲢴�ӡ�ո�*/
			if (*s == ' ')
			{
				x1 = x1 + 10;
				s += 1;
				continue;  //��ֹ����ո�ͬʱ����
			}

			/*ʶ���з�������*/
			if (*s == '\n')
			{
				x1 = x0;
				y0 += 10 + 5;
				s += 1;
				continue;   //��ֹ�������ͬʱ����
			}
			if (*s == '	')
			{
				x1 = x0;
				y0 += 10 + 5;
				s += 1;
				continue;   //��ֹ�������ͬʱ����
			}
			if (outputLetterNum2(*s, x1, y0,color) == 1)
			{
				x1 = x1 + 10;
				s += 1;
				continue;  //��ֹ������ֺ���ĸͬʱ����
			}

			y1=y0;
			quma=s[0]-0x1a0;                      //�������
			weima=s[1]-0x1a0;                     //���λ��
			offset=(94*(quma-1)+(weima-1))*32L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
			fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
			fread (mat,32,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ���������

			for(i=0;i<16;i++)
			{
				pos=2*i;       //16*16��������ÿһ���������ֽ�
				for(j=0;j<16;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
				{
					if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
					{
						putpixel(x1+j,y1,color);
					}
				}
				y1++;
			}
			/*������һ��������ʾ��*/
			x1+=16;        //��x1 һ��ƫ����part
			s+=2;           //�������ŵ������룬2���ֽڣ�����Ҫ��2
		}
		x1=x0;y0+=16+5; //һ�к�����ʾ���,���´���࿪ʼ������֣���y1һ��ƫ����
	}
	fclose(hzk_p);
}

int outputLetterNum2(char ch,int x,int y,int color)
{
	if (31<ch&&127>ch)
	{
		char temp[2] = { '\0','\0' };
		temp[0] = ch;
		xouttextxy(x,y,temp,color);
		return 1;
	}
	else return 0;
}