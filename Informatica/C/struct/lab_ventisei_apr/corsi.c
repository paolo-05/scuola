/*
    Autore: Paolo Bianchessi 3ic
    Data: 26/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM 7
typedef struct _
{
    char nomec[20];
    char cognome[15];
    int iscritti;
} Corso;
typedef Corso Corsi[ELEM];

int mediaIscritti(Corsi c);
void stampaMagGUguale(Corsi c, int m);
void ordina(Corsi c);

int main()
{
    srand((long)time(NULL));
    Corsi c = {
        {"analisi1", "foschi", 0},
        {"geometria", "mazzanti", 0},
        {"informatica", "gavanelli", 0},
        {"fisica1", "frontera", 0},
        {"fisica2", "zavattini", 0},
        {"inglese", "rossi", 0},
        {"analisi2", "paoli", 0}};

    // inizzializzazione degli iscritti con random
    for (int i = 0; i < ELEM; i++)
    {
        c[i].iscritti = rand() % 56 + 45;
        printf("%d ", c[i].iscritti);
    }

    int m = mediaIscritti(c);
    ordina(c);
    stampaMagGUguale(c, m);

    return 0;
}

int mediaIscritti(Corsi c)
{
    int acc = 0;
    for (int i = 0; i < ELEM; i++)
        acc += c[i].iscritti;
    return acc / ELEM;
}

void stampaMagGUguale(Corsi c, int m)
{
    printf("\nStampa dei corsi con iscritti maggiori di %d in ordine descrescente:", m);
    printf("\n   Nome corso\t\tCognome prof\n");
    for (int i = 0; i < ELEM; i++)
        if (c[i].iscritti >= m)
            printf("    %s\t\t%s\n", c[i].nomec, c[i].cognome);
}

void ordina(Corsi vet)
{
    Corso temp;
    int scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < ELEM - 1; i++)
            if (vet[i].iscritti < vet[i + 1].iscritti)
            {
                temp = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = temp;
                scambi = 1;
            }
    } while (scambi == 1);
}