#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "graphic.h"
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>

void cursor()
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void ColorSet(int backGroundColor, int TextColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (backGroundColor << 4) + TextColor);
}
typedef enum ColorKinds {
	black,
	blue,
	green,
	skyBlue,
	red,
	pink,
	Orange,
	white
};

void Money_Square() {
	ColorSet(white, white);
	int y = 4;
	int i = 1;

	for (int next = 4; next <= 74; next += 35) {
		gotoxy(next, y);
		printf("#################################");
		for (i; i < 18; i++) {
			gotoxy(next, y + i);
			printf("##");
			gotoxy(next + 31, y + i);
			printf("##");
		}
		gotoxy(next, y + i);
		i = 1;
		printf("#################################");
	}
	ColorSet(black, white);
}

int get_menu_capital() {
	int x = 10;
	gotoxy(45, 2);
	printf("초기 자본을 선택하세요.");
	gotoxy(0, 10);
	printf("	 __   _____  _____  _____ \n	/  | |  _  ||  _  ||  _  |\n	`| | | | | || | | || | | |\n	 | | | | | || | | || | | |\n	_| |_\\ |_| /\\ |_| /\\ |_| /\n	\\___/ \\___/  \\___/  \\___/");
	gotoxy(44, 10);
	printf("10000");
	gotoxy(80, 10);
	printf("100000");
	gotoxy(0, 4);
	Money_Square();
	gotoxy(x, 24);
	printf("> 게임 시작");
	int key;
	int End = 1;
	while (1) {

		key = getch();
		switch (key) {
		case 224:
			key = getch();
			switch (key) {
			case 75:
				if (x > 10) {
					gotoxy(x, 24);
					printf("          ");
					x = x - 40;
					gotoxy(x, 24);
					printf("> 게임 시작");
				}
				break;

			case 77:
				if (x < 90) {
					gotoxy(x, 24);
					printf("          ");
					x = x + 40;
					gotoxy(x, 24);
					printf("> 게임 시작");
				}
				break;

			default:
				break;
			}
			break;
		case 13:
			system("cls");
			if (x == 10) {
				return 1000;
			}
			else if (x == 50) {
				return 10000;
			}
			else if (x == 90) {
				return 100000;
			}
			End = 0;
			break;

		default:
			break;
		}

		if (End == 0) {
			break;
		}
	}
}

PLAYMODE get_menu_playmode() {
	int x = 50;
	int y = 13;
	int key = 99;
	int select = -1;
	gotoxy(0, 3);
	printf("					 ____          _\n					| ___ \\       | |\n					| |_/ /  ___  | | __  ___  _ __\n					|  __/  / _ \\ | |/ / / _ \\|  __|\n					| |    | (_) ||   < |  __/| |\n					|_|     \\___/ |_|\\_\\ \\___||_|");
	gotoxy(x - 2, y);
	printf("> 싱글플레이");
	gotoxy(x, y + 2);
	printf("멀티플레이");
	gotoxy(x, y + 4);
	printf("게임 종료");

	while (1) {

		key = getch();
		switch (key) {
		case 224:
			key = getch();
			switch (key) {
			case 72:
				if (y > 13) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, y - 2);
					y = y - 2;
					printf(">");
				}
				break;

			case 80:
				if (y < 17) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, y + 2);
					y = y + 2;
					printf(">");
				}
				break;

			default:
				break;
			}
			break;
		case 13:
			system("cls");
			if (y == 13) {
				select = SINGLE;
				return SINGLE;
			}
			else if (y == 15) {
				select = ONLINE;
			}
			else if (y == 17) {
				select = EXIT;
			}
			break;

		default:
			break;
		}

		if (select != -1) {
			break;
		}
	}
}

void set_table() {
	gotoxy(0, 0);
	char table[29][121] =
	{
		{"########################################################################################################################\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"############################                                                                 ###########################\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"##                        ##                                                                 ##                       ##\n"},
		{"########################################################################################################################\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"########################################################################################################################\n"},
	};

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 121; j++)
		{
			if (table[i][j] == '#')
			{
				ColorSet(white, white);
			}
			else if (table[i][j] == ' ')
			{
				ColorSet(black, black);
			}

			printf("%c", table[i][j]);

		}
	}
	ColorSet(black, white);
}

BET get_menu_bet()
{
	printf("");
}

