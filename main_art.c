#include "main.h"

void main_first()
{
	printf("		LOADING~~");
	gotoxy(0, 1);
	printf("�������������������������������������������������������������������������������������� ");
	gotoxy(0, 2);
	printf("��                                         �� ");
	gotoxy(0, 3);
	printf("��                                         �� ");
	gotoxy(0, 4);
	printf("��������������������������������������������������������������������������������������");

	for (int i = 2; i < 35; i++)
	{
		gotoxy(i, 2);
		printf("�����");
		gotoxy(i, 3);
		printf("�����");
		S05;
		i += 7;
	}
}

void m_main(int x, int y, int z) //z�� ����(z=0�� -���) 1�� |
{
	if (z == 0)
	{
		gotoxy(x, y);
		printf("��");
	}
}

void main_second()
{

	int input_main = 0;
	//����ȭ��
	gotoxy(0, 0);
	printf("�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�");

	
	for (int i = 3;i<8;i++)
	{
		m_main(4, i, 0);
		m_main(8, i, 0);
		m_main(18, i, 0);
		m_main(22, i, 0);
		m_main(26, i, 0);
		m_main(30, i, 0);
		m_main(34, i, 0);
		m_main(38, i, 0);
	}
	for (int i = 3; i < 6; i++)
	{
		m_main(12, i, 0);
	}
	m_main(6, 3, 0);
	m_main(6, 7, 0);

	m_main(20, 3, 0);
	m_main(24, 3, 0);

	m_main(32, 3, 0);
	m_main(32, 7, 0);

	m_main(40, 5, 0);
	m_main(42, 4, 0);
	m_main(42, 6, 0);

	m_main(44, 3, 0);
	m_main(44, 7, 0);

	m_main(12, 7, 0);

	gotoxy(42, 10);
	printf("ver 2.0");

	gotoxy(0, 11);
	printf("�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�");
	gotoxy(6, 13);
	printf("1.���ӽ���\n");
	gotoxy(6, 15);
	printf("2.�ҷ�����\n");
	gotoxy(6, 17);
	printf("3.����\n");
	gotoxy(6, 19);
	printf("4.������\n");

	memu_input_1();
}

