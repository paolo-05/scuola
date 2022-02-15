/*
    Autore: Paolo Bianchessi 3ic
    Data: 11/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAT 24
char mat[MAT][MAT];

void wait_sec(double);
void riempi();
void stampaMatrice();

int main()
{
    int i = 0, n;
    riempi();
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    while (i < 24)
    {
        mat[i][i] = '*';
        i++;
    }
    stampaMatrice();
    return 0;
}

void riempi()
{
    for (int i = 0; i < MAT; i++)
    {
        for (int j = 0; j < MAT; j++)
        {
            mat[i][j] = '.';
        }
    }
}

void stampaMatrice()
{
    for (int i = 0; i < MAT; i++)
    {
        for (int j = 0; j < MAT; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void wait_sec(double sec)
{

    double sec_passed;

    clock_t starttime, now;

    starttime = clock();

    do
    {

        now = clock();

        sec_passed = (double)(now - starttime) / CLOCKS_PER_SEC;

    } while (sec_passed < sec);
}