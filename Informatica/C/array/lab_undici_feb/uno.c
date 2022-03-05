/*
    Autore: Paolo Bianchessi 3ic
    Data: 11/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

#define MAT 24
char mat[MAT][MAT];

void riempi();
void stampaMatrice();

int main()
{
    int riga, colonna;
    riempi();
    printf("Inserisci la riga: ");
    scanf("%d", &riga);
    printf("Inserisci la colonna: ");
    scanf("%d", &colonna);
    mat[riga - 1][colonna - 1] = '*';
    stampaMatrice();
    return 0;
}

void riempi()
{
    for (int i = 0; i < MAT; i++)
        for (int j = 0; j < MAT; j++)
            mat[i][j] = '.';
}

void stampaMatrice()
{
    for (int i = 0; i < MAT; i++)
    {
        for (int j = 0; j < MAT; j++)
            printf("%c", mat[i][j]);
        printf("\n");
    }
}
