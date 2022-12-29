#include "main.h"

int rull_check()
{


	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{

			if (S_p[i][j] == turn)//각 순서별 (흑돌과 백돌)
			{
				//한줄에 같은거 5개 //i가 x, j가 y
				if (i + 4 < 11)
					if (S_p[i][j] == turn && S_p[i + 1][j] == turn && S_p[i + 2][j] == turn && S_p[i + 3][j] == turn && S_p[i + 4][j] == turn)
					{
						switch (turn)
						{
						case 0:
						{
							return(1);
							break;
						}
						case 1:
						{
							return(2);
							break;
						}
						}
					}
				//세로선 5개
				if (j + 4 < 11)
					if (S_p[i][j] == turn && S_p[i][j + 1] == turn && S_p[i][j + 2] == turn && S_p[i][j + 3] == turn && S_p[i][j + 4] == turn)
					{
						switch (turn)
						{
						case 0:
						{
							return(1);
							break;
						}
						case 1:
						{
							return(2);
							break;
						}
						}
					}
				//대각선 좌상우하
				if (i + 4 < 11 && j + 4 < 11)
					if (S_p[i][j] == turn && S_p[i + 1][j + 1] == turn && S_p[i + 2][j + 2] == turn && S_p[i + 3][j + 3] == turn && S_p[i + 4][j + 4] == turn)
					{
						switch (turn)
						{
						case 0:
						{
							return(1);
							break;
						}
						case 1:
						{
							return(2);
							break;
						}
						}
					}
				if (j >= 4)//대각선 우상좌하
				{
					if (i + 4 < 11 && j - 4 >= 0)
						if (S_p[i][j] == turn && S_p[i + 1][j - 1] == turn && S_p[i + 2][j - 2] == turn && S_p[i + 3][j - 3] == turn && S_p[i + 4][j - 4] == turn)
						{
							switch (turn)
							{
							case 0:
							{
								return(1);
								break;
							}
							case 1:
							{
								return(2);
								break;
							}
							}
						}
				}
			}

		}
	}
	return(0);
}


