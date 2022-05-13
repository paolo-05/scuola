/*
    Autore: Paolo Bianchessi 3ic
    Data: 12/05/2022
    Descrizione:
*/

#include <stdio.h>
#include <string.h>

typedef struct extra
{
    char ruota[20];
    int numeri[5];
} Estrazione;

void leggiDati(Estrazione d[])
{
    int i, j;
    FILE *f;
    f = fopen("estrazione.txt", "r");
    if (f != NULL)
    {
        for (i = 0; i < 10; i++)
        {
            fscanf(f, "%s", d[i].ruota);
            for (j = 0; j < 5; j++)
                fscanf(f, "%d", &d[i].numeri[j]);
        }
        fclose(f);
    }
}

void stampaDati(Estrazione d[])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        printf("%s\t", d[i].ruota);
        for (j = 0; j < 5; j++)
            printf("%d\t", d[i].numeri[j]);
        printf("\n");
    }
}

// COMPITO PER 15/5
void controlla(Estrazione d[], char ruota[], int num[], int n)
{
    int res = 0;
    for (int i = 0; i < 10; i++)
        if (strcmp(d[i].ruota, ruota) == 0)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 5; k++)
                    if (d[i].numeri[k] == num[j])
                        res++;

    printf("\n\nHai indovinato %d estrazioni\n\n", res);
}

int main()
{
    char ruota[20];
    int num[10], n;
    Estrazione dati[10];
    leggiDati(dati);
    printf("Quale ruota: ");
    scanf("%s", ruota);
    printf("Quanti numeri: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d° numero: ", i + 1);
        scanf("%d", &num[i]);
    }
    controlla(dati, ruota, num, n);
    stampaDati(dati);

    return 0;
}