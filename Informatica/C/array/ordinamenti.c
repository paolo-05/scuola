/*
    Autore: Paolo Bianchessi 3ic
    Data: 11/03/2022
    Descrizione: esempi di algoritmi di ordinamento con interi
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

void riempi(int *, int, int);
void visualizza(int *, int);
void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);

int main()
{
    int vettore[DIM], max = 100, s;
    riempi(vettore, DIM, max);
    visualizza(vettore, DIM);
    printf("\n1 - bubbleSort\n2 - selectionSort\n3 - insertionSort");
    printf("\nalgoritmo: ");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        bubbleSort(vettore, DIM);
        break;
    case 2:
        selectionSort(vettore, DIM);
        break;
    case 3:
        insertionSort(vettore, DIM);
        break;
    default:
        printf("Numero non corretto");
        break;
    }
    visualizza(vettore, DIM);
    return 0;
}
void riempi(int vet[], int num, int max)
{
    int conta;
    srand((unsigned)time(NULL));
    for (conta = 0; conta < num; conta++)
        vet[conta] = (rand() % max + 1);
}
void visualizza(int vettore[], int dimensione)
{
    for (int i = 0; i < dimensione; i++)
        printf("%d ", vettore[i]);
    printf("\n");
}
void bubbleSort(int vet[], int tanti)
{
    int temp, scambi = 0;
    do
    {                                       // ripeti finché ci sono scambi
        scambi = 0;                         // inizializzo sentinella
        for (int i = 0; i < tanti - 1; i++) // li confronto tutti a coppie (-x)
            if (vet[i] > vet[i + 1])        // (se fosse < sarebbe ordinato in ordine descrescente)
            {                               // se ne trovo uno maggiore
                temp = vet[i];              // li scambio tra loro
                vet[i] = vet[i + 1];
                vet[i + 1] = temp;
                scambi = 1;
            }
    } while (scambi == 1);
}

void insertionSort(int a[], int dim)
{
    int i, j, temp;
    for (i = 1; i < dim; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j]; // shift
            j--;
        }
        a[j + 1] = temp; // scambio
    }
}

void selectionSort(int vet[], int tanti)
{
    int x, y, i_min;
    int temp;
    for (x = 0; x < tanti - 1; x++)
    {                                   // ricerca del minimo in [i..n-1]
        i_min = x;                      // pongo il primo come minimo
        for (y = x + 1; y < tanti; y++) // scorro tutto il vettore
            if (vet[y] < vet[i_min])    // se trovo un elemento minore (ordinamento crescente se fosse > sarebbe decrescente)
                i_min = y;              // è il nuovo minimo
        if (x != i_min)
        {                      // se il min non è l'elemento corrente
            temp = vet[i_min]; // scambia [i_min] e l'elemento corrente
            vet[i_min] = vet[x];
            vet[x] = temp;
        }
        visualizza(vet, tanti); // visualizza un passo di ordinamento
    }
}
