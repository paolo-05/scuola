/*
    Autore: Paolo Bianchessi 3ic
    Data: 17/12/2021
    Descrizione: 
*/

#include <stdio.h>
void scan_car(char c, int *pv, int *pc, int *pd, int *pw, int *po)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        (*pv)++;
        return;
    }
    if (c >= 'A' && c <= 'Z')
    {
        (*pc)++;
        return;
    }
    if (c >= '0' && c <= '9')
    {
        (*pd)++;
        return;
    }
    if (c == ' ')
    {
        (*pw)++;
        return;
    }
    (*po)++;
}

int main()
{
    char scelta;
    char lettere[89];
    int i = 0;
    int vocaliC, consonantiC, cifreC, spaziVoutiC, altriCarC;
    do
    {
        printf("Inserisci il carattere: ");
        scanf(" %c", &lettere[i]);
        i++;
        printf("\nContinuare? (s/n) ");
        scanf(" %c", &scelta);
    } while (scelta == 's');
    for (int k = 0; k < lettere[k]; k++)
    {
        /* code */
    }

    printf("Num. vocali: %d\n", vocaliC);
    printf("Num. consonanti: %d\n", consonantiC);
    printf("Num. cifre: %d\n", cifreC);
    printf("Num. spazi bianchi: %d\n", spaziVoutiC);
    printf("Num. altri caratteri: %d\n", altriCarC);

    return 0;
}
