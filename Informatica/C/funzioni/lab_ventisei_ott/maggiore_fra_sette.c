/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/10/2021
    Descrizione: 
*/

#include <stdio.h>
#include <limits.h>

int main()
{
    int n, max = INT_MIN, min = INT_MAX; // iniziallizzazione variabili
    for (int i = 0; i < 7; i++)          // tramite un for...
    {
        printf("Inserisci un numero: "); //itero l'acquisione in input di n e...
        scanf("%d", &n);
        if (n > max) //controllo se n è maggiore di max (nella prima iterazione sarà vero)
        {
            max = n; //se vero assegno a max il valore di n
        }
        if (n < min) //controllo se n è minore di min
        {
            min = n; // se vero assegno a min il valore di n
        }
    }
    printf("max: %d, min: %d\n", max, min); //alla fine stampo il max e il min
    return 0;
}
