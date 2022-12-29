#include "main.h"

void map()
{

	Screen(64, 40);

	//큰틀
	for (int i = 7; i < 35; i++)
	{
		m_map(0, i, 1);
	}
	for (int i = 7; i < 35; i++)
	{
		m_map(62, i, 1);
	}

	for (int i = 2; i < 62; i++)
	{
		m_map(i, 7, 0);
	}
	for (int i = 2; i < 62; i++)
	{
		m_map(i, 34, 0);
	}
	m_map(0, 7, 3);
	m_map(62, 7, 4);
	m_map(0, 34, 5);
	m_map(62, 34, 6);

	for (int j = 11; j < 33; j++)
	{
		for (int i = 2; i < 56; i++)
		{
			i += 4;
			m_map(i, j, 7);
		}
		j += 1;
	}

	m_map(31, 21, 100);

}


void m_map(int x, int y, int z) //z로 구분(z=0이 -출력) 1은 |
{
	if (z == 0)
	{
		gotoxy(x, y);
		printf("━");
	}
	else if (z == 1)
	{
		gotoxy(x, y);
		printf("┃");
	}
	else if (z == 2)
	{
		gotoxy(x, y);
		printf("＠");
	}
	else if (z == 9)
	{
		x += 2;
		gotoxy(x, y);
		printf("\b\b●");
	}
	else if (z == 3)
	{
		gotoxy(x, y);
		printf("┏");
	}
	else if (z == 4)
	{
		gotoxy(x, y);
		printf("┓");
	}
	else if (z == 5)
	{
		gotoxy(x, y);
		printf("┗");
	}
	else if (z == 6)
	{
		gotoxy(x, y);
		printf("┛");
	}
	else if (z == 7)
	{
		gotoxy(x, y);
		printf("┿");
	}
	else if (z == 8)
	{
		gotoxy(x, y);
		printf("");
	}

	else if (z == 100)//흑돌
	{
		gotoxy(x, y);
		TextColor(128);
		printf("●");
		TextColor(143);
	}
	else if (z == 101)//백돌
	{
		gotoxy(x, y);
		printf("●");
	}
	else if (z == 99)//안됨
	{
		gotoxy(x, y);
		TextColor(140);
		printf("Ｘ");
		TextColor(143);
	}
	else if (z == 1100)//흑돌 복구
	{

		gotoxy(x, y);
		TextColor(128);
		printf("●");
		TextColor(143);
	}
	else if (z == 1101)//백돌 복구
	{
		gotoxy(x, y);
		printf("●");
	}
	else if (z == 17)//무정의 복구
	{
		gotoxy(x, y);
		printf("┿");
	}
}
