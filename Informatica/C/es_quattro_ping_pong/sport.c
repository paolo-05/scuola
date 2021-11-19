/*  Autore: Paolo Bianchessi 3ic
    Data: 30.09.2021
    Descirzione: Se uno studente è più alto di 170 cm e fa almeno la quarta, partecipa al torneo di pallavolo, altrimenti partecipa al torneo di ping pong
*/
#include <stdio.h>
int main(){
    int altezza;
    int classe;
    printf("Quanto sei alto? ");
    scanf("%d",&altezza);
    printf("Che classe fai?  ");
    scanf("%d",&classe);
    if(altezza>=170 && classe>=4)
    {
        printf("Partecipi al torneo di pallavolo");
    }
    else
    {
        printf("Partecipi al torneo di ping pong");
    }
    return 0;
}