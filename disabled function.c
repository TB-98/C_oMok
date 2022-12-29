#include "main.h"

void function_disable_play() //판정기능 비활성화
{
	int end = 0;
	while (1)
	{
		display_player();
		dis_play_input();
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

void dis_play_input()
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
			gotoxy(8, 36);
			printf("                              ");
			input_c = _getch();
			if (input_c == '\r')
			{
				enter_step = 1;
				dis_print_play(x_step, y_step, enter_step);
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
					dis_print_play(x_step, y_step, enter_step);
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
					dis_print_play(x_step, y_step, enter_step);
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
					dis_print_play(x_step, y_step, enter_step);
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
					dis_print_play(x_step, y_step, enter_step);
					break;
					;//오른쪽
				}
			}
		}

	}
}

void dis_print_play(int x, int y, int enter_step)//입력 좌표가져오기
{

	int posi_x, posi_y;  //좌표로 변환
	int seq_x, seq_y;//배열로 변환
	int turn_color = 0;

	posi_x = print_play_x(x);
	posi_y = print_play_y(y);
	seq_x = print_play_x_seq(x);
	seq_y = print_play_y_seq(y);


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
			gotoxy(8, 36);
			TextColor(252);
			printf("해당위치는 놓을 수 없습니다.");
			reset();
			dis_play_input();
		}

		else if (S_p[seq_x][seq_y] != 1 && S_p[seq_x][seq_y] != 0)
		{


			S_p[seq_x][seq_y] = turn;




		}
	}
}