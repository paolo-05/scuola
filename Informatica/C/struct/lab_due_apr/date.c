/*
    Autore: Paolo Bianchessi 3ic
    Data: 02/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int giorno;
    int mese;
    int anno;
} Data;

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

Data nuovaData(char s[])
{
    Data d;
    sscanf(s, "%d/%d/%d\n", &d.giorno, &d.mese, &d.anno);
    return d;
}

int ggTra(Data d1, Data d2)
{
    int numGG[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int g1, g2;
    g1 = d1.anno * 365 + d1.giorno + numGG[d1.mese - 1];
    g2 = d2.anno * 365 + d2.giorno + numGG[d2.mese - 1];

    return g1 - g2;
}
Data aggiungiGiorni(Data d, int gg)
{
    Data nd;
    int gg, mm, aa;
    int numGG[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    gg = d.anno * 365 + d.giorno + numGG[d.mese - 1] + gg;

    return nd;
}
int main()
{
    Data d1, d2;
    char s[10];
    int n;
    printf("Inserisci una data: ");
    scanf("%s", s);
    d1 = nuovaData(s);
    strcpy(s, "");
    printf("\nInserisci una data: ");
    scanf("%s", s);
    d2 = nuovaData(s);
    n = ggTra(d1, d2);
    printf("\nI giorni tra le due date sono %d\n", n);
    return 0;
}
