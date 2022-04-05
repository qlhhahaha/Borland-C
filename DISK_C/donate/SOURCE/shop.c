#include"common.h"
#include"shop.h"

/*
功能：管理员的调度、查询和封禁功能
作者：李浩宇
最后修改：2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_6_0
参数：pagestate:页面编号;u:用户信息
返回值：无
功能：商店货架函数
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_6_0(int *pagestate,USER *u)//商店货架函数
{
	int i;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_6_0(u);
	while(1)//鼠标检测 
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//上菜单栏鼠标检测
		{
			return;//若点击上方菜单，则return至mainpage并跳转到其它页面
		}
		for(i=0;i<9;i++)//检测是否点击到商品 
		{
			if (mouse_press(20+200*(i%3),110+110*(i/3),210+200*(i%3),210+110*(i/3))==1)
			{
				if(s_2_6_1(u,i,pagestate)==1)//商品兑换函数
				{
					return;
				}
			}
		}	
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_6_1
参数：pagestate:页面编号;u:用户信息;order:此商品的顺序
返回值：默认为1
功能：对商品进行兑换
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int s_2_6_1(USER *u,int order,int *pagestate)//商品兑换功能函数
{
	USER_STR tempuser_str;//更改后的用户信息草稿
	FILE *fp; 
	long int price[9]={100,300,600,800,500,1000,10000,40000,500000};
	memset(&tempuser_str,'\0',sizeof(USER_STR));
	clrmous(MouseX, MouseY);	
	if(u->score<price[order])//如果积分不足以兑换此商品 
	{
		g_2_6_2();//积分不足提示窗口
		delay(1234);
		return 1;
	}
	if(u->goods[order]>=200000)//检测持有量是否达到上限
	{
		g_2_6_4();
		delay(1234);
		return 1;
	}
	else //积分足够 
	{
		g_2_6_1(u,order);
	}
	delay(300);
	while(1)
	{	
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//上菜单栏鼠标检测
		{
			return 1;
		}
		
		if (mouse_press(320,300,415,352)==1)//点击“确认”按钮,进行兑换、修改用户信息文件
		{
			if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
			{
				printf("CAN`T OPEN FILE");
				delay(500);
				exit(0);
			}
			fseek(fp,(sizeof(USER_STR))*(u->usercode),SEEK_SET);//创建兑换后的用户数据信息
			u->score-=price[order];
			u->goods[order]+=1;
			USER_ntoa(u,&tempuser_str);
			fwrite(&tempuser_str,sizeof(USER_STR),1,fp);//覆盖写入数据库 
			free(fp);
			fclose(fp);
			clrmous(MouseX, MouseY);
			g_2_6_3();//提示兑换成功 
			delay(1234); 
			return 1;
		}
		if (mouse_press(440,180,460,200)==1)
		{
			delay(300);
			return 1;
		}
	}
} 




