/*
    Autore: Paolo Bianchessi 3ic
    Data: 06/05/2022
    Descrizione: contare le parole presenti in un file di testo
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *input;
    char parola[30], nomefile[20];
    int contaparole = 0;
    printf("\nInserisci il nome del file da aprire: ");
    scanf("%s", nomefile);

    if ((input = fopen(nomefile, "r")) == NULL)
    {
        fprintf(stderr, "Impossibile aprire il file %s\n", nomefile);
        return EXIT_FAILURE;
    }
    input = fopen(nomefile, "r");
    // ciclo di lettura del contenuto del file finché non è finito
    while (!feof(input))
    {
        fscanf(input, "%s", parola);
        contaparole++;
    }
    fclose(input);
    fprintf(stdout, "Il file %s contiene %d parole\n", nomefile, contaparole);
    return 0;
}
