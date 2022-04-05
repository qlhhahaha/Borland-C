#include"common.h"
#include"message.h"

/*
功能：留言板功能
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_5_0
参数传递：pagestate:页面编号
返回值：无
功能：留言页面主函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_5_0(int *pagestate)
{
	MESSAGE temp;
	int row=0,page=0,i=0,showorder=0;
	FILE *fp;
	long int mes_size,fsize;
	/* 
		MESSAGE temp:中转结构体
		row、page：一个留言在表格中显示的行数和页数
		showorder：输出的留言的计数器
		mes_size：每个留言的大小
		i:很普通的计数器
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
		while(ftell(fp)<fsize)//逐个填充表格内容
		{
			setcolor(WHITE);
			setfillstyle(1,LIGHTBLUE);
			settextstyle(0,0,2);
			row=showorder%3;
			page=showorder/3;
			fread(&temp,mes_size,1,fp);//将指定文件信息放入中转结构体,每次读一个MESSSAGE结构体
			/*fseek(fp,mes_size,SEEK_CUR);*/
			bar(1,2+120*row,639,118+120*row);//覆盖原有文字
			puthz(2,120*row+5,"留言人：",16,20,WHITE);
			puthz(2,120*row+25,"留言内容：",16,20,WHITE);
			rectangle(605,5,635,35);
			LineThick(610,10,630,30,WHITE,3,1);
			LineThick(630,10,610,30,WHITE,3,1);
			/*outtextxy(75,120*row+5,temp.name);//显示新文字
			outtextxy(2,120*row+45,temp.text);*/
			outputhz(75,120*row+5,635,120*row+45,temp.name,WHITE);
			outputhz(2,120*row+45,635,120*row+85,temp.text,WHITE);
			/*puthz(75,120*row+5,temp.name,16,20,WHITE);
			puthz(2,120*row+45,temp.text,16,20,WHITE);*/
			showorder+=1;
			if(row>=2) break;			//此页已显示完毕,停止循环并进入鼠标检测		
		}

		for(i=row+1;i<3;i++)//如果此页应有空白行，则将空白行所在位置的文字清除
		{
			setfillstyle(1,LIGHTBLUE);
			bar(1,2+120*i,639,118+120*i);
		}
				
		while(1)//鼠标检测
		{
			newmouse(&MouseX,&MouseY,&press);
			if (MouseX > 50 && MouseX < 150 && MouseY>420 && MouseY < 460)
			{
				if (mouse_press(50,420,150,460) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(50,420,150,460) == 1)//鼠标点击”上一页“按钮
				{
					MouseS = 0;
					if(page>0)
					{
						showorder=(page-1)*3;//重定向至上一页首个项目
						fseek(fp,mes_size*showorder,SEEK_SET);
						delay(200);
						break;
					}
					if(page==0)//当前已经是第一页
					{
						showorder=0;//重定向至本页首个项目
						fseek(fp,0,SEEK_SET);
						break;
					}
					if(page<0)
					{
						printf("error!!!!why the page<0???");//出大问题
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
				else if (mouse_press(490,420,590,460) == 1)//鼠标点击”下一页“按钮
				{
					delay(200);
					break;		//退出鼠标循环,由于fp一直会指向下一个结构体，所以此时再循环时会接着输出后面的留言
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
			
			if (mouse_press(605,5,635,35) == 1)//返回框点击
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
函数名：s_2_5_1
参数传递：pagestate:页面编号
返回值：无
功能：留言页面发起函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_5_1(int *pagestate)
{
	MESSAGE mes;
	int num = 0;
	int state1 = 0;       //内容输入判断参数
	int state2 = 0;
	int len[2]={0};
	char NAME[20] = { '\0' };//留言人名
	char TEXT[200]= { '\0' };//留言内容
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_5_1();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 105 && MouseX < 580 && MouseY>20 && MouseY < 60)
		{
			if (mouse_press(105,20,580,60) == 2)//姓名框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_message(105,20,580,60, LIGHTCYAN, LIGHTGRAY, 0);
					num = 1;
				}
				continue;
			}
			else if (mouse_press(105,20,580,60) == 1)//姓名框点击
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
			if (mouse_press(20,125,620,400) == 2)//留言框未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)//防止被重复标亮
				{
					lightbutton_message(20,125,620,400, LIGHTCYAN, LIGHTGRAY, 0);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(20,125,635,400) == 1)//留言框点击
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
			if (mouse_press(270,420,370,470) == 2)					//未点击确认框
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
				if ((message_judge(NAME,TEXT))==1)//成功发起留言则返回1
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
		
		if (mouse_press(605,5,635,35) == 1)//返回框点击
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
函数名：message_judge
参数传递：char *NAME,char *TEXT
返回值：无
功能：留言发起鲁棒函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int message_judge(char *NAME,char *TEXT)
{
	int i;
	int state = 0;//是否输入的变量
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
			message_make(NAME,TEXT);//写入数据库
			puthz(280,410, "留言成功", 16, 20, RED);
			delay(1000);
			return 1;//返回
		}
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：message_make
参数传递：char *NAME,char *TEXT
返回值：无
功能：留言发起保存至文件
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
	fseek(fp, 0L, SEEK_END);//跳转至文件末尾
	fwrite(mes, sizeof(MESSAGE), 1, fp);//把用户信息写入文件
	
	debug=fseek(fp, 0L, SEEK_END);//跳转至文件末尾
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
函数名：lightbutton_message
参数传递：int x, int y, int x1, int y1, int color1, int color2, int flag
返回值：无
功能：留言页面点亮函数
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_message(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	
	if(flag==1)
	{
		puthz(275,425, "确认", 48,40, BLACK);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：recoverbutton_message
参数传递：int status
返回值：无
功能：留言页面恢复函数
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
			puthz(275,425,"确认",48,40,BLACK);
			break;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：inputadmin_new
参数传递：char* id, int x1, int y1, int charnum, int color
返回值：无
功能：信息输入函数，可以打空格
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputadmin_new(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int i = 0;//i用于计数
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);//画光标线
	while (1)
	{
		t = bioskey(0); //用t记录键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != 033)//当t不为特殊键时
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标  
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：inputadmin_des
参数传递：char* id, int x1, int y1, int charnum, int color
返回值：无
功能：详情等长信息的输入函数，可以实现换行功能
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputadmin_des(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int i = 0,k=0,line_num= 0,count=0,high=40,back=0;//i用于每行里计数,line_num是行数,count用于总的计数,back用于在光标处于末尾时，检测是否是从下一行退回来的
	int ii[10]={0};//数组用于记录每行末尾的横坐标
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式
	line(x1+10,y1+6,x1+10,y1+20);//画光标线
	while (1)
	{
		t = bioskey(0); //用t记录键值
		if (count < charnum)
		{
			if (t!= '\n'
				&& t!= '\r'
				&& t!= 033)//当t不为特殊键时
			{
				if (t != '\b')
				{
					if((x1+8+i*18)>610)//放在if (t != '\b')内部的前面，这样才会在敲下键盘之后判断是否超出(以维持删除后退回到行尾的状态)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high);
						line_num += 1;
						ii[k]=i;//把该行最右边的i（光标处）记录到数组中
						k++;
						i=0;
					}		
					*(id+count) = t;
					*(id+count+1) = '\0';
					bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //遮盖光标
					outtextxy(x1+8+i*18,y1-1+line_num*high,id+count);//输出t字符(16)
					i++;
					count++;
					line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
				}
				else if (t=='\b'&&count>0)//退格键
				{
					if(i==0 && line_num>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //遮盖光标
						line_num--;
						
						i=ii[k-1];
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
					}
					
					if(i>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //遮盖光标
						bar(x1-10+i*18,y1+3+line_num*high,x1+7+i*18,y1+24+line_num*high);//遮盖文字
						i--;//减少一个字数
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
				bar(x1+8+i*18,y1+3+line_num*high, x1+12+i*18,y1+24+line_num*high);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != 033)//Esc
			{
				if (t=='\b'&&count>0)//退格键
				{
					if(i==0 && line_num>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); //遮盖光标
						line_num=line_num-1;
						i=ii[k-1];
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
					}
					
					if(i>0)
					{
						bar(x1+8+i*18,y1+3+line_num*high,x1+12+i*18,y1+24+line_num*high); 
						bar(x1-10+i*18,y1+3+line_num*high,x1+7+i*18,y1+24+line_num*high);//遮盖文字
						i--;//减少一个字数
						line(x1+10+i*18,y1+6+line_num*high,x1+10+i*18,y1+20+line_num*high);
						*(id+count) = '\0';
						*(id+count+1) = '\0';
					}
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1+8+i*18,y1+3+line_num*high, x1+12+i*18,y1+24+line_num*high);//遮盖光标 
				break;
			}
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：outputinfo
参数传递：char* id, int x1, int y1
返回值：无
功能：恢复页面时将已保存的信息进行输出
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputinfo(char* id, int x1, int y1)
{
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式
	/*outtextxy(x1+8,y1-1,id);*/
	puthz(x1,y1+15,id,16,20,8);
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：outputinfo_des
参数传递：char* des, int x1, int y1
返回值：无
功能：恢复页面时将已保存的留言、详情等长信息进行输出，可换行
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputinfo_des(char* des, int x1, int y1)
{
	int i=0,j=0,k=0,count=0;//i用于计数
	char des_small_1[41]={'0'};
	char des_small_2[41]={'0'};
	char des_small_3[41]={'0'};
	char des_small_4[41]={'0'};// 不能用数组，因为连续空间不能实现outtextxy的分行输出
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式

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
函数名：outputinfo_pro_des
参数传递：char* des, int x1, int y1
返回值：无
功能：项目详情将已保存的详情长信息进行输出，可换行
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputinfo_pro_des(char* des, int x1, int y1)
{
	int i=0,j=0,k=0,count=0;//i用于计数
	char des_small_1[41]={'0'};
	char des_small_2[41]={'0'};
	char des_small_3[41]={'0'};
	char des_small_4[41]={'0'};// 不能用数组，因为连续空间不能实现outtextxy的分行输出
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式

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