/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/01/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

int mystery(int, int);
int secret(int, int);

int main()
{
    int res = secret(24, 3);
    printf("res = %d\n", res);
    return 0;
}

int mystery(int a, int b)
{
    if ((2 * a) > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int secret(int a, int b)
{
    if ((a + b) > mystery(a, b))
    {
        return a;
    }
    else
    {
        mystery(a, b);
    }
}
