/*
    Autore: Paolo Bianchessi 3ic
    Data: 8.10.2021
    Descrizione: Inserito da tastiera un numero che rappresenti un'età, stampare in base alla stessa:
    "sei un bambino", se l'età è inferiore a 14 anni
    "sei un adolescente" se l'età è compresa fra 14 e 17 anni
    "sei un adulto" se l'età è almeno 18
*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int anni;
    do
    {
        printf("Inserisci l'eta': ");
        scanf("%d", &anni);
    } while (anni < 0);

    if (anni <= 14)
        printf("Sei un bambino");
    else if (anni >= 14 && anni <= 17)
        printf("Sei un adolescente");
    else
        printf("Sei un adulto");
}