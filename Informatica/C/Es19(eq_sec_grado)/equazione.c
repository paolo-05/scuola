/*
    Autore: Paolo Bianchessi 3ic
    Data: 12/11/2021
    Descrizione: 
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, delta, x1, x2;

    char continua = 's';
    do
    {
        printf("\nInserisci i coefficienti dell'equazione: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a == 0)
        {
            printf("\nEquazione di primo grado.");
        }
        else
        {
            delta = b * b - 4 * a * c;
            if (delta >= 0)
            {
                if (delta == 0)
                {
                    x1 = -(b / (2 * a));
                    x2 = x1;
                }
                else
                {
                    x1 = (-b - (sqrt(delta))) / 2 * a;
                    x2 = (-b + (sqrt(delta))) / 2 * a;
                }
                printf("soluzioni: %.2lf %.2lf\n", x1, x2);
            }
            else
            {
                printf("L'equazione non ha soluzioni reali");
            }
        }
        printf("\n Continuare? (s/n): ");
        scanf(" %c", &continua);
    } while (continua == 's');

    return 0;
}
