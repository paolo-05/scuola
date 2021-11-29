/*
    Autore: Paolo Bianchessi 3ic
    Data: 26/11/2021
*/

#include <stdio.h>

int main()
{
    double saldo, interesse, soglia;
    int i = 0; //inizzializzazione variabli
    printf("\nInserisci il saldo iniziale: ");
    scanf("%lf", &saldo);
    printf("Inserisci il tasso di interesse: "); //acquisizione in input
    scanf("%lf", &interesse);
    printf("Inserisci la soglia da raggiungere: ");
    scanf("%lf", &soglia);
    while (saldo <= soglia) // finché saldo è minore della soglia...
    {
        i++;                              //.. incrementa i...
        saldo += saldo * interesse / 100; //.. calcola e comunica il nuovo saldo
        printf("\nanno %d saldo %.2lf\n", i, saldo);
    }
    printf("Ci sono voluti %d anni per raggiungere o superare %.2lf\n", i, soglia); // alla fine del programma comunica quanti anni ci sono voluti
    return 0;
}
