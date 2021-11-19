/*
    Autore: Paolo Bianchessi 3ic
    Data: 14/11/2021
    Descrizione
*/

#include <stdio.h>

int main()
{
    int pesOttimale, tolleranza, peso, pesoMax, pesoMin, errori = 0, i = 0;
    printf("\nInserisci il peso ottimale: ");
    scanf("%d", &pesOttimale);
    printf("\nInserisci la tolleranza accettabile: ");
    scanf("%d", &tolleranza);
    pesoMax = (100 + tolleranza) * pesOttimale / 100;
    pesoMin = (100 - tolleranza) * pesOttimale / 100;
    printf("\n==> peso minimo: %d\n==> peso max: %d", pesoMin, pesoMax);
    do
    {
        printf("\nInserisci il peso del sacchetto in grammi: ");
        scanf("%d", &peso);
        if (peso <= pesoMax && peso >= pesoMin)
        {
            printf("\nAccettato");
        }
        else
        {
            errori += 1;
            printf("\nPeso al di fuori del range di tolleranza");
        }
        i++;

    } while (errori < 5);
    printf("\nNumero di errori massimo raggiunto.\nErrori: %d%%\n", 5 * 100 / i);

    return 0;
}
