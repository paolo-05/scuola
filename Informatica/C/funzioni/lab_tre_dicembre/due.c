
#include <stdio.h>

int farina = 5000;

int panini(int n)
{
    while (n * 100 > farina)
    {
        n--;
    }
    farina = farina - n * 100;
    return n;
}

int pizza(int n)
{
    while (n * 80 > farina)
    {
        n--;
    }
    farina = farina - n * 80;
    return n;
}

int pasta(int n)
{
    while (n * 75 > farina)
    {
        n--;
    }
    farina = farina - n * 75;
    return n;
}

int main()
{
    int scelta, npezzi;
    do
    {
        printf("\nCosa vuoi fare?\n");
        printf("1 per ordinare pane\n");
        printf("2 per ordinare pizza\n");
        printf("3 per ordinare pasta\n");
        printf("4 per uscire\n");
        printf("\nScelta: ");
        scanf("%d", &scelta);
        printf("Inserisci il numero di pezzi: ");
        scanf("%d", &npezzi);
        switch (scelta)
        {
        case 1:
            printf("\nEcco %d panini\n", panini(npezzi));
            printf("Rimangono %d grammi di farina\n", farina);
            break;
        case 2:
            printf("\nEcco %d pizze\n", pizza(npezzi));
            printf("rimangono %d grammi di farina\n", farina);
            break;
        case 3:
            printf("\nEcco %d paste\n", pasta(npezzi));
            printf("rimangono %d grammi di farina\n", farina);
            break;
        default:
            break;
        }
    } while (scelta != 4 && farina > 0);
    if (farina == 0)
    {
        printf("Abbiamo finito le scorte grazie e arrivederci\n");
    }

    printf("Grazie e arrivederci\n");

    return 0;
}