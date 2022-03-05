/*
    Autore: Paolo Bianchessi 3ic
    Data: 17/12/2021
    Descrizione: 
*/

#include <stdio.h>

int isPrime(int *i, int n)
{
    return n % *i ? n == *i : isPrime(&*i + 1, n);
}

int menu(int *n)
{
    printf("Inserisci un numero: ");
    scanf("%d", &*n);
}

int main()
{

    int n, primoDiv = 2;
    char scelta;
    do
    {
        do
        {
            menu(&n);
        } while (n < 0);
        if (isPrime(&primoDiv, n))
        {
            printf("\n%d e' primo\n", n);
        }
        else
        {
            printf("\n%d non e' primo: %d primo divisore\n", n, primoDiv);
        }

        printf("\nContinuare? (s/n) ");
        scanf(" %c", &scelta);
    } while (scelta == 's');
    printf("\n");
    return 0;
}
