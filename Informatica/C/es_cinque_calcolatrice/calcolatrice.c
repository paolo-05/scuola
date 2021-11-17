/*
    Autore: Paolo Bianchessi 3ic
    Data: 05.10.2021
    Descrzione: Inseriti da tastiera due numeri interi a e b, ed il tipo di operazione
    aritmetica da eseguire, tramite il carattere corrispondente (+, -, *, /) 
    oppure tramite inserimento di un numero associato all'operazione (1=somma, 2=differenza,
    3=prodotto, 4=quoziente), calcolare e comunicare il risultato dell'operazione.
*/

#include <stdio.h>

int main(){
    int a, b, flag;
    #define FALSE 0;
    #define TRUE 1;
    int res;
    char operazione;
    printf("\nInserisci il primo operando: ");
    scanf(" %d",&a);
    printf("\nInserisci il secondo operando: ");
    scanf(" %d",&b);

    do
    {
        printf("Inserisci l'operando [+ - * /] ");
        scanf(" %c", &operazione);
    } while (operazione != '+' && operazione != '-' && operazione != '*' && operazione != '/');
    
    if (operazione=='+'){
        res = a+b;
    }else if (operazione=='-'){
        res = a-b;
    }else if (operazione=='*'){
        res = a*b;
    }else if (operazione=='/'){
        if(b == 0){
            flag=TRUE;
        }else{
            res = a/b;
        }
    }
    if (flag){
        printf("Divisione impossibile dividere per 0!");
    }
    else{
        printf("Il risultato dell'operazione e': %d", res);
    }

    return 0;
}