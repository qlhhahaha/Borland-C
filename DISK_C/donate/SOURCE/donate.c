#include"common.h"
#include"donate.h"
#include"user.h"


/*
功能：我要捐赠功能
作者：李浩宇
最后修改：2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_2_0
参数：pagestate:页面编号
返回值：点击的项目在文件中的次序
功能：使用户可以查看所有项目，并提供排列、翻页和筛选功能
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int s_2_2_0(int *pagestate)//我要捐助页面功能函数
{
	PRO temp;
	PRO_STR temp_str;
	static int order=1,type=7,state=0;
	int row=0,page=0,showorder=0,allorder=0,i;
	long int prosize,fsize,prosite[50][10]={0},ltoi;
	FILE *fp;
	/* 
		PRO temp:中转结构体
		PRO_STR temp_s:中转结构体的字符串形式 
		order：1，顺序 -1，倒序
		type:筛选的项目类型，type=7时为全部类型
		state:筛选项目的完成情况，state=0时输出未完成项目，state=1时输出已完成项目
		row、page：一个项目在表格中显示的行数和页数
		prosite[page][row]：第page页、row行的项目在文件中的次序(从0开始)
		showorder：筛选后输出的项目的计数器
		allorder：筛选前项目的计数器
		prosize：每个项目的大小
		i:很普通的计数器
		fp:很普通的文件指针
		fsize:文件大小
	*/
	prosite[0][0]=-1;//用以判断本页是否显示了项目，若未显示则此值为-1不变，若显示了则此值被覆盖
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
	g_2_0();//绘制上方常驻菜单
	g_2_2_0();//绘制表格线
	fsize=fsize_init(fp,order);
	
	while(1)
	{
		g_2_0_0(0);//绘制右边菜单
		puthz(5,22,"非定向公共募捐",24,28,WHITE);
		switch(order)//正反序
		{
			case 1://正序
			{
				while(ftell(fp)<fsize)//逐个填充表格内容
				{
					if(info_output(fp,fsize,state,type,NULL,&allorder,&showorder,order,'p')==1)
					{
						continue;
					}
					row=showorder%10;
					page=showorder/10;
					prosite[page][row]=allorder-1;//记录显示在页面上的项目在文件中的次序（从0开始）
					showorder+=1;
					
					if(row>=9)//此页已显示完毕,停止循环并进入鼠标检测
					{
						break;
					}			
				}
				blank_draw(order,row,0);
				setcolor(BLUE);
				line(280,68,280,479);

				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(s_2_0(pagestate)==1)//上菜单栏鼠标检测
					{
						free(fp);
						fclose(fp);
						order=1;
						type=7;
						state=0;
						delay(100);
						return 0;//若点击上方菜单，则return至mainpage并跳转到其它页面
					}
					if (mouse_press(605,21,639,116)==1)//鼠标点击"上一页"按钮
					{
						delay(100);
						if(page>0)
						{
							showorder=(page-1)*10;//重定向至上一页首个项目
							ltoi=prosite[showorder/10][0];
							allorder=(int)ltoi;
							fseek(fp,prosize*allorder,SEEK_SET);
							delay(200);
							break;
						}
						if(page==0)//当前已经是第一页
						{
							showorder=0;//重定向至本页首个项目
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0,SEEK_SET);
							break;
						}
						if(page<0)
						{
							printf("error!!!!why the page<0???");//出大问题
							delay(5000);
						}
					}
					if (mouse_press(605,367,639,479)==1)//鼠标点击”下一页“按钮
					{
						delay(100);
						break;//退出鼠标循环
					}
					if (mouse_press(605,117,639,240)==1)//鼠标点击”顺序or倒序按钮“，改变排序方式
					{
						order=-1;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;//返回至mainpage，给prosite赋值0
					}
					if (mouse_press(605,241,639,366)==1)//鼠标点击”种类筛选“按钮
					{
						if(s_2_2_1(&type,&state,pagestate,0)==1)//功能模块，如果在s_2_2_1里点击了上方菜单则关闭、返回
						{
							free(fp);
							fclose(fp);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//检测是否点击到公共项目
					{
						*pagestate=222;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;
					}
					for(i=0;i<=row;i++)//检测是否点击到项目
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)//prosite:判断本页是否显示了项目
						{
							*pagestate=224;//转到项目详情页面
							free(fp);
							fclose(fp);
							delay(100);
							return prosite[page][i];
						}	
					}
				}
			}
			break;//退出switch，再重新进入switch
			//----------------------------------------------------------------------------
			case -1://倒序
			{
				while(ftell(fp)>fsize)//逐个填充表格内容
				{
					if(info_output(fp,fsize,state,type,NULL,&allorder,&showorder,order,'p')==1)
					{
						continue;
					}
					row=showorder%10;
					page=showorder/10;
					prosite[page][row]=allorder-1;//记录显示在页面上的项目在文件中的次序（从0开始）
					showorder+=1;
					
					if(row>=9)//此页已显示完毕,停止循环并进入鼠标检测
					{
						break;
					}		
				}
				blank_draw(order,row,0);
				setcolor(BLUE);
				line(280,21,280,479);

				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(s_2_0(pagestate)==1)//上菜单栏鼠标检测
					{
						free(fp);
						fclose(fp);
						order=1;
						type=7;
						state=0;
						return 0;
					}
					if (mouse_press(605,21,639,116)==1)//鼠标点击"上一页"按钮
					{
						delay(100);
						if(page>0)
						{
							showorder=(page-1)*10;//重定向至上一页首个项目
							ltoi=prosite[showorder/10][0];
							allorder=(int)ltoi;
							fseek(fp,-1*prosize*allorder,SEEK_END);
							delay(200);
							break;
						}
						if(page==0)//当前已经是第一页
						{
							showorder=0;//重定向至本页首个项目
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0L,SEEK_END);
							break;
						}
						if(page<0)
						{
							printf("error!!!!why the page<0???");//出大问题
						}
					}
					if (mouse_press(605,367,639,479)==1)//鼠标点击”下一页“按钮
					{
						delay(100);
						break;
					}
					if (mouse_press(605,117,639,240)==1)//鼠标点击”顺序or倒序按钮“，改变排序方式
					{
						order=1;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;
					}
					if (mouse_press(605,241,639,366)==1)//鼠标点击”种类筛选“按钮
					{
						delay(100);
						if(s_2_2_1(&type,&state,pagestate,0)==1)//功能模块
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//检测是否点击到公共项目
					{
						*pagestate=222;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;//return至mainpage，再进入公共页面的功能函数
					}
					for(i=0;i<=row;i++)//检测是否点击到项目
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=224;//转到项目详情页面
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
			puthz(210,210,"没有更多了。",32,34,WHITE);
			return 0;
		}
	}	
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_2_1
参数：pagestate:页面编号
返回值：如果鼠标点击了按钮则返回1
功能：我要捐助的种类筛选功能
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_2_1(int *type,int *state,int *pagestate,int who)//种类筛选功能
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
	g_2_2_1(state);//绘制种类选择页面
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(who==0 && s_2_0(pagestate)==1)//点击上方菜单都return回mainpage
		{
			return 1;
		}
		if(who==1 && sa_0(pagestate)==1)//点击上方菜单都return回mainpage
		{
			return 1;
		}
		if(mouse_press(66,90,179,150)==1)//选择儿童
		{
			*type=0;
			return 1;
		}
		if(mouse_press(245,90,358,150)==1)//选择老人
		{
			*type=1;
			return 1;
		}
		if(mouse_press(424,90,537,150)==1)//选择扶贫
		{
			*type=2;
			return 1;
		}
		if(mouse_press(66,216,179,276)==1)//选择救灾
		{
			*type=3;
			return 1;
		}
		if(mouse_press(245,216,358,276)==1)//选择抗疫
		{
			*type=4;
			return 1;
		}
		if(mouse_press(424,216,537,276)==1)//选择教育
		{
			*type=5;
			return 1;
		}
		if(mouse_press(66,342,179,402)==1)//选择环保
		{
			*type=6;
			return 1;
		}
		if(mouse_press(245,342,358,402)==1)//选择全部
		{
			*type=7;
			return 1;
		}
		if(mouse_press(424,342,537,402)==1)//改变完成情况的筛选
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
函数名：s_2_2_2
参数：pagestate:页面编号，u：用户的信息
返回值：无
功能：公共项目的种类选择
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_2(int *pagestate,USER *u)//公共项目类型选择弹窗
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
		for(i=0;i<7;i++)//鼠标点击了某个类别
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
函数名：s_2_2_3
参数：pagestate:页面编号；pubtype:进入的公共物资池的种类；u：用户的信息
返回值：如果鼠标点击了上菜单或确认，则返回1
功能：向公共项目池进行捐助
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_2_3(int *pagestate,int pubtype,USER *u)//公共项目填写
{
	char tempid[20];
	RECORD temp2;//捐助记录草稿
	RECORD_STR temp2_str;
	long int input[9]={0},stock[9]={0},judge=0;
	char stock_str[9][11];
	FILE *fp;
	int i,judge1=0;
	clrmous(MouseX, MouseY);
	g_2_0();
	g_2_2_3(pubtype);
	if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)//读取公共物品池
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,9*11*pubtype*sizeof(char),SEEK_SET);//只读取相应种类
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
		for(i=0;i<9;i++)//填入数字
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
		
		
		if (mouse_press(320,390,440,450)==1)//确认捐助，将填写的信息写入文件
		{
			for(i=0;i<9;i++)//检验是否将超出库存
			{
				stock[i]=atol(stock_str[i]);
				if(stock[i]+input[i]>=2000000000)//超出库存
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
			if(judge==0)//判断有没有捐东西
			{
				setfillstyle(1,8);
				bar(180,200,480,250);
				puthz(190,210,"咱不能啥都不捐啊",32,35,WHITE);
				delay(2000);
				*pagestate=220;
				return 1;
			}
			//确实捐了东西，进入下一步
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
				setfillstyle(1,8);//捐助完成，弹出感谢窗口，短暂延迟后回到"我要捐助"页面
				bar(180,200,450,400);
				setfillstyle(1,WHITE);
				bar(185,205,445,395);
				puthzlimit(195,215,385,"捐助失败！",24,26,4,8);
				puthzlimit(195,245,385,"捐助的物资仓库已满！",24,26,4,8);
				delay(2000);
				return 1;
			}
			judge=-3*input[0];//Judge用于计分
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
			fp=NULL;//完成对公共项目池的修改 
			
			s_2_2_5_1(u,judge);//更改个人信息中的积分与捐助次数
			achieve_change(u,7);//记录成就
			
			//写捐助记录草稿
			temp2.procode=-1;//公共项目的procode为-1
			strcpy(temp2.userid,u->userid);
			strcpy(temp2.proname,"公共物资池");
			temp2.protype=pubtype;
			for(i=0;i<9;i++)
			{
				temp2.amount[i]=input[i];
			}
			RECORD_ntoa(&temp2,&temp2_str);//草稿写好啦！
			if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,0,SEEK_END);
			fwrite(&temp2_str,sizeof(RECORD_STR),1,fp);
			fclose(fp);
			
			setfillstyle(1,8);//捐助完成，弹出感谢窗口，短暂延迟后回到"我要捐助"页面
			bar(180,200,450,400);
			setfillstyle(1,WHITE);
			bar(185,205,445,395);
			puthzlimit(195,215,385,"感谢您的善行！",24,26,4,8);
			puthzlimit(195,245,385,"好人一生平安！！！",24,26,4,8);
			if(judge1==1)
			{
				puthzlimit(195,275,385,"部分超出库存的物资将退回！",24,26,4,8);
			}
			delay(2000);
			*pagestate=220;
			return 1;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_2_4
