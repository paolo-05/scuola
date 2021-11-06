/*
    Autore: Paolo Bianchessi 3ic
    Data: 05/11/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int volte, potenza, percentuale, i;
    double accOtt, accBuo, accSuff, accIns;

    printf("Quanti valori vuoi inserire: ");
    scanf("%d", &volte);
    for (i = 0; i < volte; i++)
    {
        do
        {
            printf("Inserisci un valore in input: ");
            scanf("%d", &potenza);
        } while (potenza > 0);

        if (potenza >= -50)
        {
            printf("Ottimale\n");
            accOtt += 1;
        }
        else if (potenza < -50 && potenza >= -60)
        {
            printf("Buono\n");
            accBuo += 1;
        }
        else if (potenza < -60 && potenza >= -70)
        {
            printf("Sufficiente\n");
            accSuff += 1;
        }
        else
        {
            printf("Insufficiente\n");
            accIns += 1;
        }
    }
    printf(
        "la percentuale degli ottimi e' %.2lf %% dei buoni %.2lf %%, dei sufficienti %.2lf %%, degli insufficienti %.2lf %%\n",
        accOtt / volte * 100, accBuo / volte * 100, accSuff / volte * 100, accIns / volte * 100);
    return 0;
}
