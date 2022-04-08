/*
    Autore: Paolo Bianchessi 3ic
    Data: 08/04/2022
    Descrizione: Cambiamonete
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PEZZI_MONETE 15
// 1cent 2cent 5cent 10cent 20cent 50cent 1euro 2euro 5euro 10euro 20euro 50euro 100euro 200euro 500euro
// 1     2     5     10     20     50     100   200   500   1000   2000   5000  10000   20000   50000 centesimi

int valorePezzo[PEZZI_MONETE] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};

int main()
{
    int moneteInserite[PEZZI_MONETE], moneteDaDare[PEZZI_MONETE], centesimiTot = 0;
    for (int i = 0; i < PEZZI_MONETE; i++)
        scanf("%d", &moneteInserite[i]);
    for (int j = 0; j < PEZZI_MONETE; j++)
        centesimiTot += moneteInserite[j] * valorePezzo[j];

    for (int k = PEZZI_MONETE - 1; k >= 0; k--)
    {
        moneteDaDare[k] = centesimiTot / valorePezzo[k];
        centesimiTot %= valorePezzo[k];
    }
    for (int i = 0; i < PEZZI_MONETE; i++)
    {
        printf("%d ", moneteDaDare[i]);
    }

    return 0;
}
