/*
    Autore: Paolo Bianchessi 3ic
    Data: 21/12/2021
    Descrizione:
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ESTRAZIONI 30

int isEven(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    return 0;
}

void stampa(int *array, int nElementi)
{
    for (int i = 0; i < nElementi; i++)
    {
        printf(" %d ", array[i]);
    }
}
int main()
{
    srand((long)time(NULL));
    int num, pariC = 0, dispariC = 0, pari[ESTRAZIONI], dispari[ESTRAZIONI];
    for (int i = 0; i < ESTRAZIONI; i++)
    {
        num = rand() + 1;
        if (isEven(num))
        {
            pari[pariC] = num;
            pariC++;
        }
        else
        {
            dispari[dispariC] = num;
            dispariC++;
        }
    }
    printf("Ci sono %d numeri dispari e %d numeri pari\n", dispariC, pariC);
    printf("\n");
    printf("\nPari: ");
    stampa(pari, pariC);
    printf("\n\nDispari: ");
    stampa(dispari, dispariC);
    printf("\n\n");
    return 0;
}
