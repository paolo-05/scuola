/*
    Autore: Paolo Bianchessi 3ic
    Data: 16/12/2021
    Descrizione: 
*/

#include <stdio.h>

int eleva(int b, int e)
{
    if (b == 1)
        return 1;
    else
        return b * eleva(b, e - 1);
}
int main()
{
    int b, e;
    printf("\nPotenza\n");
    printf("Inserisci un numero e il suo esponente (n^e): ");
    scanf("%d^%d", &b, &e);
    printf("%d^%d = %d", b, e, eleva(b, e));
    return 0;
}
