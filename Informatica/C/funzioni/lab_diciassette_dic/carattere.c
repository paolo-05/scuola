/*
    Autore: Paolo Bianchessi 3ic
    Data: 17/12/2021
    Descrizione:
*/

#include <stdio.h>
void scan_car(char c, int *pv, int *pc, int *pd, int *pw, int *po)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        (*pv)++;
        return;
    }
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
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
void pulisciBuffer()
{
    while (getchar() != '\n')
        ;
}
int main()
{
    char scelta;
    char car;
    int i = 0;
    int vocaliC = 0, consonantiC = 0, cifreC = 0, spaziVoutiC = 0, altriCarC = 0;
    do
    {
        printf("Inserisci il carattere: ");
        scanf("%c", &car);
        pulisciBuffer();
        i++;
        scan_car(car, &vocaliC, &consonantiC, &cifreC, &spaziVoutiC, &altriCarC);
        printf("\nContinuare? (s/n)");
        scanf("%c", &scelta);
        pulisciBuffer();
    } while (scelta == 's');

    printf("Num. vocali: %d\n", vocaliC);
    printf("Num. consonanti: %d\n", consonantiC);
    printf("Num. cifre: %d\n", cifreC);
    printf("Num. spazi bianchi: %d\n", spaziVoutiC);
    printf("Num. altri caratteri: %d\n", altriCarC);

    return 0;
}
