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
int controllaVincita();

int main()
{
    int x, y;
    int turno = 0;
    char c;
    stampaTab();

    for (int i = 0; i < mosse; i++)
    {

        printf("\nGiocatore %d: inserisci le cordinate: \n", turno + 1);
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
            tavola[y - 1][x - 1] = 'X';
        }
        else
        {
            turno = 0;
            tavola[y - 1][x - 1] = 'O';
        }
        stampaTab();

        if (controllaVincita() == 0)
        {
            printf("\nHa vinto il giocatore 1\n");
            return 0;
        }
        else if (controllaVincita() == 2)
        {
            printf("\nHa vinto il giocatore 2\n");
            return 0;
        }
    }
    printf("\nPareggio\n");
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
            printf("%c ", tavola[i][j]);
        printf("\n");
    }
}
int controllaVincita()
{
    if (tavola[0][0] == 'X' && tavola[0][1] == 'X' && tavola[0][2] == 'X' || tavola[1][0] == 'X' && tavola[1][1] == 'X' && tavola[1][2] == 'X' || tavola[2][0] == 'X' && tavola[2][1] == 'X' && tavola[2][2] == 'X' ||
        tavola[0][0] == 'X' && tavola[1][0] == 'X' && tavola[2][0] == 'X' || tavola[0][1] == 'X' && tavola[1][1] == 'X' && tavola[2][1] == 'X' || tavola[0][2] == 'X' && tavola[1][2] == 'X' && tavola[2][2] == 'X' ||
        tavola[0][0] == 'X' && tavola[1][1] == 'X' && tavola[2][2] == 'X' || tavola[0][2] == 'X' && tavola[1][1] == 'X' && tavola[2][0] == 'X')
        return 0;

    if (tavola[0][0] == 'O' && tavola[0][1] == 'O' && tavola[0][2] == 'O' || tavola[1][0] == 'O' && tavola[1][1] == 'O' && tavola[1][2] == 'O' || tavola[2][0] == 'O' && tavola[2][1] == 'O' && tavola[2][2] == 'O' ||
        tavola[0][0] == 'O' && tavola[1][0] == 'O' && tavola[2][0] == 'O' || tavola[0][1] == 'O' && tavola[1][1] == 'O' && tavola[2][1] == 'O' || tavola[0][2] == 'O' && tavola[1][2] == 'O' && tavola[2][2] == 'O' ||
        tavola[0][0] == 'O' && tavola[1][1] == 'O' && tavola[2][2] == 'O' || tavola[0][2] == 'O' && tavola[1][1] == 'O' && tavola[2][0] == 'O')
        return 2;
}