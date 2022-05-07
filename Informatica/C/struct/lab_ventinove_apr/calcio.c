/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct _
{
    char nome[20];
    int codice;
    int segnatiG;
    int subitiG;
} Squadra;
typedef Squadra Squadre[MAX];

void stampaVincenti(Squadre s, int dim)
{
    printf("Stampa delle square con numero di goal segnati maggiore di quelli subiti\n");
    printf("\nNome Squadra\tCodice\n");
    for (int i = 0; i < dim; i++)
        if (s[i].segnatiG > s[i].subitiG)
            printf(" %s\t\t%d\n", s[i].nome, s[i].codice);
}

int ricerca(Squadre s, int dim)
{
    int codice;
    printf("Inserisci il codice della squadra: ");
    scanf("%d", &codice);
    for (int i = 0; i < dim; i++)
        if (codice == s[i].codice)
            return i;
    return -1;
}
void stampaSquadra(Squadre s, int dim)
{
    int posizione = ricerca(s, dim);
    if (posizione != -1)
    {
        printf("\nNome squadra: %s", s[posizione].nome);
        printf("\nGoal segnati: %d", s[posizione].segnatiG);
        printf("\nGoal subiti: %d\n", s[posizione].subitiG);
    }
}

int caricaDaFile(Squadre sq)
{
    FILE *fp;
    char nomefile[20];
    int i = 0;
    printf("Inserisci il nome del file: ");
    scanf("%s", nomefile);
    if ((fp = fopen(nomefile, "r")) == NULL)
    {
        fprintf(stderr, "Impossibile aprire il file %s", nomefile);
        return -1;
    }
    fp = fopen(nomefile, "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s %d %d %d", sq[i].nome, &sq[i].codice, &sq[i].segnatiG, &sq[i].subitiG);
        i++;
    }
    fclose(fp);
    return i;
}

int main()
{
    int dim;
    Squadre sq;
    dim = caricaDaFile(sq);
    if (dim != -1)
    {
        stampaVincenti(sq, dim);
        stampaSquadra(sq, dim);
    }
    return 0;
}
