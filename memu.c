#include "main.h"

void C_pcol_main(int pcount) //메뉴 선택시 색상변경
{
	pcount %= 4;
	switch (pcount)
	{
	case 0: //4번 메뉴

		//원복
		gotoxy(50, 17);
		ere51;
		TextColor(143);
		gotoxy(6, 17);
		printf("3.전적\n");

		//변경
		gotoxy(50, 19);
		ere51;
		TextColor(240);
		gotoxy(6, 19);
		printf("4.끝내기\n");
		break;
	case 1: //1번메뉴
		//원복
		gotoxy(50, 19);
		ere51;
		TextColor(143);
		gotoxy(6, 19);
		printf("4.끝내기\n");
		//변경
		gotoxy(50, 13);
		ere51;

		TextColor(240);
		gotoxy(6, 13);
		printf("1.게임시작\n");
		break;
	case 2: //2번 메누
		//원복
		gotoxy(50, 13);
		ere51;
		TextColor(143);
		gotoxy(6, 13);
		printf("1.게임시작\n");
		//변경
		gotoxy(50, 15);
		ere51;

		TextColor(240);
		gotoxy(6, 15);
		printf("2.불러오기\n");
		break;
	case 3: //3번메누
		//원복
		gotoxy(50, 15);
		ere51;
		TextColor(143);
		gotoxy(6, 15);
		printf("2.불러오기\n");
		//변경
		gotoxy(50, 17);
		ere51;

		TextColor(240);
		gotoxy(6, 17);
		printf("3.전적\n");
		break;

	}
}

void Gaming_mode()
{
	char input_mode = 0;
	gotoxy(2, 1);
	printf("1.게임모드 선택");
	gotoxy(4, 4);
	printf("1).1인 대전\n");
	gotoxy(4, 6);
	printf("2).2인 대전\n");
	gotoxy(4, 8);
	printf("3).뒤로가기\n");

	int count = 1;
	C_pcol_game(count);

	while (1) {
		if (_kbhit())
		{
			input_mode = '\0';
			input_mode = _getch();
			if (input_mode == -32)
			{
				input_mode = _getch();
				switch (input_mode)
				{
				case 80:
					count++;
					C_pcol_game(count);
					break;
				}
			}
			else if (input_mode == '\r')
			{
				count %= 3;
				switch (count)
				{
				case 1: //메뉴1
					TextColor(143);
					clear;
					play_solo();
					break;
				case 2: //메뉴2
					TextColor(143);
					clear;
					play_dual();
					break;
				case 0://메뉴3
					TextColor(143);
					clear;
					main_second();
					break;
				}
			}
		}
	}
}


void C_pcol_game(int pcount) //메뉴 선택시 색상변경
{
	pcount %= 3;
	switch (pcount)
	{
	case 0: //3번 메뉴

		//원복
		gotoxy(50, 6);
		ere51;
		TextColor(143);
		gotoxy(4, 6);
		printf("2).2인 대전\n");

		//변경
		gotoxy(50, 8);
		ere51;
		TextColor(240);
		gotoxy(4, 8);
		printf("3).뒤로가기\n");
		break;


	case 1: //1번메뉴
		//원복
		gotoxy(50, 8);
		ere51;
		TextColor(143);
		gotoxy(4, 8);
		printf("3).뒤로가기\n");
		//변경
		gotoxy(50, 4);
		ere51;

		TextColor(240);
		gotoxy(4, 4);
		printf("1).1인 대전\n");
		break;


	case 2: //2번 메누
		//원복
		gotoxy(50, 4);
		ere51;
		TextColor(143);
		gotoxy(4, 4);
		printf("1).1인 대전\n");
		//변경

		gotoxy(50, 6);
		ere51;

		TextColor(240);
		gotoxy(4, 6);
		printf("2).2인 대전\n");
		break;

	}
}

void file_null()
{
	Screen(40, 6);
	gotoxy(2, 1);
	printf("저장된 데이터가 존재하지 않습니다.\n");
	gotoxy(8, 2);
	printf("초기화면으로 이동합니다.");
	for (int i = 3; i > 0; i--)
	{
		ere51;
		gotoxy(8, 4);
		printf("%d초 후 초기화면으로 이동", i);
		S1;
	}
	clear;
	Screen(50, 21);
	main_second();
}

void ranking_system()
{
	int input_c;
	int c = 0;
	FILE* rank;
	rank = fopen("rank.txt", "r");
	if (rank == NULL)
	{
		file_null();
	}

	while ((c = fgetc(rank)) != EOF)
	{
		putchar(c);
	}
	fclose(rank);

	gotoxy(35, 18);
	printf("나가기: ESC");

	input_c = 0;
	while (1)
	{
		if (_kbhit())
		{
			input_c = _getch();
			if (input_c == 27)//나가기 
			{
				clear;
				Screen(50, 21);
				main_second();
			}
		}
	}
}

