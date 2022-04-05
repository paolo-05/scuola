/*
    Autore: Paolo Bianchessi 3ic
    Data: 05/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dato
{
    int valore;
    int presente; // flag di validità
} Dato;

void stampa(Dato v[], int d)
{
    for (int i = 0; i < d; i++)
        printf("%d ", v[i].valore);
}

void stampaP(Dato v[], int d)
{
    for (int i = 0; i < d; i++)
        if (v[i].presente)
            printf("%d ", v[i].valore);
}

void elimina(Dato v[], int d, int p)
{
    for (int i = p; i < d - 1; i++)
        v[i] = v[i + 1];
}
void cancella(Dato v[], int d, int p)
{
    v[p].presente = 0;
}

int main()
{
    int dim = 9;
    Dato a[9] = {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}};
    stampa(a, dim);
    // elimina(a, dim, 3);
    // dim--;
    cancella(a, dim, 3);

    printf("\n");
    // stampa(a, dim);
    stampaP(a, dim);
    return 0;
}
