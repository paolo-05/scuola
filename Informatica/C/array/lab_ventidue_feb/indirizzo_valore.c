/*
    Autore: Paolo Bianchessi 3ic
    Data: 22/02/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>

int f1(int, int);
int f2(int *, int *);

int main()
{
    int a = 2, b = 3;
    int c = 0;
    c = f1(a, b);
    printf("Dopo f1: a = %d, b = %d, c = %d\n", a, b, c);

    a = 2;
    b = 3;
    c = 0;
    c = f2(&a, &b);
    printf("Dopo f2: a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}

int f1(int a, int b)
{
    int res = a + b;
    a = 0;
    b = 0;
    return res;
}

int f2(int *a, int *b)
{
    int res = *a + *b;
    *a = 0;
    *b = 0;
    return res;
}