/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/03/2022
    Descrizione: carte da gioco
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// rappresenta una carta da gioco
typedef struct carta
{
    char seme;  // c,q,p,f
    int valore; // 1,...13 1=A, 11=J, 12=Q, 13=K
} Carta;
// numero di carte nel mazzo
#define NUMCARTE 52
#define EST 5
// mazzo di carte (da scala 40)
typedef Carta Mazzo[NUMCARTE];
// iniz carte estratte
typedef Carta Estratte[EST];

void inizializzamazzo(Mazzo M);
void stampamazzo(Mazzo M);
void scambiacarte(Carta *c1, Carta *c2);
void mescolamazzo(Mazzo M);
void elimina(Mazzo M, int n);

void estraiCarte(Mazzo M, Estratte E, int m);
void mostraEstratte(Estratte E);
void cambiaCarta(Estratte E, Mazzo M, int m);
int calcolaPunti(Estratte E);

// programma del gioco
int main()
{
    int punti;
    srand(time(NULL));
    Mazzo M;
    Estratte E;
    inizializzamazzo(M);
    printf("Mazzo iniziale\n");
    stampamazzo(M);
    mescolamazzo(M);
    /*printf("Mazzo mescolato\n");
    stampamazzo(M);*/

    // inizio gioco
    for (int i = NUMCARTE; i > EST; i--)
    {
        printf("\n\n\nCarte estratte: ");
        estraiCarte(M, E, i);
        mostraEstratte(E);
        cambiaCarta(E, M, i);
        printf("\nCalcolo del punteggio in corso...\n");
        punti = calcolaPunti(E);
        printf("Punti: %2d", punti);
    }
}
// inizializza il mazzo di carte M
void inizializzamazzo(Mazzo M)
{
    int i, s;
    char semi[4] = {'c', 'q', 'f', 'p'};
    for (i = 1; i <= 13; i++)
    {
        for (s = 0; s < 4; s++)
        {
            M[s * 13 + i - 1].valore = i;
            M[s * 13 + i - 1].seme = semi[s];
        }
    }
}

// stampa mazzo "fridendly"
void stampamazzo(Mazzo M)
{
    int i;
    char c;
    for (i = 0; i < NUMCARTE; i++)
    {
        switch (M[i].valore)
        {
        case 1:
            c = 'A';
            break;
        case 11:
            c = 'J';
            break;
        case 12:
            c = 'Q';
            break;
        case 13:
            c = 'K';
            break;
        }
        if (M[i].valore == 1 || M[i].valore >= 11 && M[i].valore <= 13)
            printf("%2c%c ", c, M[i].seme);
        else
            printf("%2d%c ", M[i].valore, M[i].seme);
        if (i % 13 == 12)
            printf("\n");
    }
}

// scambia due carte tra loro nel mazzo
void scambiacarte(Carta *c1, Carta *c2)
{
    Carta t;
    t = *c1;
    *c1 = *c2;
    *c2 = t;
}

// mescola completamente il mazzo
void mescolamazzo(Mazzo M)
{
    int k, i, j;
    for (k = 0; k < 100; k++)
    {
        i = rand() % NUMCARTE;
        j = rand() % NUMCARTE;
        scambiacarte(&M[i], &M[j]);
    }
}
void elimina(Mazzo M, int n)
{
    for (int i = 0; i < NUMCARTE; i++)
    {
        M[i - 1] = M[i];
    }
}

// estrazione casuale di carte dal mazzo
void estraiCarte(Mazzo M, Estratte E, int m)
{
    int i, k;
    for (k = 0; k < EST; k++)
    {
        i = rand() % m;
        E[k] = M[i];
        elimina(M, i);
    }
}
//
void mostraEstratte(Estratte E)
{
    int i;
    char c;
    for (i = 0; i < EST; i++)
    {
        switch (E[i].valore)
        {
        case 1:
            c = 'A';
            break;
        case 11:
            c = 'J';
            break;
        case 12:
            c = 'Q';
            break;
        case 13:
            c = 'K';
            break;
        }
        if (E[i].valore == 1 || E[i].valore >= 11 && E[i].valore <= 13)
            printf("%2c%c ", c, E[i].seme);
        else
            printf("%2d%c ", E[i].valore, E[i].seme);
        if (i % 13 == 12)
            printf("\n");
    }
}
// chiede se si vuole cambiare e si prende casualmente dal mazzo una carta
void cambiaCarta(Estratte E, Mazzo M, int m)
{
    int p = 0, s = rand() % m;
    char c = 'n';
    printf("\nHai visto il mazzo, vuoi cambiare una di queste carte? (s/n) ");
    scanf(" %c", &c);
    if (c == 's')
    {
        printf("\nBene, inserisci la posizione della carta che vuoi cambiare: ");
        do
        {
            scanf("%d", &p);
            if (p < 0 || p > 4)
            {
                printf("\nErrore, inserisci un numero valido (0 - 4): ");
            }

        } while (p < 0 || p > 4);

        // scambio della carta desiderata
        E[p] = M[s];

        printf("\nCarte finali: ");
        mostraEstratte(E);
        printf("\n");
    }
    else
    {
        printf("\nOk, allora proseguiamo.\n");
    }
}
// calcolo dei punti tramite dei if
int calcolaPunti(Estratte E)
{
    int punti = 0;
    for (int i = 0; i < EST - 1; i++)
    {
        for (int j = 0; j < EST; j++)
        {
            if ((E[i].seme == E[j].seme || E[i].valore == E[j].valore) && i != j)
            {
                punti++;
            }
        }
    }
    return punti;
}