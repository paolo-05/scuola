/*
    Autore: Paolo Bianchessi 3ic
    Data: 31/10/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int a, b, r;
    printf("Inserisci un numero: ");
    scanf("%d", &a);
    printf("inserisci un altro numero: ");
    scanf("%d", &b);
    while (b != 0) //ripetere finché non riduciamo a zero
    {
        r = a % b;
        a = b;
        b = r; //scambiamo il ruolo di a e b
    }

    printf("il massimo comun divisore e': %d", a); //... e quando b è (o è diventato) 0, il risultato è a
    return 0;
}
