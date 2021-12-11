/*
    Autore: Paolo Bianchessi 3ic
    Data: 8.10.2021
    Descrizione: Scrivere un programma che converta in secondi un intervallo di tempo composto da ore, minuti e secondi inserito dall'utente. Controllare che i valori inseriti siano validi altrimenti stampare un messaggio d'errore.
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int ore, sec, min;
    do
    {
        printf("Inserisci un numero di ore: ");
        scanf("%d", &ore);
        printf("\nInserisci un numero di minuti: ");
        scanf("%d", &min);

        printf("\nInserisci un numero di secondi: ");
        scanf("%d", &sec);
    } while (ore <= 0 || ore >= 24 || sec <= 0 || sec >= 60 || min <= 0 || min >= 60);

    if (ore != 0)
    {
        ore = ore * 3600;
    }
    if (min != 0)
    {
        min = min * 60;
    }
    sec = sec + ore + min;

    printf("L'orario convertito in secondi e': %d", sec);

    return 0;
}