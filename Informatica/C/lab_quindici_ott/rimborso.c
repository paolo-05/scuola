/*
    Autore: Paolo Bianchessi 3ic
    Data: 15/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int rimborso;
    char nomeStud[20];
    float distanza, mediaVoti;

    printf("Inserisci il tuo nome: ");
    scanf("%s", nomeStud); //per le stringhe è possibile omettere la & prima del nome della variabile
    printf("%s, inserisci la distanza tra casa tua e la scuola: ", nomeStud);
    scanf("%f", &distanza);
    printf("%s, inserisci la media dei tuoi votii a scuola: ", nomeStud);
    if (distanza > 10)
    {
        scanf("%f", &mediaVoti);
        if (mediaVoti > 8)
            rimborso = 100;
        else
            rimborso = 50;

        printf("%s, che disti dalla scuola %.2f km con una media voti di %.2f hai diritto al rimborso del %d %%", nomeStud, distanza, mediaVoti, rimborso);
    }
    else
    {
        printf("%s, non hai diritto al rimborso, distanza %.2f km minore di 10km", nomeStud);
    }

    return 0;
}
