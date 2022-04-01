/*
    Autore: Paolo Bianchessi 3ic
    Data: 01/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NFUNGHI 1000

typedef struct
{
    char nomeF[50];
    float altezzaF;
    char meseRacF[4];
} Fungo;

typedef Fungo Raccolta[NFUNGHI];

int menu();
void input(Raccolta r, int p);
void stampaRaccolta(Raccolta r, int d);

int cercaFungoAlto(Raccolta r, int d);
void elencoFunghiMese(Raccolta r, int d, char mese[]);
void ordinaAltezza(Raccolta r, int d);

int main()
{
    Raccolta r;
    int c = 0, scelta, ultimo = 0, max = 0;
    char mese[4];
    printf("Raccolta di funghi\n\n");
    do
    {
        printf("\nInserimento %d\n", ultimo);
        scelta = menu();
        switch (scelta)
        {
        case 1:
            input(r, ultimo);
            ultimo++;
            break;
        case 2:
            max = cercaFungoAlto(r, ultimo);
            printf("Fungo piu' alto \nNome: %s\nMese di raccolta: %s\n", r[max].nomeF, r[max].meseRacF);
            break;
        case 3:
            printf("Inserisci il mese: ");
            scanf("%s", mese);
            elencoFunghiMese(r, ultimo, mese);
            printf("\n");
            break;
        case 4:
            ordinaAltezza(r, ultimo);
            printf("\nElenco ordinato per altezza: \n");
            stampaRaccolta(r, ultimo);
            printf("\n");
            break;
        case 5:
            c = 1;
            printf("\n");
            break;
        default:
            printf("\nErrore, numero inserito non corretto.\n");
            break;
        }

    } while (c == 0);

    return 0;
}
int menu()
{
    int scelta;
    printf("\n1 - Inserisci i dati di un fungo");
    printf("\n2 - Nome e mese di raccolta del fungo più alto");
    printf("\n3 - Elenco di tutti i funghi dato un mese di raccolta");
    printf("\n4 - Ordinamento per altezza dei funghi");
    printf("\n5 - Esci");
    printf("\nScelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void input(Raccolta r, int p)
{
    printf("Nome del fungo: ");
    scanf("%s", r[p].nomeF);

    printf("Altezza del fungo: ");
    scanf("%f", &r[p].altezzaF);

    printf("Mese di raccolta: ");
    scanf("%s", r[p].meseRacF);
}

int cercaFungoAlto(Raccolta r, int d)
{
    int max = 0;
    for (int i = 0; i < d; i++)
        if (r[i].altezzaF > r[max].altezzaF)
            max = i;
    return max;
}

void elencoFunghiMese(Raccolta r, int d, char mese[])
{
    Fungo trovati[d];
    int t = 0;
    for (int i = 0; i < d; i++)
        if (strcmp(r[i].meseRacF, mese) == 0)
        {
            t++;
            trovati[i] = r[i];
        }

    printf("\nI funghi che vengono raccolti in %s sono: \n", mese);
    for (int j = 0; j < t; j++)
        printf("%s\n", trovati[j].nomeF);
}

void ordinaAltezza(Raccolta r, int d)
{
    Fungo t;
    int scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < d - 1; i++)
        {
            if (r[i].altezzaF < r[i + 1].altezzaF)
            {
                t = r[i];
                r[i] = r[i + 1];
                r[i + 1] = t;
                scambi = 1;
            }
        }
    } while (scambi == 1);
}

void stampaRaccolta(Raccolta r, int d)
{
    printf("Nome\tAltezza\tMese di raccolta\n");
    for (int i = 0; i < d; i++)
        printf("%s\t%.2f\t%s\n", r[i].nomeF, r[i].altezzaF, r[i].meseRacF);
}