int double_3(int seq_x, int seq_y, int posi_x, int posi_y)
{
	gotoxy(8, 35);
	printf("       ");
	gotoxy(8, 37);
	printf("       ");
	gotoxy(8, 38);
	printf("       ");
	gotoxy(16, 35);
	printf("       ");
	gotoxy(16, 37);
	printf("       ");
	gotoxy(16, 38);
	printf("       ");
	int c = 0;
	int Test[11][11];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			Test[i][j] = S_p[i][j];
		}
	}
	Test[seq_x][seq_y] = 0;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			//가로줄 완성

			if (Test[i][j] == 0 && Test[i + 1][j] == 0 && Test[i + 2][j] == 0)
				if (i + 2 < 11)
				{
					for (int k = 0; k < 3; k++)
					{
						if (i + k < 11)
						{
							if (j >= 0 && j + 2 < 11)
								if (Test[i + k][j] == 0 && Test[i + k][j + 1] == 0 && Test[i + k][j + 2] == 0)
								{
									if (Test[i + k][j + 3] != 1 && Test[i + k][j - 1] != 1) //흰돌이 앞이나 뒤를 막고 있지 않다.
									{
										gotoxy(posi_x, posi_y);
										printf("    ");
										m_map(posi_x, posi_y, 7);
										c++;
										gotoxy(8, 35);
										printf("동작1");
										break;
									}
								}

							//1번째 세로줄-2
							if (c == 0)
								if (j - 1 >= 0 && j + 1 < 11)
									if (Test[i + k][j - 1] == 0 && Test[i + k][j] == 0 && Test[i + k][j + 1] == 0)
									{
										if (Test[i + k][j + 2] != 1 && Test[i + k][j - 2] != 1) //흰돌이 앞이나 뒤를 막고 있지 않다.
										{
											gotoxy(posi_x, posi_y);
											printf("    ");
											m_map(posi_x, posi_y, 7);
											c++;
											gotoxy(8, 37);
											printf("동작2");
											break;
										}
									}


							//1번째 세로줄-3
							if (c == 0)
								if (j - 2 >= 0 && j < 11)
									if (Test[i + k][j - 2] == 0 && Test[i + k][j - 1] == 0 && Test[i + k][j] == 0)
									{
										if (Test[i + k][j - 3] != 1 && Test[i + k][j + 1] != 1) //흰돌이 앞이나 뒤를 막고 있지 않다.
										{
											gotoxy(posi_x, posi_y);
											printf("    ");
											m_map(posi_x, posi_y, 7);
											c++;
											gotoxy(8, 38);
											printf("동작3");
											break;
										}
									}
						}
					}
				}

			//세로줄 완성
			if (c == 0)
				if (Test[i][j] == 0 && Test[i][j + 1] == 0 && Test[i][j + 2] == 0)
					if (j + 2 < 11)
					{
						for (int k = 0; k < 3; k++)
						{
							if (j + k < 11)
							{
								//1번째 가로줄-1
								if (i >= 0 && i + 2 < 11)
									if (Test[i][j + k] == 0 && Test[i + 1][j + k] == 0 && Test[i + 2][j + k] == 0)
									{
										if (Test[i - 1][j + k] != 1 && Test[i + 3][j + k] != 1) //흰돌이 앞이나 뒤를 막고 있지 않다.
										{
											gotoxy(posi_x, posi_y);
											printf("    ");
											m_map(posi_x, posi_y, 7);
											c++;
											gotoxy(16, 35);
											printf("동작4");
											break;
										}
									}


								//1번째 가로줄-2
								if (c == 0)
									if (i - 1 >= 0 && i + 1 < 11)
										if (Test[i - 1][j + k] == 0 && Test[i][j + k] == 0 && Test[i + 1][j + k] == 0)
										{
											if (Test[i - 2][j + k] != 1 && Test[i + 2][j + k] != 1) //흰돌이 앞이나 뒤를 막고 있지 않다.
											{
												gotoxy(posi_x, posi_y);
												printf("    ");
												m_map(posi_x, posi_y, 7);
												c++;
												gotoxy(16, 37);
												printf("동작5");
												break;
											}
										}


								//1번째 가로줄-3
								if (c == 0)
									if (i - 2 >= 0 && i < 11)
										if (Test[i - 2][j + k] == 0 && Test[i - 1][j + k] == 0 && Test[i][j + k] == 0)
										{
											if (Test[i - 3][j + k] != 1 && Test[i + 1][j + k] != 1) //흰돌이 앞이나 뒤를 막고 있지 않다.
											{
												gotoxy(posi_x, posi_y);
												printf("    ");
												m_map(posi_x, posi_y, 7);
												c++;
												gotoxy(16, 38);
												printf("동작6");
												break;
											}
										}
							}

						}
					}
		}
	}
	if (c == 0)
	{
		return(0);
	}
	else if (c != 0)
	{
		return(1);
	}
	else
	{
		return(0);
	}

}


