/*
    Autore: Paolo Bianchessi 3ic
    Data: 04/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

#define N_D 11
#define L 60
#define MAX_ERR 6

void stampaDomanda(int);
void acquisiciControllaRisposta(char *, int, int *, int *);
void disegnaPatibolo(int);

char domande[N_D][L] = {
    "Dante ha scritto la Commedia",
    "Dante ha scritto i Promessi Sposi",
    "Manzoni ha scritto la Commedia",
    "Virgilio ha scritto la Commedia",
    "Boccaccio ha scritto il Decameron",
    "La Provincia e' il giornale delle provincia di Cremona",
    "2+2 = 2x2",
    "4^5 = 4x5",
    "6+6 = 6x6",
    "La CPU e' la parte meno importante di un PC",
    "\n"},
     risposte[N_D] = {'s', 'n', 'n', 'n', 's', 's', 's', 'n', 'n', 'n', '\0'};

int main()
{
    int errori = 0, corrette = 0;
    char risposta;

    printf("\t\tGIOCO DELL'IMPICCATO\n");
    printf("\t\tDomande di conoscenza generale\n");

    for (int i = 0; i < N_D - 1 && errori < MAX_ERR; i++)
    {
        printf("\nDomanda numero %d\n", i + 1);
        stampaDomanda(i);
        acquisiciControllaRisposta(&risposta, i, &errori, &corrette);
        disegnaPatibolo(errori);
    }
    printf("Risposte esatte %d\nRipsoste errate %d", corrette, errori);

    if (errori >= MAX_ERR)
    {
        printf("\nHai perso\n");
    }
    else
    {
        printf("\nHai vinto! Complimenti!");
    }

    return 0;
}

void stampaDomanda(int numero)
{
    printf("%s? (s/n) ", domande[numero]);
}

void acquisiciControllaRisposta(char *ris, int nRis, int *errori, int *esatte)
{
    do
    {
        scanf(" %c", ris);
    } while (*ris != 115 && *ris != 110);

    if (*ris == risposte[nRis])
    {
        printf("Corretto.\n\n");
        (*esatte)++;
    }
    else
    {
        printf("Errato.\n\n");
        (*errori)++;
    }
}

void disegnaPatibolo(int nErr)
{
    switch (nErr)
    {
    case 0:
        printf("*---------\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|________\n");
        break;
    case 1:
        printf("*---------\n");
        printf("|         o\n");
        printf("|\n");
        printf("|\n");
        printf("|________\n");
        break;
    case 2:
        printf("*---------\n");
        printf("|         o\n");
        printf("|         |\n");
        printf("|\n");
        printf("|________\n");
        break;
    case 3:
        printf("*---------\n");
        printf("|         o\n");
        printf("|        /|     \n");
        printf("|\n");
        printf("|________\n");
        break;
    case 4:
        printf("*---------\n");
        printf("|         o\n");
        printf("|        /|\\ \n");
        printf("|\n");
        printf("|________\n");
        break;
    case 5:
        printf("*---------\n");
        printf("|         o\n");
        printf("|        /|\\ \n");
        printf("|        /\n");
        printf("|________\n");
        break;
    case 6:
        printf("*---------\n");
        printf("|         o\n");
        printf("|        /|\\ \n");
        printf("|        /\\\n");
        printf("|________\n");
        break;
    default:
        break;
    }
}