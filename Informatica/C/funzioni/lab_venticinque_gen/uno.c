/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/01/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

int effe(int a);
int gi(int a);

int main()
{
    int f = effe(10);
    printf("%d\n", f);
    return 0;
}
int effe(int a)
{
    if (a < 2)
    {
        return 2 * a;
    }
    else
    {
        return gi(a - 1) + gi(a - 2);
    }
}
int gi(int a)
{
    if (a < 2)
    {
        return effe(a);
    }
    else
    {
        return effe(a - 1) + effe(a - 2);
    }
}
