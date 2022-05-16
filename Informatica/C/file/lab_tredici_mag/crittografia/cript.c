#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    FILE *k;
    FILE *o;
    char key[32]; // chiave di cifratura
    char nomefile[50];
    char criptato[50];
    int i;
    char c;

    // apre fie chiave
    k = fopen("key.txt", "r");
    if (k == NULL)
    {
        printf("Chiave non trovata\n");
        return -1;
    }

    // legge chiave
    for (int i = 0; i < 32; i++)
        fscanf(k, "%c", &key[i]);
    fclose(k);

    // chiede file da criptare
    printf("File da criptare: ");
    scanf("%s", nomefile);
    f = fopen(nomefile, "r");
    if (f == NULL)
    {
        printf("File non trovato\n");
        return -1;
    }
    strcpy(criptato, nomefile), strcat(criptato, ".enc");
    // scrive file criptato applicando exor ai caratteri
    o = fopen(criptato, "w");
    i = 0;
    while (!feof(f))
    {
        if (fscanf(f, "%c", &c) > 0)
        {
            c = c ^ key[i % 32];
            fprintf(o, "%c", c);
            i++;
        }
    }
    fclose(f);
    fclose(o);

    // chiede file da de-criptare
    printf("\nFile da de-criptare: "), scanf("%s", nomefile);
    f = fopen(nomefile, "r");
    if (f == NULL)
    {
        printf("File non trovato\n");
        return -1;
    }

    // decripta il file
    o = fopen("decripta.txt", "w");
    i = 0;
    while (!feof(f))
    {
        if (fscanf(f, "%c", &c) > 0)
        {
            c = c ^ key[i % 32];
            fprintf(o, "%c", c);
            i++;
        }
    }
}