/*
    Autore: Paolo Bianchessi 3ic
    Data: 18/12/2021
    Descrizione: acquisire in input n valori
    e stamparli al contrario
*/

#include <stdio.h>

int main()
{
    int nInput;
    printf("Quanti valori vuoi acquisire? ");
    scanf("%d", &nInput);
    int valori[nInput - 1];
    for (int i = 0; i < nInput; i++)
    {
        printf("\nInserisci il %d numero: ", i + 1);
        scanf("%d", &valori[i]);
    }
    for (int j = nInput; j >= 0; j--)
        printf("\nIl %d numero vale %d\n", j + 1, valori[j]);

    return 0;
}