参数：pagestate:页面编号，prosite：此项目在文件中的次序
返回值：无
功能：用户查看项目详情
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_4(int *pagestate,long int prosite)//项目详情页面
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
	g_2_2_4(&temp,&temp_str);//绘制此页面
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)
		{
			return;
		}
		if (mouse_press(10,370,70,470)==1 && temp.state==0)//点击捐助，如果此项目未完成则进入填写页面
		{
			*pagestate=225;
			return;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_2_5
参数：pagestate:页面编号，prosite：此项目在文件中的次序；u：用户的信息
返回值：无
功能：用户对项目进行捐助
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_5(int *pagestate,long int prosite,USER *u)//填写捐款数额页面
{
	long int input[9]={0},judge=0;//input:中转数组;judge:用于判断
	int i,judge1=0;
	PRO temp1;
	PRO_STR temp1_str;
	RECORD temp2;
	RECORD_STR temp2_str;
	char tempid[15];
	FILE *fp;
	if((fp=fopen("c:\\donate\\DATABASE\\PRO.dat","rb+"))==NULL)//读出pro信息
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
	g_2_2_5(&temp1,'u');//绘制页面
	delay(200);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)
		{
			return;
		}
		for(i=0;i<9;i++)//在input中填入数字
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
		
		if (mouse_press(320,390,435,440)==1)//确认捐助，将填写的信息写入文件
		{
			judge=0;
			for(i=0;i<9;i++)//将要捐出的物品数量加到临时项目副本中
			{	
				if(input[i]<=(temp1.amount[0][i]-temp1.amount[1][i]))//判断溢出
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
			
			if(judge==0)//捐出的物资全部为0
			{
				if(judge1==1)//填了东西但要捐的都已经集满了
				{
					setfillstyle(1,8);
					bar(180,200,530,250);
					puthz(190,210,"你捐的物资已经集齐啦",32,35,WHITE);
					delay(2000);
					return;
				}
				else
				{
					setfillstyle(1,8);
					bar(180,200,480,250);
					puthz(190,210,"咱不能啥都不捐啊",32,35,WHITE);
					delay(2000);
					return;
				}
			}
			judge=0;
			for(i=0;i<9;i++)//判断是否所有物资需求都已满足
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
			fwrite(&temp1_str,sizeof(PRO_STR),1,fp);//用临时项目副本覆盖原文件
			free(fp);
			fclose(fp);
			fp=NULL;
			
			temp2.procode=temp1.procode;//创建捐助记录草稿
			strcpy(temp2.userid,u->userid);
			strcpy(temp2.proname,temp1.proname);
			temp2.protype=temp1.protype;
			judge=-3*input[0];//计算积分增长量
			for(i=0;i<9;i++)
			{
				temp2.amount[i]=input[i];
				judge+=4*input[i];
			}
			RECORD_ntoa(&temp2,&temp2_str);
			//草稿写好了！
			if((fp=fopen("c:\\donate\\DATABASE\\RECORD.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,0,SEEK_END);
			fwrite(&temp2_str,sizeof(RECORD_STR),1,fp);//写入捐助记录
			free(fp);
			fclose(fp);
			
			s_2_2_5_1(u,judge);
			//向用户信息写入新的积分和捐助次数的信息
			achieve_change(u,temp1.protype);//记录成就
			setfillstyle(1,8);//捐助完成，弹出感谢窗口，短暂延迟后回到"我要捐助"页面
			bar(180,200,450,400);
			setfillstyle(1,WHITE);
			bar(185,205,445,395);
			if(judge1==1)
			{
				puthzlimit(195,215,385,"我们只收取其所需，超出项目所需部分的物资将不会收取。感谢您的善行！好人一生平安！！！",24,26,4,8);
				delay(3000);
			}
			else
			{
				puthzlimit(195,215,385,"感谢您的善行！",24,26,4,8);
				puthzlimit(195,245,385,"好人一生平安！！！",24,26,4,8);
				delay(3000);
			}
			
			*pagestate=220;
			return;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_2_5_1
参数：u：用户信息；judge:用户积分增加量
返回值：无
功能：对用户的积分、捐助次数进行修改
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_2_5_1(USER *u,long int judge)//向用户信息写入新的积分和捐助次数的信息的功能函数
{
	FILE *fp;
	USER_STR us;
	memset(&us,'\0',sizeof(USER_STR));
	if(u->score-2000000000+judge>0)//检测是否会溢出
	{
		u->score=2000000000;
	}
	(u->score)+=judge;
	if(u->times!=20000)//检测是否会溢出
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
函数名：inputnumber
参数：number：接受输入的数字信息的指针；x1、y1：输入框的位置；
	maxnum：数字最大的位数；color:输入框的颜色
返回值：无
功能：通过键盘输入数字，并实时显示输入框
备注：字体默认为白色
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void inputnumber(long int* number,int x1,int y1,int maxnum,int color)//用来储存数字的长整型量的指针，输入的xy，输入的字符限制，输入框的颜色
{
	char temp[30];
	int i=0,j;//i用于计数
	long int k;
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
		if (i < maxnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//当t不为特殊键时
			{
				if (t>=48 && t<=57)//判断输入的是否为数字
				{
					*(temp + i) = t;
					*(temp + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
					outtextxy(x1 + 8 + i * 18, y1-1,temp + i);//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(temp + i) = '\0';
					*(temp+ i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
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
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(temp + i) = '\0';
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
	*number=atol(temp);
}
