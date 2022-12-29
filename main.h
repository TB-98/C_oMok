#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define clear system("cls")
#define erease printf("\b\b\b\b\b\b\b\b\b\b\b\b");
#define p_n printf("\n"); 
#define ptest printf("\n**test**\n")
#define S1 Sleep(1000);
#define S05 Sleep(500);
#define S075 Sleep(750);
#define ere51 for(int i=0;i<51;i++)printf("\b")
#define ere40 for(int i=0;i<39;i++)printf("\b")
#define test while (1){if (_kbhit()){exit(-1);}}
#define deco51 for(int i=0;i<64;i++)printf("*")

void main_first();
void main_second();
void memu_input_1();
void Gaming_mode();
void ranking_system();
void load_data();
void play_solo();
void play_dual();
void Screen(int cols, int lines);
void gotoxy(int x, int y);
void Cursor(int onoff);
void TextColor(int c);
void C_pcol_game(int pcount);
void C_pcol_main(int pcount);
void m_map(int, int, int);
void map();
void play_input();
void play_in();
void print_play(int, int, int);
int print_play_y(int y);
int print_play_x(int x);
void m_main(int x, int y, int z);
int print_play_x_seq(int x);
int print_play_y_seq(int y);
int rull_check();
void display_player();
void erease_r(int, int);
void warning();
int double_3(int, int, int, int);
int double_4(int, int, int, int);
void save_data();
void option_3(int posi_x, int posi_y);
void reset();
void winner(int);
void intime();
int six_player_0(int seq_x, int seq_y, int posi_x, int posi_y);
void file_null();
void dis_play_input();
void function_disable_play();
void dis_print_play(int x, int y, int enter_step);

int function_disable;
int S_p[11][11]; //중복방지 체크및 여러가지 용도
int turn;
int turn_t;