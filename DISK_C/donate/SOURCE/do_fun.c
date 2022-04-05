#include"common.h"
#include"do_fun.h"

/*
功能：我要捐助功能的相关函数
作者：李浩宇
最后修改：2020/10/29
*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：fsize_init
参数：fp:文件指针，order:输出的顺序
返回值：文件指针frell(fp)终点位置
功能：得到以order为顺序是的文件终点
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
			puthz(606,182,"正",24,24,WHITE);
			fseek(fp,0L,SEEK_END);
			fsize=ftell(fp);
			fseek(fp,0L,SEEK_SET);
		}
		break;
		
		case -1:
		{
			setfillstyle(1,RED);
			bar(605,181,631,206);
			puthz(606,182,"倒",24,24,WHITE);
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
函数名：info_output
参数：fp:文件指针,fsize:文件终点;state：“p”模式：完成状态、“r”模式：捐助者筛选
	“u”模式：用户状态;type:项目or记录的种类;name:“r”模式下的用户名;allorder:此项目
	在文件中的次序；showorder:此项目在所有输出项目中的次序;order:输出顺序;mode:操作模式
返回值：如果此项信息呗跳过（未通过筛选）则返回1，否则返回0
功能：读取文件信息并判断是否输出
备注：每调用一次，文件指针fp都会向order方向移动fsize个字节
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int info_output(FILE *fp,long int fsize,int state,int type,char *name,int *allorder,int *showorder,int order,char mode)
{
	int i,page,row;
	long int prosize;
	char leixing[7][5]={"儿童","老人","扶贫","救灾","抗疫","教育","环保"};
	PRO *pro;
	PRO_STR *pro_str;
	RECORD *rec;
	RECORD_STR *rec_str;
	USER *user;
	USER_STR *user_str;
	//void *temp,*temp_str;
	switch(mode)//开辟内存
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
	switch(order)//读取文件
	{
		case 1:
		{
			switch(mode)
			{
				case 'p':
				fread(pro_str,prosize,1,fp);//将指定文件信息放入中转结构体,每次读一个PRO结构体
				*allorder+=1;
				break;
				
				case 'r':
				fread(rec_str,prosize,1,fp);//将指定文件信息放入中转结构体,每次读一个PRO结构体
				*allorder+=1;
				break;
				
				case 'u':
				fread(user_str,prosize,1,fp);//将指定文件信息放入中转结构体,每次读一个PRO结构体
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
			fseek(fp,-prosize,SEEK_CUR);//从要读的项目数据尾移动至数据头
			switch(mode)
			{
				case 'p':
				fread(pro_str,prosize,1,fp);
				//将指定文件信息放入中转结构体,每次读一个PRO结构体，读完后指针移到数据尾
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
			fseek(fp,-prosize,SEEK_CUR);//定位到上一个项目数据的尾
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
	switch(mode)//绘制
	{
		case 'p':
		{
			PRO_aton(pro,pro_str);
			if(type!=7 && type!=pro->protype)//类型筛选,如果项目种类不符合条件则直接进入下一个数据
			{
				free(pro);
				free(pro_str);
				return 1;//遍历整个PRO数据库，类型符合的才展示
			}
			if((pro->state)!=state)//完成情况筛选,如果完成情况不符合条件则直接进入下一个数据
			{
				free(pro);
				free(pro_str);
				return 1;
			}
			row=*showorder%10;
			page=*showorder/10;
			bar(1,110+41*(row-1),279,108+41*row);//覆盖原有文字
			outputhz(3,110+41*(row-1)+4,295,110+41*(row-1)+4+40,pro_str->proname,WHITE);
			bar(281,110+41*(row-1),420,108+41*row);
			progress_draw(283,110+10+41*(row-1),20,pro);//绘制进度条
			setfillstyle(1,RED);
			setcolor(WHITE);
			settextstyle(0,0,4);
			bar(422,110+41*(row-1),494,108+41*row);
			puthz(425,110+41*(row-1)+4,leixing[atoi(pro_str->protype)],32,35,WHITE);
			bar(496,110+41*(row-1),603,108+41*row);
			switch(pro->state)//判断并显示项目的完成状况
			{
				case 1:
				puthz(499,110+41*(row-1)+4,"已完成",32,35,WHITE);
				break;
						
				case 0:
				puthz(499,110+41*(row-1)+4,"进行中",32,35,WHITE);
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
			RECORD_aton(rec,rec_str);//将字符串格式的信息转换成正常格式 
			if((rec->procode)==-2)
			{
				free(rec);
				free(rec_str);
				return 1;//此记录已被删除
			}
			if(type!=7 && type!=rec->protype)//类型筛选
			{
				free(rec);
				free(rec_str);
				return 1;//遍历整个RECORD数据库，类型符合的才展示
			}
			if(state!=1 && strcmp(name,rec->userid))//捐助者筛选 
			{
				free(rec);
				free(rec_str);
				return 1;
			}
			
			row=*showorder%10;
			page=*showorder/10;
			bar(1,110+41*(row-1),420-40,108+41*row);//覆盖原有文字
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
			if(state==-1 && user->times>=0)//状态筛选,如果项目种类不符合条件则直接进入下一个数据
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
			bar(1,110+41*(row-1),420,108+41*row);//覆盖原有文字
			outtextxy(3,110+41*(row-1)+4,user_str->userid);//显示新文字
			bar(422,110+41*(row-1),494,108+41*row);
			outtextxy(425,110+41*(row-1)+4,user_str->usercode);
			bar(496,110+41*(row-1),603,108+41*row);
			switch(state)
			{
				case 1:
				puthz(499,110+41*(row-1)+4,"正常",32,35,WHITE);
				break;
							
				case -1:
				puthz(499,110+41*(row-1)+4,"封禁",32,35,WHITE);
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
函数名：blank_draw
参数：order：顺序;row:此页面有信息行数;state:模式
返回值：填充空行的个数
功能：在一页表格信息输出后，对剩下的位置使用空白进行填充
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int blank_draw(int order,int row,int state)
{
	int i=0,j=0,time=0;
	if(state==2)
	{
		j=40;
	}
	for(i=row+1;i<10;i++)//如果此页应有空白行，则将空白行所在位置的文字清除
	{
		setfillstyle(1,RED);
		bar(1,110+41*(i-1),420-j,108+41*i);
		bar(422-j,110+41*(i-1),494-j,108+41*i);
		bar(496-j,110+41*(i-1),603,108+41*i);
		time+=1;
	}
	if(state==0 || state==2)
	{		
		g_2_0_0(state);//绘制右边菜单
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
		puthz(606,182,"正",24,24,WHITE);
		break;
			
		case -1:
		puthz(606,182,"倒",24,24,WHITE);
		break;
			
		default:
		printf("order error");
		break;
	}
	return time;
}
/*------------------------------------------------------------------
函数名：progress_draw
参数：x、y：绘制进度条的左上角坐标
	height：进度条的高度
	pro：需要计算百分比并绘制进度条的项目
返回值：进度的百分比（int型）
功能：进度条功能函数
备注：当x、y、height均为0时，将不会绘制进度条，仅返回百分比
-------------------------------------------------------------------*/
int progress_draw(int x,int y,int height,PRO *pro)
{
	int i,propor;//propor:完成的百分度
	char propor_str[7];
	long long int sumscore,nowscore,temp;//记录物资按权重积累后的值
	
	sumscore=-3*(pro->amount[0][0]);
	nowscore=-3*(pro->amount[1][0]);
	for(i=0;i<9;i++)
	{
		sumscore+=4*(pro->amount[0][i]);
		nowscore+=4*(pro->amount[1][i]);
	}
	temp=(nowscore*100)/sumscore;
	propor=(int)temp;
	if(propor==0 && nowscore!=0)//如果已得物资过少，propor不为0而将变为1
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