/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/11/2021
    Descrizione: 
*/

#include <stdio.h>

int differenza(int n1, int n2, int n3)
{
    return (n1 * n2 * n3) - (n1 + n2 + n3);
}

int main()
{
    int n1, n2, n3;
    printf("Inserisci tre numeri: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("Il risultato e' %d\n", differenza(n1, n2, n3));
    return 0;
}
