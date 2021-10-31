/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/10/2021
    Descrizione:
*/

#include <stdio.h>
int mcd(int a, int b) // dichiaro una funzione di tipo int con argomenti a e b
{
    if (b == 0) //controllo se b è 0 e...
    {
        return a; // se vero ritorno a...
    }
    else // altrimenti...
    {
        return mcd(b, a % b); // chiamo di nuovo la funzione però gli passo argomenti diversi, al posto di a passo b e al posto di b passo il resto fra a e b
    }
}
int main() // funzione pricipale
{
    int a, b;                        // iniziallizzazione variabili
    printf("Inserisci un numero: "); /* acquisisco in input a e b */
    scanf("%d", &a);
    printf("inserisci un altro numero: ");
    scanf("%d", &b);

    printf("il massimo comun divisore e': %d", mcd(a, b)); // comunico all'utente l'mcd tra a e b chiamando la funzione
}

/* so che le funzioni non le abbiamo ancora fatte e questo tipo di approcio è recursive
   però era il metodo più semplice */
