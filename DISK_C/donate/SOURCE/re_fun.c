#include"common.h"
#include"re_fun.h"
#include "input.h"

/*
功能：发起请求页面的一些功能函数
作者：钱力晖
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：lightbutton_request
参数传递：x,y,x1,y1,color1,color2,flag
返回值：无
功能：界面按钮点亮
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void lightbutton_request(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(50);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	
	if(flag==1)
	{
		puthz(435,415, "发起", 48,40, GREEN);
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：recoverbutton_request
参数传递：status
返回值：无
功能：界面按钮恢复
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
			puthz(435,415,"发起",48,40,8);
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
函数名：read_judge
参数传递：status
返回值：无
功能：判断画勾状态并作出相应绘制
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void read_judge(int *count)
{
	delay(200);//解决鼠标press值不清楚的问题
	//count在0和1之间切换
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
		setcolor(LIGHTGREEN);//通过颜色相同的方法，让勾看起来消失了，一手瞒天过海
		line(95,425,100,435);
		line(100,435,108,422);
		*count = 0;
		return ;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：request_judge
参数传递：int *count,char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u
返回值：1/0
功能：判断发起请求的状态
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int request_judge(int *count,char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u)
{
	int i;
	int state = 0;//是否输入的变量
	while (1)
	{
		judge(PRONAME, &state,572,10);
		judge(PLACE, &state,572,55);
		judge(MANNAME, &state,470,130);
		judge(DES, &state,100,180);
		if (pro->protype==8)
		{
			puthz(20,140,"请选择类型！",16,17,RED);
		}
		if (*count==0)
		{
			puthz(100,440,"请同意条款！",16,17,RED);
		}
		if (state == 1||*count==0||pro->protype==8)
		{
			break;
		}
		else if (state == 0 && (*count)==1 && pro->protype!=8)
		{
			request_save(PRONAME,PLACE,MANNAME,DES,pro,u);//写入数据库
			return 1;//返回
		}
	}
	return 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：request_save
参数传递：char *PRONAME,char *PLACE,char *MANNAME,char *DES,PRO *pro,USER *u
返回值：1/0
功能：发起项目成功后保存项目到文件
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
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	len=ftell(fp)/sizeof(PRO_STR);//计算出PRO_STR结构体的个数，即已存在项目的个数
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
	pro->state=0;//amount和protype都在相应函数中直接赋值给pro了
	PRO_ntoa(pro,pros);//将PRO转化为PRO_STR
	debug=fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(pros, sizeof(PRO_STR), 1, fp);//把用户信息写入文件
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
函数名：s_2_3_4
参数传递：char *PRONAME,char *PLACE,char *MANNAME,char *DES
返回值：无
功能：页面恢复功能函数
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
函数名：outputhz
参数传递：int x1,int y1,int x2,int y2,char *s,int color
返回值：无
功能：显示汉字和字符并换行  只提供16*16的汉字
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void outputhz(int x1,int y1,int x2,int y2,char *s,int color)   //显示汉字和字符并换行  只提供16*16的汉字
{
	FILE *hzk_p;                                       //定义汉字库文件指针
	unsigned char quma,weima;                 //定义汉字的区码和位码
	unsigned long offset;                          //定义汉字在字库中的偏移量
	unsigned char mask[] = {0x180,0x140,0x120,0x110,0x108,0x104,0x102,0x101};  //功能数组，用于显示汉字点阵中的亮点
	int i,j,pos;			 
	char mat[32];   //16*16的汉字需要32个字节的数组来存储
	int y0=y1;
	int x0=x1;
	           
	hzk_p = fopen("./HZK/HZ16", "rb");               //使用相对路径
	 if(hzk_p==NULL)
	 {
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open hzk16 file!Press any1 key1 to quit...");
		getch();
		exit(1);
	}
	while(*s!=NULL)
	{
		while (x1<x2 && y1<y2 && (*s!=NULL))   //界定范围
		{
			/*识别空格并打印空格*/
			if (*s == ' ')
			{
				x1 = x1 + 10;
				s += 1;
				continue;  //防止多个空格同时出现
			}

			/*识别换行符并换行*/
			if (*s == '\n')
			{
				x1 = x0;
				y0 += 10 + 5;
				s += 1;
				continue;   //防止多个换行同时出现
			}
			if (*s == '	')
			{
				x1 = x0;
				y0 += 10 + 5;
				s += 1;
				continue;   //防止多个换行同时出现
			}
			if (outputLetterNum2(*s, x1, y0,color) == 1)
			{
				x1 = x1 + 10;
				s += 1;
				continue;  //防止多个数字和字母同时出现
			}

			y1=y0;
			quma=s[0]-0x1a0;                      //求出区码
			weima=s[1]-0x1a0;                     //求出位码
			offset=(94*(quma-1)+(weima-1))*32L;   //求出要显示的汉字在字库文件中的偏移
			fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
			fread (mat,32,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

			for(i=0;i<16;i++)
			{
				pos=2*i;       //16*16矩阵中有每一行有两外字节
				for(j=0;j<16;j++)    //一行一行地扫描，将位上为了1的点显示出来
				{
					if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
					{
						putpixel(x1+j,y1,color);
					}
				}
				y1++;
			}
			/*以上是一个汉字显示完*/
			x1+=16;        //给x1 一个偏移量part
			s+=2;           //汉字里存放的是内码，2个字节，所以要加2
		}
		x1=x0;y0+=16+5; //一行汉字显示完后,重新从左侧开始输出汉字，给y1一个偏移量
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