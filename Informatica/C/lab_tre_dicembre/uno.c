/*
    Autore: Paolo Bianchessi 3ic
    Data: 03/12/2021
    Descrizione: 
*/

#include <stdio.h>

const double PI = 3.14;

double circonferenza(double raggio)
{
    return raggio * 2 * PI;
}
double area(double raggio)
{
    return raggio * raggio * PI;
}
double volume(double raggio, double altezza)
{
    return area(raggio) * altezza;
}

int main()
{
    int scelta;
    double raggio, altezza, risposta;
    printf("\n1 - Calcola circonferenza dato il raggio\n2 - Calcola volume dati raggio e altezza\n");
    do
    {
        printf("Scelta: ");
        scanf("%d", &scelta);
    } while (!(scelta == 1 || scelta == 2));

    printf("\nInserisci il raggio: ");
    scanf("%lf", &raggio);

    if (scelta == 1)
    {
        risposta = circonferenza(raggio);
    }
    else
    {
        printf("Inserisci l'altezza del cilindro: ");
        scanf("%lf", &altezza);
        risposta = volume(raggio, altezza);
    }
    printf("\nIl risultato e' %.2lf\n", risposta);

    return 0;
}
