#include"common.h"
#include"trans.h"


/*
���ܣ������еĽṹ����ļ��еĽṹ���ת��
���ߣ������
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������USER_ntoa
�������ݣ�USER *u,USER_STR *us
����ֵ����
���ܣ���USERת��ΪUSER_STR
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void USER_ntoa(USER *u,USER_STR *us)//��USERת��ΪUSER_STR 
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
��������PRO_ntoa
�������ݣ�PRO *p,PRO_STR *ps
����ֵ����
���ܣ���PROת��ΪPRO_STR
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void PRO_ntoa(PRO *p,PRO_STR *ps)//��PROת��ΪPRO_STR
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
��������RECORD_ntoa
�������ݣ�RECORD *r,RECORD_STR *rs
����ֵ����
���ܣ���RECORDת��ΪRECORD_STR
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void RECORD_ntoa(RECORD *r,RECORD_STR *rs)//��RECORDת��ΪRECORD_STR 
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

//++++++++++++++++++++++�ϱ�������ת�ַ������±����ַ���ת���� 

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������USER_aton
�������ݣ�USER *u,USER_STR *us
����ֵ����
���ܣ���USER_STRת��ΪUSER
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void USER_aton(USER *u,USER_STR *us)//��USER_STRת��ΪUSER
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
��������PRO_aton
�������ݣ�PRO *p,PRO_STR *ps
����ֵ����
���ܣ���PRO_STRת��ΪPRO
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void PRO_aton(PRO *p,PRO_STR *ps)//��PRO_STRת��ΪPRO
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
��������RECORD_aton
�������ݣ�RECORD *r,RECORD_STR *rs
����ֵ����
���ܣ���RECORD_STRת��ΪRECORD 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void RECORD_aton(RECORD *r,RECORD_STR *rs)//��RECORD_STRת��ΪRECORD 
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














