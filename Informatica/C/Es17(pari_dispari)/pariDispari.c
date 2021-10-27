/*
    Autore: Paolo Bianchessi 3ic
    Data: 27/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    while (n > 2)
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

    return 0;
}
