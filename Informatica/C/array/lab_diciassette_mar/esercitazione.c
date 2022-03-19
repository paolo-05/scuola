/*
    Autore: Paolo Bianchessi 3ic
    Data: 17/03/2022
    Descrizione:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPRODOTTI 50
#define MAXL 20

void acquisisci(char prodotti[][MAXL], double prezzi[], int d);
void report(char prodotti[][MAXL], double prezzi[], int d);
int ricercaPerNome(char prodotti[][MAXL], int d);
double ricavatoTotale(double prezzi[], int d);
double importoMedio(char prodotti[][MAXL], double prezzi[], int d);
void ordina(char prodotti[][MAXL], double prezzi[], int d);
void stampa(char prodotti[][MAXL], double prezzi[], int scelta, int contatore, int d);
int minoreMaggiore(char prodotti[][MAXL], double prezzi[], int d);
void scelte(char prodotti[][MAXL], double prezzi[], int d);
void menu(char prodotti[][MAXL], double prezzi[]);

int main()
{
    char prodotti[MAXPRODOTTI][MAXL];
    double prezzi[MAXPRODOTTI];
    menu(prodotti, prezzi);
}

void acquisisci(char prodotti[][MAXL], double prezzi[], int d)
{
    int i;
    for (i = 0; i < d; i++)
    {
        printf("Inserisci prodotto %d: ", i + 1);
        scanf("%s %lf", prodotti[i], &prezzi[i]);
    }
}

void report(char prodotti[][MAXL], double prezzi[], int d)
{
    int i;
    printf("\nProdotto\t\tPrezzo\n");
    for (i = 0; i < d; i++)
    {
        printf("%s\t\t%.2lf\n", prodotti[i], prezzi[i]);
    }
}

int ricercaPerNome(char prodotti[][MAXL], int d)
{
    char scelta[MAXL];
    int i;
    printf("\nDigita il nome del prodotto: ");
    scanf("%s", scelta);
    for (i = 0; i < d; i++)
    {
        if (strcmp(prodotti[i], scelta) == 0)
        {
            return i;
        }
    }
    return -1;
}

double ricavatoTotale(double prezzi[], int d)
{
    int i;
    double somma = 0;
    for (i = 0; i < d; i++)
    {
        somma += prezzi[i];
    }
    return somma;
}

double importoMedio(char prodotti[][MAXL], double prezzi[], int d)
{
    char scelta[MAXL];
    int i, counter = 0;
    double somma = 0;
    printf("\nDigita il nome del prodotto: ");
    scanf("%s", scelta);
    for (i = 0; i < d; i++)
    {
        if (strcmp(scelta, prodotti[i]) == 0)
        {
            counter++;
            somma += prezzi[i];
        }
    }
    if (counter > 0)
    {
        return somma / (double)counter;
    }
    else
    {
        return 0;
    }
}

void ordina(char prodotti[][MAXL], double prezzi[], int d)
{
    int i, j;
    double temp;
    char strtemp[MAXL];
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < d; j++)
        {
            if (prezzi[i] < prezzi[j])
            {
                temp = prezzi[i];
                prezzi[i] = prezzi[j];
                prezzi[j] = temp;
                strcpy(strtemp, prodotti[i]);
                strcpy(prodotti[i], prodotti[j]);
                strcpy(prodotti[j], strtemp);
            }
        }
    }
}

void stampa(char prodotti[][MAXL], double prezzi[], int scelta, int contatore, int d)
{
    if (scelta == 1)
    {
        if (prezzi[contatore + 1] == prezzi[contatore])
        {
            printf("%s\n", prodotti[contatore + 1]);
            contatore++;
            stampa(prodotti, prezzi, scelta, contatore, d);
        }
    }
    else
    {
        if (prezzi[d - 1] == prezzi[d - 2])
        {
            printf("%s\n", prodotti[d - 2]);
            d--;
            stampa(prodotti, prezzi, scelta, contatore, d);
        }
    }
}

int minoreMaggiore(char prodotti[][MAXL], double prezzi[], int d)
{
    int scelta;
    ordina(prodotti, prezzi, d);
    printf("Cosa vuoi stampare?\n1.prodotti meno cari\n2.prodotti piu' cari\n->");
    scanf("%d", &scelta);
    if (scelta == 1)
        return 0;
    else
        return d - 1;
}

void scelte(char prodotti[][MAXL], double prezzi[], int d)
{
    int scelta;
    int pos;
    double valore;
    printf("\nCosa vuoi fare?\n1.Visualizzare il report\n2.Cerca per nome\n3.Ricavato totale vendite\n4.visualizza il prezzo medio di vendita di un prodotto\n5.visualizza i prodotti con il prezzo maggiore e con il prezzo minore\n-> ");
    scanf("%d", &scelta);
    switch (scelta)
    {
    case 1:
        report(prodotti, prezzi, d);
        scelte(prodotti, prezzi, d);
        break;
    case 2:
        pos = ricercaPerNome(prodotti, d);
        if (pos >= 0)
            printf("Prodotto trovato in posizione %d\n", pos);
        else
            printf("Prodotto non trovato\n");
        scelte(prodotti, prezzi, d);
        break;
    case 3:
        valore = ricavatoTotale(prezzi, d);
        printf("Ricavo totale: %lf\n", valore);
        scelte(prodotti, prezzi, d);
        break;
    case 4:
        valore = importoMedio(prodotti, prezzi, d);
        if (valore > 0)
            printf("Importo medio: %lf\n", valore);
        else
            printf("Valore nullo\n");
        scelte(prodotti, prezzi, d);
        break;
    case 5:
        pos = minoreMaggiore(prodotti, prezzi, d);
        printf("Il prodotto e' %s\n", prodotti[pos]);
        scelte(prodotti, prezzi, d);
        break;
    default:
        printf("Grazie di aver usato il mio programma!");
    }
}

void menu(char prodotti[][MAXL], double prezzi[])
{
    int d;
    printf("Quanti prodotti vuoi inserire? ");
    scanf("%d", &d);
    acquisisci(prodotti, prezzi, d);
    scelte(prodotti, prezzi, d);
}