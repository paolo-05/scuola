/*
    Autore: Paolo Bianchessi 3ic
    Data: 26/11/2021
*/

#include <stdio.h>

char maisculo(char car)
{
    return car - 32;
}
char shft(char car, int offset)
{
    int ris = car + offset;
    if (ris > 'z')
        return (ris % 'z') + 'a' - 1;
    return ris;
}
int main()
{
    char carattere;
    int scelta, offset;
    char risposta;
    printf("Cosa vuoi fare?");
    printf("\n1 - per avere il carattere maiuscolo\n2 - per avere il carattere shiftato di un offset specificato da te\n");
    printf("\nScelat: ");
    do
    {
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta != 2);
    printf("Inserisci un carattere: ");
    do
    {
        scanf("%c", &carattere);
    } while (!(carattere >= 'a' && carattere <= 'z'));

    if (scelta == 1)
    {
        risposta = maisculo(carattere);
    }
    else
    {
        printf("Inserisci un offset: ");
        scanf("%d", &offset);
        risposta = shft(carattere, offset);
    }
    printf("Il risultato e' %c\n", risposta);

    return 0;
}
