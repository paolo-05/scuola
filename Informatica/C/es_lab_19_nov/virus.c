/*
    Autore: Paolo Bianchessi 3ic
    Data: 19/11/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int persone, tasso, malati = 1, giorni = 0;
    printf("inserisci la popolazione: ");
    scanf("%d", &persone);
    printf("inserisci il tasso di contagio: ");
    scanf("%d", &tasso);

    while (malati < (persone / 2))
    {
        malati = malati + (malati * tasso);
        printf("  Il giorno %d ci sono %d malati\n", giorni + 1, malati);
        giorni++;
    }
    printf("i giorni neessari per far ammalare almeno la meta' della popolazione sono %d\n", giorni);
}
