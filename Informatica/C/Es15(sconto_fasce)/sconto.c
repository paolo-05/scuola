/*
    Autore: Paolo Bianchessi 3ic
    Data: 15/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    float prezzo;
    int numProd1, numProd2, prodAcq, perScontoUno, perScontoDue;

    printf("Inserisci il prezzo unitario: ");
    scanf("%f", &prezzo);
    printf("\nInserisci il numero minimo di pezzi per lo sconto: ");
    scanf("%d", &numProd1);
    printf("\nInserisci il numero massimo di pezzi per lo sconto: ");
    scanf("%d", &numProd2);
    printf("\nInserisci il numero di prodotti acquistati: ");
    scanf("%d", &prodAcq);
    printf("\nInserisci il valore della percentuale di sconto 1: ");
    scanf("%d", &perScontoUno);
    printf("\nInserisci il valore della percentuale di sconto 2: ");
    scanf("%d", &perScontoDue);

    if (prodAcq >= numProd1 && prodAcq < numProd2)
    {
        prezzo = prezzo - prezzo * perScontoUno / 100;
        prezzo *= prodAcq;
    }
    else if (prodAcq >= numProd2)
    {
        prezzo = prezzo - prezzo * perScontoDue / 100;
        prezzo *= prodAcq;
    }
    else
    {
        prezzo *= prodAcq;
    }
    printf("Il prezzo e' %.2f", prezzo);
    return 0;
}
