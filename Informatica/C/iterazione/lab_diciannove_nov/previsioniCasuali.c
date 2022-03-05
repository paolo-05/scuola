/*
    Autore: Paolo Bianchessi 3ic
    Data: 19/11/2021
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main()
{
    int num, acc, massimo, minimo, max = INT_MIN, min = INT_MAX;
    int numeriGenerati[21];
    int numeroInserito, volteApparso;
    srand((long)time(NULL));

    printf("Inserisci il range dei numeri validi (min max): ");
    scanf("%d %d", &minimo, &massimo);

    for (int i = 0; i < 20; i++)
    {
        num = (rand() % (massimo - minimo + 1) + minimo);
        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }
        acc += num;
        numeriGenerati[i] = num;
    }
    printf("\n La media dei numeri generati e': %.2f\nIl numero minimo e': %d\n Il numero massimo e': %d", (float)acc / 20, min, max);
    printf("\n--------------------------------------------------------------\n");
    printf("Inserisci un numero: ");
    scanf("%d", &numeroInserito);
    for (int j = 0; j < 20; j++)
    {
        if (numeroInserito == numeriGenerati[j])
        {
            volteApparso++;
        }
    }
    if (volteApparso)
    {
        printf("Il numero %d e' apparso %d volte.\n", numeroInserito, volteApparso);
    }
    else
    {
        printf("Il numero %d non e' mai apparso nella generazione casuale.\n", numeroInserito);
    }

    return 0;
}
