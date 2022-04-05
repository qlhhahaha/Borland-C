#include"common.h"
#include"search.h"


/*
功能：查询功能
作者：李浩宇
最后修改：2020/10/29
*/


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_4_0
参数：pagestate:页面编号;u:用户信息;who:进入此功能的模式（普通用户or管理员）
返回值：点击的记录在文件中的次序
功能：使用户可以查看所记录目，并提供排列、翻页和筛选功能
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
long int s_2_4_0(int *pagestate,USER *u,int who)//捐助记录页面功能函数
{
	RECORD temp;
	RECORD_STR temp_str; 
	static int order=1,type=7,whodoit=1;
	int row=0,page=0,showorder=0,allorder=0,i;
	FILE *fp;
	long int fsize,prosize,prosite[50][10]={0},ltoi;
	/* 
		PRO temp:中转结构体
		order：1，顺序 -1，倒序
		type:筛选的项目类型，type=7时为全部类型
		row、page：一个项目在表格中显示的行数和页数
		prosite[page][row]：第page页、row行的项目在文件中的次序(从0开始计数)
		showorder：筛选后输出的项目的计数器
		allorder：筛选前项目的计数器
		prosize：每个项目的大小
		i:很普通的计数器
		fp:很普通的文件指针
		fsize:文件大小
		whodoit:是否筛选捐助者ID的记号，若为-1则只显示当前用户的捐助记录，若为1则显示所有人的捐助记录 
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
		ga_0();//绘制管理员上方常驻菜单栏
	}
	else
	{
		g_2_0();//绘制上方常驻菜单
	}
	g_2_4_0();//绘制表格线
	fsize=fsize_init(fp,order);
	while(1)
	{
		g_2_0_0(2);//绘制右边菜单
		switch(order)//正反序
		{
			case 1://正序
			{
				while(ftell(fp)<fsize)//逐个填充表格内容
				{
					if(info_output(fp,fsize,whodoit,type,u->userid,&allorder,&showorder,order,'r')==1)
					{
						continue;
					}
					row=showorder%10;
					page=showorder/10;
					prosite[page][row]=allorder-1;//记录显示在页面上的项目在文件中的次序（从0开始）
					showorder+=1;//这里的showorder事实上已经变成了下一个项目
					
					
					if(row>=9)//此页已显示完毕,停止循环并进入鼠标检测
					{
						break;
					}			
				}
				blank_draw(order,row,2);

				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(who==0)//上菜单栏鼠标检测
					{
						if(s_2_0(pagestate)==1)
						{
							free(fp);
							fclose(fp);
							order=1;
							whodoit=1;
							type=7;
							delay(100);
							return 0;//若点击上方菜单，则return至mainpage并跳转到其它页面
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
							return 0;//若点击上方菜单，则return至mainpage并跳转到其它页面
						}
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
						if(s_2_4_1(&type,&whodoit,pagestate,who)==1)//功能模块，如果在s_2_4_1里点击了上方菜单则关闭、返回
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					for(i=0;i<=row;i++)//检测是否点击到一个记录 
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=242;//转到记录详情页面
							free(fp);
							fclose(fp);
							delay(100);
							return prosite[page][i];
						}	
					}	
				}
			}
			break;//退出switch，再重新进入switch
			
			case -1://倒序
			{
				while(ftell(fp)>fsize)//逐个填充表格内容
				{
					if(info_output(fp,fsize,whodoit,type,u->userid,&allorder,&showorder,order,'r')==1)
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
				blank_draw(order,row,2);

				while(1)//鼠标检测
				{
					newmouse(&MouseX,&MouseY,&press);
					if(who==0)//上菜单栏鼠标检测
					{
						if(s_2_0(pagestate)==1)
						{
							free(fp);
							fclose(fp);
							order=1;
							whodoit=1;
							type=7;
							delay(100);
							return 0;//若点击上方菜单，则return至mainpage并跳转到其它页面
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
							return 0;//若点击上方菜单，则return至mainpage并跳转到其它页面
						}
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
						if(s_2_4_1(&type,&whodoit,pagestate,who)==1)//功能模块，如果在s_2_4_1里点击了上方菜单则关闭、返回
						{
							free(fp);
							fclose(fp);
							delay(100);
							return 0;
						}
					}
					for(i=0;i<=row;i++)//检测是否点击到一个记录 
					{
						if (mouse_press(0,110+41*(i-1),604,110+41*i)==1 && prosite[0][0]!=-1)
						{
							*pagestate=242;//转到记录详情页面
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
			puthz(210,210,"没有更多了。",32,34,WHITE);
			return 0;
		}
	}
}	

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_4_1
参数：type:种类的筛选;whodoit:捐助者的筛选;pagestate:页面编号;who:进入的模式
返回值：若点击了按钮则返回1
功能：改变捐助记录的筛选状态
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_4_1(int *type,int *whodoit,int *pagestate,int who)//种类筛选功能
{
	clrmous(MouseX, MouseY);
	delay(300);
	cleardevice();
	if(who==1)
	{
		ga_0();//绘制管理员上方常驻菜单栏
	}
	else
	{
		g_2_0();//绘制上方常驻菜单
	}
	g_2_4_1();//绘制种类选择页面
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(who==0)//点击上方菜单都return回mainpage
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
			*whodoit=1;
			return 1;
		}
		if(mouse_press(424,342,537,402)==1)//点击捐助者筛选按钮，改变whodoit的值
		{
			*whodoit=-1;
			return 1;
		} 
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_4_2
参数：pagestate:页面编号;recordsite:此纪录在文件中的次序;who:模式
返回值：无
功能：使用户可以查看所有项目，并提供排列、翻页和筛选功能
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_4_2(int *pagestate,long int recordsite,int who)//捐助记录详情页面 
{
	RECORD temp;
	RECORD_STR temp_str;
	FILE *fp;
	cleardevice;
	//clrmous(MouseX, MouseY);
	if(who==1)
	{
		ga_0();//绘制管理员上方常驻菜单栏
	}
	else
	{
		g_2_0();//绘制上方常驻菜单
	}
	g_2_4_2(recordsite);
	if(who==1)
	{
		setfillstyle(1,WHITE);
		bar(10,370,70,470);
		puthzlimit(16,376,70,"删除",48,50,2,8);
	}
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(who==0 && s_2_0(pagestate)==1)//点击上方菜单都return回mainpage
		{
			return ;
		}
		if(who==1 && sa_0(pagestate)==1)
		{
			return ;
		}
		if (mouse_press(10,370,70,470)==1 && who==1)//点击删除
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
			
			temp.procode=-2;//标记删除
			RECORD_ntoa(&temp,&temp_str);
			fseek(fp,recordsite*sizeof(RECORD_STR),SEEK_SET);
			fwrite(&temp_str,(long int)sizeof(RECORD_STR),1,fp);
			free(fp);
			fclose(fp);
			fp=NULL;
			setfillstyle(1,BLUE);
			bar(200,150,450,200);
			puthz(210,165,"已移入回收站",32,33,WHITE);
			delay(2000);
			return ;
		}
	}
}

