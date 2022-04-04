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
// stampa un data in formato gg/nomeMese/aa
void stampaDataF(Data d)
{
    char mesi[12][10] = {"gennaio", "febbraio",
                         "marzo", "aprile",
                         "maggio", "giungo",
                         "luglio", "agosto",
                         "settembre", "ottobre",
                         "novembre", "dicembre"};
    printf("%d %s %d\n", d.giorno, mesi[d.mese - 1], d.anno);
}
// ritorna un tipo una data ricevendo una stringa
Data nuovaData(char s[])
{
    Data d;
    sscanf(s, "%d/%d/%d\n", &d.giorno, &d.mese, &d.anno);
    return d;
}
// ritorna il valore assoluto della differenza tra le due date
int ggTra(Data d1, Data d2)
{
    int numGG[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int g1, g2;
    g1 = d1.anno * 365 + d1.giorno + numGG[d1.mese - 1];
    g2 = d2.anno * 365 + d2.giorno + numGG[d2.mese - 1];

    return abs(g1 - g2);
}
/*
    aggiunge gg giorni a una data
*/
Data aggiungiGiorni(Data d, int gg)
{
    /*  Data nd;
        int ggTot, mm;
        int numGG[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        ggTot = d.anno * 365 + d.giorno + numGG[d.mese - 1] + gg;
        nd.anno = ggTot / 365;
        mm = ggTot - (nd.anno * 365) - d.giorno - gg;
        for (int i = 0; i < 12; i++)
            if (numGG[i] == mm)
                nd.mese = i + 1;
        nd.giorno = ggTot - mm - (nd.anno * 365);
        return nd;
    */
    for (int i = 0; i < abs(gg); i++)
    {
        d.giorno++;
        if (
            ((d.giorno > 28) && (d.mese == 2)) ||
            ((d.mese > 30) && ((d.mese == 11) || (d.mese == 4) || (d.mese == 6) || (d.mese == 9))) ||
            ((d.giorno > 31) && ((d.mese == 1) || (d.mese == 3) || (d.mese == 5) || (d.mese == 7) || (d.mese == 8) || (d.mese == 10) || d.mese == 12)))
        {
            d.giorno = 1;
            d.mese++;
        }
        if (d.mese > 12)
        {
            d.mese = 1;
            d.anno++;
        }
    }
    return d;
}
int main()
{
    Data d1, d2;
    int offset;
    char s[10];
    printf("Inserisci una data: ");
    scanf("%s", s);
    d1 = nuovaData(s);
    stampaDataF(d1);
    printf("\ninserisci un numero di giorni: ");
    scanf("%d", &offset);
    d2 = aggiungiGiorni(d1, offset);
    stampaDataF(d2);
    return 0;
}
