/*
    Autore: Paolo Bianchessi 3ic
    Data: 03/05/2022
    Descrizione: Verfica
*/

#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct indirizzo
{
    char via[20];
    int civico;
    char citta[20];
} Indirizzo;

typedef struct casa
{
    Indirizzo indirizzo;   // via - civico - città
    int mq;                // metri quadri
    char classeEnergetica; // A - F, dove A consuma poco e F consuma tanto
    double prezzo;         // Euro
} Casa;
typedef Casa Case[N];
/*
    Chiede all'utente i dati di N case
*/
void init(Case c);
/*
    Ritorna la poszione del vettore che ha associato il minor costo al mq
*/
int minorCosto(Case c);
/*
    Ritorna la poszione del vettore che ha associato la casa con la migliore
    classe energetica (in caso di parità di livello di classe energetica si riporti
    quella più grande)
*/
int miglioreClasseE(Case c);

int main()
{
    int p;
    Case caseInVendita;
    init(caseInVendita);
    p = minorCosto(caseInVendita);
    printf("\nLa casa con un migliore rapporto prezzo/mq (%2.lf) e' situata in via %s %d a %s",
           (float)caseInVendita[p].prezzo / caseInVendita[p].mq, caseInVendita[p].indirizzo.via,
           caseInVendita[p].indirizzo.civico, caseInVendita[p].indirizzo.citta);
    p = miglioreClasseE(caseInVendita);
    printf("\nLa casa con una migliore classe energetica (%c) e' situata in via %s %d a %s\n",
           caseInVendita[p].classeEnergetica, caseInVendita[p].indirizzo.via,
           caseInVendita[p].indirizzo.civico, caseInVendita[p].indirizzo.citta);
    return 0;
}
void init(Case c)
{
    for (int i = 0; i < N; i++)
    {
        printf("Inserisci l'indirizzo della casa (NomeVia Ncivico NomeCitta'): ");
        scanf("%s %d %s", c[i].indirizzo.via, &c[i].indirizzo.civico, c[i].indirizzo.citta);
        printf("Inserisci la grandezza in metri quadri della casa: ");
        scanf("%d", &c[i].mq);
        do
        {
            printf("Inserisci la classe energetica della casa: ");
            scanf(" %c", &c[i].classeEnergetica);
            if (c[i].classeEnergetica < 'A' || c[i].classeEnergetica > 'F')
                printf("\nErrore! La classe energetica deve essere compresa tra A e F\n");
        } while (c[i].classeEnergetica < 'A' || c[i].classeEnergetica > 'F');
        printf("Inserisci il prezzo della casa: ");
        scanf("%lf", &c[i].prezzo);
    }
}

int minorCosto(Case c)
{
    int min = 0;
    for (int i = 0; i < N; i++)
        if (c[min].prezzo / c[min].mq > c[i].prezzo / c[i].mq)
            min = i;
    return min;
}

int miglioreClasseE(Case c)
{
    int b = 0;
    for (int i = 0; i < N; i++)

        if (c[b].classeEnergetica >= c[i].classeEnergetica)
            if (c[b].classeEnergetica > c[i].classeEnergetica)
                b = i;
            else if (c[b].mq < c[i].mq)
                b = i;
    return b;
}