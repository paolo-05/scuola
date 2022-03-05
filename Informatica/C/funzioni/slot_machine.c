/*
    Autore: Paolo Bianchessi 3ic
    Data: 09/11/2021
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char estrazione()
{
    int n;
    n = rand() % 10;
    if (n >= 0 && n < 5)
        return 'A';
    if (n >= 5 && n < 8)
        return 'B';
    if (n >= 8)
        return 'C';
}

int main()
{
    srand(time(NULL)); // inizializza generatore casuale
    int n;             // numero casuale
    char s1, s2, s3;   // simboli estratti
    int soldi = 10;    // somma inizile
    char ancora = 's'; // scelta se proseguire
    do
    {
        // estrazione s1
        s1 = estrazione();
        // estrazione s2
        s2 = estrazione();
        // estrazione s3
        s3 = estrazione();

        printf("%c %c %c\n", s1, s2, s3); // mostra estrazione

        if (s1 == s2 && s2 == s3) // controlla vincita
        {
            //vinto
            switch (s1)
            {
            case 'A':
                soldi += 2;
                break;
            case 'B':
                soldi += 5;
                break;
            case 'C':
                soldi += 10;
                break;
            default:
                break;
            }
        }
        else
        {
            // perso
            soldi--;
        }
        printf("Soldi: %d\n", soldi);
        printf("Ancora (s/n)? ");
        scanf(" %c", &ancora);

    } while (soldi > 0 && ancora == 's');

    return 0;
}
