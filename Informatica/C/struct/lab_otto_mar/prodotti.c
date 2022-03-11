/*
    Autore: Paolo Bianchessi 3ic
    Data: 08/03/2022
    Descrizione: prodotto, codice, nome, descrizione, categoria
*/

#include <stdio.h>
#include <stdlib.h>
#define QT 3

struct prodotto
{
    char nome[200];
    int codice;
    char descrizione[1000];
    char categoria[50];
} a[QT];

int main()
{
    for (int i = 0; i < QT; i++)
    {
        printf("\nInserisci il nome del prodotto: ");
        fgets(a[i].nome, 200, stdin);
        printf("Inserisci il codice del prodotto: ");
        scanf("%d", &a[i].codice);
        printf("Inserisci la categoria del prodotto: ");
        fgets(a[i].categoria, 50, stdin);
        printf("Inserisci la descrizione del prodotto: ");
        fgets(a[i].descrizione, 1000, stdin);
    }
    printf("\nnome | codice | categoria | descrizione\n");
    for (int i = 0; i < QT; i++)
    {
        printf("%s | %d | %s | %s\n", a[i].nome, a[i].codice, a[i].categoria, a[i].descrizione);
    }
    printf("\n");
    return 0;
}
