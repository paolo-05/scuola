/*
    Esercizi: 01
    Autore: Paolo Bianchessi 3ic
    Data: 28.09.2021
    Descrizione: acquisito un voto in input comunicare
                se è sufficiente oppure insufficiente  
*/
#include <stdio.h> //inclusione delle libererie

int main(){
    float voto;

    printf("\nInserisci un voto: ");
    scanf("%f", &voto);

    if (voto>=6)
    {
        printf("Il voto %f e' sufficiente", voto);
    }else
    {
        printf("Il tuo voto %f e' insufficiente", voto);
    };
    return 0;
}