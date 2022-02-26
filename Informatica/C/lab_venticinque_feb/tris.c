/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#define T 3

int mosse = 9;
int tavola[T][T] = {
    {'#', '#', '#'},
    {'#', '#', '#'},
    {'#', '#', '#'},
};

void acquisicqiPos(int *, int *);
void stampaTab();

int main()
{
    int x, y;
    int turno = 0;
    char c;
    for (int i = 0; i < mosse; i++)
    {
        stampaTab();

        printf("\nGiocatore %d: inserisci le cordinate: \n", turno);
        do
        {
            acquisicqiPos(&x, &y);

            if (tavola[y - 1][x - 1] == 'X' || tavola[y - 1][x - 1] == 'O')
            {
                printf("\nSpiacente, in (%d, %d) e' gia' presente '%c'\n", x, y, tavola[y - 1][x - 1]);
            }

        } while (tavola[y - 1][x - 1] == 'X' || tavola[y - 1][x - 1] == 'O');

        printf("\n\n");
        if (turno == 0)
        {
            turno = 1;
            tavola[x - 1][y - 1] = 'X';
        }
        else
        {
            turno = 0;
            tavola[x - 1][y - 1] = 'O';
        }
    }

    return 0;
}

void acquisicqiPos(int *x, int *y)
{
    do
    {
        printf("y: ");
        scanf("%d", y);
        if (*y < 1 || *y > 3)
        {
            printf("La cordinata y può essere massimo 3 e minimo 1\n");
        }

    } while (*y < 1 || *y > 3);

    do
    {
        printf("x: ");
        scanf("%d", x);
        if (*x < 1 || *x > 3)
        {
            printf("La cordinata x può essere massimo 3 e minimo 1\n");
        }
    } while (*x < 1 || *x > 3);
}
void stampaTab()
{
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            printf("%c ", tavola[i][j]);
        }
        printf("\n");
    }
}