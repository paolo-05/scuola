/*
    Autore: Paolo Bianchessi 3ic
    Data: 11/01/2022
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 200

void stampaIstogramma(int array[], int nValori)
{
    int i;
    for (i = 0; i < nValori; i++)
    {
        printf("\nElemento di posizione %d vale %d: ", i, array[i]);
        for (int j = 0; j < array[i]; j++)
        {
            printf("*");
        }
    }
}

int main()
{
    int nVal, valori[MAX_VAL] = {0};
    do
    {
        printf("Inserisci il numero di valori in input, al massimo 200: ");
        scanf("%d", &nVal);
        if (nVal > MAX_VAL)
        {
            printf("\nErrore: il numero dev'essere compreso fra 1 e 200\n");
        }

    } while (nVal > MAX_VAL);

    for (int i = 0; i < nVal; i++)
    {
        do
        {
            printf("Inserisci l'elemento di posizione %d: ", i);
            scanf("%d", &valori[i]);
            if (valori[i] < 0)
            {
                printf("\nErrore: si devono inserire numero maggiori di zero!\n");
            }

        } while (valori[i] < 0);
    }
    stampaIstogramma(valori, nVal);
    printf("\n");
    return 0;
}
