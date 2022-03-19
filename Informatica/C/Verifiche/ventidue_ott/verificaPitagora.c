/*
    Autore: Paolo Bianchessi 3ic
    Data: 22/10/2021
    Descrizione: Piragora:inseriti tre numeri da tastiera (x, y e z)
                 indicare se costituiscono
                 una terna pitagorica (se x^2+y^2=z^2)
*/

#include <stdio.h>

int main()
{
    int cateto1, cateto2, ipotenusa;
    printf("Inserisci il cateto 1: "); //acquisione in input dei lati
    scanf("%d", &cateto1);
    printf("Inserisci il cateto 2: ");
    scanf("%d", &cateto2);
    printf("Inserisci l'ipotenusa: ");
    scanf("%d", &ipotenusa);

    if (cateto1 <= 0) //controllo sull'input e se ...
    {
        printf("Un cateto non puo' essere minore di 0"); // il primo lato è minore o uguale di zero stampa
    }
    else if (cateto2 < 0) //altrimenti se ...
    {
        printf("Un cateto non puo' essere 0"); //il secondo lato è minore o oguale di zero stampa
    }
    else if (ipotenusa < 0) //altrimenti se ...
    {
        printf("L'ipotenusa non puo' essere 0"); //il terzo lato è minore o uguale di zero
    }
    else //altrimenti eseguo ill programma
    {
        if (cateto1 * cateto1 + cateto2 * cateto2 == ipotenusa * ipotenusa) //controllo se i tre numeri sono una terna pitagorica
        {
            printf("I numeri %d, %d, %d sono una terna pitagorica", cateto1, cateto2, ipotenusa);
        }
        else
        {
            printf("I numeri %d, %d, %d non sono una terna pitagorica", cateto1, cateto2, ipotenusa);
        }
    }

    return 0;
}
