#include"common.h"
#include"message.h"

/*
���ܣ����԰幦��
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_5_0
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ�����ҳ��������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_5_0(int *pagestate)
{
	MESSAGE temp;
	int row=0,page=0,i=0,showorder=0;
	FILE *fp;
	long int mes_size,fsize;
	/* 
		MESSAGE temp:��ת�ṹ��
		row��page��һ�������ڱ������ʾ��������ҳ��
		showorder����������Եļ�����
		mes_size��ÿ�����ԵĴ�С
		i:����ͨ�ļ�����
	*/
	mes_size=sizeof(MESSAGE);
	fp=NULL;
	if((fp=fopen("c:\\donate\\DATABASE\\MESSAGE.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_5_0();
	fseek(fp,0L,SEEK_END);
	fsize=ftell(fp);
	fseek(fp,0L,SEEK_SET);
			
	while(1)
	{
		while(ftell(fp)<fsize)//������������
		{
			setcolor(WHITE);
			setfillstyle(1,LIGHTBLUE);
			settextstyle(0,0,2);
			row=showorder%3;
			page=showorder/3;
			fread(&temp,mes_size,1,fp);//��ָ���ļ���Ϣ������ת�ṹ��,ÿ�ζ�һ��MESSSAGE�ṹ��
			/*fseek(fp,mes_size,SEEK_CUR);*/
			bar(1,2+120*row,639,118+120*row);//����ԭ������
			puthz(2,120*row+5,"�����ˣ�",16,20,WHITE);
			puthz(2,120*row+25,"�������ݣ�",16,20,WHITE);
			rectangle(605,5,635,35);
			LineThick(610,10,630,30,WHITE,3,1);
			LineThick(630,10,610,30,WHITE,3,1);
			/*outtextxy(75,120*row+5,temp.name);//��ʾ������
			outtextxy(2,120*row+45,temp.text);*/
			outputhz(75,120*row+5,635,120*row+45,temp.name,WHITE);
			outputhz(2,120*row+45,635,120*row+85,temp.text,WHITE);
			/*puthz(75,120*row+5,temp.name,16,20,WHITE);
			puthz(2,120*row+45,temp.text,16,20,WHITE);*/
			showorder+=1;
			if(row>=2) break;			//��ҳ����ʾ���,ֹͣѭ�������������		
		}

		for(i=row+1;i<3;i++)//�����ҳӦ�пհ��У��򽫿հ�������λ�õ��������
		{
			setfillstyle(1,LIGHTBLUE);
			bar(1,2+120*i,639,118+120*i);
		}
				
		while(1)//�����
		{
			newmouse(&MouseX,&MouseY,&press);
			if (MouseX > 50 && MouseX < 150 && MouseY>420 && MouseY < 460)
			{
				if (mouse_press(50,420,150,460) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(50,420,150,460) == 1)//���������һҳ����ť
				{
					MouseS = 0;
					if(page>0)
					{
						showorder=(page-1)*3;//�ض�������һҳ�׸���Ŀ
						fseek(fp,mes_size*showorder,SEEK_SET);
						delay(200);
						break;
					}
					if(page==0)//��ǰ�Ѿ��ǵ�һҳ
					{
						showorder=0;//�ض�������ҳ�׸���Ŀ
						fseek(fp,0,SEEK_SET);
						break;
					}
					if(page<0)
					{
						printf("error!!!!why the page<0???");//��������
					}
				}
			}
			
			if (MouseX > 490 && MouseX < 590 && MouseY>420 && MouseY < 460)
			{
				if (mouse_press(490,420,590,460) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(490,420,590,460) == 1)//���������һҳ����ť
				{
					delay(200);
					break;		//�˳����ѭ��,����fpһֱ��ָ����һ���ṹ�壬���Դ�ʱ��ѭ��ʱ�����������������
				}
			}
			
			if (MouseX > 260 && MouseX < 390 && MouseY>420 && MouseY < 460)
			{
				if (mouse_press(260,420,390,460) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(260,420,390,460) == 1)
				{
					MouseS = 0;
					s_2_5_1(pagestate);
					free(fp);
					fclose(fp);
					return ;
				}
			}
			
			if (mouse_press(605,5,635,35) == 1)//���ؿ���
			{
				MouseS = 0;
				*pagestate = 21;
				delay(500);
				cleardevice();
				return;
			}
			
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_5_1
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ�����ҳ�淢����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_5_1(int *pagestate)
{
	MESSAGE mes;
	int num = 0;
	int state1 = 0;       //���������жϲ���
	int state2 = 0;
	int len[2]={0};
	char NAME[20] = { '\0' };//��������
	char TEXT[200]= { '\0' };//��������
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_5_1();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 105 && MouseX < 580 && MouseY>20 && MouseY < 60)
		{
			if (mouse_press(105,20,580,60) == 2)//������δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_message(105,20,580,60, LIGHTCYAN, LIGHTGRAY, 0);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(105,20,580,60) == 1)//��������
			{
				MouseS = 0;
				lightbutton_message(105,20,580,60, LIGHTCYAN, LIGHTGRAY, 0);
				NAME[0] = '\0';
				/*inputadmin_new(NAME,110,25,20,LIGHTGRAY);*/
				len[0]=0;
				len[0]=hz_input(110,25,575,55,NAME,len[0]);
				if(strlen(NAME) != 0)
					state1 = 1;	
				else 
					state1 = 0;
				continue;
			}
		}
		
		if (MouseX > 20 && MouseX < 620 && MouseY>125 && MouseY < 400)
		{
			if (mouse_press(20,125,620,400) == 2)//���Կ�δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)//��ֹ���ظ�����
				{
					lightbutton_message(20,125,620,400, LIGHTCYAN, LIGHTGRAY, 0);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(20,125,635,400) == 1)//���Կ���
			{
				MouseS = 0;
				lightbutton_message(20,125,635,400, LIGHTCYAN, LIGHTGRAY, 0);
				TEXT[0] = '\0';
				/*inputadmin_des(TEXT,25,130,100,LIGHTGRAY);*/
				len[1]=0;
				len[1]=hz_input(25,130,630,395,TEXT,len[1]);
				if(strlen(TEXT) != 0)
					state2 = 1;	
				else 
					state2 = 0;
				continue;
			}
		}
		
		if (MouseX > 270 && MouseX < 370 && MouseY>420 && MouseY < 470)
		{
			if (mouse_press(270,420,370,470) == 2)					//δ���ȷ�Ͽ�
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_message(270,420,370,470, LIGHTCYAN, LIGHTGRAY, 1);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(270,420,370,470) == 1)
			{
				MouseS = 0;
				if ((message_judge(NAME,TEXT))==1)//�ɹ����������򷵻�1
				{
					cleardevice();
					g_2_5_2();
					delay(3000);
					*pagestate =250;
					return;
				}
				else
				{
					continue;
				}
			}
		}
		
		if (mouse_press(605,5,635,35) == 1)//���ؿ���
			{
				MouseS = 0;
				*pagestate = 250;
				delay(500);
				cleardevice();
				return;
			}
		
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_message(1);
			}
			if (state2 == 0)
			{
				recoverbutton_message(2);
			}
			if (num == 3)
			{
				recoverbutton_message(3);
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
��������message_judge
�������ݣ�char *NAME,char *TEXT
����ֵ����
���ܣ����Է���³������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int message_judge(char *NAME,char *TEXT)
{
	int i;
	int state = 0;//�Ƿ�����ı���
	while (1)
	{
		judge(NAME, &state,510,30);
		judge(TEXT, &state,90,90);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			message_make(NAME,TEXT);//д�����ݿ�
			puthz(280,410, "���Գɹ�", 16, 20, RED);
			delay(1000);
			return 1;//����
		}
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������message_make
�������ݣ�char *NAME,char *TEXT
����ֵ����
���ܣ����Է��𱣴����ļ�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void message_make(char* NAME,char* TEXT)
{
	FILE* fp;
	MESSAGE *mes;
	int len,debug;
	if((fp=fopen("DATABASE\\MESSAGE.dat","rb+"))==NULL)
	{
		printf("cannot open file MESSAGE.dat");
		delay(3000);
		exit(1);
	}
	if ((mes=(MESSAGE*)malloc(sizeof(MESSAGE)))==NULL)
	{
		printf("memoryallocation runs wrong in message.c");
		delay(3000);
		exit(1);
	}
	memset(mes,'\0',sizeof(MESSAGE));
	strcpy(mes->name,NAME);
	strcpy(mes->text,TEXT);
	fseek(fp, 0L, SEEK_END);//��ת���ļ�ĩβ
	fwrite(mes, sizeof(MESSAGE), 1, fp);//���û���Ϣд���ļ�
	
	debug=fseek(fp, 0L, SEEK_END);//��ת���ļ�ĩβ
	len=(ftell(fp)/sizeof(MESSAGE));
	/*if(len==0)
	{
		printf("this fucking message is gross");
		delay(3000);
		exit(1);
	}*/
	
	if (mes != NULL)
	{
		free(mes);
		mes = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������lightbutton_message
�������ݣ�int x, int y, int x1, int y1, int color1, int color2, int flag
����ֵ����
���ܣ�����ҳ���������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_message(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
		puthz(275,425, "ȷ��", 48,40, BLACK);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������recoverbutton_message
�������ݣ�int status
����ֵ����
���ܣ�����ҳ��ָ�����
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void recoverbutton_message(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);

	switch (status)
	{
		case 1:
			bar(105,20,580,60);
			rectangle(105,20,580,60);
			break;
			
		case 2:
			bar(20,125,635,400);
			rectangle(20,125,635,400);
			break;
			
		case 3:
			setfillstyle(1, LIGHTGRAY);
			bar(270,420,370,470);
			puthz(275,425,"ȷ��",48,40,BLACK);
			break;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������inputadmin_new
�������ݣ�char* id, int x1, int y1, int charnum, int color
����ֵ����
���ܣ���Ϣ���뺯�������Դ�ո�
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputadmin_new(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
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
��������inputadmin_des
�������ݣ�char* id, int x1, int y1, int charnum, int color
����ֵ����
���ܣ�����ȳ���Ϣ�����뺯��������ʵ�ֻ��й���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputadmin_des(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{
	int i = 0,k=0,line_num= 0,count=0,high=40,back=0;//i����ÿ�������,line_num������,count�����ܵļ���,back�����ڹ�괦��ĩβʱ������Ƿ��Ǵ���һ���˻�����
	int ii[10]={0};//�������ڼ�¼ÿ��ĩβ�ĺ�����
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//����ˮƽ����ʹ�ֱ������ı����뷽ʽ
	line(x1+10,y1+6,x1+10,y1+20);//�������
	while (1)
	{
		t = bioskey(0); //��t��¼��ֵ
		if (count < charnum)
		{
			if (t!= '\n'
				&& t!= '\r'
				&& t!= 033)//��t��Ϊ�����ʱ
			{
				if (t != '\b')
				{
					if((x1+8+i*18)>610)//����if (t != '\b')�ڲ���ǰ�棬�����Ż������¼���֮���ж��Ƿ񳬳�(��ά��ɾ�����˻ص���β��״̬)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high);
						line_num += 1;
						ii[k]=i;//�Ѹ������ұߵ�i����괦����¼��������
						k++;
						i=0;
					}		
					*(id+count) = t;
					*(id+count+1) = '\0';
					bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //�ڸǹ��
					outtextxy(x1+8+i*18,y1-1+line_num*high,id+count);//���t�ַ�(16)
					i++;
					count++;
					line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
				}
				else if (t=='\b'&&count>0)//�˸��
				{
					if(i==0 && line_num>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //�ڸǹ��
						line_num--;
						
						i=ii[k-1];
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
					}
					
					if(i>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //�ڸǹ��
						bar(x1-10+i*18,y1+3+line_num*high,x1+7+i*18,y1+24+line_num*high);//�ڸ�����
						i--;//����һ������
						count--;
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
						*(id+count) = '\0';
						*(id+count+1) = '\0';
					}
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1+8+i*18,y1+3+line_num*high, x1+12+i*18,y1+24+line_num*high);//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != 033)//Esc
			{
				if (t=='\b'&&count>0)//�˸��
				{
					if(i==0 && line_num>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //�ڸǹ��
						line_num=line_num-1;
						i=ii[k-1];
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
					}
					
					if(i>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); 
						bar(x1-10+i*18,y1+3+line_num*high,x1+7+i*18,y1+24+line_num*high);//�ڸ�����
						i--;//����һ������
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
						*(id+count) = '\0';
						*(id+count+1) = '\0';
					}
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1+8+i*18,y1+3+line_num*high, x1+12+i*18,y1+24+line_num*high);//�ڸǹ�� 
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������outputinfo
�������ݣ�char* id, int x1, int y1
����ֵ����
���ܣ��ָ�ҳ��ʱ���ѱ������Ϣ�������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputinfo(char* id, int x1, int y1)
{
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//����ˮƽ����ʹ�ֱ������ı����뷽ʽ
	/*outtextxy(x1+8,y1-1,id);*/
	puthz(x1,y1+15,id,16,20,8);
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������outputinfo_des
�������ݣ�char* des, int x1, int y1
����ֵ����
���ܣ��ָ�ҳ��ʱ���ѱ�������ԡ�����ȳ���Ϣ����������ɻ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputinfo_des(char* des, int x1, int y1)
{
	int i=0,j=0,k=0,count=0;//i���ڼ���
	char des_small_1[41]={'0'};
	char des_small_2[41]={'0'};
	char des_small_3[41]={'0'};
	char des_small_4[41]={'0'};// ���������飬��Ϊ�����ռ䲻��ʵ��outtextxy�ķ������
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	settextjustify(LEFT_TEXT, TOP_TEXT);//����ˮƽ����ʹ�ֱ������ı����뷽ʽ

	strncpy(des_small_1,des,40);
	strncpy(des_small_2,des+40,40);
	strncpy(des_small_3,des+80,40);
	strncpy(des_small_4,des+120,40);
	if(des_small_1[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*0,des_small_1);*/
		puthz(x1+8,y1-1+30*0,des_small_1,16,20,8);
	}
	if(des_small_2[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*1,des_small_2);*/
		puthz(x1+8,y1-1+30*1,des_small_2,16,20,8);
	}
	if(des_small_3[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*2,des_small_3);*/
		puthz(x1+8,y1-1+30*2,des_small_3,16,20,8);
	}
	if(des_small_4[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*3,des_small_3);*/
		puthz(x1+8,y1-1+30*3,des_small_3,16,20,8);
	}
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������outputinfo_pro_des
�������ݣ�char* des, int x1, int y1
����ֵ����
���ܣ���Ŀ���齫�ѱ�������鳤��Ϣ����������ɻ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputinfo_pro_des(char* des, int x1, int y1)
{
	int i=0,j=0,k=0,count=0;//i���ڼ���
	char des_small_1[41]={'0'};
	char des_small_2[41]={'0'};
	char des_small_3[41]={'0'};
	char des_small_4[41]={'0'};// ���������飬��Ϊ�����ռ䲻��ʵ��outtextxy�ķ������
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);//����ˮƽ����ʹ�ֱ������ı����뷽ʽ

	for(i=0;i<20;i++)
	{
		des_small_1[i]=des[count++];
		if(des[count-1] == NULL)
		{
			count--;
			break;
		}	
	}
	
	for(i=0;i<20;i++)
	{
		if(des[count] == NULL)
		{
			break;
		}
		des_small_2[i]=des[count++];		
	}
	
	for(i=0;i<20;i++)
	{
		if(des[count] == NULL)
		{
			break;
		}	
		des_small_3[i]=des[count++];
	}
	
	for(i=0;i<20;i++)
	{
		if(des[count] == NULL)
		{
			break;
		}
		des_small_4[i]=des[count++];		
	}
		
	if(des_small_1[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*0,des_small_1);*/
		puthz(x1+8,y1-1+15*0,des_small_1,16,20,8);
	}
	if(des_small_2[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*1,des_small_2);*/
		puthz(x1+8,y1-1+15*1,des_small_2,16,20,8);
	}
	if(des_small_3[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*2,des_small_3);*/
		puthz(x1+8,y1-1+15*2,des_small_3,16,20,8);
	}
	if(des_small_4[0] != NULL)
	{
		/*outtextxy(x1+8,y1-1+30*3,des_small_3);*/
		puthz(x1+8,y1-1+15*3,des_small_3,16,20,8);
	}
	return;
}