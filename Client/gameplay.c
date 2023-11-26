// Client.c : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <process.h>
#include "graphic.h"

int randomcard();
int randomshape();
int checkcard(int deck1, int deck2, int deck3, int deck4, int deck5, int player1, int player2);
void play_single(int get_menu_capital);

int randomcard()
{
	int card;

	card = rand() % 13;

	return card;
}

int randomshape()
{
	int shape;

	shape = rand() % 4;

	return shape;
}

void play_single(int get_menu_capital)
{
	srand(time(NULL));
	int start_money = get_menu_capital;
	int player[5][3];//카드 1, 카드 2, 돈
	//player 1은 플레이어 나머지 2,3,4,5는 ai
	int deck[5];//가운데 5개 카드
	int playerchoose;//플레이어 돈 배팅 선택
	int call = get_menu_capital / 100;
	int raise;
	int ingamemoney = 0;//판돈
	int gameover[5] = { 0,0,0,0,0 };
	int max = -1;
	int deckpower[5];
	int same = 0;
	int raisemoney = 0;
	char name[5][20] = { "Player","AI 1","AI 2","AI 3","AI 4" };

	for (int i = 0; i < 5; i++)//플레이어 초반 돈
	{
		player[i][2] = get_menu_capital;
	}
	while (1)//게임 끝(ㄹㅇ 게임) 
	{
		int card[4][13] = { {0,1,2,3,4,5,6,7,8,9,10,11,12},{13,14,15,16,17,18,19,20,21,22,23,24,25},{26,27,28,29,30,31,32,33,34,35,36,37,38},{39,40,41,42,43,44,45,46,47,48,49,50,51} };
		int win = 0;
		set_table();
		for (int i = 0; i < 5; i++)
		{
			if (gameover[i] == 0)
			{
				set_player_name(i, name[i]);
			}
		}
		int turn = 0;
		call = get_menu_capital / 100;
		same = 0;
		int winner[5] = { 0,0,0,0,0 };
		int fold[5] = { 0,0,0,0,0 };
		int allin[5] = { 0,0,0,0,0 };
		ingamemoney = 0;
		max = -1;
		while (1)//한 라운드 끝(카드 공개하는거에서 한 라운드)
		{
			while (1)//한 턴 끝(콜 레이즈 등 하는데 한바퀴)
			{
				call = get_menu_capital / 100;
				gotoxy(46, 6);
				printf("                   ");
				set_player_capital(5, ingamemoney);//판돈
				for (int i = 0; i < 5; i++)
				{
					if (gameover[i] == 0)
					{
						set_player_capital(i, player[i][2]);
					}
				}
				if (turn == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							if (gameover[i] == 0)
							{
								int chooseshape = randomshape();
								int choosecard = randomcard();
								player[i][j] = card[chooseshape][choosecard];
								while (card[chooseshape][choosecard] == -1)
								{
									chooseshape = randomshape();
									choosecard = randomcard();
									player[i][j] = card[chooseshape][choosecard];
								}

								card[chooseshape][choosecard] = -1;
							}

						}
					}
					for (int i = 0; i < 5; i++)
					{
						int chooseshape = randomshape();
						int choosecard = randomcard();
						deck[i] = card[chooseshape][choosecard];
						while(card[chooseshape][choosecard] == -1)
						{
							chooseshape = randomshape();
							choosecard = randomcard();
							deck[i] = card[chooseshape][choosecard];
						}
						card[chooseshape][choosecard] = -1;
					}
					set_card(player[0][0] / 13, player[0][0] % 13 + 1, 0, 0);
					set_card(player[0][1] / 13, player[0][1] % 13 + 1, 0, 1);
					for (int i = 1; i < 5; i++)//ai 카드 세팅
					{
						for (int j = 0; j < 2; j++)
						{
							if (gameover[i] == 0)
							{
								set_card(4, player[i][j] % 13+1, i, j);
							}
						}
					}
					for (int i = 0; i < 5; i++)//덱 카드
					{
						set_card(4, deck[i] % 13+1, 5, i);
					}
					playerchoose = get_menu_bet(&raisemoney);
					if (playerchoose == 0 && allin[0] == 0 && fold[0] == 0)//플레이어가 콜했을 때(우선 ai들도 다 똑같이 행동)(구현 안됬기 때문)(폴드일 경우엔 진행을 위해 콜만 가능)
					{
						for (int i = 0; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)//콜할 돈이 없는데 돈은 있을때 자동 올인
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
								else if (player[i][2] <= 0)
								{
									gameover[i] = 1;
								}
							}
						}
					}
					else if (playerchoose == 1 && allin[0] == 0 && fold[0] == 0)
					{
						if (player[0][2] >= raisemoney)
						{
							call = raisemoney;
							for (int i = 0; i < 5; i++)
							{
								if (gameover[i] == 0)
								{
									if (fold[i] == 1 || allin[i] == 1)
									{
										continue;
									}
									if (player[i][2] > call)
									{
										ingamemoney += call;
										player[i][2] -= call;
										continue;
									}
									else if (player[i][2] <= call && allin[i] == 0)
									{
										ingamemoney += player[i][2];
										player[i][2] = 0;
										allin[i] = 1;
										continue;
									}
								}
							}
						}
					}
					else if (playerchoose == 2 && fold[0] == 0 && allin[0] == 0)//플레이어가 폴드했을때
					{
						fold[0] = 1;
						set_card(4, player[0][0] % 13+1, 0, 0);
						set_card(4, player[0][1] % 13+1, 0, 1);
						for (int i = 0; i < 5; i++)//여기에 플레이어는 폴드 했기 때문에 ai들의 혈투를 넣어야하는데 지금은 ai들끼리 콜만 하는 걸로 통일
						{
							if (gameover[i] == 0)
							{
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else if (playerchoose == 3 && allin[0] == 0 && fold[0] == 0)//플레이어가 올인 했을때(ai들은 아직 플레이어만 따라하는 ㄹㅇ 응애임)
					{
						allin[0] = 1;
						call = player[0][2];
						ingamemoney += player[0][2];
						player[0][2] = 0;
						for (int i = 1; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (player[i][2] > call)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
								if (player[i][2] <= call && allin[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
							}
						}
					}
					else
					{
						turn++;
						continue;
					}
					turn++;
					continue;
				}
				if (turn == 1)
				{
					for (int i = 0; i < 3; i++)//덱 카드
					{
						set_card(deck[i] / 13, deck[i] % 13 + 1, 5, i);
					}
					for (int i = 3; i < 5; i++)//덱 카드
					{
						set_card(4, deck[i] % 13 + 1, 5, i);
					}
					playerchoose = get_menu_bet(&raisemoney);
					if ((fold[0] == 1 || allin[0] == 1) && (fold[1] == 1 || allin[1] == 1) && (fold[2] == 1 || allin[2] == 1) && (fold[3] == 1 || allin[3] == 1) && (fold[4] == 1 || allin[4] == 1))
					{
						turn++;
						continue;
					}
					else if (playerchoose == 0 && allin[0] == 0 && fold[0] == 0)//플레이어가 콜했을 때(우선 ai들도 다 똑같이 행동)(구현 안됬기 때문)(폴드일 경우엔 진행을 위해 콜만 가능)
					{
						for (int i = 0; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									break;
								}
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)//콜할 돈이 없는데 돈은 있을때 자동 올인
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else  if (playerchoose == 1 && allin[0] == 0 && fold[0] == 0)
					{
						if (player[0][2] >= raisemoney)
						{
							call = raisemoney;
							for (int i = 0; i < 5; i++)
							{
								if (gameover[i] == 0)
								{
									if (fold[i] == 1 || allin[i] == 1)
									{
										continue;
									}
									if (player[i][2] > call)
									{
										ingamemoney += call;
										player[i][2] -= call;
										continue;
									}
									else if (player[i][2] <= call && allin[i] == 0)
									{
										ingamemoney += player[i][2];
										player[i][2] = 0;
										allin[i] = 1;
										continue;
									}
								}
							}
						}
					}
					else if (playerchoose == 2 && fold[0] == 0 && allin[0] == 0)//플레이어가 폴드했을때
					{
						fold[0] = 1;
						set_card(4, player[0][0] % 13 + 1, 0, 0);
						set_card(4, player[0][1] % 13 + 1, 0, 1);
						for (int i = 0; i < 5; i++)//여기에 플레이어는 폴드 했기 때문에 ai들의 혈투를 넣어야하는데 지금은 ai들끼리 콜만 하는 걸로 통일
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									continue;
								}
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else if (playerchoose == 3 && allin[0] == 0 && fold[0] == 0)//플레이어가 올인 했을때(ai들은 아직 플레이어만 따라하는 ㄹㅇ 응애임)
					{
						allin[0] = 1;
						call = player[0][2];
						ingamemoney += player[0][2];
						player[0][2] = 0;
						for (int i = 1; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									continue;
								}
								if (player[i][2] > call)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
								if (player[i][2] <= call && allin[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
							}
						}
					}
					else
					{
						turn++;
						continue;
					}
					turn++;
					continue;
				}
				if (turn == 2)
				{
					for (int i = 0; i < 4; i++)//덱 카드
					{
						set_card(deck[i] / 13, deck[i] % 13+1, 5, i);
					}
					for (int i = 4; i < 5; i++)//덱 카드
					{
						set_card(4, deck[i] % 13+1, 5, i);
					}
					playerchoose = get_menu_bet(&raisemoney);
					if ((fold[0] == 1 || allin[0] == 1) && (fold[1] == 1 || allin[1] == 1) && (fold[2] == 1 || allin[2] == 1) && (fold[3] == 1 || allin[3] == 1) && (fold[4] == 1 || allin[4] == 1))
					{
						turn++;
						continue;
					}
					else if (playerchoose == 0 && allin[0] == 0 && fold[0] == 0)//플레이어가 콜했을 때(우선 ai들도 다 똑같이 행동)(구현 안됬기 때문)(폴드일 경우엔 진행을 위해 콜만 가능)
					{
						for (int i = 0; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									continue;
								}
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)//콜할 돈이 없는데 돈은 있을때 자동 올인
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else if (playerchoose == 1 && allin[0] == 0 && fold[0] == 0)
					{
						if (player[0][2] >= raisemoney)
						{
							call = raisemoney;
							for (int i = 0; i < 5; i++)
							{
								if (gameover[i] == 0)
								{
									if (fold[i] == 1 || allin[i] == 1)
									{
										continue;
									}
									if (player[i][2] > call)
									{
										ingamemoney += call;
										player[i][2] -= call;
										continue;
									}
									else if (player[i][2] <= call && allin[i] == 0)
									{
										ingamemoney += player[i][2];
										player[i][2] = 0;
										allin[i] = 1;
										continue;
									}
								}
							}
						}
					}
					else if (playerchoose == 2 && fold[0] == 0 && allin[0] == 0)//플레이어가 폴드했을때
					{
						fold[0] = 1;
						set_card(4, player[0][0] % 13 + 1, 0, 0);
						set_card(4, player[0][1] % 13 + 1, 0, 1);
						for (int i = 0; i < 5; i++)//여기에 플레이어는 폴드 했기 때문에 ai들의 혈투를 넣어야하는데 지금은 ai들끼리 콜만 하는 걸로 통일
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									continue;
								}
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else if (playerchoose == 3 && allin[0] == 0 && fold[0] == 0)//플레이어가 올인 했을때(ai들은 아직 플레이어만 따라하는 ㄹㅇ 응애임)
					{
						allin[0] = 1;
						call = player[0][2];
						ingamemoney += player[0][2];
						player[0][2] = 0;
						for (int i = 1; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (player[i][2] > call)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
								if (player[i][2] <= call && allin[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
							}
						}
					}
					else
					{
						turn++;
						continue;
					}
					turn++;
					continue;
				}
				if (turn == 3)
				{
					for (int i = 0; i < 5; i++)//덱 카드
					{
						set_card(deck[i] / 13, deck[i] % 13+1, 5, i);
					}
					playerchoose = get_menu_bet(&raisemoney);
					if ((fold[0] == 1 || allin[0] == 1) && (fold[1] == 1 || allin[1] == 1) && (fold[2] == 1 || allin[2] == 1) && (fold[3] == 1 || allin[3] == 1) && (fold[4] == 1 || allin[4] == 1))
					{
						turn++;
						continue;
					}
					else if (playerchoose == 0 && fold[0] == 0 && allin[0] == 0)//플레이어가 콜했을 때(우선 ai들도 다 똑같이 행동)(구현 안됬기 때문)(폴드일 경우엔 진행을 위해 콜만 가능)
					{
						for (int i = 0; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									continue;
								}
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)//콜할 돈이 없는데 돈은 있을때 자동 올인
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else if (playerchoose == 1 && fold[0] == 0 && allin[0] == 0)
					{
						if (player[0][2] >= raisemoney)
						{
							call = raisemoney;
							for (int i = 0; i < 5; i++)
							{
								if (gameover[i] == 0)
								{
									if (fold[i] == 1 || allin[i] == 1)
									{
										continue;
									}
									if (player[i][2] > call)
									{
										ingamemoney += call;
										player[i][2] -= call;
										continue;
									}
									else if (player[i][2] <= call && allin[i] == 0)
									{
										ingamemoney += player[i][2];
										player[i][2] = 0;
										allin[i] = 1;
										continue;
									}
								}
							}
						}
					}
					else if (playerchoose == 2 && fold[0] == 0 && allin[0] == 0)//플레이어가 폴드했을때
					{
						fold[0] = 1;
						set_card(4, player[0][0] % 13 + 1, 0, 0);
						set_card(4, player[0][1] % 13 + 1, 0, 1);
						for (int i = 0; i < 5; i++)//여기에 플레이어는 폴드 했기 때문에 ai들의 혈투를 넣어야하는데 지금은 ai들끼리 콜만 하는 걸로 통일
						{
							if (gameover[i] == 0)
							{
								if (allin[i] == 1)
								{
									continue;
								}
								if (player[i][2] <= call && player[i][2] >= 0 && fold[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
								else if (player[i][2] > call && fold[i] == 0)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
							}
						}
					}
					else if (playerchoose == 3 && allin[0] == 0 && fold[0] == 0)//플레이어가 올인 했을때(ai들은 아직 플레이어만 따라하는 ㄹㅇ 응애임)
					{
						allin[0] = 1;
						call = player[0][2];
						ingamemoney += player[0][2];
						player[0][2] = 0;
						for (int i = 1; i < 5; i++)
						{
							if (gameover[i] == 0)
							{
								if (player[i][2] > call)
								{
									player[i][2] -= call;
									ingamemoney += call;
								}
								if (player[i][2] <= call && allin[i] == 0)
								{
									ingamemoney += player[i][2];
									player[i][2] = 0;
									allin[i] = 1;
								}
							}
						}
					}
					else
					{
						turn++;
						continue;
					}
					turn++;
					continue;
				}
				if (turn == 4)
				{
					for (int i = 1; i < 5; i++)//ai 카드 세팅
					{
						for (int j = 0; j < 2; j++)
						{
							if (gameover[i] == 0)
							{
								set_card(player[i][j]/13, player[i][j] % 13+1, i, j);							
							}
						}
					}
					break;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (gameover[i] == 0)
				{
					deckpower[i] = checkcard(deck[0], deck[1], deck[2], deck[3], deck[4], player[i][0], player[i][1]);
					if (deckpower[i] >= max && fold[i] == 0)
					{
						max = deckpower[i];
					}
				}
				if (gameover[i] == 1)
				{
					deckpower[i] == -2;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (gameover[i] == 0)
				{
					set_player_hand(i, deckpower[i] + 1);
					Sleep(2000);
				}
			}
			Sleep(1000);
			for (int i = 0; i < 5; i++)
			{
				if (deckpower[i] == max)
				{
					winner[i] = 1;
					same++;
					if (fold[i] == 1)
					{
						same--;
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (winner[i] == 1 && fold[i] == 0)
				{
					player[i][2] += ingamemoney / same;
				}
				if (allin[i] == 1 && winner[i] == 0)
				{
					gameover[i] = 1;
				}
			}
			break;
		}
		if (gameover[0] == 1)
		{
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			if (gameover[i] == 1)
			{
				win++;
			}
		}
		if (win == 4)
		{
			break;
		}
	}
	system("cls");
}
//0 1 2 3 다야 스페이드 하트 클로버
//0 1 2 3 4 5 6 7 8 9 10 11 12 카드 숫자들
int checkcard(int deck1, int deck2, int deck3, int deck4, int deck5, int player1, int player2)
{
	int checkcard[7] = { deck1,deck2,deck3,deck4,deck5,player1,player2 };
	int fair[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int faircheck = 0;
	int triple = 0;
	int four = 0;
	int straight[7] = { deck1,deck2,deck3,deck4,deck5,player1,player2 };
	int flush = 0;
	int shape[4] = { 0,0,0,0 };
	int straightcheck = 0;
	int straightflush = 0;
	int royal = 0;
	int straightzogun[13][5] = { {0,1,2,3,4},{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9},{6,7,8,9,10},{7,8,9,10,11},{8,9,10,11,12},{9,10,11,12,0},{10,11,12,0,1},{11,12,0,1,2},{12,0,1,2,3} };
	int straightflushzogun[13][5] = { {0,1,2,3,4},{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9},{6,7,8,9,10},{7,8,9,10,11},{8,9,10,11,12},{9,10,11,12,0},{10,11,12,0,1},{11,12,0,1,2},{12,0,1,2,3} };
	int correct = 0;
	int colorcheck= 0;

	for (int i = 0; i < 7; i++)//페어 체크
	{
		fair[checkcard[i] % 13] ++;
	}
	for (int i = 0; i < 13; i++)//원페어인지 투페어인지 트리플인지 포카드인지 체크
	{
		if (fair[i] == 2)
		{
			faircheck++;
		}
		if (fair[i] == 3)
		{
			triple++;
		}
		if (fair[i] >= 4)
		{
			four++;
		}
	}
	for (int i = 0; i < 13; i++)
	{
		correct = 0;
		for (int j = 0; j < 5; j++)
		{
			if (straight[0]%13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
			if (straight[1]%13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
			if (straight[2]%13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
			if (straight[3]%13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
			if (straight[4]%13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
			if (straight[5]%13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
			if (straight[6] % 13 == straightzogun[i][j])
			{
				correct++;
				straightzogun[i][j] = -1;
			}
		}
		if (correct == 5)
		{
			straightcheck++;
		}
	}
	for (int i = 0; i < 7; i++)//플러쉬 확인
	{
		shape[checkcard[i] / 13] ++;
	}
	for (int i = 0; i < 4; i++)//플러쉬 확인
	{
		if (shape[i] >= 5)
		{
			flush++;
			colorcheck = i;
		}
	}
	for (int i = 0; i < 13; i++)
	{
		correct = 0;
		for (int j = 0; j < 5; j++)
		{
			if (straight[0] % 13 == straightflushzogun[i][j] && straight[0]/13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j]=-1;
			}
			if (straight[1] % 13 == straightflushzogun[i][j] && straight[1] / 13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j] = -1;
			}
			if (straight[2] % 13 == straightflushzogun[i][j] && straight[2] / 13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j] = -1;
			}
			if (straight[3] % 13 == straightflushzogun[i][j] && straight[3] / 13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j] = -1;
			}
			if (straight[4] % 13 == straightflushzogun[i][j] && straight[4] / 13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j] = -1;
			}
			if (straight[5] % 13 == straightflushzogun[i][j] && straight[5] / 13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j] = -1;
			}
			if (straight[6] % 13 == straightflushzogun[i][j] && straight[6] / 13 == colorcheck)
			{
				correct++;
				straightflushzogun[i][j] = -1;
			}
		}
		if (correct == 5)
		{
			straightflush++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int royalstraightflush[5] = { 0,9,10,11,12 };
		correct = 0;
		for (int j = 0; j < 5; j++)
		{
			if (straight[0] % 13 ==royalstraightflush[j] && straight[0] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
			if (straight[1] % 13 == royalstraightflush[j] && straight[1] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
			if (straight[2] % 13 == royalstraightflush[j] && straight[2] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
			if (straight[3] % 13 == royalstraightflush[j] && straight[3] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
			if (straight[4] % 13 == royalstraightflush[j] && straight[4] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
			if (straight[5] % 13 == royalstraightflush[j] && straight[5] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
			if (straight[6] % 13 == royalstraightflush[j] && straight[6] / 13 == colorcheck)
			{
				correct++;
				royalstraightflush[i] = -1;
			}
		}
		if (correct == 5)
		{
			royal++;
		}
	}
	if (royal >= 1)
	{
		return 9;
	}
	if (straightcheck >= 1)
	{
		if (royal >= 1)
		{
			return 9;
		}
		else if (straightflush >= 1)
		{
			return 8;
		}
		else if (flush == 1)
		{
			return 5;
		}
		else
		{
			return 4;
		}
	}
	else if (triple == 1)
	{
		if (faircheck >= 1)
		{
			return 6;
		}
		if (flush == 1)
		{
			return 5;
		}
		else
		{
			return 3;
		}
	}
	else if (four == 1)
	{
		return 7;
	}
	else if (flush == 1)
	{
		return 5;
	}
	else if (faircheck == 1)
	{
		return 1;
	}
	else if (faircheck >= 2)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
