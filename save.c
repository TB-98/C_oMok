#include "main.h"

void save_data()
{
	clear;
	Screen(50, 20);
	FILE* save, * save_0, * save_1, * save_2, * save_3, * save_4, * save_5, * save_6, * save_7, * save_8, * save_9, * save_10;
	save = fopen("save.txt", "w");
	save_0 = fopen("save_0.txt", "w");
	save_1 = fopen("save_1.txt", "w");
	save_2 = fopen("save_2.txt", "w");
	save_3 = fopen("save_3.txt", "w");
	save_4 = fopen("save_4.txt", "w");
	save_5 = fopen("save_5.txt", "w");
	save_6 = fopen("save_6.txt", "w");
	save_7 = fopen("save_7.txt", "w");
	save_8 = fopen("save_8.txt", "w");
	save_9 = fopen("save_9.txt", "w");
	save_10 = fopen("save_10.txt", "w");


	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			switch (i)
			{
			case 0:
				fprintf(save_0, "%d ", S_p[i][j]);
				break;
			case 1:
				fprintf(save_1, "%d ", S_p[i][j]);
				break;
			case 2:
				fprintf(save_2, "%d ", S_p[i][j]);
				break;
			case 3:
				fprintf(save_3, "%d ", S_p[i][j]);
				break;
			case 4:
				fprintf(save_4, "%d ", S_p[i][j]);
				break;
			case 5:
				fprintf(save_5, "%d ", S_p[i][j]);
				break;
			case 6:
				fprintf(save_6, "%d ", S_p[i][j]);
				break;
			case 7:
				fprintf(save_7, "%d ", S_p[i][j]);
				break;
			case 8:
				fprintf(save_8, "%d ", S_p[i][j]);
				break;
			case 9:
				fprintf(save_9, "%d ", S_p[i][j]);
				break;
			case 10:
				fprintf(save_10, "%d ", S_p[i][j]);
				break;
			}
		}
	}

	fprintf(save, "%d %d", turn, turn_t);

	fclose(save);
	fclose(save_0);
	fclose(save_1);
	fclose(save_2);
	fclose(save_3);
	fclose(save_4);
	fclose(save_5);
	fclose(save_6);
	fclose(save_7);
	fclose(save_8);
	fclose(save_9);
	fclose(save_10);

	gotoxy(12, 5);
	printf("저장이 완료되었습니다.");
	gotoxy(4, 7);
	printf("이어서 플레이는 불러오기를 이용해주세요!");
	for (int i = 3; i > 0; i--)
	{
		ere51;
		gotoxy(12, 9);
		printf("%d초 후 메인화면으로 이동", i);
		S1;
	}
	clear;
	Screen(50, 21);
	main_second();
}