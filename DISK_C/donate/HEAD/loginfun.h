#ifndef _LGFUNC_H_
#define _LGFUNC_H_
#include"database.h"
#include"register.h"

int admin_judge(char* admin, char* pass);
//����Ա����Ƿ�ƥ��
void inputadmin(char* id, int x1, int y1, int charnum, int color);
//x1,y1�ֱ����˺ţ���֤���������Ϣ����˵���϶˵�
void inputpassword(char* id, int x1, int y1, int charnum, int color);
//x1,y1�ֱ��������������Ϣ�������˵���϶˵�
int login_complete(char* u, char* p,int *pagestate);
//�����жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ
int judge_rightpassword(char* name, char* pass,int *pagestate);
//�û����������Ƿ�ƥ��
int judge_ban(int times);
//�����жϵ�ǰ�ʺŵķ��״̬
int register_complete(char*u,char *p,char* cp, char* ph,char* vc, char* rdvc);
//�����ж�ע����Ϣ�Ƿ�������ȫ����ȷ
void judge(char* str, int* state, int x, int y); 
//�ж�ע���״̬
void recoverhz(int x, int y, int color);
//����֮ǰ����ĺ���
int judge_sameuser(char* new_user,int flag);
//�ж��˻��Ƿ��������,�Լ��һ�����ʱ�ж��û����Ƿ����
int checkright_confirmedpassword(char* str1, char* str2, int x, int y);
//���ȷ�������Ƿ�һ��
int checkright_verificationcode(char* str1, char* str2, int x, int y);
//�����֤���Ƿ�һ��
void input_database(char* name,  char* code, char* phone);
//���û�ע����Ϣд���ļ�
int input_uinfo(USER* us);
//��½����û���Ϣ����u
int id_phone(char* id, char* ph, char* np, char* cp);
//�ж��˺���绰���Ƿ�ƥ�䣬���ж���������������Ƿ���ͬ
#endif