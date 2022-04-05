#include"common.h"
#include"trans.h"


/*
功能：程序中的结构体和文件中的结构体的转换
作者：李浩宇
最后修改：2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：USER_ntoa
参数传递：USER *u,USER_STR *us
返回值：无
功能：将USER转化为USER_STR
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void USER_ntoa(USER *u,USER_STR *us)//将USER转化为USER_STR 
{
	int i;
	strcpy(us->userid,u->userid);
	strcpy(us->password,u->password);
	strcpy(us->phone,u->phone);
	ltoa(u->score,us->score,10);
	itoa(u->times,us->times,10);
	itoa(u->achi,us->achi,10);
	itoa(u->usercode,us->usercode,10);
	for(i=0;i<9;i++)
	{
		itoa(u->goods[i],us->goods[i],10);
	}
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：PRO_ntoa
参数传递：PRO *p,PRO_STR *ps
返回值：无
功能：将PRO转化为PRO_STR
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void PRO_ntoa(PRO *p,PRO_STR *ps)//将PRO转化为PRO_STR
{
	int i;
	strcpy(ps->proname,p->proname);
	strcpy(ps->place,p->place);
	itoa(p->protype,ps->protype,10);
	strcpy(ps->call,p->call);
	strcpy(ps->manname,p->manname);
	strcpy(ps->userid,p->userid);
	itoa(p->procode,ps->procode,10);
	for(i=0;i<9;i++)
	{
		ltoa(p->amount[0][i],ps->amount[0][i],10);
		ltoa(p->amount[1][i],ps->amount[1][i],10);
	}
	strcpy(ps->descri,p->descri);
	itoa(p->state,ps->state,10);
	return;
} 

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：RECORD_ntoa
参数传递：RECORD *r,RECORD_STR *rs
返回值：无
功能：将RECORD转化为RECORD_STR
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void RECORD_ntoa(RECORD *r,RECORD_STR *rs)//将RECORD转化为RECORD_STR 
{
	int i;
	strcpy(rs->proname,r->proname);
	itoa(r->procode,rs->procode,10);
	itoa(r->protype,rs->protype,10);
	strcpy(rs->userid,r->userid);
	for(i=0;i<9;i++)
	{
		ltoa(r->amount[i],rs->amount[i],10);
	}
	return;
} 

//++++++++++++++++++++++上边是数字转字符串，下边是字符串转数字 

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：USER_aton
参数传递：USER *u,USER_STR *us
返回值：无
功能：将USER_STR转化为USER
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void USER_aton(USER *u,USER_STR *us)//将USER_STR转化为USER
{
	int i;
	strcpy(u->userid,us->userid);
	strcpy(u->password,us->password);
	strcpy(u->phone,us->phone);	
	u->score=atol(us->score);
	u->times=atoi(us->times);
	u->achi=atoi(us->achi);
	u->usercode=atoi(us->usercode);
	for(i=0;i<9;i++)
	{
		u->goods[i]=atoi(us->goods[i]);
	}
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：PRO_aton
参数传递：PRO *p,PRO_STR *ps
返回值：无
功能：将PRO_STR转化为PRO
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void PRO_aton(PRO *p,PRO_STR *ps)//将PRO_STR转化为PRO
{
	int i;
	strcpy(p->proname,ps->proname);
	strcpy(p->place,ps->place);
	p->protype=atoi(ps->protype);
	strcpy(p->call,ps->call);
	strcpy(p->manname,ps->manname);
	strcpy(p->userid,ps->userid);
	p->procode=atoi(ps->procode);
	for(i=0;i<9;i++)
	{
		p->amount[0][i]=atol(ps->amount[0][i]);
		p->amount[1][i]=atol(ps->amount[1][i]);
	}
	strcpy(p->descri,ps->descri);
	p->state=atoi(ps->state);
	return;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
函数名：RECORD_aton
参数传递：RECORD *r,RECORD_STR *rs
返回值：无
功能：将RECORD_STR转化为RECORD 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void RECORD_aton(RECORD *r,RECORD_STR *rs)//将RECORD_STR转化为RECORD 
{
	int i;
	strcpy(r->proname,rs->proname);
	r->procode=atoi(rs->procode);
	r->protype=atoi(rs->protype);
	strcpy(r->userid,rs->userid);
	for(i=0;i<9;i++)
	{
		r->amount[i]=atol(rs->amount[i]);
	}
	return;
} 














