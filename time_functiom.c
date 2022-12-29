#include "main.h"

void intime()
{
	struct tm* now;
	time_t  now_t;

	time(&now_t);

	now = localtime(&now_t);
	TextColor(143);
	gotoxy(28, 20);
	printf("%d일 %d시 %d분 %d초   ", now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
}

void TextColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void gotoxy(int x, int y)   //출력위치 지정
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void Screen(int cols, int lines)
{
	char str[100];
	sprintf(str, "mode con:cols=%d lines=%d", cols, lines);
	system(str);
}

void Cursor(int onoff)  // OFF:0, on:1
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = (onoff == 1);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}
