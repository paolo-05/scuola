/*
    Autore: Paolo Bianchessi 3ic
    Data: 05/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <string.h>

#define V_L 20

void bubbleSort(char *);
void visualizza(char *);
int confronto(char *, char *);

int main()
{
    char stringaA[V_L], stringaB[V_L];
    printf("\ninserisci la prima stringa: ");
    scanf("%s", stringaA);
    printf("inserisci la seconda stringa: ");
    scanf("%s", stringaB);

    bubbleSort(stringaA);
    bubbleSort(stringaB);

    // visualizza(stringaA);
    // visualizza(stringaB);

    if (confronto(stringaA, stringaB))
    {
        printf("\nle parole sono l'una l'anagramma dell'altra");
    }
    else
    {
        printf("\nle parole non sono l'una l'anagramma dell'altra");
    }

    return 0;
}

void bubbleSort(char str[])
{
    int i, scambi, len;
    char Temp;

    len = strlen(str);

    do
    {
        scambi = 0;

        for (i = 0; i < len - 1; i++)
        {
            if (str[i] > str[i + 1])
            {
                Temp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = Temp;
                scambi = 1;
            }
        }
    } while (scambi != 0);
}

void visualizza(char str[])
{
    printf("\n%s", str);
}

int confronto(char strA[], char strB[])
{
    if (strlen(strA) == strlen(strB))
    {
        if (strcmp(strA, strB) == 0)
        {
            return 1;
        }
        return 1;
    }
    return 0;
}
