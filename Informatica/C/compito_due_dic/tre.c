/*
    Autore: Paolo Bianchessi 3ic
    Data: 29/11/2021
    Descrizione: 
*/

#include <stdio.h>
#include <math.h>

float discriminte(float a, float b, float c)
{
    return (b * b) - (4 * a * c);
}

float incognitaUno(float delta, float a, float b, float c)
{
    return (-b - sqrt(delta)) / (2 * a);
}

float incognitaDue(float delta, float a, float b, float c)
{
    return (-b + sqrt(delta)) / (2 * a);
}

int procedura()
{
    float a, b, c, x1, x2;
    float delta;
    printf("\nInserire il valore a dell'equazione: ");
    scanf("%f", &a);
    printf("\nInserire il valore b dell'equazione: ");
    scanf("%f", &b);
    printf("\nInserire il valore c dell'equazione: ");
    scanf("%f", &c);
    if (a == 0)
    {
        printf("\nEquazione di primo grado");
    }
    else
    {
        delta = discriminte(a, b, c);
        if (delta >= 0)
        {
            if (delta == 0)
            {
                x1 = (-b) / (2 * a);
                x2 = x1;
            }
            else
            {
                x1 = incognitaUno(delta, a, b, c);
                x2 = incognitaDue(delta, a, b, c);
            }
            printf("\nI risultati sono x1 = %.2f e x2 =  %.2f ", x1, x2);
        }
        else
        {
            printf("\nL'equazione non ha valori reali");
        }
    }
}

int main()
{
    char scelta;
    do
    {
        procedura();
        printf("\nVuoi calcolare un'altra equazione (s-n) ?");
        scanf(" %c", &scelta);
    } while (scelta == 's');
}