#ifndef _LGFUNC_H_
#define _LGFUNC_H_
#include"database.h"
#include"register.h"

int admin_judge(char* admin, char* pass);
//管理员身份是否匹配
void inputadmin(char* id, int x1, int y1, int charnum, int color);
//x1,y1分别是账号，验证码等输入信息的左端点和上端点
void inputpassword(char* id, int x1, int y1, int charnum, int color);
//x1,y1分别是密码等隐藏信息输入的左端点和上端点
int login_complete(char* u, char* p,int *pagestate);
//用来判断登录信息是否输入完全和正确
int judge_rightpassword(char* name, char* pass,int *pagestate);
//用户名和密码是否匹配
int judge_ban(int times);
//用来判断当前帐号的封禁状态
int register_complete(char*u,char *p,char* cp, char* ph,char* vc, char* rdvc);
//用来判断注册信息是否输入完全和正确
void judge(char* str, int* state, int x, int y); 
//判断注册的状态
void recoverhz(int x, int y, int color);
//覆盖之前输出的汉字
int judge_sameuser(char* new_user,int flag);
//判断账户是否出现重名,以及找回密码时判断用户名是否存在
int checkright_confirmedpassword(char* str1, char* str2, int x, int y);
//检查确认密码是否一致
int checkright_verificationcode(char* str1, char* str2, int x, int y);
//检查验证码是否一致
void input_database(char* name,  char* code, char* phone);
//把用户注册信息写入文件
int input_uinfo(USER* us);
//登陆后把用户信息读入u
int id_phone(char* id, char* ph, char* np, char* cp);
//判断账号与电话号是否匹配，并判断两次输入的密码是否相同
#endif