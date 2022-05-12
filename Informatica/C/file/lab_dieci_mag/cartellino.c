#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct reg
{
    int ora;
    int min;
    char mat[9];
} Reg;

int assoluto(int v)
{
    if (v < 0)
        v = -v;
    return v;
}

int calcolaDipendente(char m[])
{
    FILE *f;
    Reg ent, usc, r;
    ent.ora = 0;
    ent.min = 0;
    usc.ora = 0;
    usc.min = 0;
    int stato = 0;
    int minlav = 0;
    // aprire il file
    f = fopen("dati.csv", "r");
    // leggo dati per cercare info
    while (!feof(f))
    {
        fscanf(f, "%d,%d,%s", &r.ora, &r.min, r.mat);
        if (strcmp(r.mat, m) == 0)
        {
            if (stato == 0)
            {
                ent = r;
                stato = 1;
            }
            else
            {
                usc = r;
            }
        }
    }
    // chiudo file
    fclose(f);
    // elaborazione
    minlav = (usc.ora * 60 + usc.min) - (ent.ora * 60 + ent.min);
    return assoluto(minlav);
}
int caricaStruct(Reg s[])
{
    FILE *input;
    int i = 0;
    input = fopen("dati.csv", "r");
    while (fscanf(input, "%d,%d,%s", &s[i].ora, &s[i].min, s[i].mat) != EOF)
        i++;
    fclose(input);
    return i;
}
void riepilogo()
{
    Reg s[100], ent, usc;
    int stato = 0, min;
    FILE *output;
    int i = caricaStruct(s);
    // carico tutto il file in memoria
    char mat[i / 2][9];
    for (int j = 0; j < i / 2; j++)
        if (strcmp(mat[j], s[j].mat) != 0)
            strcpy(mat[j], s[j].mat);
    output = fopen("orario.txt", "w");
    for (int k = 0; k < i / 2; k++)
    {
        for (int h = 0; h < i; h++)
        {
            if (strcmp(s[h].mat, mat[k]) == 0)
            {
                if (stato == 0)
                {
                    ent = s[h];
                    stato = 1;
                }
                else
                    usc = s[h];
            }
        }
        min = assoluto((usc.ora * 60 + usc.min) - (ent.ora * 60 + ent.min));
        fprintf(output, "Ore di lavoro di %s: %d ore e %d minuti\n", mat[k], min / 60, min % 60);
    }
    fclose(output);
}

int main()
{
    int min, s;
    char mat[9];
    printf("1 - Calcola per dipendente\n");
    printf("2 - Elabora dati\n");
    printf("3 - Esci\n");
    printf("Scelta: ");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        printf("Matricola: ");
        scanf("%s", mat);
        min = calcolaDipendente(mat);
        printf("Ha lavorato %d ore e %d minuti\n", min / 60, min % 60);
        break;
    case 2:
        riepilogo();
        printf("Elaborazione salvata in orario.txt\n");
        break;
    }
    return 0;
}
