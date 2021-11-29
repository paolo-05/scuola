/*
    Autore: Paolo Bianchessi 3ic
    Data: 23/11/2021
    Descrizione: 
*/

#include <stdio.h>

int main()
{
    int offertaUno, offertaDue;
    char nome1[21], nome2[21];
    printf("---------------------------------------------------");
    printf("\n                Benvenuti all'asta!!");
    printf("\n---------------------------------------------------\n");
    printf("Inserite i vostri nomi: ");
    printf("\ncompratore 1 = ");
    scanf("  %s", nome1);
    printf("compratore 2 = ");
    scanf(" %s", nome2);
    do
    {
        printf("%s, tocca a te, fai un'offerta: ", nome1);
        scanf("%d", &offertaUno);
        printf("%s, tocca te ora, fai un'offerta: ", nome2);
        scanf("%d", &offertaDue);

    } while (offertaUno != 0 && offertaDue != 0);
    if (offertaUno == 0)
    {
        printf("Congratulazioni %s, hai vinto!!\n", nome2);
    }
    else if (offertaDue == 0)
    {
        printf("Congratulazioni %s, hai vinto!!\n", nome1);
    }

    return 0;
}
