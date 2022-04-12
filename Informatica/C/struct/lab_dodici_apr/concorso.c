/*
    Autore: Paolo Bianchessi 3ic
    Data: 12/04/2022
    Descrizione:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PARTS 6

typedef struct part
{
    char nome[10];
    int prova[10];
} Partecipante;
typedef Partecipante Concorso[PARTS];

void stampaVincitore(Concorso c, int prova);

int main()
{
    int scelta = 0, e = 1;
    Concorso c = {
        {"Rossi",
         {4, 6, 1, 2, 0, 4, 0, 1, 2, 2}},
        {"Bianchi",
         {12, 0, 9, 4, 5, 2, 1, 1, 0, 5}},
        {"Verdi",
         {2, 3, 7, 9, 10, 4, 5, 9, 7, 2}},
        {"Astolfi",
         {0, 2, 6, 1, 8, 5, 9, 10, 7, 8}},
        {"Lorenzi",
         {6, 9, 7, 1, 0, 0, 4, 5, 2, 1}},
        {"Franchi",
         {1, 10, 11, 19, 4, 7, 2, 0, 2, 7}}};

    printf("\nConcorso\n");
    do
    {
        printf("\nDi quale prova vuoi sapere il risultato (1-10): ");
        scanf("%d", &scelta);

        if (scelta > 10 || scelta < 1)
            e = 0;
        else
            stampaVincitore(c, scelta - 1);

    } while (e);

    return 0;
}

void stampaVincitore(Concorso c, int prova)
{
    int max = 0;
    for (int i = 0; i < PARTS; i++)
        if (c[i].prova[prova] > c[max].prova[prova])
            max = i;

    printf("\nIl vincitore della prova %d e' %s con un punteggio di %d\n", prova + 1, c[max].nome, c[max].prova[prova]);
}
