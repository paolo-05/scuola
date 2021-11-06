/*
    Autore: Paolo Bianchessi 3ic
    Data: 05/11/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    //acquisisco le dimensioni del foglio
    double l1, l2, lmin, altezza = 0, v, vMax, altezzaottimale;
    printf("inserisci il primo lato: ");
    scanf("%lf", &l1);
    printf("\ninserisci il secondo lato: ");
    scanf("%lf", &l2);
    //v massimo ottenibile
    if (l1 < l2)
    {
        lmin = l1;
    }
    else
    {
        lmin = l2;
    }
    while (altezza < lmin / 2)
    {
        v = (l1 - altezza * 2) * (l2 - altezza * 2) * altezza;
        if (vMax < v)
        {
            vMax = v;
            altezzaottimale = altezza;
        }
        altezza += 0.5;
    }
    //stampo i risultati
    printf("Il v massimo ottenibile e': %.2lf e l'atezza ottimale e' %.2lf\n", vMax, altezzaottimale);

    return 0;
}
