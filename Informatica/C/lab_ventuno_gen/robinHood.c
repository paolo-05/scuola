/*
    Autore: Paolo Bianchessi 3ic
    Data: 21/01/2022
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>

void robinHood(float *p1, float *p2)
{
    *p1 = (*p1 + *p2) / 2;
    *p2 = *p1;
}

int controllo(int daControllare)
{
    if (daControllare > 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    float x, y;
    do
    {
        printf("Inserisci il valore del patrimonio della persona ricca: ");
        scanf("%f", &x);
    } while (controllo(x));

    do
    {
        printf("Inserisci il valore del patrimonio della persona povera: ");
        scanf("%f", &y);
    } while (controllo(y));

    robinHood(&x, &y);
    printf("\n\n Dopo che è passato Robin Hood la persona ricca ha %.2f euro e la persona povera ha %.2f euro\n", x, y);
    return 0;
}
