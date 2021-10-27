/*
    Autore: Paolo Bianchessi 3ic
    Data: 13/10/2021
    Descrizione: ....
*/

#include <stdio.h>

int main()
{
    int num, totale;
    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &num);
        totale += num;
        printf("Totale = %d\n", totale);
    } while (totale < 100);
}