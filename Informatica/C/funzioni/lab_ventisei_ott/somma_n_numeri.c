/*
    Autore: Paolo Bianchessi 3ic
    Data: 27/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int n, sum;
    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nNumero negativo.");
        }

    } while (n < 0);

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("\n la somma e' %d", sum);

    return 0;
}
