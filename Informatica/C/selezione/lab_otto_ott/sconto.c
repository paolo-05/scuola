/*
    Autore: Paolo Bianchessi 3ic
    Data: 8.10.2021
    Descrizione: Un negoziante per incrementare le sue vendite, prevede di applicare uno sconto progressivo sull’importo della fattura,
    in base al numero di pezzi acquistati. Se il cliente compra 1 pezzo non viene applicato alcuno sconto, per 2 pezzi viene applicato il
    10%, per 3 pezzi o più il 30%. Dato l’importo e il numero di pezzi acquistati, visualizzare lo sconto applicato e l’importo effettivo
    che il cliente deve pagare.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double importo, sconto, percentuale;
    int nPezzi;

    printf("Inserisci il prezzo di una fattura: ");
    scanf("%lf", &importo);
    printf("\nInserisci il numero di pezzi acquistati dal cliente: ");
    scanf("%d", &nPezzi);

    switch (nPezzi)
    {
    case 1:
        sconto = .9 * importo;
        percentuale = .1 * importo;
        printf("\nSconto del 10");
        break;
    case 2:
        sconto = .8 * importo;
        percentuale = .2 * importo;
        printf("\nSconto del 20");
        break;
    default:
        sconto = 0.7 * importo;
        percentuale = .3 * importo;
        printf("\nSconto del 30");
        break;
    }
    printf("\n\nIl prezzo da pagare e': %.2lf. Con uno sconto di: %.2lf", sconto, percentuale);
}