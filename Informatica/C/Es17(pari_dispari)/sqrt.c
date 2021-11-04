/*
    Autore: Paolo Bianchessi 3ic
    Data: 02/11/2021
    Descrizione: squared root
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, xp, x;
    printf("Inserisci un numero: ");
    scanf("%lf", &a);
    xp = a;
    x = a;

    do
    {

        xp = x;
        x = 0.5 * (xp + a / xp);
        printf("---->%lf\n", x);
    } while ((xp - x) > 0.0001);
    printf("La radice del numero %lf vale %lf\n", a, x);
    return 0;
}
