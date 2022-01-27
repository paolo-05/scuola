/*
    Autore: Paolo Bianchessi 3ic
    Data: 14/10/2021
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TENTA 7

int main()
{
    int num, conta = 0, prova;
    printf("\nGioco: Indovina il numero");
    srand((long)time(NULL));
    num = (rand() % 100) + 1;
    do
    {
        printf("\nInserisci un numero: ");
        scanf("%d", &prova);
        conta++;
        if (prova < num)
        {
            printf("\n... Numero troppo piccolo");
        }
        if (prova > num)
        {
            printf("\n... Numero troppo grandde");
        }

    } while ((num != prova) && (conta != MAX_TENTA));
    if (num == prova)
    {
        printf("\nBravo hai indovinato ");
        printf("\n in %d tentativi!", conta);
    }
    else
    {
        printf("\nPeccato non hai indovinato in %d tentativi, il numero era %d", conta, num);
    }

    return 0;
}
