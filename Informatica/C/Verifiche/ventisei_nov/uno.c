/*
    Autore: Paolo Bianchessi 3ic
    Data: 26/11/2021
*/

#include <stdio.h>

int main()
{
    double importo, speseMilano = 0, speseRoma = 0, speseNapoli = 0, m = 0, r = 0, n = 0; // dichiarazione variabili
    char sede;
    char altreSpese = 's';
    int i = 0;
    do // fai...
    {
        printf("\nInserisci la sede: ");
        scanf(" %c", &sede);
        printf("Inserisci l'importo: ");
        scanf("%lf", &importo);
        printf("Devi inserire altre spese (s/n): "); // acquisizione in input variabli
        scanf(" %c", &altreSpese);
        if (sede == 'M') //se la sede è Milano (M)/ Roma(R)/ Napoli(N) incrementa l'accumulatore delle spese e anche il contatore della spese
        {
            speseMilano += importo;
            m++;
        }
        else if (sede == 'R')
        {
            speseRoma += importo;
            r++;
        }
        else if (sede == 'N')
        {
            speseNapoli += importo;
            n++;
        }

        i++;
    } while (altreSpese == 's');                                                          //... finché la scelta è uguale a s ovvero continua
    printf("\nLa spesa media per la sede di Milano e' di euro %.2lf\n", speseMilano / m); //stampa la spesa media di città in città facendo la divisione tra l'accumulatore e il contatore
    printf("\nLa spesa media per la sede di Roma e' di euro %.2lf\n", speseRoma / r);
    printf("\nLa spesa media per la sede di Napoli e' di euro %.2lf\n", speseNapoli / n);

    return 0;
}
