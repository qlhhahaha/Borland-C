#include"common.h"
#include"user.h"


/*
功能：用户个人信息
作者：李浩宇
最后修改：2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_7_0
参数：pagestate:页面编号;u:用户信息
返回值：无
功能：显示个人信息页面
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_7_0(int *pagestate,USER *u)
{
	int i;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_7_0(u);
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//将pagestate作为地址传入s_2_0，如果点击了上方菜单则s_2_0返回1 
		{
			return;
		}
		
		if (MouseX > 450 && MouseX < 580 && MouseY>40 && MouseY < 80)
		{
			if (mouse_press(450,40,580,80) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(450,40,580,80) == 1)
			{
				MouseS = 0;
				*pagestate=280;
				break;
			}
		}
		
		for(i=0;i<12;i++)
		{
			if (MouseX > 50+200*(i%3) && MouseX < 190+200*(i%3) && MouseY>260+50*(i/3) && MouseY < 300+50*(i/3))
			{
				if (mouse_press(50+200*(i%3),260+50*(i/3),190+200*(i%3),300+50*(i/3)) == 2)
				{
					MouseS = 1;
					continue;
				}
				else if (mouse_press(50+200*(i%3),260+50*(i/3),190+200*(i%3),300+50*(i/3)) == 1)
				{
					MouseS = 0;
					s_2_7_1(pagestate,i,u->achi);//打开成就详情
					return;;
				}
			}
		}
		
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
} 

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：s_2_7_1
参数：pagestate:页面编号;type:此成就的编号;achi:用户的成就信息
返回值：无
功能：显示一个成就的详情
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_7_1(int *pagestate,int type,int achi)
{
	int i,judge=1;
	clrmous(MouseX, MouseY);
	for(i=0;i<type;i++)
	{
		judge*=2;
	}
	if((achi/judge)%2==0)//用户未完成此成就
	{
		g_2_7_1(12);
	}
	else
	{
		g_2_7_1(type);
	}
	delay(100);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//将pagestate作为地址传入s_2_0，如果点击了上方菜单则s_2_0返回1 
		{
			return;
		}
		if (MouseX > 460 && MouseX < 480 && MouseY>200 && MouseY < 220)
		{
			if (mouse_press(460,200,480,220) == 2)
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(460,200,480,220) == 1)
			{
				MouseS = 0;
				return;
			}
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：achieve_change
参数：u:用户信息；type:类型
返回值：无
功能：对用户的成就状态进行判断，若用户满足要求则赋予对应成就
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void achieve_change(USER *u,int type)//type:当前项目的类型，从0开始计数，公共项目为7，发起请求为8
{
	FILE *fp;
	USER_STR u_str;
	/*
	1初出茅庐/1：加在发起捐助成功后
	第一次发起捐助请求
	2慷慨解囊/2：加在进行捐助城功并改写USER后
	第一次进行捐助
	3好事成双/4：同上
	累计捐助两次
	4慈悲为怀/8：同上
	累计捐助十次
	5活佛再世/16：同上
	累计捐助五十次
	6至德天尊/32：同上
	累计捐助一百次
	7仓鼠飞轮/64：同上
	积分积累超过10000000
	8大爱无疆/128：同上
	对抗疫or救灾项目进行捐助
	9亚圣之风/256：同上
	对老人or儿童项目进行捐助
	10森林妖精/512：同上
	对环保项目及进行捐助
	11携手并进/1024：同上
	对扶贫or教育项目进行捐助
	12选择恐惧/2048：同上
	对公共项目进行捐助
	*/
	
	if(type==8 && (u->achi/1)%2==0)
	{
		u->achi+=1;
	}
	if((u->achi/2)%2==0 && u->times>=1)//用户没有完成成就但已经达到成就的要求
	{
		u->achi+=2;
	}
	if((u->achi/4)%2==0 && u->times>=2)
	{
		u->achi+=4;
	}
	if((u->achi/8)%2==0 && u->times>=10)
	{
		u->achi+=8;
	}
	if((u->achi/16)%2==0 && u->times>=50)
	{
		u->achi+=16;
	}
	if((u->achi/32)%2==0 && u->times>=100)
	{
		u->achi+=32;
	}
	if((u->achi/64)%2==0 && u->score>=10000000)
	{
		u->achi+=64;
	}
	if(type==3 || type==4)
	{
		if((u->achi/128)%2==0 )
		{
			u->achi+=128;
		}
	}
	if(type==0 || type==1)
	{
		if((u->achi/256)%2==0 )
		{
			u->achi+=256;
		}
	}
	if(type==6)
	{
		if((u->achi/512)%2==0 )
		{
			u->achi+=512;
		}
	}
	if(type==2 || type==5)
	{
		if((u->achi/1024)%2==0 )
		{
			u->achi+=1024;
		}
	}
	if(type==7)
	{
		if((u->achi/2048)%2==0 )
		{
			u->achi+=2048;
		}
	}
	USER_ntoa(u,&u_str);
	if((fp=fopen("c:\\donate\\DATABASE\\USER.dat","rb+"))==NULL)
	{
		printf("CAN`T OPEN FILE");
		delay(500);
		exit(0);
	}
	fseek(fp,(u->usercode)*sizeof(USER_STR),SEEK_SET);
	fwrite(&u_str,sizeof(USER_STR),1,fp);
	free(fp);
	fclose(fp);
	fp=NULL;
	return;
}


