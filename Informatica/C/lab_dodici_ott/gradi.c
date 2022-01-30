/*
    Autore: Paolo Bianchessi 3ic
    Data: 12/10/2021
    Descrizione: Scrivere un programma che, data una temperatura in gradi Centigradi inserita dall’utente, la converta in gradi Fahrenheit e viceversa.

Fahrenheit = 32 + Centigradi * 1,8

Centigradi = (Fahrenheit - 32) / 1,8
*/

#include <stdio.h>
int main(){
    int scelta=0;
    printf("Vuoi convertire i gradi F (0) o C (1), premi 0 o 1 per la scelta: ");
    scanf("%d",&scelta);
    float f,c;
    if (scelta==0)
    {
        printf("Inserisci i gradi in F: ");
        scanf("%f",&f);
        c=(f-32)/1.8;
        printf("La conversione risulta: %f C",c);
    }
    else if (scelta==1){
        printf("Inserisci i gradi in C: ");
        scanf("%f",&c);

        f=32+c*1.8;
        printf("La conversione risulta: %f F",f);
    }
    else{
        printf("La scelta %d non ha portato a risultati.", scelta);
    }
}