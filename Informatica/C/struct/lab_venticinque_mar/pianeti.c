/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/03/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOT 3

typedef char String[20];
typedef struct
{
    String nome;
    double diametro; // km
    int lune;
    double orbita;    // anni
    double rotazione; // ore
} Pianeta;

// void carica(Pianeta *);
void menu(Pianeta *);
void scelte();

void stampa(Pianeta *);
int maxDiametro(Pianeta *);
double tempMedOrbite(Pianeta *);
void ordinaAlf(Pianeta *);

int main()
{
    Pianeta sistemaSolare[TOT] = {
        {"Terra", 100000.34, 1, 1, 24.1},
        {"Marte", 50000.45, 4, 10, 52.1},
        {"Nettuno", 655554.454, 23, 2, 600.343}};
    printf("Pianeti");
    // carica(sistemaSolare);
    menu(sistemaSolare);
    return 0;
}
/*void carica(Pianeta ss[])
{
    for (int i = 0; i < TOT; i++)
    {
        printf("\nCaricamento %d", i + 1);
        printf("Nome: ");
        scanf("%s", ss[i].nome);
        printf("Diametro in KM: ");
        scanf("%d", &ss[i].diametro);
        printf("Numero di lune: ");
        scanf("%d", &ss[i].lune);
        printf("Durata orbita attorno al sole: ");
        scanf("%d", &ss[i].dRotazione);
        printf("Durata della rotazione attorno al proprio asse: ");
        scanf("%f", &ss[i].tOrbita);
    }
}*/

void scelte()
{
    printf("\n1 - stampa di tutte le informazioni inserite");
    printf("\n2 - pianeta con il diametro piu' grande");
    printf("\n3 - durata orbita media");
    printf("\n4 - pianeti in ordine alfabetico");
    printf("\n5 - esci");
}

void menu(Pianeta sistemaSolare[])
{
    int e = 0, scelta, mDim;
    double m;
    while (!e)
    {
        scelte();
        printf("\nScelta: ");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            stampa(sistemaSolare);
            break;
        case 2:
            mDim = maxDiametro(sistemaSolare);
            printf("\nIl pianeta con il diametro piu' grande e' %s con una lunghezza di ben %.2lf km\n",
                   sistemaSolare[mDim].nome, sistemaSolare[mDim].diametro);
            break;
        case 3:
            m = tempMedOrbite(sistemaSolare);
            printf("\nIl tempo medio delle orbite dei pianeti inseriti e' %.2lf\n", m);
            break;
        case 4:
            ordinaAlf(sistemaSolare);
            stampa(sistemaSolare);
            break;
        case 5:
            printf("\nGrazie e arrivederci.\n");
            e = 1;
            break;
        default:
            printf("\nScelta non corretta.\n");
            break;
        }
    }
}
void stampa(Pianeta ss[])
{
    for (int i = 0; i < TOT; i++)
    {
        printf("\nNome: ");
        printf("%s", ss[i].nome);
        printf("\nDiametro in KM: ");
        printf("%.2lf", ss[i].diametro);
        printf("\nNumero di lune: ");
        printf("%d", ss[i].lune);
        printf("\nDurata orbita attorno al sole: ");
        printf("%.2lf", ss[i].rotazione);
        printf("\nDurata della rotazione attorno al proprio asse: ");
        printf("%.2lf\n", ss[i].orbita);
    }
}

int maxDiametro(Pianeta ss[])
{
    int max = 0;
    for (int i = 0; i < TOT; i++)
    {
        if (ss[i].diametro > ss[max].diametro)
            max = i;
    }
    return max;
}

double tempMedOrbite(Pianeta ss[])
{
    double m = 0;
    for (int i = 0; i < TOT; i++)
    {
        m += ss[i].diametro;
    }
    return m / TOT;
}

void ordinaAlf(Pianeta ss[])
{
    Pianeta t;
    int scambi = 0;
    do
    {
        scambi = 0;
        for (int i = 0; i < TOT - 1; i++)
        {
            if (strcmp(ss[i].nome, ss[i + 1].nome) > 0)
            {
                t = ss[i];
                ss[i] = ss[i + 1];
                ss[i + 1] = t;
                scambi = 1;
            }
        }
    } while (scambi == 1);
}