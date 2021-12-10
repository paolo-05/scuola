/*
    Autore: Paolo Bianchessi 3ic
    Data: 07/12/2021
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>

int bisestile(int anno)
{
    if (anno % 4 == 0)
    {
        if (anno % 100 == 0)
        {
            if (anno % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int controllaData(int gg, int mm, int aa)
{
    return gg + mm * 12 + aa * 365;
}

int main()
{
    int g1, m1, a1, bisestile1;
    int g2, m2, a2, bisestile2;
    printf("Inserisci una data (gg/mm/aa/): ");
    scanf("%d/%d/%d", &g1, &m1, &a1);

    printf("Inserisci un'altra data (gg/mm/aa): ");
    scanf("%d/%d/%d", &g2, &m2, &a2);
    bisestile1 = bisestile(a1);
    if (bisestile1)
    {
        printf("\nIl primo anno e' bisestile\n");
    }

    else
    {
        printf("Il primo anno non e' bisestile\n");
    }
    bisestile2 = bisestile(a2);
    if (bisestile2)
    {
        printf("Il secondo anno e' bisestile\n");
    }
    else
    {
        printf("Il secondo anno non e' bisestile\n");
    }
    g1 = controllaData(g1, m1, a1);
    g2 = controllaData(g2, m2, a2);
    if (g1 > g2)
    {
        printf("\nLa prima data e' maggiore della seconda");
    }
    else
    {
        printf("\nLa seconda data è maggiore della prima\n");
    }

    return 0;
}
