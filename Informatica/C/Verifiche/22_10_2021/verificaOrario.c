/*
    Autore: Paolo Bianchessi 3ic
    Data: 22/10/2021
    Descrizione: Orario: dati due oriari (ore:min) stampare quale viene prima
*/

#include <stdio.h>

int main()
{
    int ore1, min1, ore2, min2, temp1, temp2;
    printf("Inserisci un orario (hh:mm): ");
    scanf("%d:%d", &ore1, &min1); //acquisione in input del primo orario

    printf("Inserisci un altro orario (hh:mm): "); //acquisione in input del secondo orario
    scanf("%d:%d", &ore2, &min2);

    if (ore1 < 0 || ore1 >= 24 || min1 <= 0 || min1 >= 60) //controllo l'input e...
    {
        printf("Orario 1 non valido"); //se il primo orario non è valido stampo
    }
    else if (ore2 < 0 || ore2 >= 24 || min2 <= 0 || min2 >= 60) //altrimenti se...
    {
        printf("Orario 2 non valido"); // il secondo orario se il secondo orario non è valido stampo
    }
    else //altrimenti eseguo il programma
    {
        temp1 = min1 + ore1 * 60; //converto le ore in minuti in modo da fare una selezione più semplice utilizzando una variabile temponranea
        temp2 = min2 + ore2 * 60;
        if (temp1 < temp2) // controlle se il primo orario è minore del secondo e ...
        {
            printf("Viene prima %d:%d", ore1, min1); //se vero stampo che viene prima l'orario 1
        }
        else
        {
            printf("Viene prima %d:%d", ore2, min2); //altrimenti stampo che viene prima l'orario 2
        }
    }

    return 0;
}
