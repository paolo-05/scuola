#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define DIM 10
#define L 20

void riempi(char mat[][L])
{
    for (int i = 0; i < DIM; i++)
    {
        printf("Inserisci la stringa in posizione %d: ", i);
        scanf("%s", mat[i]);
    }
}

void visualizza(char mat[][L])
{
    for (int i = 0; i < DIM; i++)
    {
        printf("\n%d. %s\n", i, mat[i]);
    }
}

void bubbleSort(char mat[][L])
{
    int i;
    char t[L];
    int scambi = 0;
    do
    {
        scambi = 0;
        for (i = 0; i < DIM - 1; i++)
            if (strcmp(mat[i], mat[i + 1]) > 0)
            {
                strcpy(t, mat[i]);
                strcpy(mat[i], mat[i + 1]);
                strcpy(mat[i + 1], t);
                scambi = 1;
            }
    } while (scambi == 1);
}

int main()
{
    char mat[DIM][L];

    riempi(mat);
    bubbleSort(mat);
    visualizza(mat);

    return 0;
}