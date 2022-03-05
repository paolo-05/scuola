/*
    Autore: Paolo Bianchessi 3ic
    Data: 19/12/2021
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int estrai(int *v1, int *v2, int *v3, int *v4, int *v5, int *v6)
{
    int num = (rand() % 6) + 1;
    switch (num)
    {
    case 1:
        (*v1)++;
        break;
    case 2:
        (*v2)++;
        break;
    case 3:
        (*v3)++;
        break;
    case 4:
        (*v4)++;
        break;
    case 5:
        (*v5)++;
        break;

    default:
        (*v6)++;
        break;
    }
    return num;
}

int main()
{
    srand((long)time(NULL));
    int nEstrazioni;
    int volteUno = 0, volteDue = 0, volteTre = 0, volteQuattro = 0, volteCinque = 0, volteSei = 0;
    printf("Quante estrazioni vuoi fare? ");
    scanf("%d", &nEstrazioni);
    int estratti[nEstrazioni - 1];
    for (int i = 0; i < nEstrazioni; i++)
    {
        estratti[i] = estrai(&volteUno, &volteDue, &volteTre, &volteQuattro, &volteCinque, &volteSei);
    }

    printf("\nIl numero 1 e' uscito %d volte", volteUno);
    printf("\nIl numero 2 e' uscito %d volte", volteDue);
    printf("\nIl numero 3 e' uscito %d volte", volteTre);
    printf("\nIl numero 4 e' uscito %d volte", volteQuattro);
    printf("\nIl numero 5 e' uscito %d volte", volteCinque);
    printf("\nIl numero 6 e' uscito %d volte\n", volteSei);

    for (int j = 0; j < nEstrazioni; j++)
    {
        printf(" %d ", estratti[j]);
    }
    printf("\n");

    return 0;
}
