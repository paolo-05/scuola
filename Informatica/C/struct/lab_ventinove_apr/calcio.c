/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef struct _
{
    char nome[20];
    int codice;
    int segnatiG;
    int subitiG;
} Squadra;
typedef Squadra Squadre[N];

void stampaVincenti(Squadre s)
{
    printf("Stampa delle square con numero di goal segnati maggiore di quelli subiti\n");
    printf("\nNome Squadra\tCodice\n");
    for (int i = 0; i < N; i++)
        if (s[i].segnatiG > s[i].subitiG)
            printf(" %s\t\t%d\n", s[i].nome, s[i].codice);
}

int ricerca(Squadre s)
{
    int codice;
    printf("Inserisci il codice della squadra: ");
    scanf("%d", &codice);
    for (int i = 0; i < N; i++)
        if (codice == s[i].codice)
            return i;
    return -1;
}
void stampaSquadra(Squadre s)
{
    int posizione = ricerca(s);
    printf("\nNome squadra: %s", s[posizione].nome);
    printf("\nGoal segnati: %d", s[posizione].segnatiG);
    printf("\nGoal subiti: %d\n", s[posizione].subitiG);
}

int main()
{
    Squadre sq = {
        {"juventus", 1, 10, 12},
        {"milan", 8, 7, 6},
        {"inter", 10, 13, 11},
        {"palermo", 2, 9, 10},
        {"lazio", 5, 8, 4},
        {"udinese", 14, 5, 7}};

    stampaVincenti(sq);
    stampaSquadra(sq);
    return 0;
}
