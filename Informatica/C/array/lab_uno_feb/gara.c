#include <stdio.h>
#include <string.h>

#define DIM 10
#define L 20

void riempi(char nomi[][L], int punteggi[])
{
    for (int i = 0; i < DIM; i++)
    {
        printf("\nInserisci il nome dell'atleta: ");
        scanf("%s", nomi[i]);
        printf("Inserisci il suo punteggio: ");
        scanf("%d", &punteggi[i]);
    }
}

void visualizza(char nomi[][L], int punteggi[])
{
    for (int i = 0; i < DIM; i++)
    {
        printf("\n%d. %s con %d punti\n", i + 1, nomi[i], punteggi[i]);
    }
}

void bubbleSort(char nomi[][L], int punteggi[])
{
    int i;
    char t[L];
    int temp;
    int scambi = 0;
    do
    {
        scambi = 0;
        for (i = 0; i < DIM - 1; i++)
            if (punteggi[i] < punteggi[i + 1])
            {
                temp = punteggi[i];
                punteggi[i] = punteggi[i + 1];
                punteggi[i + 1] = temp;
                strcpy(t, nomi[i]);
                strcpy(nomi[i], nomi[i + 1]);
                strcpy(nomi[i + 1], t);
                scambi = 1;
            }
    } while (scambi == 1);
}

int main()
{
    char nomi[DIM][L];
    int punteggi[DIM];

    riempi(nomi, punteggi);
    bubbleSort(nomi, punteggi);
    visualizza(nomi, punteggi);

    return 0;
}