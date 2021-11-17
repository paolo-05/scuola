/*  Autore: Paolo Bianchessi 3ic
    Data: 30.09.2021
    Descirzione: Chiedi all'utente quanti soldi ha e quanto costa la moto. Stampa se puo' comprare la moto o no
*/
#include <stdio.h>

int main(){
    float costoMoto, soldiDispozione;

    printf("Quanto costa la moto che vuoi prendere? ");
    scanf("%f",&costoMoto);

    printf("Quanti soldi hai a disosizione? ");
    scanf("%f",&soldiDispozione);
    
    if (soldiDispozione >= costoMoto){
        printf("Puoi comprare la moto.");
    }
    else{
        printf("Noon puoi comprare la moto.");
    }

    return 0;
}