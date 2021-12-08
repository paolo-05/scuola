/*
    Autore: Paolo Bianchessi 3ic
    Data: 12.10.2021
    Descrizione: ...
*/

#include <stdio.h>

int main()
{
    int anno;
    printf("Inserisci un anno: ");
    scanf("%d", &anno);

    if (anno % 4 == 0)
    {
        if (anno % 100 == 0)
        {
            if (anno % 400 == 0)
            {
                printf("\nL'anno %d e' bisestile", anno);
            }
            else
            {
                printf("\nL'anno %d e' non bisestile", anno);
            }
        }
        else
        {
            printf("\nL'anno %d e' bisestile", anno);
        }
    }
    else
    {
        printf("\nL'anno %d e' non bisestile", anno);
    }
}
