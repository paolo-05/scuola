/*
    Autore: Paolo Bianchessi 3ic
    Data: 21/12/2021
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((long)time(NULL));

    int num, faccie[91] = {0};

    for (int i = 0; i < 900; i++)
    {
        num = rand() % 90 + 1;
        faccie[num]++;
    }
    for (int i = 1; i < 91; i++)
    {
        printf("Il numero %d e' uscito %d volte\n", i, faccie[i]);
    }

    return 0;
}
