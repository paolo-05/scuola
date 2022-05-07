/*
    Autore: Paolo Bianchessi 3ic
    Data: 06/05/2022
    Descrizione: Scrivere con un editor un file contenente dei
                numeri, uno per riga. Sviluppare un
                programma che chieda all’utente il nome di
                questo file, lo apra e calcoli e stampi a video
                quanti sono i valori letti, il valore massimo, il
                valore minimo, la somma e la media di tutti i
                valori presenti nel file.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char nomefile[20];
    int i = 0, max = 0, min = 0, acc = 0, v[50];
    printf("\nInserisci il nome del file: ");
    scanf("%s", nomefile);
    if ((fp = fopen(nomefile, "r")) == NULL)
    {
        fprintf(stderr, "Impossibile aprire il file %s", nomefile);
        return EXIT_FAILURE;
    }
    fp = fopen(nomefile, "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &v[i]);
        printf("%d  ", v[i]);
        i++;
    }
    fclose(fp);
    for (int j = 0; j < i; j++)
    {
        if (v[max] < v[j])
            max = j;
        if (v[min] > v[j])
            min = j;
        acc += v[j];
    }
    printf("\n\nNumero di valori: %d\nIl valore massimo nel file e' %d\nIl valore minimo e' %d\nLa media e' %2.f\n",
           i, v[max], v[min], (float)acc / i);
    return 0;
}