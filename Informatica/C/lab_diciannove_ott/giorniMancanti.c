/*
    Autore: Paolo Bianchessi 3ic
    Data: 19/10/2021
    Descrizione:
*/

#include <stdio.h>
#define MESE 31
#define MES 30
#define ANNO 365

int main()
{
    int giorno, mese, rimanenti;
    do
    {
        printf("Inerisci un giorno: ");
        scanf("%d", &giorno);
    } while (giorno <= 0 && giorno >= 31);
    do
    {
        printf("Inerisci un mese: ");
        scanf("%d", &mese);
    } while (mese <= 1 && mese >= 12);
    switch (mese)
    {
    case 1: // gennaio
        giorno = MESE - giorno;
        rimanenti = ANNO - giorno;
        break;
    case 2: // febbraio
        giorno = 28 - giorno;
        rimanenti = ANNO - giorno;
    default:
        break;
    }

    return 0;
}