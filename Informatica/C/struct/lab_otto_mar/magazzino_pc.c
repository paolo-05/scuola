/*
    Autore: Paolo Bianchessi 3ic
    Data: 08/03/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR 100
#define DIM 100

struct magazzino
{
    char marca[STR];
    char cpu[10];
    int video;
    float prezzo;
} pc[DIM], t;

void caricaMagazzino(int);
void visualizzaStruct(int);
void ordinaCar(int);
void controllaPrezzi(int, int);

int main()
{
    char scelta;
    int cont = 0, costo;
    do
    {
        caricaMagazzino(cont);
        printf("Inserire ancora (s/n): ");
        scanf(" %c", &scelta);
        cont++;
    } while (scelta != 'n' && cont < DIM);
    if (cont == DIM)
        printf("\nIl magazzino e' pieno");

    ordinaCar(cont);
    visualizzaStruct(cont);

    printf("Inserisci un prezzo limite: ");
    scanf("%d", &costo);
    controllaPrezzi(cont, costo);
    return 0;
}
void caricaMagazzino(int i)
{
    printf("\nCaricamento %d\n", i + 1);
    printf("Inserisci la marca: ");
    scanf("%s", pc[i].marca);
    printf("Inserisci la marca della cpu presente nel pc: ");
    scanf("%s", pc[i].cpu);
    printf("Insersci la grandezza della VRAM: ");
    scanf("%d", &pc[i].video);
    printf("Inserisci il prezzo del prodotto: ");
    scanf("%f", &pc[i].prezzo);
}
void visualizzaStruct(int dimensione)
{
    printf("\n\nMagazzino: \n");
    printf("\nmarca | cpu | video | prezzo\n\n");
    for (int i = 0; i < dimensione; i++)
    {
        printf("%s | %s | %d | %.2f\n", pc[i].marca, pc[i].cpu, pc[i].video, pc[i].prezzo);
    }
}
void ordinaCar(int dimensione)
{
    int i;

    int scambi = 0;
    do
    {
        scambi = 0;
        for (i = 0; i < dimensione - 1; i++)
            if (strcmp(pc[i].marca, pc[i + 1].marca) > 0)
            {
                t = pc[i];
                pc[i] = pc[i + 1];
                pc[i + 1] = t;
                scambi = 1;
            }
    } while (scambi == 1);
}
void controllaPrezzi(int dimensione, int prezzo)
{
    int m = 0;
    printf("\n\nI pc che hanno un prezzo inferiore di %d sono: \n\n", prezzo);
    for (int i = 0; i < dimensione; i++)
    {
        if (pc[i].prezzo < prezzo)
        {
            printf("%s | %s | %d | %.2f\n", pc[i].marca, pc[i].cpu, pc[i].video, pc[i].prezzo);
            m++;
        }
    }
    printf("\nCi sono %d pc che hanno un prezzo minore di %d\n", m, prezzo);
}