#include"drawone.h"
#include"common.h"

/*
���ܣ�ҳ�����
���ߣ�Ǯ����
����޸ģ�2020/10/29
*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1
�������ݣ���
����ֵ����
���ܣ�������ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1(void)
{
	setbkcolor(LIGHTRED);
	setcolor(WHITE);
	rectangle(80,80,560,160);
	puthz(100,100,"���ʾ����뷢��ϵͳ",48,50,WHITE);
	
	rectangle(30,300,180,360);
	puthz(55,310,"��½",32,80,WHITE);
	
	rectangle(460,300,610,360);
	puthz(470,310,"��������",32,35,WHITE);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1_1
�������ݣ���
����ֵ����
���ܣ���������ѡ��ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1_1(void)
{
	cleardevice();
	setbkcolor(LIGHTRED);
	setcolor(WHITE);
	rectangle(160,60,480,420);
	puthz(240,100,"ѡ������",32,50,WHITE);
	rectangle(240,170,400,220);
	puthz(285,180,"����",32,40,WHITE);
	rectangle(240,260,400,310);
	puthz(285,270,"����",32,40,WHITE);
	rectangle(240,350,400,400);
	puthz(270,360,"����Ա",32,35,WHITE);
	
	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1_2
�������ݣ���
����ֵ����
���ܣ����Ƶ�½ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1_2(void)
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(60,100,130,150);
	bar(135,100,540,150);
	puthz(65,115,"�˺�",24,40,BLACK);
	
	bar(60,250,130,300);
	bar(135,250,540,300);
	puthz(65,265,"����",24,40,BLACK);
	
	Linex(250,335,360,335,WHITE);
	puthz(260,315,"�������룿",16,20,WHITE);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(110,370,260,450);
	puthz(130,390,"��½",32,80,WHITE);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(380,370,530,450);
	puthz(400,390,"ע��",32,80,WHITE);
		
	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1_2_0
�������ݣ���
����ֵ����
���ܣ����ƹ���Ա��½ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1_2_0(void)
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(60,100,130,150);
	bar(135,100,540,150);
	puthz(65,110,"�˺�",24,40,BLACK);
	
	bar(60,250,130,300);
	bar(135,250,540,300);
	puthz(65,260,"����",24,40,BLACK);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(230,370,390,450);
	puthz(250,390,"��½",32,80,WHITE);
		
	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1_2_1
�������ݣ���
����ֵ����
���ܣ����Ʒ��ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1_2_1(void)
{
	setfillstyle(SOLID_FILL, YELLOW);
	bar(150,180,500,330);
	puthz(190,205,"�����˺Ŵ��ڷ��գ��ѱ���ʱ���",16,20,8);
	puthz(300,235,"������",16,20,8);
	puthz(180,265,"�����߸�����������ϵ����Ա��",16,20,8);
	puthz(210,295,"��������󷵻ص�½����",16,20,8);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1_3
�������ݣ���
����ֵ����
���ܣ�����ע��ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1_3(void)
{
	cleardevice();
	//����½С��
	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	fillellipse(320, 40, 25, 25);//��Բ��亯����x��yΪԲ�ģ�x1��y1Ϊx��뾶��y��뾶
	setfillstyle(1, WHITE);
	pieslice(320, 40, 230, 310, 25);//���κ�����x��yΪԲ�ģ�stangle��endangleΪ�Ƕȷ�Χ���Ƕ��ƣ���radiusΪ�뾶
	fillellipse(320, 35, 12, 12);
	setcolor(WHITE);
	circle(320, 35, 12);		

	setbkcolor(CYAN);

	setfillstyle(SOLID_FILL, WHITE);
	bar(60,80,130,120);
	bar(135,80,540,120);
	puthz(65,85,"�˺�",24,40,BLACK);

	bar(60,140,130,180);
	bar(135,140,540,180);
	puthz(65,145,"����",24,40,BLACK);

	bar(60,200,130,240);
	bar(135,200,540,240);
	puthz(65,205,"ȷ��",24,40,BLACK);

	bar(60,260,130,300);
	bar(135,260,540,300);
	puthz(65,265,"�绰",24,40,BLACK);
	
	bar(60,320,130,360);
	bar(135,320,540,360);
	puthz(65,325,"��֤",24,40,BLACK);
		
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(240,380,410,450);
	puthz(265,390,"ע��",48,60,BLACK);

	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_1_4
�������ݣ���
����ֵ����
���ܣ�������������ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_1_4(void)
{
	cleardevice();
	setbkcolor(CYAN);

	setfillstyle(SOLID_FILL, WHITE);
	bar(60,80,130,120);
	bar(135,80,540,120);
	puthz(65,85,"�˺�",24,40,BLACK);

	bar(60,160,130,200);
	bar(135,160,540,200);
	puthz(65,165,"�绰",24,40,BLACK);

	bar(60,240,130,280);
	bar(135,240,540,280);
	puthz(65,245,"������",16,20,BLACK);

	bar(60,320,130,360);
	bar(135,320,540,360);
	puthz(65,325,"ȷ��",24,40,BLACK);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(240,380,410,450);
	puthz(270,390,"�޸�",48,50,WHITE);

	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_1
�������ݣ���
����ֵ����
���ܣ����ư��ı���ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_1(void)//���ư��ı���ҳ��
{
	putbmp(0,22,"c:\\donate\\PICTURE\\heart.bmp");//ͼƬλ�����ļ�·��
	
	setbkcolor(LIGHTMAGENTA);
	puthz(270,35,"���ı���",48,50,RED);
	
	puthz(70,120,"��",32,24,8);
	puthz(70,160,"��",32,24,8);
	puthz(70,200,"��",32,24,8);
	puthz(70,280,"��",32,24,8);
	puthz(70,330,"��",32,24,8);
	puthz(70,380,"��",32,24,8);
	puthz(70,430,"��",32,24,8);
	
	puthz(570,120,"��",32,24,8);
	puthz(570,160,"��",32,24,8);
	puthz(570,200,"��",32,24,8);
	puthz(570,280,"��",32,24,8);
	puthz(570,330,"ů",32,24,8);
	puthz(570,380,"��",32,24,8);
	puthz(570,430,"��",32,24,8);
	
	puthz(120,130,"�й�����˼��ʹ���",16,20,8);
	puthz(400,130,"�ԴԶ����",16,20,8);
	puthz(120,170,"����ԭʼ��ᣬ�й�������ḣ����˼��Ͳ�����",16,20,8);
	puthz(120,190,"�й������Ĵ�����ҵ���������͸����뷢չ������",16,20,8);
	puthz(130,210,"�л������ܻᴴ���󣬴��ƻҲƵƵ��չ����",16,20,8);
	puthz(120,230,"�ִ��й��Ĵ�����ҵ�ǽ���������������֮�ϵ�",16,20,8);
	puthz(120,250,"��˼�������������Ľ��������Ƴ��ֳ��׶����ص�",16,20,8);
	puthz(120,270,"�������γɾ����й���ɫ�����������Ƹ���˼��",16,20,8);
	puthz(160,290,"���ķ�չ�ͷ����벻��ÿ���˵İ���",16,20,8);
	/*puthz(130,310,"�����������ů���֣��������ģ���ֲ����!",16,20,8);*/
	puthz(150,310,"����ÿһ�ξ�������������һ��������",16,20,8);
	puthz(260,330,"Ը���ǵĵ�θ���",16,20,8);
	puthz(260,350,"���۳ɰ��ĵĲʺ�",16,20,8);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_3_0
