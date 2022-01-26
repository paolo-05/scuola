/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/01/2022
    Descrizione: opzione d
*/

#include <stdio.h>
#include <stdlib.h>

int calc(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else
    {
        return 2 * n - 1 + calc(n - 1);
    }
}

int main()
{
    int res = calc(4);
    printf("res = %d\n", res);
    return 0;
}
