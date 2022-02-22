/*
    Autore: Paolo Bianchessi 3ic
    Data: 18/02/2022
    Descrizione:
*/

#include <stdio.h>

void acquisisciVettore(int *, int);
void ordina(int *, int);
void unisci(int *, int *, int *, int, int);
void visualizza(int *, int);

int main()
{
    int l1, l2, lTot;

    printf("Quanti numeri saranno inseriti nel primo vettore? ");
    scanf("%d", &l1);
    int vet1[l1];
    printf("Inserisci il primo vettore di %d elementi\n", l1);
    acquisisciVettore(vet1, l1);

    ordina(vet1, l1);
    printf("\nStampa del primo vettore ordinato\n");
    visualizza(vet1, l1);

    printf("Quanti numeri saranno inseriti nel secondo vettore? ");
    scanf("%d", &l2);
    printf("\nInserisci il primo vettore di %d elementi\n", l2);
    int vet2[l2];
    acquisisciVettore(vet2, l2);

    ordina(vet2, l2);
    printf("\nStampa del secondo vettore ordinato\n");
    visualizza(vet2, l2);

    printf("Il vetttore risultatante contiene %d elementi\n", l1 + l2);
    int vN[l1 + l2];
    unisci(vet1, vet2, vN, l1, l2);
    ordina(vN, l1 + l2);
    visualizza(vN, l1 + l2);
    return 0;
}

void acquisisciVettore(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void ordina(int v[], int l)
{
    int temp, scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < l - 1; i++)
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                scambi = 1;
            }
    } while (scambi == 1);
}

void visualizza(int v[], int l)
{
    for (int i = 0; i < l; i++)
        printf("Elemento %d: %d\n", i + 1, v[i]);
}

void unisci(int v1[], int v2[], int vN[], int l1, int l2)
{
    int i = 0, j = 0;
    while (i < l1)
    {
        vN[i] = v1[i];
        j++;
        i++;
    }
    i = 0;
    while (i < l2)
    {
        vN[j] = v2[i];
        j++;
        i++;
    }
}