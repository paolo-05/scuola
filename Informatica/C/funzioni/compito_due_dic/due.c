/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/11/2021
    Descrizione: 
*/

#include <stdio.h>
#include <math.h>

int ipotenusa(int base, int altezza)
{
    return sqrt((double)((base * base) + (altezza * altezza)));
}
int perimetro(int base, int altezza)
{
    return (base + altezza + ipotenusa(base, altezza));
}
int area(int base, int altezza)
{
    return (base * altezza) / 2;
}
int main()
{
    int base, altezza;
    printf("Inserisci la base e l'altezza: ");
    scanf("%d %d", &base, &altezza);
    printf("L'ipotenusa vale: %d\nIl perimetro vale: %d\nL'area vale: %d\n",
           ipotenusa(base, altezza), perimetro(base, altezza), area(base, altezza));
    return 0;
}
