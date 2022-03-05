#include <stdio.h>
#include <math.h>

float a, b, c;
double x1, x2, d;

void coefficienti()
{
    printf("coefficiente a:\t");
    scanf("%f", &a);
    printf("coefficiente b:\t");
    scanf("%f", &b);
    printf("coefficiente c:\t");
    scanf("%f", &c);
}

void determinante()
{
    d = b * b - 4 * a * c;
}

void soluzioni()
{
    if (d < 0)
        printf("\nnon possono esserci soluzioni reali\n");
    else if (d == 0)
    {
        x1 = (-b) / (2 * a);
        printf("Due soluzioni reali coincidenti x1 e x2: %.2lf\n", x1);
    }
    else
    {
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        printf("Due soluzioni reali distinte x1: %.2lf e x2: %.2lf\n", x1, x2);
    }
}

void equazione_primo()
{
    if ((b == 0) && (c == 0))
        printf("\nequazione indeterminata\n");
    else if (b == 0)
        printf("\nequazione impossibile\n");
    else
    {
        x1 = -c / b;
        printf("x: %.2lf\n", x1);
    }
}

int main()
{
    coefficienti();
    if (a == 0)
        equazione_primo();
    else
    {
        determinante();
        soluzioni();
    }
    printf("\n");
}