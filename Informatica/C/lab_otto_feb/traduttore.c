/*
    Autore: Paolo Bianchessi 3ic
    Data: 09/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <string.h>

#define WS 20
#define L 20
const char ingC[] = "ing";
const char itaC[] = "ita";
const char helpC[] = "help";

void prompt();
void commandHandler(char *, char *);

void ita(char *);
void ing(char *);
void help();

char itaWs[WS][L] = {
    "ciao",
    "tavolo",
    "matita",
    "scuola",
    "tastiera",
    "sedia",
    "cartella",
    "cane",
    "gatto",
    "musica",
    "lavoro",
    "acqua",
    "sabbia",
    "magiare",
    "dormire",
    "cucinare",
    "cercare",
    "libro"
    "zaino",
    "pantaloni",
    "negozio"};
char ingWs[WS][L] = {
    "hello",
    "table",
    "pencil"
    "school",
    "keyboard"
    "chair",
    "folder",
    "dog"
    "cat",
    "music",
    "work",
    "water",
    "sand",
    "to eat",
    "to sleep",
    "to cook",
    "to search",
    "book",
    "backpack",
    "pants",
    "shop"};

int main()
{
    char comando[L];
    char argomento[L] = {0};
    int fine = 0;
    do
    {
        prompt();
        commandHandler(comando, argomento);
        if (strcmp(comando, ingC) == 0)
            ing(argomento);
        else if (strcmp(comando, itaC) == 0)
            ita(argomento);
        else if (strcmp(comando, helpC) >= 0 || argomento == NULL) // in questo modo anche in assenza di argomenti
            help();                                                // per i comandi principali si stampa l'help
        else
            fine = 1;

    } while (!fine);

    return 0;
}

void prompt()
{
    printf("\ntraduttore>");
}
void ing(char word[])
{
    int traduzione = 0;
    for (int i = 0; i < WS; i++)
        if (strcmp(word, ingWs[i]) == 0)
            traduzione = i;
    if (traduzione)
        printf("traduzione: %s\n", itaWs[traduzione]);
    else
        printf("Non sono riuscito a trovare la parola.\n");
}
void ita(char parola[])
{
    int traduzione = 0;
    for (int j = 0; j < WS; j++)
        if (strcmp(parola, itaWs[j]) == 0)
            traduzione = j;
    if (traduzione)
        printf("traduzione: %s\n", ingWs[traduzione]);
    else
        printf("Non sono riuscito a trovare la parola.\n");
}

void help()
{
    printf("\nLista dei comandi presenti: ");
    printf("\n - ing <parola> : traduce dall'inglese all'italiano una parola data");
    printf("\n - ita <parola> : traduce dall'italiano all'inglese una parola data");
    printf("\n - help : questo comando");
    printf("\n - exit : esci\n");
}

void commandHandler(char cmd[], char arg[])
{
    fgets(cmd, L, stdin);           // prendo in input sia il comando che l'argomento (parola)
    char *token = strtok(cmd, " "); // splitto la stringa
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (token != NULL)      // se il pezzo di stringa non è NULL
            strcpy(arg, token); // copio il token in arg
    }
}
