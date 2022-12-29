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
				case 1: //�޴�1
					TextColor(143);
					clear;
					Gaming_mode();
					break;
				case 2: //�޴�2
					TextColor(143);
					clear;
					load_data();
					break;
				case 3://�޴�3
					TextColor(143);
					clear;
					ranking_system();
					break;
				case 0://�޴�4
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
			if (input_c == 88 || input_c == 120)//x��ư ������ ��� ������� ����
			{
				function_disable = 1;
				function_disable_play();
				break;
			}
			if (input_c == 90 || input_c == 122)//z��ư ������ ��� ������� Ȱ��
			{
				function_disable = 0;
				play_in();
				break;
			}
			if (input_c == 27)//������ 
			{
				clear;
				Screen(50, 21);
				main_second();
				break;
			}
			if (input_c == 115 || input_c == 83)//s or S ���� �� ������ 
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
					y_step++; //����
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
					y_step--; //�Ʒ���
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
					x_step--; //����
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
					;//������
				}
			}
		}

	}
}


void print_play(int x, int y, int enter_step)//�Է� ��ǥ��������
{

	int posi_x, posi_y;  //��ǥ�� ��ȯ
	int seq_x, seq_y;//�迭�� ��ȯ
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
		turn_color = 100;//�浹
		break;
	}
	case 1:
	{
		turn_color = 101;//�鵹
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
			printf("�ش���ġ�� ���� �� �����ϴ�_(�ߺ�)");
			reset();
			play_input();
		}

		else if (S_p[seq_x][seq_y] != 1 && S_p[seq_x][seq_y] != 0)
		{
			if (turn == 0)
			{
				if (c == 0 && c_2 == 0) //�ֻ� �ƴҶ�,6�� �ƴҶ�
				{

					if (c_1 == 0) //�ֻ簡 �ƴҶ�
					{
						S_p[seq_x][seq_y] = turn;

					}
					else if (c_1 == 1)//�ֻ� �϶�
					{
						S_p[seq_x][seq_y] = turn;
						win = rull_check();
						gotoxy(8, 39);
						if (win == 0)
						{
							S_p[seq_x][seq_y] = 10;
							gotoxy(15, 8);
							TextColor(252);
							printf("�ش���ġ�� ���� �� �����ϴ�_(4*4)");
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
				else if (c == 1 && c_2 == 0)//�ֻ��ϋ�
				{
					gotoxy(15, 8);
					TextColor(252);
					printf("�ش���ġ�� ���� �� �����ϴ�_(3*3)");
					reset();
					play_input();
				}
				else if (c == 1 && c_2 == 1)//�ֻ��ϋ�+6���ϋ�
				{
					gotoxy(15, 8);
					TextColor(252);
					printf("�ش���ġ�� ���� �� �����ϴ�_(3*3 / 6)");
					reset();
					play_input();
				}
				else if (c == 0 && c_2 == 1)//6���ϋ�
				{
					gotoxy(15, 8);
					TextColor(252);
					printf("�ش���ġ�� ���� �� �����ϴ�_(6)");
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