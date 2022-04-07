/*
    Autore: Paolo Bianchessi 3ic
    Data: 07/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EL 100

typedef struct r
{
    char nome[20];
    char cognome[20];
    char numero[20];
} Record;
typedef Record Rubrica[MAX_EL];

void init(Rubrica r, int *elementi);
void menu(Rubrica r, int *elementi);
void scelte();

void stampa(Rubrica r, int elementi);
int ricerca(Rubrica r, int elementi);
void aggiornamento(Rubrica r, int posizione);
void cancella(Rubrica r, int *elementi);

int main()
{
    int elementi = 0;
    char s = 's';
    Rubrica r;
    while (s == 's' && elementi < MAX_EL)
    {
        init(r, &elementi);
        printf("Continuare (s/n): ");
        scanf(" %c", &s);
    }
    menu(r, &elementi);
    return 0;
}
// inizializza la rubirca
void init(Rubrica r, int *elementi)
{
    printf("Nome: ");
    scanf("%s", r[(*elementi)].nome);
    printf("Cognome: ");
    scanf("%s", r[(*elementi)].cognome);
    printf("Numero di telefono: ");
    scanf("%s", r[(*elementi)].numero);
    (*elementi)++;
}

// gestisce tutto il programma
void menu(Rubrica r, int *elementi)
{
    int c = 1, scelta;
    int presente;
    do
    {
        scelte();
        printf("Scelta: ");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            // stampa
            stampa(r, *elementi);
            break;
        case 2:
            // ricerca
            presente = ricerca(r, *elementi);
            (presente == -1) ? printf("\nNell'archivio non è stata trovata nessuna corrispondenza\n")
                             : printf("\nIl numero di telefono di %s %s e' %s", r[presente].nome, r[presente].cognome, r[presente].numero);
            break;
        case 3:
            // aggiornamento di un numero telefonico
            presente = ricerca(r, *elementi);
            aggiornamento(r, presente);
            break;
        case 4:
            // insrimento di un altro record
            ((*elementi) < 100) ? init(r, elementi) : printf("\nImpossibile aggiungere altri record: Rubrica piena.\n");
            break;
        case 5:
            // cancella
            cancella(r, elementi);
            break;
        case 6:
            // uscita dal programma
            printf("\nCiao.\n");
            c = 0;
            break;
        default:
            printf("\nNumero inserito non corretto.");
            break;
        }
    } while (c);
}

// stampa le scelte del menu
void scelte()
{
    printf("\n1 - Stampa");
    printf("\n2 - Ricerca");
    printf("\n3 - Aggiornamento");
    printf("\n4 - Inserimento");
    printf("\n5 - Cancellazione");
    printf("\n6 - Uscita\n");
}

// stampa formattata della rubrica
void stampa(Rubrica r, int elementi)
{
    printf("\nNome\t\tCognome\t\tNumero di telefono\n");
    for (int i = 0; i < elementi; i++)
        printf("%s\t\t%s\t\t%s\n", r[i].nome, r[i].cognome, r[i].numero);
}

// ricerca di un numero tramite nome - cognome
int ricerca(Rubrica r, int elementi)
{
    char nome[20], cognome[20];
    printf("\n Nome: ");
    scanf("%s", nome);
    printf(" Cognome: ");
    scanf("%s", cognome);

    for (int i = 0; i < elementi; i++)
        if (strcmp(r[i].nome, nome) == 0 && strcmp(r[i].cognome, cognome) == 0)
            return i;
    return -1;
}

// aggiornamento di un numero di telefono data la posizione
void aggiornamento(Rubrica r, int posizione)
{
    char numero[20];
    printf("Inserisci un nuovo numero di telefono per %s %s: ", r[posizione].nome, r[posizione].cognome);
    scanf("%s", numero);
    strcpy(r[posizione].numero, numero);
}

// cancella sovrascrivendo data una posizione
void cancella(Rubrica r, int *elementi)
{
    printf("\nChi vuoi cancellare: ");
    int p = ricerca(r, *elementi);
    if (p != -1)
    {
        for (int i = p; i < (*elementi) - 1; i++)
            r[i] = r[i + 1];
        (*elementi)--;
    }
    else
        printf("\nNon e' stato possibile eseguire l'operazione: utente non trovato.\n");
}