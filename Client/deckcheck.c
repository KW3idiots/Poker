#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int royal(int a, int b, int c, int d, int e, int card1, int card2);

int check(int a, int b, int c, int d, int e, int card1, int card2)
{
	//0 = 클로버, 1 = 하트, 2 = 다야, 3 = 스페이드
	//0 = a . . . . . .10 = j 11 = q 12 = k
	int cardnum[7] = { a,b,c,d,e,card1,card2 };
	int shape[7] = { a,b,c,d,e,card1,card2 };
	int fair = 0;
	int straight1 = 0;
	int flush = 0;
	int straight[7];
	int shapecheck[4];
	int result;
	int max = -1;
	int check;
	int triple = 0;
	int four = 0;

	
	for (int i = 0; i < 7; i++)
	{
		cardnum[i] = cardnum[i] % 13;
	}
	for (int i = 0; i < 7; i++)
	{
		shape[i] = shape[i] / 13;
	}
	//페어
	for (int i = 0; i < 7; i++)
	{
		for (int j = i+1; j < 7; j++)
		{
			if (cardnum[i] == cardnum[j])
			{
				fair++;
			}
		}
		if (shape[i] == 0)
		{
			shapecheck[0]++;
		}
		if (shape[i] == 1)
		{
			shapecheck[1]++;
		}
		if (shape[i] == 2)
		{
			shapecheck[2]++;
		}
		if (shape[i] == 3)
		{
			shapecheck[3]++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (shapecheck[i] >= 5)
		{
			flush++;
		}
	}
	for (int i = 0; i< 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (cardnum[j] >= max)
			{
				max = cardnum[j];
				check = j;
			}
		}
		straight[i] = max;
 		cardnum[check] = -1;
	}
	for (int i = 0; i < 6; i++)
	{
		if (straight[i + 1] == straight[i]-1)
		{
			straight1++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (straight[i] == straight[i + 1] && straight[i + 1] == straight[i + 2])
		{
			triple++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (straight[i] == straight[i + 1] && straight[i + 1] == straight[i + 2] && straight[i + 2] == straight[i + 3])
		{
			four++;
		}
	}
	if (fair == 1)//원페어
	{
		result = 1;
	}
	else if (fair == 2 || fair ==3)//투페어
	{
		result = 2;
	}
	else if (fair == 3 && triple ==1)//쓰리오브카드
	{
		result = 3;
	}
	else if (straight1 >= 5)//스트레이트
	{
		result = 4;
	}
	else if (flush == 1)//플러쉬
	{
		result = 5;
	}
	else if (fair >= 4)//풀하
	{
		result = 6;
	}
	else if (fair >= 4 && four == 1)//포카드
	{
		result = 7;
	}
	else if (royal(a, b, c, d, e, card1, card2) == 10)//로얄 플러쉬
	{
		result = 9;
	}
	else if (royal(a, b, c, d, e, card1, card2) == 9)//스트레이트 플러쉬
	{
		result = 8;
	}
	else//하이카드
	{
		result = 0;
	}
	return result;
}
int royal(int a, int b, int c, int d, int e, int card1, int card2)
{
	int max = -1;
	int royal[7];
	int num[7] = { a,b,c,d,e,card1,card2 };
	int check;
	int royal1 = 0;
	int royal2 = 0;

	for (int i = 0; i, 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (num[j] >= max)
			{
				max = num[j];
				check = j;
			}
		}
		royal[i] = max;
		num[check] = -1;
	}
	for (int i = 0; i < 6; i++)
	{
		if (royal[i] == royal[i + 1] - 1)
		{
			royal1++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (royal[i] == 9 + 13 * j && royal[i + 1] == 10 + 13 * j && royal[i + 2] == 11 + 13 * j && royal[i + 3] == 12 + 13 * j)
			{
				for (int k = 0; k < 7; k++)
				{
					royal[k] == 13 * j;
					royal2++;
				}
			}
		}
	}
	if (royal2 != 0)
	{
		return 10;
	}
	if (royal1 != 0)
	{
		return 9;
	}

}
//0 1 2 3 4 5 6 7 8 9 10 11 12 = 클로버
//13 14 15 16 17 18 19 20 21 22 23 24 25 = 하트
//26 27 28 29 30 31 32 33 34 35 36 37 38 = 다야
//39 40 41 42 43 44 45 46 47 48 49 50 51 = 스페이드