int six_player_0(int seq_x, int seq_y, int posi_x, int posi_y)  //6목
{
	int c = 0;
	int Test[11][11];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			Test[i][j] = S_p[i][j];
		}
	}
	Test[seq_x][seq_y] = 0;


	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (Test[i][j] == 0 && Test[i + 1][j] == 0 && Test[i + 2][j] == 0 && Test[i + 3][j] == 0 && Test[i + 4][j] == 0 && Test[i + 5][j] == 0)
			{
				option_3(posi_x, posi_y);
				c++;
				break;
			}

			if (Test[i][j] == 0 && Test[i][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i][j + 3] == 0 && Test[i][j + 4] == 0 && Test[i][j + 5] == 0)
			{
				option_3(posi_x, posi_y);
				c++;
				break;
			}

		}
	}
	if (c == 0)
	{
		return(0);
	}
	else if (c != 0)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int double_4(int seq_x, int seq_y, int posi_x, int posi_y)
{
	int c = 0;
	int Test[11][11];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			Test[i][j] = S_p[i][j];
		}
	}
	Test[seq_x][seq_y] = 0;


	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			//좌상우하 대각과 대각선
			if (Test[i][j] == 0 && Test[i + 1][j + 1] == 0 && Test[i + 2][j + 2] == 0 && Test[i + 3][j + 3] == 0)
			{
				//_1
				if (c == 0)
					if (Test[i + 3][j - 3] == 0 && Test[i + 2][j - 2] == 0 && Test[i + 1][j - 1] == 0 && Test[i][j] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 4][j - 2] == 0 && Test[i + 3][j - 1] == 0 && Test[i + 2][j] == 0 && Test[i + 1][j + 1] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 5][j - 1] == 0 && Test[i + 4][j] == 0 && Test[i + 3][j + 1] == 0 && Test[i + 2][j + 2] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 6][j] == 0 && Test[i + 5][j + 1] == 0 && Test[i + 4][j + 2] == 0 && Test[i + 3][j + 3] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				//_2
				if (c == 0)
					if (Test[i + 2][j - 2] == 0 && Test[i + 1][j - 1] == 0 && Test[i][j] == 0 && Test[i - 1][j + 1] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 3][j - 1] == 0 && Test[i + 2][j] == 0 && Test[i + 1][j + 1] == 0 && Test[i][j + 2] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 4][j] == 0 && Test[i + 3][j + 1] == 0 && Test[i + 2][j + 2] == 0 && Test[i + 1][j + 3] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 5][j + 1] == 0 && Test[i + 4][j + 2] == 0 && Test[i + 3][j + 3] == 0 && Test[i + 2][j + 4] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				//_3
				if (c == 0)
					if (Test[i + 1][j - 1] == 0 && Test[i][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i - 2][j + 2] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 2][j] == 0 && Test[i + 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i - 1][j + 3] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 3][j + 1] == 0 && Test[i + 2][j + 2] == 0 && Test[i + 1][j + 3] == 0 && Test[i][j + 4] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 4][j + 2] == 0 && Test[i + 3][j + 3] == 0 && Test[i + 2][j + 4] == 0 && Test[i + 1][j + 5] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				//_4
				if (c == 0)
					if (Test[i][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i - 2][j + 2] == 0 && Test[i - 3][j + 3] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i - 1][j + 3] == 0 && Test[i - 2][j + 4] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 2][j + 2] == 0 && Test[i + 1][j + 3] == 0 && Test[i][j + 4] == 0 && Test[i - 1][j + 5] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
				if (c == 0)
					if (Test[i + 3][j + 3] == 0 && Test[i + 2][j + 4] == 0 && Test[i + 1][j + 5] == 0 && Test[i][j + 6] == 0)
					{
						option_3(posi_x, posi_y);
						c++;
						break;
					}
			}

			//가로줄 완성
			if (c == 0)
				if (Test[i][j] == 0 && Test[i + 1][j] == 0 && Test[i + 2][j] == 0 && Test[i + 3][j] == 0)
				{
					if (i + 3 < 11)
					{
						for (int k = 0; k < 4; k++)
						{
							if (i + k < 11)
							{
								if (c == 0)
									if (j >= 0 && j + 3 < 11)
										if (Test[i + k][j] == 0 && Test[i + k][j + 1] == 0 && Test[i + k][j + 2] && Test[i + k][j + 3] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}

								//1번째 세로줄-2
								if (c == 0)
									if (j - 1 >= 0 && j + 2 < 11)
										if (Test[i + k][j - 1] == 0 && Test[i + k][j] == 0 && Test[i + k][j + 1] == 0 && Test[i + k][j + 2] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}

								//1번째 세로줄-3
								if (c == 0)
									if (j - 2 >= 0 && j + 1 < 11)
										if (Test[i + k][j - 2] == 0 && Test[i + k][j - 1] == 0 && Test[i + k][j] == 0 && Test[i + k][j + 1] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}

								//1번째 세로줄-4
								if (c == 0)
									if (j - 3 >= 0 && j < 11)
										if (Test[i + k][j - 3] == 0 && Test[i + k][j - 2] == 0 && Test[i + k][j - 1] == 0 && Test[i + k][j] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}

							}
						}
					}
					//가로 후 좌상 우하 대각선 인식 _3칸 위로
					if (c == 0)
						if (Test[i][j] == 0 && Test[i - 1][j - 1] == 0 && Test[i - 2][j - 2] == 0 && Test[i - 3][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 1][j] == 0 && Test[i][j - 1] == 0 && Test[i - 1][j - 2] == 0 && Test[i - 2][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 2][j] == 0 && Test[i + 1][j - 1] == 0 && Test[i][j - 2] == 0 && Test[i - 1][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 3][j] == 0 && Test[i + 2][j - 1] == 0 && Test[i + 1][j - 2] == 0 && Test[i][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 좌상 우하 대각선 인식 _2칸 위로
					if (c == 0)
						if (Test[i + 1][j + 1] == 0 && Test[i][j] == 0 && Test[i - 1][j - 1] == 0 && Test[i - 2][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 2][j + 1] == 0 && Test[i + 1][j] == 0 && Test[i][j - 1] == 0 && Test[i - 1][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 3][j + 1] == 0 && Test[i + 2][j] == 0 && Test[i + 1][j - 1] == 0 && Test[i][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 4][j + 1] == 0 && Test[i + 3][j] == 0 && Test[i + 2][j - 1] == 0 && Test[i + 1][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 좌상 우하 대각선 인식 _1칸 위로
					if (c == 0)
						if (Test[i + 2][j + 2] == 0 && Test[i + 1][j + 1] == 0 && Test[i][j] == 0 && Test[i - 1][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 3][j + 2] == 0 && Test[i + 2][j + 1] == 0 && Test[i + 1][j] == 0 && Test[i][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 4][j + 2] == 0 && Test[i + 3][j + 1] == 0 && Test[i + 2][j] == 0 && Test[i + 1][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 5][j + 2] == 0 && Test[i + 4][j + 1] == 0 && Test[i + 3][j] == 0 && Test[i + 2][j + 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 좌상 우하 대각선 인식 _0칸 위로
					if (c == 0)
						if (Test[i + 3][j + 3] == 0 && Test[i + 2][j + 2] == 0 && Test[i + 1][j + 1] == 0 && Test[i][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 4][j + 3] == 0 && Test[i + 3][j + 2] == 0 && Test[i + 2][j + 1] == 0 && Test[i + 1][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 5][j + 3] == 0 && Test[i + 4][j + 2] == 0 && Test[i + 3][j + 1] == 0 && Test[i + 2][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 6][j + 3] == 0 && Test[i + 5][j + 2] == 0 && Test[i + 4][j + 1] == 0 && Test[i + 3][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 우상 좌하 대각선 인식 _3칸 위로
					if (c == 0)
						if (Test[i + 3][j] == 0 && Test[i + 4][j - 1] == 0 && Test[i + 5][j - 2] == 0 && Test[i + 6][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 2][j] == 0 && Test[i + 3][j - 1] == 0 && Test[i + 4][j - 2] == 0 && Test[i + 5][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 1][j] == 0 && Test[i + 2][j - 1] == 0 && Test[i + 3][j - 2] == 0 && Test[i + 4][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i][j] == 0 && Test[i + 1][j - 1] == 0 && Test[i + 2][j - 2] == 0 && Test[i + 3][j - 3] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 우상 좌하 대각선 인식 _2칸 위로
					if (c == 0)
						if (Test[i + 2][j + 1] == 0 && Test[i + 3][j] == 0 && Test[i + 4][j - 1] == 0 && Test[i + 5][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i + 1][j + 1] == 0 && Test[i + 2][j] == 0 && Test[i + 3][j - 1] == 0 && Test[i + 4][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i][j + 1] == 0 && Test[i + 1][j] == 0 && Test[i + 2][j - 1] == 0 && Test[i + 3][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i - 1][j + 1] == 0 && Test[i][j] == 0 && Test[i + 1][j - 1] == 0 && Test[i + 2][j - 2] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 우상 좌하 대각선 인식 _1칸 위로
					if (c == 0)
						if (Test[i + 1][j + 2] == 0 && Test[i + 2][j + 1] == 0 && Test[i + 3][j] == 0 && Test[i + 4][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i][j + 2] == 0 && Test[i + 1][j + 1] == 0 && Test[i + 2][j] == 0 && Test[i + 3][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i - 1][j + 2] == 0 && Test[i][j + 1] == 0 && Test[i + 1][j] == 0 && Test[i + 2][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i - 2][j + 2] == 0 && Test[i - 1][j + 1] == 0 && Test[i][j] == 0 && Test[i + 1][j - 1] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					//가로 후 우상 좌하 대각선 인식 _0칸 위로
					if (c == 0)
						if (Test[i][j + 3] == 0 && Test[i + 1][j + 2] == 0 && Test[i + 2][j + 1] == 0 && Test[i + 3][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i - 1][j + 3] == 0 && Test[i][j + 2] == 0 && Test[i + 1][j + 1] == 0 && Test[i + 2][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i - 2][j + 3] == 0 && Test[i - 1][j + 2] == 0 && Test[i][j + 1] == 0 && Test[i + 1][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}
					if (c == 0)
						if (Test[i - 3][j + 3] == 0 && Test[i - 2][j + 2] == 0 && Test[i - 1][j + 1] == 0 && Test[i][j] == 0)
						{
							option_3(posi_x, posi_y);
							c++;
							break;
						}

				}
			//세로줄 완성
			if (c == 0)
				if (Test[i][j] == 0 && Test[i][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i][j + 3] == 0)
				{
					if (j + 3 < 11)
					{
						for (int k = 0; k < 4; k++)
						{
							if (j + k < 11)
							{
								//1번째 가로줄-1
								if (i >= 0 && i + 3 < 11)
									if (Test[i][j + k] == 0 && Test[i + 1][j + k] == 0 && Test[i + 2][j + k] == 0 && Test[i + 3][j + k] == 0)
									{
										option_3(posi_x, posi_y);
										c++;
										break;
									}

								//1번째 가로줄-2
								if (c == 0)
									if (i - 1 >= 0 && i + 2 < 11)
										if (Test[i - 1][j + k] == 0 && Test[i][j + k] == 0 && Test[i + 1][j + k] == 0 && Test[i + 2][j + k] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}

								//1번째 가로줄-3
								if (c == 0)
									if (i - 2 >= 0 && i + 1 < 11)
										if (Test[i - 2][j + k] == 0 && Test[i - 1][j + k] == 0 && Test[i][j + k] == 0 && Test[i + 1][j + k] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}

								//1번째 가로줄-4
								if (c == 0)
									if (i - 2 >= 0 && i < 11)
										if (Test[i - 3][j + k] == 0 && Test[i - 2][j + k] == 0 && Test[i - 1][j + k] == 0 && Test[i][j + k] == 0)
										{
											option_3(posi_x, posi_y);
											c++;
											break;
										}
							}


						}

						//세로 후 좌상 우하 대각선 인식 _3칸 위로
						if (c == 0)
							if (Test[i - 3][j - 3] == 0 && Test[i - 2][j - 2] == 0 && Test[i - 1][j - 1] == 0 && Test[i][j] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 3][j - 2] == 0 && Test[i - 2][j - 1] == 0 && Test[i - 1][j] == 0 && Test[i][j + 1] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 3][j - 1] == 0 && Test[i - 2][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i][j + 2] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 3][j] == 0 && Test[i - 2][j + 1] == 0 && Test[i - 1][j + 2] == 0 && Test[i][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 좌상 우하 대각선 인식 _2칸 위로
						if (c == 0)
							if (Test[i - 2][j - 2] == 0 && Test[i - 1][j - 1] == 0 && Test[i][j] == 0 && Test[i + 1][j + 1] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 2][j - 1] == 0 && Test[i - 1][j] == 0 && Test[i][j + 1] == 0 && Test[i + 1][j + 2] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 2][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i + 1][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 2][j + 1] == 0 && Test[i - 1][j + 2] == 0 && Test[i][j + 3] == 0 && Test[i + 1][j + 4] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 좌상 우하 대각선 인식 _1칸 위로
						if (c == 0)
							if (Test[i - 1][j - 1] == 0 && Test[i - 1][j] == 0 && Test[i][j + 1] == 0 && Test[i + 1][j + 2] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 1][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i + 1][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 1][j + 1] == 0 && Test[i - 1][j + 2] == 0 && Test[i][j + 3] == 0 && Test[i + 1][j + 4] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i - 1][j + 2] == 0 && Test[i - 1][j + 3] == 0 && Test[i][j + 4] == 0 && Test[i + 1][j + 5] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 좌상 우하 대각선 인식 _0칸 위로
						if (c == 0)
							if (Test[i][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i + 1][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i][j + 1] == 0 && Test[i - 1][j + 2] == 0 && Test[i][j + 3] == 0 && Test[i + 1][j + 4] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i][j + 2] == 0 && Test[i - 1][j + 3] == 0 && Test[i][j + 4] == 0 && Test[i + 1][j + 5] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i][j + 3] == 0 && Test[i - 1][j + 4] == 0 && Test[i][j + 5] == 0 && Test[i + 1][j + 6] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 우상좌하 대각선 인식 _3칸 위로
						if (c == 0)
							if (Test[i + 3][j - 3] == 0 && Test[i + 2][j - 2] == 0 && Test[i + 1][j - 1] == 0 && Test[i][j] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 3][j - 2] == 0 && Test[i + 2][j - 1] == 0 && Test[i + 1][j] == 0 && Test[i][j + 1] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 3][j - 1] == 0 && Test[i + 2][j] == 0 && Test[i + 1][j + 1] == 0 && Test[i][j + 2] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 3][j] == 0 && Test[i + 2][j + 1] == 0 && Test[i + 1][j + 2] == 0 && Test[i][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 우상좌하 대각선 인식 _2칸 위로
						if (c == 0)
							if (Test[i + 2][j - 2] == 0 && Test[i + 1][j - 1] == 0 && Test[i][j] == 0 && Test[i - 1][j + 1] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 2][j - 1] == 0 && Test[i + 1][j] == 0 && Test[i][j + 1] == 0 && Test[i - 1][j + 2] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 2][j] == 0 && Test[i + 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i - 1][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 2][j + 1] == 0 && Test[i + 1][j + 2] == 0 && Test[i][j + 3] == 0 && Test[i - 1][j + 4] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 우상좌하 대각선 인식 _1칸 위로
						if (c == 0)
							if (Test[i + 1][j - 1] == 0 && Test[i][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i - 2][j + 2] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 1][j] == 0 && Test[i][j + 1] == 0 && Test[i - 1][j + 2] == 0 && Test[i - 2][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 1][j + 1] == 0 && Test[i][j + 2] == 0 && Test[i - 1][j + 3] == 0 && Test[i - 2][j + 4] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i + 1][j + 2] == 0 && Test[i][j + 3] == 0 && Test[i - 1][j + 4] == 0 && Test[i - 2][j + 5] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						//세로 후 우상좌하 대각선 인식 _0칸 위로
						if (c == 0)
							if (Test[i][j] == 0 && Test[i - 1][j + 1] == 0 && Test[i - 2][j + 2] == 0 && Test[i - 3][j + 3] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i][j + 1] == 0 && Test[i - 1][j + 2] == 0 && Test[i - 2][j + 3] == 0 && Test[i - 3][j + 4] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i][j + 2] == 0 && Test[i - 1][j + 3] == 0 && Test[i - 2][j + 4] == 0 && Test[i - 3][j + 5] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
						if (c == 0)
							if (Test[i][j + 3] == 0 && Test[i - 1][j + 4] == 0 && Test[i - 2][j + 5] == 0 && Test[i - 3][j + 6] == 0)
							{
								option_3(posi_x, posi_y);
								c++;
								break;
							}
					}
				}
		}
	}
	if (c == 0)
	{
		return(0);
	}
	else if (c != 0)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}