/*
    Autore: Paolo Bianchessi 3IC
    Data: 12/11/2021
    Descrizione: distributore automatico
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prodotto, prezzo, moneta, sommaimp = 0;

    printf("1. coca-cola\n2. fanta\n3.sprite\n4.acqua nat\n5.acqua friz");
    printf("Scelta: ");
    scanf("%d", &prodotto);

    switch (prodotto)
    {
    case 1:
        prezzo = 125;
        break;
    case 2:
        prezzo = 150;
        break;
    case 3:
        prezzo = 175;
        break;
    case 4:
    case 5:
        prezzo = 100;
        break;
    case 6:
        exit(0);
    default:
        break;
    }

    printf("\nL'articolo scelto costa %d centesimi", prezzo);
    do
    {
        do
        {
            printf("\ninserisci moneta(1-5-10-20-50): ");
            scanf("%d", &moneta);

        } while (moneta != 1 && moneta != 5 && moneta != 10 && moneta != 20 && moneta != 50);
        sommaimp += moneta;
        printf("\nimporto inserito: %d centesimi", sommaimp);
    } while (sommaimp < prezzo);

    printf("\nprodotto erogato!");
    printf("\nHai %d monete da 5 centesimi", (sommaimp - prezzo) / 5);
    printf("\nHai %d monete da 1 centesimo", (sommaimp - prezzo) % 5);

    return 0;
}
