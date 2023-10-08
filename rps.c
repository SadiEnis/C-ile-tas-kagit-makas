#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play(int);

int win = 0;
int lose = 0;

int main()
{
    char player;
    int temp;
    system("COLOR 4");

    printf("TAS KAGIT MAKAS\n");
    printf("Tas: T\nKagit: K\nMakas: M\nCikis:C\n\n");

    do
    {
        printf("\nHamlenizi giriniz: ");
        scanf("%s", &player);
        switch(player)
        {
            case 'T':
                temp = 0;
                break;
            case 'K':
                temp = 1;
                break;
            case 'M':
                temp = 2;
                break;
            case 'C':
                temp = 3;
                break;
            default:
                printf("Gecersiz hamle girdiniz. Talimatlara uyarak yeniden deneyiniz.");
                temp = 4;
                break;
        }
        if (temp != 4)
            play(temp);
    } while (temp != 3);
    printf("Oyuncu: %d\nBilgisayar: %d\n", win, lose);
    if (win - lose == 1)
        printf("Az kalsin kaybediyordun.");
    else if (lose - win == 1)
        printf("Az kalsin kazaniyordun.");
    return 0;
}

void play (int _player)
{
    srand(time(0));
    int _temp;
    _temp = rand()%3;

    if (_player == _temp)
    {
        printf("Beraberlik..");
    }
    else if((_player == 0 && _temp == 2) ||
            (_player == 1 && _temp == 0) ||
            (_player == 2 && _temp == 1))
    {
        printf("Kazandin.");
        win++;
    }
    else if((_temp == 0 && _player == 2) ||
            (_temp == 1 && _player == 0) ||
            (_temp == 2 && _player == 1))
    {
        printf("Kaybettin.");
        lose++;
    }
}