�������ݣ���
����ֵ����
���ܣ����Ʒ����������
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_3_0(void)//���Ʒ����������
{
	int polypoints[8]={170,110,170,130,190,120,170,110};
	setbkcolor(LIGHTGREEN);
	
	rectangle(5,5,145,45);
	rectangle(150,5,570,45);
	puthz(20,20,"��Ŀ����",24,25,8);

	rectangle(5,50,145,90);
	rectangle(150,50,570,90);
	puthz(20,65,"������ַ",24,25,8);
	
	rectangle(5,95,145,135);
	rectangle(150,95,200,135);
	puthz(20,110,"��������",24,25,8);

	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(4,polypoints);
	
	rectangle(320,95,430,135);
	puthz(325,100,"ѡ������",24,25,8);
	
	rectangle(320,145,460,185);
	rectangle(465,145,630,185);
	puthz(330,155,"����������",24,25,8);
	
	rectangle(10,160,90,200);
	rectangle(10,200,630,400);
	puthz(20,170,"����",24,25,8);
	
	rectangle(420,410,539,460);
	puthz(435,415,"����",48,50,8);
	
	rectangle(90,420,110,440);
	puthz(115,420,"�����Ķ���ͬ��",16,17,8);
	puthz(115+120,420,"������",16,20,RED);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(115+120,440,115+175,440);
	
	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_3_1
�������ݣ���
����ֵ����
���ܣ����Ʒ�����������ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_3_1(void)//��������ҳ��
{
	rectangle(210,95,295,197);
	
	rectangle(215,100,250,120);
	puthz(218,103,"��ͯ",16,17,WHITE);
	
	rectangle(215,125,250,145);
	puthz(218,128,"����",16,17,WHITE);
	
	rectangle(215,150,250,170);
	puthz(218,153,"��ƶ",16,17,WHITE);
	
	rectangle(255,100,290,120);
	puthz(258,103,"����",16,17,WHITE);
	
	rectangle(255,125,290,145);
	puthz(258,128,"����",16,17,WHITE);
	
	rectangle(255,150,290,170);
	puthz(258,153,"����",16,17,WHITE);
	
	rectangle(235,175,270,195);
	puthz(240,178,"����",16,17,WHITE);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_3_2
�������ݣ���
����ֵ����
���ܣ�ѡ������ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_3_2(int protype)//ѡ������ҳ��
{
	setfillstyle(SOLID_FILL, WHITE);
	puthz(190,5,"ѡ�������������",32,30,WHITE);
	puthz(120,40,"ע�⣺��ҳ����ʾ��������������ѡ��ľ����������",16,17,RED);
	
	rectangle(20,70,115,102);
	rectangle(115,70,320,102);

	rectangle(20,142,115,174);
	rectangle(115,142,320,174);
	
	rectangle(20,214,115,246);
	rectangle(115,214,320,246);
	
	rectangle(20,306,115,338);
	rectangle(115,306,320,338);
	
	rectangle(20,398,115,430);
	rectangle(115,398,320,430);
	
	rectangle(340,70,435,102);
	rectangle(435,70,630,102);
	
	rectangle(340,142,435,174);
	rectangle(435,142,630,174);
	
	rectangle(340,214,435,246);
	rectangle(435,214,630,246);
	
	rectangle(340,306,435,338);
	rectangle(435,306,630,338);
	
	rectangle(380,390,500,460);
	puthz(395,400,"ȷ��",48,40,8);

	switch(protype)
	{
		case 0:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"Ӥ����",16,17,8);
		puthz(25,219,"��Ƭ",16,17,8);
		puthz(25,311,"�̷�",16,17,8);
		puthz(25,403,"��ƿ",16,17,8);
		puthz(345,75,"��ͯ����",16,17,8);
		puthz(345,147,"���",16,17,8);
		puthz(345,219,"Ӫ��Ʒ",16,17,8);
		puthz(345,311,"�߸�ţ��",16,17,8);
		break;
		
		case 1:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"����Ʒ",16,17,8);
		puthz(25,219,"�ϻ���",16,17,8);
		puthz(25,311,"����Ь",16,17,8);
		puthz(25,403,"������",16,17,8);
		puthz(345,75,"����",16,17,8);
		puthz(345,147,"Ӧ��ҩƷ",16,17,8);
		puthz(345,219,"����",16,17,8);
		puthz(345,311,"С�Ƴ�",16,17,8);
		break;
	
		case 2:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"����",16,17,8);
		puthz(25,219,"����",16,17,8);
		puthz(25,311,"����",16,17,8);
		puthz(25,403,"����",16,17,8);
		puthz(345,75,"����",16,17,8);
		puthz(345,147,"��ˮ��",16,17,8);
		puthz(345,219,"��ҩ��",16,17,8);
		puthz(345,311,"�ո��",16,17,8);
		break;
	
		case 3:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"����",16,17,8);
		puthz(25,219,"ʳ��",16,17,8);
		puthz(25,311,"ƿװˮ",16,17,8);
		puthz(25,403,"����",16,17,8);
		puthz(345,75,"�ƾ�",16,17,8);
		puthz(345,147,"����",16,17,8);
		puthz(345,219,"��֯��",16,17,8);
		puthz(345,311,"�����",16,17,8);
		break;
	
		case 4:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"����",16,17,8);
		puthz(25,219,"������",16,17,8);
		puthz(25,311,"����Һ",16,17,8);
		puthz(25,403,"���¼�",16,17,8);
		puthz(345,75,"������",16,17,8);
		puthz(345,147,"��Ŀ��",16,17,8);
		puthz(345,219,"��ҩ�Ƽ�",16,17,8);
		puthz(345,311,"����Լ�",16,17,8);
		break;
		
		case 5:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"�鼮",16,17,8);
		puthz(25,219,"�ľ�",16,17,8);
		puthz(25,311,"ֽ��",16,17,8);
		puthz(25,403,"���Ӿ�",16,17,8);
		puthz(345,75,"�ڰ�",16,17,8);
		puthz(345,147,"�۱�",16,17,8);
		puthz(345,219,"����",16,17,8);
		puthz(345,311,"ʵ��̾�",16,17,8);
		break;

		case 6:
		puthz(25,75,"���",16,17,8);
		puthz(25,147,"������",16,17,8);
		puthz(25,219,"������",16,17,8);
		puthz(25,311,"����Լ�",16,17,8);
		puthz(25,403,"��ѧҩ��",16,17,8);
		puthz(345,75,"����",16,17,8);
		puthz(345,147,"�ռ�ƿ",16,17,8);
		puthz(345,219,"�����",16,17,8);
		puthz(345,311,"��������",16,17,8);
		break;
	}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_3_3
