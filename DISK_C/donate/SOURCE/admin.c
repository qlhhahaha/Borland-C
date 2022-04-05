#include"common.h"
#include"admin.h"

/*
功能：管理员的调度、查询和封禁功能
作者：李浩宇
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_1_2_0
参数传递：pagestate:页面编号，adm:管理员信息（账号和密码）
返回值：无
功能：管理员登录成功后的主页函数，不停循环并检测pagestate以决定进入哪一个功能
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_1_2_0(int *pagestate,ADMIN *adm)//管理员的主函数
{
	USER u;//伪用户信息，只用来装ID（ADMIN）
	long int prosite=0,recordsite=0,usersite=0;//记录项目在文件里的位置
	*pagestate=10;//登陆进入后，默认到项目信息里
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
				prosite=sa_1_0(pagestate);//项目信息表格
				break;
			}
			case 12://管理员项目详情页面
			{
				sa_1_2(pagestate,prosite);
				break;
			}
			case 13://管理员调配物资
			{
				sa_1_3(pagestate,prosite);
				break;
			}
			case 240://管理员查看捐助记录
			{
				recordsite=s_2_4_0(pagestate,&u,1);
				break;
			}
			case 242:
			{
				s_2_4_2(pagestate,recordsite,1);//捐助记录详情页面 
				break;
			}
			case 30:
			{
				usersite=sa_3_0(pagestate);//用户信息表格
				break;
			}
			case 31:
			{
				sa_3_1(pagestate,usersite);//用户信息表格
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
				s_2_8_1(pagestate);//管理员的退出函数 
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
函数名：sa_0
参数传递：pagestate:页面编码
返回值：int型，若在鼠标点击了任何一个上菜单栏中的功能，都将会返回1，若没有点击则返回0
功能：管理员的上菜单栏鼠标检测
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int sa_0(int *pagestate)//管理员的上方菜单栏
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
				*pagestate=10;//转到项目信息表格
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
				*pagestate=240;//转到捐助记录
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
				*pagestate=30;//转到用户信息表格
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
				*pagestate=281;//退出弹窗
				return 1;
			}
		}
		if (MouseX > 0 && MouseX < 639 && MouseY>21 && MouseY < 479)
		{
			MouseS = 0;
		}
		return 0;//什么都没点 
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：sa_1_0
参数：pagestate:页面编码，adm:当前管理员的信息
返回值：long int型；鼠标点击的项目在文件中的次序
功能：将项目按一定的顺序显示，提供翻页和筛选功能
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int sa_1_0(int *pagestate)//管理员物资调配页面功能函数
{
	PRO temp;
	PRO_STR temp_str;
	static int order=1,type=7,state=0;
	int row=0,page=0,showorder=0,allorder=0,i;
	long int prosize,fsize,ltoi,prosite[50][10]={0};
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
	ga_0();
	g_2_2_0();//绘制表格线
	fsize=fsize_init(fp,order);
	while(1)
	{
		g_2_0_0(0);//绘制右边菜单
		puthz(200,22,"公共物资池",24,28,WHITE);
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
					if(sa_0(pagestate)==1)//上菜单栏鼠标检测
					{
						free(fp);
						fclose(fp);
						order=1;
						type=7;
						state=0;
						return 0;//若点击上方菜单，则return至s_1_2_0并跳转到其它页面
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
							break;
						}
						if(page==0)//当前已经是第一页
						{
							showorder=0;//重定向至本页首个项目
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0,SEEK_SET);
							delay(100);
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
						return 0;//返回至s_1_2_0，给prosite赋值0
					}
					if (mouse_press(605,241,639,366)==1)//鼠标点击”种类筛选“按钮
					{
						if(s_2_2_1(&type,&state,pagestate,1)==1)//功能模块，如果在s_2_2_1里点击了上方菜单则关闭、返回
						{
							free(fp);
							fclose(fp);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//检测是否点击到公共项目
					{
						sa_1_1(pagestate);
						return 0;
					}
					for(i=0;i<=row;i++)//检测是否点击到项目
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)//prosite:判断本页是否显示了项目
						{
							*pagestate=12;//转到项目详情页面
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
				setcolor(WHITE);
				settextstyle(0,0,4);
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
				line(280,68,280,479);
				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//上菜单栏鼠标检测
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
							break;
						}
						if(page==0)//当前已经是第一页
						{
							showorder=0;//重定向至本页首个项目
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0L,SEEK_END);
							delay(100);
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
						if(s_2_2_1(&type,&state,pagestate,1)==1)//功能模块
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					if (mouse_press(0,21,604,68)==1)//检测是否点击到公共项目
					{
						sa_1_1(pagestate);
						return 0;
					}
					for(i=0;i<=row;i++)//检测是否点击到项目
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=12;//转到项目详情页面
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
			puthz(210,210,"没有更多了。",32,34,WHITE);
			return 0;
		}
	}	
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：sa_1_1
参数：pagestate:页面编码
返回值：无
功能：公共项目类型选择弹窗
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_1_1(int *pagestate)//公共项目类型选择弹窗
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
		if(sa_0(pagestate)==1)//上菜单栏鼠标检测
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
函数名：sa_1_1_1
参数：pagestate:页面编码；pubtype:要打开的公共物资池的种类
返回值：int型；如果点击了“确认”或上菜单栏则返回1
功能：管理员查看公共物资详情
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int sa_1_1_1(int *pagestate,int pubtype)//公共物资池详情
{
	clrmous(MouseX, MouseY);
	ga_0();
	ga_1_1_1(pubtype);//绘制物资信息页面 
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(sa_0(pagestate)==1)//上菜单栏鼠标检测
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
函数名：sa_1_2
参数：pagestate:页面编号；prosite:此项目在文件中的次序
返回值：无
功能：管理员项目的详情，并可进入调配页面
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_1_2(int *pagestate,long int prosite)//项目详情页面
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
	if(temp.state==0)//只有此项目未完成时才会绘制捐助按钮
	{
		bar(10,370,70,470);
		puthzlimit(16,376,70,"调配",48,50,2,8);
	}
	if(temp.state==1)
	{
		bar(10,370,70,470);
		puthzlimit(16,376,70,"删除",48,50,2,8);
	}
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(sa_0(pagestate)==1)
		{
			return;
		}
		if (mouse_press(10,370,70,470)==1 && temp.state==0)//点击捐助，如果此项目未完成则进入填写页面
		{
			*pagestate=13;
			return;
		}
		if (mouse_press(10,370,70,470)==1 && temp.state==1)//点击删除
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
			puthz(210,165,"已移入回收站",32,33,WHITE);
			delay(2000);
			return;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：sa_1_3
参数：pagestate:页面编号;prosite：此项目在文件中的次序
返回值：无
功能：管理员对项目进行调配
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_1_3(int *pagestate,long int prosite)//填写数额页面
{
	long int pubamount[9]={0},type;//记录公共项目池中物品数量 
	char pub_str[9][11];
	long int input[9]={0},judge1=0;//input:中转数组;judge1:用于判断
	int i,judge2=0;
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
	type=temp1.protype;
	if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)//读取公共物资池数量 
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
		
		if (mouse_press(320,390,570,460)==1)//确认捐助，将填写的信息写入文件
		{
			judge1=0;
			for(i=0;i<9;i++)//将要捐出的物品数量加到临时项目副本中
			{	
				if(input[i]>(temp1.amount[0][i]-temp1.amount[1][i]))//判断溢出
				{//溢出
					input[i]=temp1.amount[0][i]-temp1.amount[1][i];
				}	
				if(pubamount[i]<input[i])//查看要捐出的物资数量是否超出了库存 
				{//超出库存
					input[i]=pubamount[i];
					judge2=1;
				}
				temp1.amount[1][i]+=input[i];
				judge1+=input[i];
			}
			if(judge1==0)//捐出的物资全部为0
			{
				setfillstyle(1,8);
				bar(180,200,480,250);
				if(judge2==1)
				{
					puthz(190,210,"库存不足，无法捐出",32,35,WHITE);
				}
				else
				{
					puthz(190,210,"调配物资数目为零",32,35,WHITE);
				}
				delay(2000);
				return;
			}
			
			judge1=0;
			for(i=0;i<9;i++)//判断是否所有物资需求都已满足
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
			fwrite(&temp1_str,sizeof(PRO_STR),1,fp);//用临时项目副本覆盖原文件
			free(fp);
			fclose(fp);
			fp=NULL;
			
			temp2.procode=temp1.procode;//创建捐助记录草稿
			strcpy(temp2.userid,"ADMIN");
			strcpy(temp2.proname,temp1.proname);
			temp2.protype=temp1.protype;
			for(i=0;i<9;i++)
			{
				temp2.amount[i]=input[i];
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
			fp=NULL;
			
			for(i=0;i<9;i++)
			{
				pubamount[i]-=input[i];
				ltoa(pubamount[i],pub_str[i],10);
			}
			
			if((fp=fopen("c:\\donate\\DATABASE\\PUBLIC.dat","rb+"))==NULL)//改写公共项目池
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
			puthzlimit(195,210,385,"物资已从公共物资池调往该项目",24,26,4,8);
			if(judge2==1)
			{
				puthzlimit(195,265,385,"部分物资超出库存，将只调出现有库存数量",24,26,4,8);
				delay(1000);
			}
			delay(3000);
			*pagestate=10;
			return;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：sa_3_0
参数：pagestate:页面编号
返回值：long int型；点击的用户在文件中的次序
功能：管理员查看所有用户的函数，提供筛选和排序功能
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
		USER temp:中转结构体
		USER_STR temp_str:中转结构体的字符串形式 
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
	ga_0();//绘制上方常驻菜单
	g_2_2_0();//绘制表格线
	fsize=fsize_init(fp,order);

	while(1)
	{
		ga_3_0(state);//绘制管理员右菜单栏
		switch(order)//正反序
		{
			case 1://正序
			{
				while(ftell(fp)<fsize)//逐个填充表格内容
				{
					if(info_output(fp,fsize,state,0,NULL,&allorder,&showorder,order,'u')==1)
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
				blank_draw(order,row,state);

				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//上菜单栏鼠标检测
					{
						free(fp);
						fclose(fp);
						order=1;
						state=1;
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
							break;
						}
						if(page==0)//当前已经是第一页
						{
							showorder=0;//重定向至本页首个项目
							allorder=0;
							row=showorder%10;
							page=showorder/10;
							fseek(fp,0,SEEK_SET);
							delay(100);
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
						return 0;
					}
					if (mouse_press(605,241,639,366)==1)//鼠标点击状态筛选按钮
					{
						
						state*=-1;
						free(fp);
						fclose(fp);
						return 0;
					}
					for(i=0;i<=row;i++)//检测是否点击到用户
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)//prosite:判断本页是否显示了项目
						{
							*pagestate=31;//转到项目详情页面
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
					if(info_output(fp,fsize,state,0,NULL,&allorder,&showorder,order,'u')==1)
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
				blank_draw(order,row,state);

				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(sa_0(pagestate)==1)//上菜单栏鼠标检测
					{
						free(fp);
						fclose(fp);
						order=1;
						state=1;
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
							delay(100);
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
						state*=-1;
						free(fp);
						fclose(fp);
						return 0;
					}
					if (mouse_press(0,21,604,68)==1)//检测是否点击到公共项目
					{
						*pagestate=222;
						free(fp);
						fclose(fp);
						delay(100);
						return 0;//return至mainpage，再进入公共页面的功能函数
					}
					for(i=0;i<=row;i++)
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=31;//转到用户详情页面
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
			puthz(210,210,"没有更多了。",32,34,WHITE);
			return 0;
		}
	}	
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：sa_3_1
参数：pagestate:页面编号；usersite：此用户在文件中的次序
返回值：无
功能：管理员查看用户信息，并可进行解封和封禁
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void sa_3_1(int *pagestate,long int usersite)//用户详情
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
	ga_3_1(&temp,&temp_str);//绘制此页面
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(sa_0(pagestate)==1)
		{
			return;
		}
		if (mouse_press(10,370,70,470)==1)
		{
			if(temp.times>=0)//用户当前为正常，使其冻结
			{
				temp.times+=1;
				(temp.times)*=-1;
			}
			else//用户当前为冻结，使其解封
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
			puthz(190,210,"操作成功！！！",32,35,WHITE);
			delay(2000);
			return;
		}
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_8_1
参数：pagestate：页面编号
返回值：无
功能：管理员退出登陆的确认界面
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