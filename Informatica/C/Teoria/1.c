// Area del rettangolo

// %d intero; %f numero reale; %c carattere

#include <stdio.h>

int main () {
    double base, altezza;
    double area;

    printf("Inserisci il valore della base: ");
    scanf("%lf",&base);

    
    printf("Inserisci il valore dell'altezza: ");
    scanf("%lf",&altezza);

    area = base*altezza;
    printf("L'area vale %f", area);
}