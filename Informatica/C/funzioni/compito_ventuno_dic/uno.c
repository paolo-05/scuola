/*
    Autore: Paolo Bianchessi 3ic
    Data: 19/12/2021
    Descrizione:
*/

#include <stdio.h>
#define N_VAL 10

float calcolaMedia(int nums[])
{
    int sum = 0;
    for (int i = 0; i < N_VAL; i++)
    {
        sum += nums[i];
    }
    return (float)sum / N_VAL;
}

int main()
{
    int valori[N_VAL];
    float media;
    for (int i = 0; i < N_VAL; i++)
    {
        printf("Inserisci il %d valore: ", i + 1);
        scanf("%d", &valori[i]);
    }
    media = calcolaMedia(valori);
    printf("\nI numeri maggiori della media (%f) sono:", media);
    for (int j = 0; j < N_VAL; j++)
    {
        if (valori[j] > media)
        {
            printf(" %d ", valori[j]);
        }
    }
    printf(".\n");

    return 0;
}
