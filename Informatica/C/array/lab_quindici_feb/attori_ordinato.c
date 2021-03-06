/*
    Autore: Paolo Bianchessi 3ic
    Data: 15/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 3
#define LEN 50

char attori[DIM][LEN];

void inserisciAttore(int);
int cercaPresenza(char *);
void ordinaAttori();
void visualizza();

int main()
{
    int c = 1;
    char at[LEN];
    printf("Inserisci gli attori\n");
    for (int i = 0; i < DIM; i++)
    {
        inserisciAttore(i);
    }
    printf("\nBene, hai riempito il cast per il film.\n");
    printf("Elenco ordinato del cast: \n");
    ordinaAttori();
    visualizza();

    while (c)
    {
        printf("\ncerca: ");
        fgets(at, LEN, stdin);
        if (cercaPresenza(at))
            printf("\nL'attore %s e' presente nel cast.", at);
        else
            printf("\nL'attore %s non e' presente nel cast.", at);

        printf("\nCercare ancora? (1: si/0: no)");
        scanf("%d", &c);
    }

    return 0;
}

void inserisciAttore(int pos)
{
    printf("Attore %d: ", pos + 1);
    fgets(attori[pos], LEN, stdin);
}

int cercaPresenza(char attore[])
{
    for (int i = 0; i < DIM; i++)
    {
        if (strcmp(attore, attori[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void ordinaAttori()
{

    int i;
    char t[LEN];
    int scambi = 0;
    do
    {
        scambi = 0;
        for (i = 0; i < DIM - 1; i++)
            if (strcmp(attori[i], attori[i + 1]) > 0)
            {
                strcpy(t, attori[i]);
                strcpy(attori[i], attori[i + 1]);
                strcpy(attori[i + 1], t);
                scambi = 1;
            }
    } while (scambi == 1);
}

void visualizza()
{
    for (int i = 0; i < DIM; i++)
    {
        printf("Attore %d: %s", i + 1, attori[i]);
    }
}
