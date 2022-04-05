/*
    Autore: Paolo Bianchessi 3ic
    Data: 05/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_P 100
typedef struct data
{
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct persona
{
    char nome[20];
    char cognome[20];
    Data nascita;
} Persona;

typedef Persona Persone[MAX_P];
// stampa un data in formato gg/nomeMese/aa
void stampaDataF(Data d);

// ritorna un tipo una data ricevendo una stringa
Data nuovaData(char s[]);

// stampa dei dati di tutte le persone in archivio
void stampaP(Persone p, int d);

// acquisizione in input dei dati di una persona
void input(Persone p, int pos);

int main()
{
    char c = 's';
    Persone p;
    int tot = 0;
    while (c == 's' && tot < MAX_P)
    {
        input(p, tot);
        printf("Contnuare (s/n): ");
        scanf(" %c", &c);
        if (c == 'n' && tot < 3)
        {
            printf("Inserire almeno 3 persone.\n");
            c = 's';
        }
        tot++;
    }
    stampaP(p, tot);
    return 0;
}

void stampaDataF(Data d)
{
    char mesi[12][10] = {"gennaio", "febbraio",
                         "marzo", "aprile",
                         "maggio", "giungo",
                         "luglio", "agosto",
                         "settembre", "ottobre",
                         "novembre", "dicembre"};
    printf("%d %s %d", d.giorno, mesi[d.mese - 1], d.anno);
}

void stampaP(Persone p, int dim)
{
    printf("Nome\t\tCognome\t\tData di nascita\n");
    for (int i = 0; i < dim; i++)
    {
        printf("\n%s\t\t%s\t\t", p[i].nome, p[i].cognome);
        stampaDataF(p[i].nascita);
    }
    printf("\n");
}
Data nuovaData(char s[])
{
    Data d;
    sscanf(s, "%d/%d/%d\n", &d.giorno, &d.mese, &d.anno);
    return d;
}

void input(Persone p, int pos)
{
    char s[10];
    printf("Nome: ");
    scanf("%s", p[pos].nome);
    printf("Cognome: ");
    scanf("%s", p[pos].cognome);
    printf("Data di nascita (gg/mm/aa): ");
    scanf("%s", s);
    p[pos].nascita = nuovaData(s);
}
