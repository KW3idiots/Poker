// Client.c : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <process.h>

int randcard()
{
    srand(time(NULL));

    int card;

    card = rand() % 52;

    return card;
}
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
        for (int j = i + 1; j < 7; j++)
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
    for (int i = 0; i < 7; i++)
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
        if (straight[i + 1] == straight[i] - 1)
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
    else if (fair == 2 || fair == 3)//투페어
    {
        result = 2;
    }
    else if (fair == 3 && triple == 1)//쓰리오브카드
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
int samecheck(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
}

void main()//'♣','♥','♦','♠'
{
    srand(time(NULL));
    char shape[4];//카드 모양(클로버 하트 다야 스페이드)
    shape[0] = 'C';
    shape[1] = 'H';
    shape[2] = 'D';
    shape[3] = 'S';
    int cardcheck[52] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,446,47,48,49,50,51 };
    int ai[4][3];//봇 카드 및 돈 ai[0],ai[1]이 카드고 ai[2]는 돈
    int startmoney[3] = { 1000,10000,100000 };//시작 돈
    int money;//내 돈
    int call, fold[5] = { 0,0,0,0,0 }, raise, allin[5] = { 0,0,0,0,0 }, pay[5];
    int choose = 4;
    int yourcard[2];
    int allmoney = 0;//배팅된 돈
    int end = 0;
    int deckcard[5];
    int startchoose;
    int player = 5;
    int result[5];
    int pasan[5] = { 0,0,0,0,0 };

    while (choose != 0)
    {
        printf("시작 돈(1 : 1000원, 2 : 10000원, 3 : 100000원) :");
        scanf("%d", &choose);

        if (choose == 1)
        {
            printf("1000원 모드를 선택하셨습니다.\n");
            money = 1000;
            call = money / 100;
            for (int i = 0; i < 4; i++)
            {
                ai[i][2] = 1000;
            }
            startchoose = choose-1;
            choose = 0;
        }
        else if (choose == 2)
        {
            printf("10000원 모드를 선택하셨습니다.\n");
            money = 10000;
            choose = 0;
            call = money / 100;
            for (int i = 0; i < 4; i++)
            {
                ai[i][2] = 10000;
            }
            startchoose = choose - 1;
            choose = 0;
        }
        else if (choose == 3)
        {
            printf("100000원 모드를 선택하셨습니다.\n");
            money = 100000;
            choose = 0;
            call = money / 100;
            for (int i = 0; i < 4; i++)
            {
                ai[i][2] = 100000;
            }
            startchoose = choose - 1;
            choose = 0;
        }
        else
        {
            printf("잘못 입력하셨습니다 다시 입력하십시오.\n");
        }
    }
    while (end == 0)
    {   
        for (int i = 0; i < 5; i++)
        {
            allin[i] = 0;
        }
        allmoney = 0;
        fold[0] = 0;
        int cardcheck[52] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,446,47,48,49,50,51 };
        yourcard[0] = randcard();
        cardcheck[yourcard[0]] = 0;
        yourcard[1] = randcard();
        while (cardcheck[yourcard[1]] == 0)//내 카드 정하기
        {
            yourcard[1] = randcard();
        }
        for (int i = 0; i < 2; i++)
        {
            cardcheck[yourcard[i]] = 0;
        }
       
        for (int i = 0; i < 4; i++)
        {
            if (pasan[i] == 1)
            {
                break;
            }
            for (int j = 0; j < 2; j++)
            {
                ai[i][j] = randcard();
            }
            while (cardcheck[ai[i][0]] == 0)
            {
                ai[i][0] = randcard();
            }
            cardcheck[ai[i][0]] = 0;
            ai[i][1] = randcard();
            while (cardcheck[ai[i][1]] == 0)
            {
                ai[i][1] = randcard();
            }
            cardcheck[ai[i][1]] = 0;
        }
        for (int i = 0; i < 5; i++)
        {
            deckcard[i] = randcard();
            while (cardcheck[deckcard[i]] == 0)
            {
                deckcard[i] = randcard();
            }
            cardcheck[deckcard[i]] = 0;
        }
        system("cls");
        int play = 0;
        int open = 0;
        while (play == 0)
        {
            if (open == 0)//1라
            {
                printf("공개된 카드 : ? / ? / ? / ? / ?\n");
            }
            if (open == 1)//2라
            {
                printf("공개된 카드 : %c %d / %c %d / %c %d / ? / ?\n", shape[deckcard[0] / 13], deckcard[0] % 13, shape[deckcard[1] / 13], deckcard[1] % 13, shape[deckcard[2] / 13], deckcard[2] % 13);
            }
            if (open == 2)//3라
            {
                printf("공개된 카드 : %c %d / %c %d / %c %d / %c %d / ?\n", shape[deckcard[0] / 13], deckcard[0] % 13, shape[deckcard[1] / 13], deckcard[1] % 13, shape[deckcard[2] / 13], deckcard[2] % 13, shape[deckcard[3] / 13], deckcard[3] % 13);
            }
            if (open == 3)//막라
            {
                printf("공개된 카드 : %c %d / %c %d / %c %d / %c %d / %c %d\n", shape[deckcard[0] / 13], deckcard[0] % 13, shape[deckcard[1] / 13], deckcard[1] % 13, shape[deckcard[2] / 13], deckcard[2] % 13, shape[deckcard[3] / 13], deckcard[3] % 13, shape[deckcard[4] / 13], deckcard[4] % 13);
            }
            if (open == 4)//담판가기
            {
                int max = -1;
                int same = 0;
                int winner = 0;
                int gamewin = 0;
                int mincheck;

                for (int i = 0; i < 4; i++)
                {
                    if (pasan[i + 1] == 1)
                    {
                        printf("ai %d님은 파산상태입니다.", i + 1);
                        break;
                    }
                    printf("ai %d의 카드 : ", i + 1);
                    for (int j = 0; j<2; j++)
                    {
                        printf("%c%d ", shape[ai[i][j] / 13], ai[i][j] % 13);
                    }
                    printf("\n");
                }
                result[0] = check(deckcard[0], deckcard[1], deckcard[2], deckcard[3], deckcard[4], yourcard[0], yourcard[1]);
                for (int i = 1; i < 5; i++)
                {
                    result[i] = check(deckcard[0], deckcard[1], deckcard[2], deckcard[3], deckcard[4], ai[i-1][0], ai[i-1][1]);
                    }
                for (int i = 0; i < 5; i++)
                {
                    if (result[i] >= max)
                    {
                        max = result[i];
                    }
                }
                winner = max;
                for (int i = 0; i < 5; i++)
                {
                    if (result[i] == winner)
                    {
                        same++;
                    }
                }
                if (result[0] == winner&& fold[0] == 0)
                {
                    money += allmoney / same;
                }
                if (result[0] != winner && allin[0] == 1)
                {
                    Sleep(5000);
                    play++;
                    end+=2;
                    break;
                }
                for (int i = 1; i < 5; i++)
                {
                    if (result[i] == winner&&fold[i] == 0)
                    {
                        ai[i-1][2] += allmoney / same;
                    }
                    if (result[i] != winner && allin[i] == 1)
                    {
                        pasan[i] == 1;
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                    if (pasan[i + 1] == 1)
                    {
                        gamewin++;
                    }
                }
                open = 0;
                play++;
                if (gamewin == 4)
                {
                    play++;
                    end++;
                    break;
                }
                break;
            }
            printf("당신의 돈 : %d\n", money);
            for (int i = 0 ;i < 4; i++)
            {
                printf("ai %d의 돈 : %d\n",i+1, ai[i][2]);
            }
            printf("당신의 카드 : %c %d / %c %d\n", shape[yourcard[0]/13], yourcard[0] % 13, shape[yourcard[1] / 13], yourcard[1] % 13);//우선 0이 나오면 그게 K인걸로
            if (fold[0] != 1 && allin[0] == 0)
            {
                printf("1. 콜, 2. 레이즈, 3. 폴드, 4. 올인 : ");
                scanf("%d", &choose);
            }
            call = startmoney[startchoose] / 100;
            if (choose == 1)
            {
                if (allin[0] != 1 || fold[0] != 1)
                {
                    if (money >= call)
                    {
                        money -= call;
                        allmoney += call;
                    }
                    else if (money < call)
                    {
                        allmoney += money;
                        money = 0;
                        printf("당신은 올인하셨습니다.\n");
                        allin[0] = 1;
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                    if (ai[i][2] < call)
                    {
                        if (fold[i + 1] == 1 || allin[i + 1] == 1)
                        {
                            break;
                        }
                        allmoney += ai[i][2];
                        ai[i][2] = 0;
                        allin[i + 1];
                    }
                    if (ai[i][2] >= call)
                    {
                        allmoney += call;
                        ai[i][2] -= call;
                    }
                }
                printf("베팅된 돈 : %d\n", allmoney);
                printf("\n");
                open++;
            }
            else if (choose == 2)
            {
                if (allin[0] != 1 || fold[0] != 1)
                {
                    printf("얼마나 레이즈 하실 겁니까? : ");
                    scanf("%d", &raise);
                    while (raise >= money)
                    {
                        printf("당신이 가진 돈보다 많습니다 다시 입력해주십시오 : ");
                        scanf("%d", &raise);
                    }
                    call = raise;
                    money -= call;
                    allmoney += call;
                }
                for (int i = 0; i < 4; i++)
                {
                    if (ai[i][2] == 0)
                    {
                        break;
                    }
                    if (ai[i][2] <= call)
                    {
                        allmoney += ai[i][2];
                        ai[i][2] = 0;
                        printf("ai %d님이 올인을 하셨습니다.\n", i + 1);
                        allin[i + 1] = 1;
                    }
                    if (ai[i][2] > call)
                    {
                        allmoney += call;
                        ai[i][2] -= call;
                    }
                }
                printf("배팅된 돈 : %d\n\n", allmoney);
                open++;
            }
            else if (choose == 3)
            {
                if (fold[0] == 0)
                {
                    fold[0]++;
                }
                for (int i = 0; i < 4; i++)
                {
                    if (ai[i][2] < call)
                    {
                        if (fold[i + 1] == 1 || allin[i + 1] == 1)
                        {
                            break;
                        }
                        allmoney += ai[i][2];
                        ai[i][2] = 0;
                        allin[i + 1];
                    }
                }
                printf("베팅된 돈 : %d\n", allmoney);
                printf("\n");
                open++;
            }
            else if (choose == 4)
            {
                allin[0] = 1;
                allmoney += money;
                call = money;
                money = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (ai[i][2] > call)
                    {
                        ai[i][2] -= call;
                        allmoney += call;
                    }
                    else if(ai[i][2] <= call)
                    {
                        allmoney += ai[i][2];
                        ai[i][2] = 0;
                        allin[i + 1] = 1;
                    }
                }
                printf("베팅된 돈 : %d\n", allmoney);
                printf("\n");
                open++;
            }
            else
            {
                printf("잘못 입력하셨습니다 다시 입력해주십시오, : ");
                scanf("%d", &choose);
                printf("\n");
            }
        }

        /*
        for (int i = 0; i < 2; i++)
        {
            printf("%d ", yourcard[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d ", ai[i][j]);
            }
        }
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", deckcard[i]);
        }
        end++;
        */
    }
    if (end == 1)
    {
        system("cls");
        printf("당신은 게임을 승리하셨습니다.");
    }
    if (end == 2)
    {
        system("cls");
        printf("당신은 파산하였습니다.");
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
