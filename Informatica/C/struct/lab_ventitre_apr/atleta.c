/*
    Autore: Paolo Bianchessi 3ic
    Data: 23/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct _
{
    char nome[20];
    int altezza; // in cm
    double peso; // in kg
} Atleta;

void stampa(Atleta b[])
{
    for (int i = 0; i < N; i++)
    {
        printf("\nNome: %s", b[i].nome);
        printf("\nAltezza: %d cm", b[i].altezza);
        printf("\nPeso: %.2lf kg\n", b[i].peso);
    }
}

void aumentaPeso(Atleta b[], int pos, double kg)
{
    b[pos].peso += kg;
}
void aumentaPeso2(Atleta *b, double kg)
{
    b->peso += kg;
}

int main()
{
    // memorizza N atleti iscritti ad una gara e inizializza
    Atleta a[N] = {
        {"Rossi", 178, 79.5},
        {"Verdi", 159, 63.2},
        {"Gialli", 169, 65.2},
        {"Azzurri", 181, 78.3},
        {"Neri", 175, 69.9}};
    // stampa dati
    stampa(a);

    // modifica peso dell'atleta 1
    // aumentaPeso(a, 1, 5.0);

    // alternativa
    aumentaPeso2(&a[1], 5.0);

    // ristampa dei dati
    stampa(a);
    return 0;
}
