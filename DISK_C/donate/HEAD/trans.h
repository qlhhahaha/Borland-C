#ifndef trans
#define _trans_h

void USER_ntoa(USER *u,USER_STR *us);//将USER转化为USER_STR
void PRO_ntoa(PRO *p,PRO_STR *ps);//将PRO转化为PRO_STR
void RECORD_ntoa(RECORD *r,RECORD_STR *rs);//将RECORD转化为RECORD_STR 
void USER_aton(USER *u,USER_STR *us);//将USER_STR转化为USER
void PRO_aton(PRO *p,PRO_STR *ps);//将PRO_STR转化为PRO
void RECORD_aton(RECORD *r,RECORD_STR *rs);//将RECORD_STR转化为RECORD

#endif
