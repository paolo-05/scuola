/*
    Autore: Paolo Bianchessi 3ic
    Data: 23/11/2021
    Descrizione: 
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int d, nBit, maxValori, resto;
    printf("Conversione di un numero decimale in un numero binario rappresentato su N bit\n");
    printf("Inserire il numero decimale da convertire: ");
    scanf("%d", &d);
    printf("Inserire il numero di bit: ");
    scanf("%d", &nBit);
    maxValori = (pow(2, (double)nBit) - 1);
    if (maxValori < d)
    {
        printf("Errore: il numero di bit e' insufficiente\n");
    }
    else
    {
        for (int i = 0; i < nBit; i++)
        {
            resto = d % 2;
            d /= 2;
            printf("\nCifra binaria in posizione %d: %d", i, resto);
        }
    }
    printf("\n");
    return 0;
}
