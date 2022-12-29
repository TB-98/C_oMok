#include "main.h"

void display_player()
{
	gotoxy(0, 0);
	deco51;
	gotoxy(32, 2);
	printf("vs");
	gotoxy(16, 3);
	printf("�浹(����)");
	gotoxy(44, 3);
	printf("�鵹(�İ�)");
	gotoxy(28, 5);
	printf("�� �ռ�:  %d", turn_t);
	gotoxy(0, 6);
	deco51;
	gotoxy(45, 37);
	printf("����: S");
	gotoxy(45, 38);
	printf("������: ESC");
	switch (turn)
	{
	case 0:
	{
		TextColor(252);
		gotoxy(12, 2);
		printf("<Player  1>");
		TextColor(143);
		gotoxy(42, 2);
		printf(" Player  2 ");

		break;
	}
	case 1:
	{
		TextColor(143);
		gotoxy(12, 2);
		printf(" Player  1 ");
		TextColor(252);
		gotoxy(42, 2);
		printf("<Player  2>");
		TextColor(143);
		break;
	}

	}

	switch (function_disable)
	{
	case 0:
	{
		gotoxy(4, 35);
		printf("                                                         ");
		gotoxy(4, 35);
		printf("������� Ȱ�� (*��Ȱ��='X')");
		break;
	}
	case 1:
	{
		gotoxy(4, 35);
		printf("                                                         ");
		gotoxy(4, 35);
		printf("������� ��Ȱ�� (*Ȱ��ȭ='Z')");
		break;
	}

	}

}

void winner(int winner)
{
	FILE* rank,*rank_count;
	int rank_to=0;
	struct tm* now;
	char name[20];
	Screen(40, 20);
	m_map(4, 2, 3);
	m_map(4, 4, 5);
	m_map(36, 2, 4);
	m_map(36, 4, 6);
	m_map(4, 3, 1);
	m_map(36, 3, 1);
	for (int i = 6; i < 36; i++)
	{
		m_map(i, 2, 0);
		m_map(i, 4, 0);
	}
	gotoxy(12, 3);
	printf("Congratulation!");
	gotoxy(12, 6);
	printf("****Winner****");
	gotoxy(14, 8);
	printf("Player %d!", winner);
	gotoxy(8, 12);
	printf("��ŷ�� ����� �̸�(�ִ� 8��)");
	gotoxy(18, 13);
	printf(":");
	scanf("%s", name);
	gotoxy(6, 15);
	printf("%s�� ����� �Ϸ�Ǿ����ϴ�.", name);


	time_t  now_t;
	time(&now_t);

	now = localtime(&now_t);

	rank_count = fopen("rank_count.txt", "r");
	if (rank_count != NULL)
	{
		fscanf(rank_count, "%d", &rank_to);
		fclose(rank_count);
	}

	rank_to++;
	
	if (rank_to > 9)
	{
		rank_to = 1;
		rank = fopen("rank.txt", "w");
		fclose(rank);
	}

	rank_count = fopen("rank_count.txt", "w");
	fprintf(rank_count,"%d",rank_to);
	fclose(rank_count);
	

	rank = fopen("rank.txt", "a");
	fprintf(rank, "%d. %d�� %d�� %d�� %d��\n", rank_to, now->tm_mon+1, now->tm_mday, now->tm_hour, now->tm_min);
	fprintf(rank, "\t%s�� �¸�!(�� %d��)\n", name, turn_t + 1);

	fclose(rank);

	for (int i = 3; i > 0; i--)
	{
		gotoxy(10, 16);
		printf("%d�� �� ����ȭ������ �̵�", i);
		S1;
	}

	clear;
	Screen(50, 21);
	main_second();
}

void reset()
{
	for (int i = -5; i < 6; i++)
	{
		for (int j = -5; j < 6; j++)
		{
			erease_r(i, j);
		}
	}
}


void option_3(int posi_x, int posi_y)
{
	gotoxy(posi_x, posi_y);
	printf("    ");
	m_map(posi_x, posi_y, 7);
}

void warning()
{
	gotoxy(8, 36);
	TextColor(252);
	printf("�ش���ġ�� ���� �� �����ϴ�.");
	TextColor(143);
}

void erease_r(int x, int y)//Ŀ���� ��ġ�� ������ ���� ����
{

	int seq_x, seq_y;//�迭�� ��ȯ
	int posi_x, posi_y;  //��ǥ�� ��ȯ

	seq_x = 0;
	seq_y = 0;

	seq_x = print_play_x_seq(x);
	seq_y = print_play_y_seq(y);
	posi_x = print_play_x(x);
	posi_y = print_play_y(y);


	if (S_p[seq_x][seq_y] == 0)//�浹��ġ
	{
		m_map(posi_x, posi_y, 1100);
	}
	else if (S_p[seq_x][seq_y] == 1)//�鵹��ġ
	{
		m_map(posi_x, posi_y, 1101);
	}
	else//�ƹ��͵� ������ġ
	{
		TextColor(143);
		gotoxy(posi_x, posi_y);
		printf("    ");
		m_map(posi_x, posi_y, 7);
	}
}