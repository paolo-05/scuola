/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int i, j, n;
    do
    {
        printf("Tabellina del: ");
        scanf("%d", &n);
    } while (n < 0 || n > 10);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 10; j++)
            printf("\t%d", i * j);
        printf("\n");
    }
    return 0;
}