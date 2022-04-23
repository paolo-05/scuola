/*
    Autore: Paolo Bianchessi 3ic
    Data: 21/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char titolo[50];
    int durata;
    int anno;
} Film;

void printFilm(Film *f)
{
    printf("\nId: %d\n", f->id);
    printf("Film: %s\n", f->titolo);
    printf("Durata: %d\n", f->durata);
    printf("Anno: %d\n", f->anno);
}

int main()
{
    Film f1;
    Film f2;

    strcpy(f1.titolo, "The Imitation Game");
    f1.durata = 130;
    f1.anno = 2014;
    f1.id = 975564;

    strcpy(f2.titolo, "Matrix");
    f2.durata = 130;
    f2.anno = 1999;
    f2.id = 975665;

    printFilm(&f1);
    printFilm(&f2);

    return 0;
}
