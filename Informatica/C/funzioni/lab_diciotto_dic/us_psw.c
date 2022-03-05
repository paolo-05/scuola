/*
    Autore: Paolo Bianchessi 3ic
    Data: 18/01/2022
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMUTENTI 5
#define MAXLUNG 15
#define MAXPASSW 9

int main()
{
    char utenti[NUMUTENTI][MAXLUNG] = {"Carlo", "Marisa", "Luca", "Marco", "Elsa"};   //array usernames
    char passwords[NUMUTENTI][MAXPASSW] = {"uno", "due", "tre", "quattro", "cinque"}; //array passwords
    char username[MAXLUNG], password[MAXPASSW];
    int ok = 0, tentativi = 3;
    do
    {
        printf("Tentativi = %d\n", tentativi);
        printf("Inserisci l'username: ");
        scanf("%s", username);
        printf("Inserisci la password: ");
        scanf("%s", password);

        for (int i = 0; i < NUMUTENTI && !ok; i++)
        {
            if (strcmp(username, utenti[i]) == 0 && strcmp(password, passwords[i]) == 0)
                ok = 1;
        }
        if (ok)
            printf("Credenziali corrette!\n");
        else
            printf("Credenziali non corrette!\n");
        tentativi--;
    } while (tentativi > 0 && !ok);
    return 0;
}
