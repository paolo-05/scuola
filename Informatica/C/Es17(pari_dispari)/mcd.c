/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/10/2021
    Descrizione:
*/

#include <stdio.h>
int mcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return mcd(b, a % b);
    }
}
int main()
{
    int a, b;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("inserisci un altro numero: ");
    scanf("%d", &b);

    printf("il massimo comun divisore e': %d", mcd(a, b));
}
