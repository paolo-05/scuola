/*
    Autore: Paolo Bianchessi 3ic
    Data: 20/11/2021
    Descrizione: 
*/

#include <stdio.h>
int orario(int h, int min, int s)
{
    return h * 60 * 60 + min * 60 + s;
}
int main(void)
{
    int h, m, s;
    printf("Inserisci un orario da confrontare (hh mm ss): ");
    scanf("%d %d %d", &h, &m, &s);
    int orarioUno = orario(h, m, s);
    printf("Inserisci un orario da confrontare con quello precendente (hh mm ss): ");
    scanf("%d %d %d", &h, &m, &s);
    int orarioDue = orario(h, m, s);
    if (orarioUno > orarioDue)
    {
        printf("L'orario 1 e' maggiore del secondo\n");
    }
    else
    {
        printf("L'orario 2 e' maggiore del secondo\n");
    }
    return 0;
}
