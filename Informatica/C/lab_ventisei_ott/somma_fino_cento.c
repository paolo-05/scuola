/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int s, n;
    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &n);
        s += n;
    } while (s <= 100);

    return 0;
}
