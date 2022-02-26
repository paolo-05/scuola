/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

int confronta(int *, int);
void inserisci(int *, int);
void visualizza(int *, int);

int main()
{
    int dim, res, max = 30;
    do
    {
        printf("Quanti numeri saranno inseriti? ");
        scanf("%d", &dim);
    } while (dim > max);
    int vet[dim];
    inserisci(vet, dim);
    printf("\nLa sequenza inserita e' la seguente\n");
    visualizza(vet, dim);
    if (confronta(vet, dim) == 0)
    {
        printf("La sequenza non e'cresecente\n");
    }
    else
    {
        printf("La sequenza e' cresecente\n");
    }

    return 0;
}
void inserisci(int v[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}
void visualizza(int v[], int l)
{
    for (int i = 0; i < l; i++)
        printf("Elemento %d: %d\n", i + 1, v[i]);
}
int confronta(int v[], int l)
{
    int e = 1;
    for (int i = 1; i < l && e == 1; i++)
    {
        if (v[i] <= v[i - 1])
            e = 0;
    }
    return e;
}