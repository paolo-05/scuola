/*
    Autore: Paolo Bianchessi 3ic
    Data: 15/10/2021
    Descrizione: convertire un binario 4 bit in decimale
*/

#include <stdio.h>

int main()
{
    int bit0, bit1, bit2, bit3, decimale;

    printf("Inserisci un numero binario con le cifre separate: ");
    scanf("%d %d %d %d", &bit0, &bit1, &bit2, &bit3);
    if ((bit0 == 0 || bit0 == 1) && (bit1 == 0 || bit1 == 1) && (bit2 == 0 || bit2 == 1) && (bit3 == 0 || bit3 == 1))
    {
        decimale = (bit3 * 8) + (bit2 * 4) + (bit1 * 2) + (bit0 * 1);
        printf("%d", decimale);
    }
    else
    {
        printf("Numero non valido");
    }

    return 0;
}
