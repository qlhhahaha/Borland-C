#include"common.h"
#include"lovebg.h"

/*
���ܣ����ı�������
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������s_2_1
�������ݣ�pagestate:ҳ����
����ֵ����
���ܣ����ı����Ĺ��ܺ���
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void s_2_1 (int *pagestate)
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_2_0();
	g_2_1();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(s_2_0(pagestate)==1)//��pagestate��Ϊ��ַ����s_2_0�����������Ϸ��˵���s_2_0����1 
		{
			return;
		}
	}
}
