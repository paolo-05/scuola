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

    return abs(g1 - g2);
}
int aggiungiGiorni(Data d, int gg)
{
    Data nd;
    int ggTot, mm, aa;
    int numGG[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    ggTot = d.anno * 365 + d.giorno + numGG[d.mese - 1] + gg;
    nd.anno = ggTot / 365;
    ggTot = numGG[((ggTot - nd.anno * 365) % 12) - 1];
    return ggTot;
}
int main()
{
    Data d1, d2;
    int ggTot;
    char s[10] = "10/02/2022";
    d1 = nuovaData(s);
    ggTot = aggiungiGiorni(d1, 10);
    printf("\n%d\n", ggTot);
    return 0;
}