�������ݣ���
����ֵ����
���ܣ��������ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_3_3(void)//�������ҳ��
{
	puthz(190,5,"�ƴ�����Ŀ��������",32,30,8);
	puthz(10,40,"��Ŀ����������ύ���ϵ���ʵ�Ը��𣬲����鹹��ʵ�����������ࡣ",16,20,8);
	puthz(10,57,"ƽ̨���ص���Υ��թƭ��Ϊ���漰�������εģ�ƽ̨�������ƽ�����",16,20,8);
	puthz(10,74,"����������������",16,20,8);
	puthz(10,96,"��Ŀ������֪��",24,30,8);
	puthz(10,130,"������������֮һ���������̷�թƭ������Ĺ涨������ϳʹ���",16,20,8);
	puthz(10,147,"һ��ͨ�����Ͷ��źͲ���绰�������û��������㲥���ӡ�������־��",16,20,8);
	puthz(10,164,"���������Ϣ���Բ��ض�������ʵʩթƭ��",16,20,8);
	puthz(10,181,"����թƭ���ֺ����ա���Ѵ���Ÿ�����ƶ�����񡢾ȼá�ҽ�ƿ����",16,20,8);
	puthz(10,198,"����������ļ������ʵʩթƭ��",16,20,8);
	puthz(10,215,"�ġ�թƭ�м��ˡ������˻���ɥʧ�Ͷ������˵Ĳ����",16,20,8);
	puthz(10,235,"��Ŀ�������ʸ�",24,30,8);
	puthz(10,260,"һ��ʮ����������",16,20,8);
	puthz(10,277,"�����л����񹲺͹�����",16,20,8);
	puthz(10,294,"����ӵ���ܹ����й�������������һ������п��˻�",16,20,8);
	puthz(10,310,"�����˳�ŵ�飺",32,30,8);
	puthz(10,350,"�漰����Ŀ�������Ϣ��ȫ��ʵ����Ч�������յ���ȫ���������ֱ�����ڱ������˵ľ������������˴���Υ����Ϊ��Ը���ге�ȫ���������Ρ�",16,20,8);
	rectangle(240,425,400,475);
	puthz(260,435,"�����Ķ�",32,30,8);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_3_4
�������ݣ���
����ֵ����
���ܣ�����ɹ���ʾҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_3_4(void)//����ɹ���ʾҳ��
{
	rectangle(30,120,580,220);
	puthz(50,140,"������Ŀ����ɹ���ף�����նɹ��ѹ�",32,30,8);
	puthz(215,180,"ҳ�潫������󷵻�",24,20,8);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_5_0
�������ݣ���
����ֵ����
���ܣ��������Բ鿴ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_5_0(void)
{
	int i;
	setcolor(WHITE);
	setbkcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	for(i=1;i<=3;i++)
	{
		line(0,120*i,640,120*i);
	}
	rectangle(50,420,150,460);
	rectangle(260,420,390,460);
	rectangle(490,420,590,460);
	puthz(55,425,"��һҳ",32,30,8);
	puthz(265,425,"��Ҫ����",32,30,8);
	puthz(495,425,"��һҳ",32,30,8);
	
	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_5_1
�������ݣ���
����ֵ����
���ܣ��������Է���ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_5_1(void)
{
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(20,20,100,60);
	rectangle(105,20,580,60);
	puthz(25,25,"����",24,25,8);
	
	rectangle(20,80,80,125);
	rectangle(20,125,635,400);
	puthz(25,85,"����",24,25,8);
	
	rectangle(270,420,370,470);
	puthz(275,425,"ȷ��",24,25,8);
	
	rectangle(605,5,635,35);
	LineThick(610,10,630,30,WHITE,3,1);
	LineThick(630,10,610,30,WHITE,3,1);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_5_2
�������ݣ���
����ֵ����
���ܣ��������Է���ɹ�ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_5_2(void)
{
	rectangle(120,150,520,230);
	puthz(130,160,"���Գɹ���лл���Ĳ��룡",32,30,8);
	puthz(210,200,"ҳ�潫������󷵻�",24,20,8);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_8_0
�������ݣ���
����ֵ����
���ܣ������˳�ѯ��ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_8_0(void)
{
	setfillstyle(SOLID_FILL, YELLOW);
	bar(170,200,480,310);
	rectangle(200,245,290,285);
	rectangle(350,245,440,285);
	puthz(190,205,"��ȷ��Ҫ�˳���ǰ�ʺ���",24,25,8);
	puthz(220,250,"ȷ��",32,30,8);
	puthz(370,250,"����",32,30,8);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������g_2_10_0
�������ݣ���
����ֵ����
���ܣ����������˵�ҳ��
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void g_2_10_0(void)
{
	setfillstyle(1,WHITE);
	bar(562,19,639,50);
	bar(562,50,639,80);
	puthz(567,22,"����ͳ��",16,16,8);
	puthz(567,52,"ʹ��˵��",16,16,8);
}

