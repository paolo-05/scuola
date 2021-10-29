/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int a, b, r, div;
    printf("Inserisci un numero a: ");
    scanf("%d", &a);
    printf("Inserisci un numero b: ");
    scanf("%d", &b);
    while (r != 0)
    {
        div = a / b;
        r = a % b;
    }

    return 0;
}
