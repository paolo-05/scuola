/*
    Autore: Paolo Bianchessi 3ic
    Data: 26/02/2022
    Descrizione: inserisci il nome e ordina i caratteri.
matrice, prima colonna crescente seconda decrescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 10
#define D 2

void ordinaCrescente(char *, int);
void ordinaDecrescente(char *, int);
void visualizza(char *, int);

int main()
{
    char cars[D][L] = {0};
    printf("Inserisci il tuo nome: ");
    fgets(cars[0], L, stdin);
    strcpy(cars[1], cars[0]);

    printf("\nSequenza ordinata in modo crescente della prima riga (%s)\n", cars[0]);
    ordinaCrescente(cars[0], strlen(cars[0]));
    visualizza(cars[0], strlen(cars[0]));

    printf("\nSequenza ordinata in modo descrescente della seconda riga (%s)\n", cars[1]);
    ordinaDecrescente(cars[1], strlen(cars[1]));
    visualizza(cars[1], strlen(cars[1]));
    return 0;
}

void ordinaCrescente(char str[], int l)
{
    char t;
    int scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < l - 1; i++)
            if (str[i] > str[i + 1])
            {
                t = str[i];
                str[i] = str[i + 1];
                str[i + 1] = t;
                scambi = 1;
            }
    } while (scambi == 1);
}
void ordinaDecrescente(char str[], int l)
{
    char t;
    int scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < l - 1; i++)
            if (str[i] < str[i + 1])
            {
                t = str[i];
                str[i] = str[i + 1];
                str[i + 1] = t;
                scambi = 1;
            }
    } while (scambi == 1);
}
void visualizza(char str[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("posizione %d: %c\n", i + 1, str[i]);
    }
}