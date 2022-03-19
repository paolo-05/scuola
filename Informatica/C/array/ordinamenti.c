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

// quickSort:
void scambia(int vet[], long x, long y);
int partiziona(int vet[], int sx, int dx);
void quickSort(int vett[], int e_sx, int e_dx);

int binarySearch(int *, int, int, int);

int main()
{
    int vettore[DIM], max = 100, s, n, trovato;
    riempi(vettore, DIM, max);
    visualizza(vettore, DIM);
    do
    {
        printf("\n1 - bubbleSort\n2 - selectionSort\n3 - insertionSort\n4 - quickSort\n5 - binarySearch");
        printf("\nalgoritmo: ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            bubbleSort(vettore, DIM);
            visualizza(vettore, DIM);
            break;
        case 2:
            selectionSort(vettore, DIM);
            visualizza(vettore, DIM);
            break;
        case 3:
            insertionSort(vettore, DIM);
            visualizza(vettore, DIM);
            break;
        case 4:
            quickSort(vettore, 0, DIM - 1);
        case 5:
            bubbleSort(vettore, DIM);
            visualizza(vettore, DIM);
            printf("\nNumero da cercare: ");
            scanf("%d", &n);
            trovato = binarySearch(vettore, 0, DIM, n);
            if (trovato == -1)
                printf("\nIl numero %d non è presente.\n", n);
            else
                printf("\nIl numero e' in posizione %d\n", trovato);

            break;
        default:
            printf("Numero non corretto");
            break;
        }
    } while (s > 0);

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

int binarySearch(int v[], int inizio, int fine, int numero)
{
    int estrInf = inizio;   // estremo inferiore
    int estrSup = fine - 1; // estremo superiore
    int medio;
    while (estrInf <= estrSup) // il vettore non è finito
    {
        medio = (estrInf + estrSup) / 2; // nuovo valore iniziale
        if (numero > v[medio])           // se il numero è maggiore
        {
            estrInf = medio + 1; // è nella parte destra
        }
        else
        {
            if (numero < v[medio])   // se il numero è minore
                estrSup = medio - 1; // è nella parte sinistra
            else
                return medio; // altrimenti l'ho trovato
        }
    }
    return -1; // il numero non è presente
}

void scambia(int vet[], long x, long y)
{
    int tmp = vet[x];
    vet[x] = vet[y];
    vet[y] = tmp;
}

int partiziona(int vett[], int sx, int dx)
{
    int pivot, ipivot;    // valore di pivot, indice posizione pivot
    ipivot = sx;          // scegli indice per il pivot: Hoare usa il primo
    pivot = vett[ipivot]; // valore_pivot <- [posizione_iniziale_pivot]
    // effettua il partizionamento in due sotto vettori individuando q (posizione_effettiva_pivot)
    while (sx < dx)
    {
        while ((vett[sx] <= pivot) && (sx < dx)) // cerco elemento di sinistra > pivot
            sx++;
        while (vett[dx] > pivot) // cerco elemento di destra < pivot
            dx--;
        if (sx < dx)
        {                          // se non ho finito di ordinare
            scambia(vett, sx, dx); // scambio i due elementi
        }
    }
    scambia(vett, ipivot, dx); // posiziona il pivot nella sua cella q
    // mostraVettore();                           // visualizza un passo
    printf("*");
    return dx;
}

void quickSort(int vett[], int e_sx, int e_dx)
{
    int q; // nuovo indice  pivot
    if (e_sx < e_dx)
    { // ctr termine vettore
        q = partiziona(vett, e_sx, e_dx);
        // -- chiamata sui sotto vettori sinistro e destro
        quickSort(vett, e_sx, q - 1); // vet di sinistra
        quickSort(vett, q + 1, e_dx); // vet di destra
    }
}