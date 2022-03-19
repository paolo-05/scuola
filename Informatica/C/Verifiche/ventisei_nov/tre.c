/*
    Autore: Paolo Bianchessi 3ic
    Data: 26/11/2021
*/

#include <stdio.h>

int main()
{
    int base;
    char carattere; //inizzializzazione variabili
    printf("Inserisci la base del triangolo: ");
    scanf("%d", &base);
    printf("Inserisci il carattere con cui vui che sia fatto il triangolo: "); // acqisizione in  input variabili
    scanf(" %c", &carattere);
    printf("\n");
    for (int i = 1; i <= base; i++) // finché i è minore o uguale della base
    {
        for (int j = 1; j <= i; j++) // finché il numero di carattere j è minore della lunghezza della lato in quel monento
        {
            printf("%c", carattere); // stampa il carattere
        }
        printf("\n"); // nuova linea
    }
    printf("\n");

    return 0;
}
