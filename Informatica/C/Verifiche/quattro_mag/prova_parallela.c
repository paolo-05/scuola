/*
    Autore: Paolo Bianchessi 3ic
    Data: 04/05/2022
    Descrizione: Prova Parallela di Informatica
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STUD_MAX 100

int redditi[STUD_MAX] = {0};
int borse[STUD_MAX] = {0};

// ritorna il numero di celle da riempire nel vettore (max 1,100)
int dimLogica();
// riempie utilizzando rand() le celle che vanno da 0 a d
void riempiRandom(int d);
// ordina le celle che vanno da 0 a d
void ordinaCrescente(int d);
void distBorse(int d);
// visualizza il contenuto delle celle da 0 a d
void stampa(int vett[], int d);

int main()
{
    srand((long)time(NULL));

    int dimensione = dimLogica();
    printf("Redditi dei %d studenti: \n", dimensione);
    riempiRandom(dimensione);
    stampa(redditi, dimensione);
    printf("\nRedditi dei %d studenti ordinati in modo crescente: \n", dimensione);
    ordinaCrescente(dimensione);
    stampa(redditi, dimensione);
    distBorse(dimensione);
    printf("\nDistribuzione delle borse di studio ai %d studenti: \n", dimensione);
    stampa(borse, dimensione);
    printf("\n");
    return 0;
}

int dimLogica()
{
    int d;
    do
    {
        printf("Insrire il numero di studenti (max 100): ");
        scanf("%d", &d);
        if (d > STUD_MAX)
            printf("Errore:  il numero di studenti puo' essere di massimo 1,100");
    } while (d > 100 || d < 1);
    return d;
}

void riempiRandom(int d)
{
    for (int i = 0; i < d; i++)
        redditi[i] = (rand() % 50 + 1);
}

void ordinaCrescente(int d)
{
    int temp, scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < d - 1; i++)
            if (redditi[i] > redditi[i + 1])
            {
                temp = redditi[i];
                redditi[i] = redditi[i + 1];
                redditi[i + 1] = temp;
                scambi = 1;
            }
    } while (scambi == 1);
}
void distBorse(int d)
{
    int pls;
    printf("\nInserisci l'importo della plusvalenza (max 100): ");
    scanf("%d", &pls);
    for (int j = 0; j < pls; j++)
        for (int i = 0; i < d; i++)
        {
            borse[i]++;
            pls--;
        }
}
void stampa(int vett[], int d)
{
    for (int i = 0; i < d; i++)
        printf("%d.000\t", vett[i]);
}
