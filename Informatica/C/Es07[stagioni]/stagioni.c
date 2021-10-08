/*
    Autore: Paolo Bianchessi 3ic
    Data: 7.10.2021
    Descrizione: STAGIONI: stampare la stagione in base a giorno e mese primavera 21/3 al 20/6 
                estate 21/6 al 22/9 autunno dal 23/09 al 20/12 inverno dal 21/12 al 20/3
*/

#include <stdio.h>

int main(){
    int giorno,mese;
    do
    {
        printf("Inserisci un mese valido: ");
        scanf("%d", &mese);
    } while (mese<1 || mese>12);
    
    do
    {   printf("Inserisci un giorno valido: ");
        scanf("%d",&giorno);
    } while (giorno<1 || giorno>31);

    switch (mese)
    {
    case 1:
        printf("\nInverno");
        break;
    case 2:
        printf("\nInverno");
        break;
    case 3:
        if (giorno>=21)
        {
            printf("\nPrimavera");
        }else{
            printf("\nInverno");
        }
        break;
    case 4:
        printf("\nPrimavera");
        break;
    case 5:
        printf("\nPrimavera");
        break;
    case 6:
        if (giorno>=21)
        {
            printf("\nEstate");
        }else{
            printf("Primavera");
        }
        break;
    case 7:
        printf("\nEstate");
        break;
    case 8:
        printf("\nEstate");
        break;
    case 9:
        if (giorno>=21)
        {
            printf("\nAutunno");
        }else{
            printf("\nEstate");
        }
        break;
    case 10:
        printf("\nAutunno");
        break;
    case 11:
        printf("\nAutunno");
        break;
    case 12:
        if (giorno>=21)
        {
            printf("\nInverno");
        }else{
            printf("\nAutunno");
        }
        break;
    default:
        printf("\nIl programma ha riscontrato un errore");
        return 1;
        break;
    }
    
    return 0;
}