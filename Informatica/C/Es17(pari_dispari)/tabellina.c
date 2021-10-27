/*
    Autore: Paolo Bianchessi 3ic
    Data: 27/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int n;
    do
    {
        printf("Inserisci un numero positivo e minore di 10: ");
        scanf("%d", &n);
    } while (n < 0 || n >= 10);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i * n);
    }

    return 0;
}
