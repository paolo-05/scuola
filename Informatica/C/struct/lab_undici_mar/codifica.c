/*
    Autore: Paolo Bianchessi 3ic
    Data: 11/03/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALF 26

void input(char *);
void codifica(char *, int, char *, char *);
void decodifica(char *, int, char *, char *);

int main()
{
    char lib[ALF] = "zyxwvutsrqponmlkjihgfedcba";
    char in[100], messCod[100], messDecod[100];
    input(in);
    codifica(in, strlen(in), lib, messCod);
    decodifica(in, strlen(in), lib, messDecod);
    return 0;
}
void input(char str[])
{
    printf("Messaggio da inviare (no caratteri speciali/numeri): ");
    scanf("%s", str);
}
void codifica(char str[], int dim, char lib[], char strCod[])
{
    int i;
    for (i = 0; i < dim; i++)
    {
        strCod[i] = lib[str[i] - 97];
    }
    strCod[i] = '\0';
    printf("\nMessaggio codificato: %s \n", strCod);
}
void decodifica(char lib[], int dim, char strCod[], char strDecod[])
{
    int i;
    for (i = 0; i < dim; i++)
    {
        strDecod[i] = lib[122 - strCod[i]];
    }
    strDecod[i] = '\0';
    printf("\nMessagio decodificato: %s\n", strDecod);
}