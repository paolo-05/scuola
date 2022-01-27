/*
    Autore: Paolo Bianchessi 3ic
    Data: 27/10/2021
    Descrizione: 
*/

#include <stdio.h>

void ciao(int numero)
{
    printf("\nciao %d\n", numero);
}

int main()
{
    int n;
    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &n);
    } while (n < 0);

    while (n > 1)
    {
        n -= 2;
    }
    if (n == 0)
    {
        printf("\nNumero pari");
    }
    else
    {
        printf("\nNumero dispari");
    }
    ciao(n);

    return 0;
}