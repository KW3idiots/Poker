#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "graphic.h"
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>
#include <mmsystem.h>		//추가됨
#pragma comment(lib, "winmm.lib")		//추가됨
#define G 200		//추가됨

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
	white,
	gray
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
	int x = 15;
	gotoxy(45, 2);
	printf("초기 자본을 선택하세요.");
	gotoxy(7, 6);
	printf("1000");
	gotoxy(8, 7);
	printf("WON");
	ColorSet(gray, gray);
	gotoxy(19, 10);
	printf("###");
	gotoxy(18, 11);
	printf("#####");
	gotoxy(15, 12);
	printf("###");
	gotoxy(19, 12);
	printf("###");
	gotoxy(23, 12);
	printf("###");
	gotoxy(14, 13);
	printf("#############");
	gotoxy(15, 14);
	printf("###");
	gotoxy(19, 14);
	printf("###");
	gotoxy(23, 14);
	printf("###");
	gotoxy(20, 15);
	printf("#");
	gotoxy(19, 16);
	printf("###");
	ColorSet(black, white);
	gotoxy(30, 19);
	printf("WON");
	gotoxy(30, 20);
	printf("1000");
	gotoxy(42, 6);
	printf("10000");
	gotoxy(43, 7);
	printf("WON");
	ColorSet(red, red);
	gotoxy(55, 8);
	printf("#");
	gotoxy(54, 9);
	printf("###");
	gotoxy(53, 10);
	printf("#####");
	gotoxy(52, 11);
	printf("#######");
	gotoxy(51, 12);
	printf("#########");
	gotoxy(50, 13);
	printf("###########");
	gotoxy(51, 14);
	printf("#########");
	gotoxy(52, 15);
	printf("#######");
	gotoxy(53, 16);
	printf("#####");
	gotoxy(54, 17);
	printf("###");
	gotoxy(55, 18);
	printf("#");
	ColorSet(black, white);
	gotoxy(65, 19);
	printf("WON");
	gotoxy(64, 20);
	printf("10000");

	gotoxy(77, 6);
	printf("100000");
	gotoxy(78, 7);
	printf("WON");
	ColorSet(gray, gray);
	gotoxy(90, 8);
	printf("#");
	gotoxy(89, 9);
	printf("###");
	gotoxy(88, 10);
	printf("#####");
	gotoxy(87, 11);
	printf("#######");
	gotoxy(85, 12);
	printf("###########");
	gotoxy(84, 13);
	printf("#############");
	gotoxy(84, 14);
	printf("#############");
	gotoxy(85, 15);
	printf("###########");
	gotoxy(90, 16);
	printf("#");
	gotoxy(89, 17);
	printf("###");
	ColorSet(black, white);
	gotoxy(100, 19);
	printf("WON");
	gotoxy(98, 20);
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
				if (x > 15) {
					gotoxy(x, 24);
					printf("          ");
					x = x - 35;
					gotoxy(x, 24);
					printf("> 게임 시작");
					Beep(G, 100);		//추가됨
					Sleep(100);
				}
				break;

			case 77:
				if (x < 85) {
					gotoxy(x, 24);
					printf("          ");
					x = x + 35;
					gotoxy(x, 24);
					printf("> 게임 시작");
					Beep(G, 100);		//추가됨
					Sleep(100);
				}
				break;

			default:
				break;
			}
			break;
		case 13:
			system("cls");
			if (x == 15) {
				Beep(G, 100);		//추가됨
				Sleep(100);
				return 1000;
			}
			else if (x == 50) {
				Beep(G, 100);		//추가됨
				Sleep(100);
				return 10000;
			}
			else if (x == 85) {
				Beep(G, 100);		//추가됨
				Sleep(100);
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
					Beep(G, 100);		//추가됨
					Sleep(100);
				}
				break;

			case 80:
				if (y < 17) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, y + 2);
					y = y + 2;
					printf(">");
					Beep(G, 100);		//추가됨
					Sleep(100);
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
				Beep(G, 100);		//추가됨
				Sleep(100);
				return SINGLE;
			}
			else if (y == 15) {
				select = ONLINE;
				Beep(G, 100);		//추가됨
				Sleep(100);
				return ONLINE;
			}
			else if (y == 17) {
				select = EXIT;
				Beep(G, 100);		//추가됨
				Sleep(100);
				return EXIT;
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
	system("mode con: cols=122 lines=34");
	gotoxy(0, 0);
	char table[33][121] =
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
		{"##                                                                                                                    ##\n"},
		{"##                                                                                                                    ##\n"},
		{"########################################################################################################################\n"},
	};

	for (int i = 0; i < 33; i++)
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
BET get_menu_bet(int* amount)
{
	int key = 99;
	int select = -1;
	int x = 100;
	int y = 22;
	char bet[5][7] = { {'c', 'a', 'l', 'l'}, {'r', 'a', 'i', 's', 'e'}, {'f', 'o', 'l', 'd'}, {'a', 'l', 'l', ' ', 'i', 'n'}, {'c', 'h', 'e', 'c', 'k'} };
	gotoxy(x - 2, y);
	printf("> ");
	for (int i = 0; i < 5; i++) {
		gotoxy(x, y + 2 * i);
		printf("%s", bet[i]);
	}
	while (1) {
		key = getch();
		switch (key) {
		case 224:
			key = getch();
			switch (key) {
			case 72:
				if (y > 22) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, y - 2);
					y = y - 2;
					printf(">");
					Beep(G, 100);
					Sleep(100);
				}
				break;

			case 80:
				if (y < 30) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, y + 2);
					y = y + 2;
					printf(">");
					Beep(G, 100);
					Sleep(100);
				}
				break;

			default:
				break;
			}
			break;
		case 13:
			if (y == 22) {
				select = CALL;
				for (int i = 0; i < 10; i++) {
					gotoxy(98, 22 + i);
					printf("        ");
				}
				Beep(G, 100);
				Sleep(100);
				return CALL;
			}
			else if (y == 24) {
				select = RAISE;
				for (int i = 0; i < 10; i++) {
					gotoxy(98, 22 + i);
					printf("        ");
				}
				Beep(G, 100);
				Sleep(100);

				char bet_input[20];
				int check = 1;

				do {
					if (check == 0) {
						gotoxy(60, 26);
						printf("다시 입력해주십시오.");
					}
					check = 1;
					gotoxy(68, 25);
					printf("                            ");
					gotoxy(60, 25);
					printf("베팅 금액 : ");
					scanf("%s", bet_input);
					for (int i = 0; bet_input[i] != '\0'; i++)
					{
						if (isdigit(bet_input[i])) {
							check += 0;

						}
						else {
							check = 0;
						}
					}
				} while (check == 0);
				gotoxy(60, 25);
				printf("                            ");
				gotoxy(60, 26);
				printf("                            ");
				*amount = atoi(bet_input);
				return RAISE;
			}
			else if (y == 26) {
				select = FOLD;
				for (int i = 0; i < 10; i++) {
					gotoxy(98, 22 + i);
					printf("        ");
				};
				Beep(G, 100);
				Sleep(100);
				return FOLD;
			}
			else if (y == 28) {
				select = ALL_IN;
				for (int i = 0; i < 10; i++) {
					gotoxy(98, 22 + i);
					printf("        ");
				}
				Beep(G, 100);
				Sleep(100);
				return ALL_IN;
			}
			else if (y == 30) {
				select = CHECK;
				for (int i = 0; i < 10; i++) {
					gotoxy(98, 22 + i);
					printf("        ");
				}
				Beep(G, 100);
				Sleep(100);
				return CHECK;
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
void set_card(CARD_SHAPE shape, int num, int player, int card_order) {
	int PLAYER_TABLE[6][2] = { {4, 23}, {4, 3}, {4, 13}, {97, 3}, {97, 13}, {46, 8} };
	char CARD[5][5] = {
		{'#', 'N', '#', '#', '#'},
		{'#', '#', '#', '#', '#'},
		{'#', '#', 'A', '#', '#'},
		{'#', '#', '#', '#', '#'},
		{'#', '#', '#', 'N', '#'},
	};
	if (shape == UNKNOWN_SHAPE) {
		for (int i = 0; i < 5; i++) {
			int x = PLAYER_TABLE[player][0] + 6 * card_order;
			int y = PLAYER_TABLE[player][1] + i;
			gotoxy(x, y);
			for (int j = 0; j < 5; j++) {
				ColorSet(gray, gray);
				printf(" ");
			}
			gotoxy(x + 5, y);
			ColorSet(black, black);
			printf(" ");
		}

	}
	else {
		for (int i = 0; i < 5; i++)
		{
			int x = PLAYER_TABLE[player][0] + 6 * card_order;
			int y = PLAYER_TABLE[player][1] + i;
			gotoxy(x, y);
			for (int j = 0; j < 5; j++)
			{
				if (CARD[i][j] == '#')
				{
					ColorSet(white, white);
					printf("%c", CARD[i][j]);
				}
				else if (CARD[i][j] == 'N')
				{
					if (num == 11) {
						ColorSet(white, black);
						printf("J");
					}
					else if (num == 12) {
						ColorSet(white, black);
						printf("Q");
					}
					else if (num == 13) {
						ColorSet(white, black);
						printf("K");
					}
					else if (num == 1) {
						ColorSet(white, black);
						printf("A");
					}
					else {
						ColorSet(white, black);
						printf("%d", num);
					}
				}
				else if (CARD[i][j] == 'A')
				{
					ColorSet(white, black);
					switch (shape) {
					case DIAMOND:
						ColorSet(white, red);
						printf("◆");
						break;
					case SPADE:
						ColorSet(white, black);
						printf("♠");
						break;
					case HEART:
						ColorSet(white, red);
						printf("♥");
						break;
					case CLUB:
						ColorSet(white, black);
						printf("♣");
						break;
					}
				}
			}
			gotoxy(x + 5, y);
			ColorSet(black, black);
			printf(" ");
		}
	}
	ColorSet(black, white);
}
void set_money(int player_num, int player_money) {
	int PLAYER_MONEY_XY[6][2] = { {4, 19}, {4, 1}, {4, 9}, {97, 1}, {97, 9}, {30, 1} };
	int x = PLAYER_MONEY_XY[player_num][0];
	int y = PLAYER_MONEY_XY[player_num][1];
	gotoxy(x, y);
	printf("%d", player_money);
}
void MUSIC(char SOUND_NAME[10]) {
	sndPlaySoundA(SOUND_NAME, SND_ASYNC);
	Sleep(100);
}
void set_player_name(int player, const char* name) {
	int NAME_LEN;
	if (name != NULL) {
		NAME_LEN = strlen(name);
	}
	else {
		NAME_LEN = 0;
	}
	switch (player) {
	case 0:
		if (name != NULL) {
			gotoxy(3, 21);
			printf("%s", name);
		}
		else {
			gotoxy(3, 21);
			printf("                      ");
		}
		break;
	case 1:
		if (name != NULL) {
			gotoxy(25 - NAME_LEN, 1);
			printf("%s", name);
		}
		else {
			gotoxy(3, 1);
			printf("                      ");
		}
		break;
	case 2:
		if (name != NULL) {
			gotoxy(25 - NAME_LEN, 11);
			printf("%s", name);
		}
		else {
			gotoxy(3, 11);
			printf("                      ");
		}
		break;
	case 3:
		if (name != NULL) {
			gotoxy(96, 1);
			printf("%s", name);
		}
		else {
			gotoxy(96, 1);
			printf("                      ");
		}
		break;
	case 4:
		if (name != NULL) {
			gotoxy(96, 11);
			printf("%s", name);
		}
		else {
			gotoxy(96, 11);
			printf("                      ");
		}
		break;
	}
}
int countDigits(long long num) {
	int count = 0;

	// 0이 입력된 경우에도 최소 한 자리로 간주
	if (num == 0) {
		return 1;
	}

	while (num != 0) {
		num /= 10; // 숫자를 10으로 나누어 한 자리씩 줄임
		++count;   // 자리수 증가
	}

	return count;
}
void set_player_capital(int player, int capital) {

	int len = 0;
	int hundred_million = capital / 100000000;
	int hundred_million_else = capital % 100000000;
	int ten_thousand = hundred_million_else / 10000;
	int ten_thousand_else = hundred_million_else % 10000;

	len = countDigits(hundred_million) + countDigits(ten_thousand) + countDigits(ten_thousand_else);
	if (hundred_million == 0) {
		len -= 2;
	}
	if (ten_thousand == 0) {
		len -= 2;
	}
	if (ten_thousand_else == 0) {
		len -= 2;
	}

	switch (player) {
	case 0:
		gotoxy(3, 22);
		printf("        ");
		gotoxy(3, 22);
		break;
	case 1:
		gotoxy(12, 2);
		printf("        ");
		gotoxy(21 - len, 2);
		break;
	case 2:
		gotoxy(12, 12);
		printf("        ");
		gotoxy(21 - len, 12);
		break;
	case 3:
		gotoxy(96, 2);
		printf("        ");
		gotoxy(96, 2);
		break;
	case 4:
		gotoxy(96, 12);
		printf("        ");
		gotoxy(96, 12);
		break;
	case 5:
		gotoxy(46, 6);
		printf("             ");
		gotoxy(46, 6);
	}

	if (hundred_million != 0) {
		printf("%d억", hundred_million);
	}
	if (ten_thousand != 0) {
		printf("%d만", ten_thousand);
	}
	if (ten_thousand_else != 0) {
		printf("%d원", ten_thousand_else);
	}
}
void set_player_hand(int player, HAND hand) {
	switch (player) {
	case 0:
		gotoxy(4, 29);
		break;
	case 1:
		gotoxy(4, 9);
		break;
	case 2:
		gotoxy(4, 19);
		break;
	case 3:
		gotoxy(97, 9);
		break;
	case 4:
		gotoxy(97, 19);
		break;
	}
	switch (hand) {
	case UNKNOWN_DECK:
		printf("                      ");
		break;
	case HIGH_CARD:
		printf("HIGH CARD");
		break;
	case ONE_PAIR:
		printf("ONE PAIR");
		MUSIC("One_pair.wav");
		break;
	case TWO_PAIR:
		printf("TWO PAIR");
		MUSIC("Two_pair.wav");
		break;
	case TRIPLE:
		printf("TRIPLE");
		MUSIC("Triple.wav");
		break;
	case STRAIGHT:
		printf("STRAIGHT");
		MUSIC("Straight.wav");
		break;
	case FLUSH:
		printf("FLUSH");
		MUSIC("Flush.wav");
		break;
	case FULL_HOUSE:
		printf("FULL HOUSE");
		MUSIC("Full_house.wav");
		break;
	case FOUR_CARD:
		printf("FOUR CARD");
		MUSIC("Four_card.wav");
		break;
	case STRAIGHT_FLUSH:
		printf("STRAIGHT FLUSH");
		MUSIC("Straight_flush.wav");
		break;
	case ROYAL:
		printf("ROYAL STRAIGHT FLUSH");
		MUSIC("Royal_straight_flush.wav");
		break;
	}
}