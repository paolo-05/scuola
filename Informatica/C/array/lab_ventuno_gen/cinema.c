/*
    Autore: Paolo Bianchessi 3ic
    Data: 21/01/2022
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define CINEMADAYS 15

void trovaMinMax(float giorni[])
{
    float max = FLT_MIN, min = FLT_MAX;
    int giornoMax, giornoMin;
    for (int i = 0; i < CINEMADAYS; i++)
    {
        if (giorni[i] > max)
        {
            giornoMax = i;
            max = giorni[i];
        }
        if (giorni[i] < min)
        {
            giornoMin = i;
            min = giorni[i];
        }
    }
    printf("\nIl giorno con ricavo massimo e' il numero %d con ricavo %.2f\n", giornoMax + 1, max);
    printf("\nIl giorno con ricavo minimo e' il numero %d con ricavo %.2f\n", giornoMin + 1, min);
}

float sommaRicavi(float giorni[])
{
    float acc;
    for (int i = 0; i < CINEMADAYS; i++)
        acc += giorni[i];

    return acc;
}

int main()
{
    int giorniSopraMedia = 0;
    float giorni[CINEMADAYS] = {0};
    float somma, media;
    for (int i = 0; i < CINEMADAYS; i++)
    {
        printf("ricavo del giorno %d: ", i + 1);
        scanf("%f", &giorni[i]);
    }
    somma = sommaRicavi(giorni);
    media = somma / CINEMADAYS;

    printf("Il totale dei ricavi vale: %.2f e la media %.2f\n", somma, media);

    trovaMinMax(giorni);
    for (int j = 0; j < CINEMADAYS; j++)
        if (giorni[j] > media)
            giorniSopraMedia++;

    printf("Ci sono %d giorni con un ricavo superiore alla media %.2f\n", giorniSopraMedia, media);

    return 0;
}
