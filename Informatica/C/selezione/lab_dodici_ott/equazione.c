/*
    Autore: Paolo Bianchessi 3ic
    Data: 12.10.2021
    Descrizione: ...
*/
#include <stdio.h>

int main(){
    double a,b;
    printf("Inserisci il coefficiente di x: ");
    scanf("%lf",&a);
    printf("Inserisci b: ");
    scanf("%lf",&b);

    if (a!=0){
        printf("La soluzione e': %lf", -b/a);
    }
    else{
        if (b!=0){
            printf("La soluzione e' impossibile");
        }
        else{
            printf("La soluzione e' indeterminata");
        }
    }
    return 0;
}