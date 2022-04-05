#ifndef _database_h
#define _database_h

/*protype0儿童 1老人 2扶贫 3救灾 4抗疫 5教育 6环保 7全部  
state 0未完成 1已完成*/ 

typedef struct userinfo
{
	char userid[15];    //不超过11位，个人用户名
	char password[15];  //不超过10位，密码
	char phone[15];		//不超过11位，手机号
	long int score;		//用户积分
	int times;			//捐赠次数
	int achi;			//成就信息
	int usercode;		//用户特定编码，注册时自动按顺序生成
	int goods[9];		//兑换商品的信息
}USER;	//封装用户信息

typedef struct userinfo_str 
{
	char userid[15];    //不超过11位，个人用户名
	char password[15];  //不超过10位，密码
	char phone[15];		//不超过11位，手机号
	char score[11];		//用户积分
	char times[6];			//捐赠次数
	char achi[6];			//成就信息
	char usercode[6];		//用户特定编码，注册时自动按顺序生成
	char goods[9][6];		//兑换商品的信息
}USER_STR;	//用户信息的字符串形式 

typedef struct admininfo
{
	char userid[15];//不超过11位，管理员账号
	char password[10];//不超过10位，管理员密码
}ADMIN;//封装管理员信息

typedef struct projectinfo
{
	char proname[50];
	char place[50];
	int protype;
	char call[11];
	char manname[20];//捐赠负责人姓名，不同于用户名
	char userid[15];
	int procode;//项目特定编码，发起成功时按顺序自动生成
	long int amount[2][9];//捐赠物资数量，考虑到可以捐钱，所以采用long int型,amount[0]是需要的, [1]是收到的
	char descri[400];//项目描述
	int state;//表示项目是否完成的状态值
}PRO;//封装项目信息

typedef struct projectinfo_str
{
	char proname[50];//(1) 
	char place[50];//(31) 
	char protype[6];// (71)
	char call[11];//(77)
	char manname[20];//(88)捐赠负责人姓名，不同于用户名
	char userid[15];//(96)
	char procode[6];//(111)项目特定编码，发起成功时按顺序自动生成
	char amount[2][9][11];//(117)捐赠物资数量，考虑到可以捐钱，所以采用long int型,amount[0]是需要的, [1]是收到的
	char descri[400];//(315)项目描述
	char state[6];//(515)表示项目是否完成的状态值
}PRO_STR;//(521)项目信息的字符串形式 

typedef struct reinfo
{
	char proname[50];
	int procode; 
	int protype;
	char userid[15];
	long int amount[9];
}RECORD;//封装捐赠记录信息

typedef struct reinfo_str
{
	char proname[50];
	char procode[6]; 
	char protype[6];
	char userid[15];
	char amount[9][11];
}RECORD_STR;//捐赠记录信息的字符串形式 

typedef struct messinfo
{
	char name[20];
	char text[200];
}MESSAGE;//封装留言信息
#endif
