#ifndef _database_h
#define _database_h

/*protype0��ͯ 1���� 2��ƶ 3���� 4���� 5���� 6���� 7ȫ��  
state 0δ��� 1�����*/ 

typedef struct userinfo
{
	char userid[15];    //������11λ�������û���
	char password[15];  //������10λ������
	char phone[15];		//������11λ���ֻ���
	long int score;		//�û�����
	int times;			//��������
	int achi;			//�ɾ���Ϣ
	int usercode;		//�û��ض����룬ע��ʱ�Զ���˳������
	int goods[9];		//�һ���Ʒ����Ϣ
}USER;	//��װ�û���Ϣ

typedef struct userinfo_str 
{
	char userid[15];    //������11λ�������û���
	char password[15];  //������10λ������
	char phone[15];		//������11λ���ֻ���
	char score[11];		//�û�����
	char times[6];			//��������
	char achi[6];			//�ɾ���Ϣ
	char usercode[6];		//�û��ض����룬ע��ʱ�Զ���˳������
	char goods[9][6];		//�һ���Ʒ����Ϣ
}USER_STR;	//�û���Ϣ���ַ�����ʽ 

typedef struct admininfo
{
	char userid[15];//������11λ������Ա�˺�
	char password[10];//������10λ������Ա����
}ADMIN;//��װ����Ա��Ϣ

typedef struct projectinfo
{
	char proname[50];
	char place[50];
	int protype;
	char call[11];
	char manname[20];//������������������ͬ���û���
	char userid[15];
	int procode;//��Ŀ�ض����룬����ɹ�ʱ��˳���Զ�����
	long int amount[2][9];//�����������������ǵ����Ծ�Ǯ�����Բ���long int��,amount[0]����Ҫ��, [1]���յ���
	char descri[400];//��Ŀ����
	int state;//��ʾ��Ŀ�Ƿ���ɵ�״ֵ̬
}PRO;//��װ��Ŀ��Ϣ

typedef struct projectinfo_str
{
	char proname[50];//(1) 
	char place[50];//(31) 
	char protype[6];// (71)
	char call[11];//(77)
	char manname[20];//(88)������������������ͬ���û���
	char userid[15];//(96)
	char procode[6];//(111)��Ŀ�ض����룬����ɹ�ʱ��˳���Զ�����
	char amount[2][9][11];//(117)�����������������ǵ����Ծ�Ǯ�����Բ���long int��,amount[0]����Ҫ��, [1]���յ���
	char descri[400];//(315)��Ŀ����
	char state[6];//(515)��ʾ��Ŀ�Ƿ���ɵ�״ֵ̬
}PRO_STR;//(521)��Ŀ��Ϣ���ַ�����ʽ 

typedef struct reinfo
{
	char proname[50];
	int procode; 
	int protype;
	char userid[15];
	long int amount[9];
}RECORD;//��װ������¼��Ϣ

typedef struct reinfo_str
{
	char proname[50];
	char procode[6]; 
	char protype[6];
	char userid[15];
	char amount[9][11];
}RECORD_STR;//������¼��Ϣ���ַ�����ʽ 

typedef struct messinfo
{
	char name[20];
	char text[200];
}MESSAGE;//��װ������Ϣ
#endif
