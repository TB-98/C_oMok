#include "main.h"

void memu_input_1()
{
	char memu_input;
	int count = 1;
	C_pcol_main(count);
	while (1)
	{
		memu_input = '\0';
		intime();
		if (_kbhit())
		{
			memu_input = _getch();
			if (memu_input == -32)
			{
				memu_input = _getch();
				switch (memu_input)
				{
				case 80:
					count++;
					C_pcol_main(count);
					break;
				}
			}

			else if (memu_input == '\r')
			{
				count %= 4;
				switch (count)
				{
				case 1: //메뉴1
					TextColor(143);
					clear;
					Gaming_mode();
					break;
				case 2: //메뉴2
					TextColor(143);
					clear;
					load_data();
					break;
				case 3://메뉴3
					TextColor(143);
					clear;
					ranking_system();
					break;
				case 0://메뉴4
					clear;
					TextColor(15);
					exit(-1);
					break;
				}
			}
		}
	}
}


void play_input()
{

	int input_c;
	int x_step;
	int y_step;
	int enter_step;

	y_step = 0;
	x_step = 0;
	enter_step = 0;

	while (1)
	{
		input_c = '\0';
		if (_kbhit()) {
			erease_r(x_step, y_step);
			TextColor(143);
			gotoxy(15, 8);
			printf("                                             ");
			input_c = _getch();
			if (input_c == '\r')
			{
				enter_step = 1;
				print_play(x_step, y_step, enter_step);
				break;
			}
			if (input_c == 88 || input_c == 120)//x버튼 누르면 기능 판정기능 정지
			{
				function_disable = 1;
				function_disable_play();
				break;
			}
			if (input_c == 90 || input_c == 122)//z버튼 누르면 기능 판정기능 활성
			{
				function_disable = 0;
				play_in();
				break;
			}
			if (input_c == 27)//나가기 
			{
				clear;
				Screen(50, 21);
				main_second();
				break;
			}
			if (input_c == 115 || input_c == 83)//s or S 저장 후 나가기 
			{
				save_data();
				break;
			}
			if (input_c == 224)
			{
				input_c = _getch();
				switch (input_c)
				{
				case 72:
					y_step++; //위쪽
					while (y_step > 5)
					{
						y_step--;
						if (y_step == 5)
						{
							break;
						}
					}
					print_play(x_step, y_step, enter_step);
					break;
				case 80:
					y_step--; //아래쪽
					while (y_step < -5)
					{
						y_step++;
						if (y_step == -5)
						{
							break;
						}
					}
					print_play(x_step, y_step, enter_step);
					break;
				case 75:
					x_step--; //왼쪽
					while (x_step < -5)
					{
						x_step++;
						if (x_step == -5)
						{
							break;
						}
					}
					print_play(x_step, y_step, enter_step);
					break;
				case 77:
					x_step++;
					while (x_step > 5)
					{
						x_step--;
						if (x_step == 5)
						{
							break;
						}
					}
					print_play(x_step, y_step, enter_step);
					break;
					;//오른쪽
				}
			}
		}

	}
}


void print_play(int x, int y, int enter_step)//입력 좌표가져오기
{

	int posi_x, posi_y;  //좌표로 변환
	int seq_x, seq_y;//배열로 변환
	int turn_color = 0;
	int c = 0;
	int c_1 = 0;
	int c_2 = 0;

	posi_x = print_play_x(x);
	posi_y = print_play_y(y);
	seq_x = print_play_x_seq(x);
	seq_y = print_play_y_seq(y);

	int win = 0;

	if (turn == 0)
	{
		//c = double_3(seq_x, seq_y, posi_x, posi_y);
		c_1 = double_4(seq_x, seq_y, posi_x, posi_y);
		c_2 = six_player_0(seq_x, seq_y, posi_x, posi_y);
	}

	switch (turn)
	{

	case 0:
	{
		turn_color = 100;//흑돌
		break;
	}
	case 1:
	{
		turn_color = 101;//백돌
		break;
	}

	}

	if (S_p[seq_x][seq_y] == 1 || S_p[seq_x][seq_y] == 0)
	{
		m_map(posi_x, posi_y, 99);
	}
	else if (S_p[seq_x][seq_y] == 10)
	{
		m_map(posi_x, posi_y, turn_color);
	}



	if (enter_step == 1)
	{

		if (S_p[seq_x][seq_y] == 1 || S_p[seq_x][seq_y] == 0)
		{
			gotoxy(15, 8);
			TextColor(252);
			printf("해당위치는 놓을 수 없습니다_(중복)");
			reset();
			play_input();
		}

		else if (S_p[seq_x][seq_y] != 1 && S_p[seq_x][seq_y] != 0)
		{
			if (turn == 0)
			{
				if (c == 0 && c_2 == 0) //쌍삼 아닐때,6목 아닐때
				{

					if (c_1 == 0) //쌍사가 아닐때
					{
						S_p[seq_x][seq_y] = turn;

					}
					else if (c_1 == 1)//쌍사 일때
					{
						S_p[seq_x][seq_y] = turn;
						win = rull_check();
						gotoxy(8, 39);
						if (win == 0)
						{
							S_p[seq_x][seq_y] = 10;
							gotoxy(15, 8);
							TextColor(252);
							printf("해당위치는 놓을 수 없습니다_(4*4)");
							reset();
							play_input();
						}
						else if (win == 1)
						{
							clear;
							winner(win);
						}
					}


				}
				else if (c == 1 && c_2 == 0)//쌍삼일떄
				{
					gotoxy(15, 8);
					TextColor(252);
					printf("해당위치는 놓을 수 없습니다_(3*3)");
					reset();
					play_input();
				}
				else if (c == 1 && c_2 == 1)//쌍삼일떄+6목일떄
				{
					gotoxy(15, 8);
					TextColor(252);
					printf("해당위치는 놓을 수 없습니다_(3*3 / 6)");
					reset();
					play_input();
				}
				else if (c == 0 && c_2 == 1)//6목일떄
				{
					gotoxy(15, 8);
					TextColor(252);
					printf("해당위치는 놓을 수 없습니다_(6)");
					reset();
					play_input();
				}
			}
			else if (turn == 1)
			{
				S_p[seq_x][seq_y] = turn;
			}



		}
	}
}