/*
    Autore: Paolo Bianchessi 3ic
    Data: 10/12/2021
    Descrizione: 
*/

#include <stdio.h>
#include <stdio.h>

int mcd(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else
        return mcd(n2, n1 % n2);
}
int dividi(int *a, int *b)
{
    int maxcomdiv, temp;
    if (a < b)
    {
        temp = *b;
        *b = *a;
        *a = temp;
        maxcomdiv = mcd(*a, *b);
        *a /= maxcomdiv;
        *b /= maxcomdiv;
        temp = *b;
        *b = *a;
        *a = temp;
    }
    else
    {
        maxcomdiv = mcd(*a, *b);
        *a /= maxcomdiv;
        *b /= maxcomdiv;
    }
}
int main()
{
    int a, b, c, d, massimoComunDivisore;
    printf("Inserisci una frazione (n/d): ");
    scanf("%d/%d", &a, &b);
    dividi(&a, &b);
    printf("Inserisci un'altra frazione (n/d): ");
    scanf("%d/%d", &c, &d);
    dividi(&c, &d);
    printf("\nLe due frazioni ridotte ai minimi termini sono %d/%d e %d/%d", a, b, c, d);
    if (b == d)
    {
        printf("\n le due frazioni hanno lo stesso denominatore.\n");
    }
}
