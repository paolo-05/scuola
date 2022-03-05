/*
    Autore: Paolo Bianchessi 3ic
    Data: 12/10/2021
    Descrizione: Gauss scoprì che la somma dei numeri naturali da 1 a n è uguale a n*(n+1)/2. Scrivere un programma che, dato un numero intero positivo n specificato dall’utente, calcoli la somma dei primi n numeri naturali utilizzando la formula di Gauss. Es.: 1+2+3+4 = 4*(4+1)/2 = 4*5/2 = 10
*/

#include <stdio.h>

int main(){
    int n;

    printf("Inserisci un numero intero *Reale*: ");
    scanf("%d",&n);

    n=n*(n+1)/2;

    printf("Il risultato e' %d", n);
}