void load_data()
{

	FILE* save;
	save = fopen("save.txt", "r");

	if (save == NULL)
	{
		file_null();
	}
	else
	{
		FILE* save_0, * save_1, * save_2, * save_3, * save_4, * save_5, * save_6, * save_7, * save_8, * save_9, * save_10;
		save_0 = fopen("save_0.txt", "r");
		save_1 = fopen("save_1.txt", "r");
		save_2 = fopen("save_2.txt", "r");
		save_3 = fopen("save_3.txt", "r");
		save_4 = fopen("save_4.txt", "r");
		save_5 = fopen("save_5.txt", "r");
		save_6 = fopen("save_6.txt", "r");
		save_7 = fopen("save_7.txt", "r");
		save_8 = fopen("save_8.txt", "r");
		save_9 = fopen("save_9.txt", "r");
		save_10 = fopen("save_10.txt", "r");

		fscanf(save, "%d %d", &turn, &turn_t);
		fclose(save);

		fscanf(save_0, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[0][0], &S_p[0][1], &S_p[0][2], &S_p[0][3], &S_p[0][4], &S_p[0][5], &S_p[0][6], &S_p[0][7], &S_p[0][8], &S_p[0][9], &S_p[0][10]);
		fclose(save_0);

		fscanf(save_1, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[1][0], &S_p[1][1], &S_p[1][2], &S_p[1][3], &S_p[1][4], &S_p[1][5], &S_p[1][6], &S_p[1][7], &S_p[1][8], &S_p[1][9], &S_p[1][10]);
		fclose(save_1);

		fscanf(save_2, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[2][0], &S_p[2][1], &S_p[2][2], &S_p[2][3], &S_p[2][4], &S_p[2][5], &S_p[2][6], &S_p[2][7], &S_p[2][8], &S_p[2][9], &S_p[2][10]);
		fclose(save_2);

		fscanf(save_3, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[3][0], &S_p[3][1], &S_p[3][2], &S_p[3][3], &S_p[3][4], &S_p[3][5], &S_p[3][6], &S_p[3][7], &S_p[3][8], &S_p[3][9], &S_p[3][10]);
		fclose(save_3);

		fscanf(save_4, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[4][0], &S_p[4][1], &S_p[4][2], &S_p[4][3], &S_p[4][4], &S_p[4][5], &S_p[4][6], &S_p[4][7], &S_p[4][8], &S_p[4][9], &S_p[4][10]);
		fclose(save_4);

		fscanf(save_5, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[5][0], &S_p[5][1], &S_p[5][2], &S_p[5][3], &S_p[5][4], &S_p[5][5], &S_p[5][6], &S_p[5][7], &S_p[5][8], &S_p[5][9], &S_p[5][10]);
		fclose(save_5);

		fscanf(save_6, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[6][0], &S_p[6][1], &S_p[6][2], &S_p[6][3], &S_p[6][4], &S_p[6][5], &S_p[6][6], &S_p[6][7], &S_p[6][8], &S_p[6][9], &S_p[6][10]);
		fclose(save_6);

		fscanf(save_7, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[7][0], &S_p[7][1], &S_p[7][2], &S_p[7][3], &S_p[7][4], &S_p[7][5], &S_p[7][6], &S_p[7][7], &S_p[7][8], &S_p[7][9], &S_p[7][10]);
		fclose(save_7);

		fscanf(save_8, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[8][0], &S_p[8][1], &S_p[8][2], &S_p[8][3], &S_p[8][4], &S_p[8][5], &S_p[8][6], &S_p[8][7], &S_p[8][8], &S_p[8][9], &S_p[8][10]);
		fclose(save_8);

		fscanf(save_9, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[9][0], &S_p[9][1], &S_p[9][2], &S_p[9][3], &S_p[9][4], &S_p[9][5], &S_p[9][6], &S_p[9][7], &S_p[9][8], &S_p[9][9], &S_p[9][10]);
		fclose(save_9);

		fscanf(save_10, "%d %d %d %d %d %d %d %d %d %d %d", &S_p[10][0], &S_p[10][1], &S_p[10][2], &S_p[10][3], &S_p[10][4], &S_p[10][5], &S_p[10][6], &S_p[10][7], &S_p[10][8], &S_p[10][9], &S_p[10][10]);
		fclose(save_10);


		clear;
		map();
		for (int i = -5; i < 6; i++)
		{
			for (int j = -5; j < 6; j++)
			{
				erease_r(i, j);
			}
		}
		play_in();
	}
}

void play_solo()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			S_p[i][j] = 10;
		}
	}
	turn = 0;
	turn_t = 0;
	clear;
	map();

	play_in();
}

void play_dual()
{

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			S_p[i][j] = 10;
		}
	}
	turn = 0;
	turn_t = 0;
	clear;
	map();

	play_in();
}




void play_in()
{

	int end = 0;
	while (1)
	{
		display_player();
		play_input();
		end = rull_check();//배열값 비교
		turn_t++;
		turn++;//turn 0이 플레이어 1,turn 1이 플레이어 2
		turn %= 2;
		if (end == 1 || end == 2)//1일때 플레이어 1, 2일때 2 승리
		{
			clear;
			winner(end);
			break;
		}


	}
}
