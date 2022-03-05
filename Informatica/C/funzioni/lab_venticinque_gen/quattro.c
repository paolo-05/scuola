/*
    Autore: Paolo Bianchessi 3ic
    Data: 25/01/2022
    Descrizione: ripsota: c
*/

#include <stdio.h>
#include <stdlib.h>

int fun(int fiore, int farfalla)
{
    if (fiore == farfalla)
    {
        return farfalla;
    }
    else
    {
        if (farfalla > fiore)
            return fun(farfalla - fiore, fiore);
        else
            return fun(farfalla, farfalla - fiore);
    }
}

int main()
{
    int res = fun(200, 200);
    printf("res = %d\n", res);
    return 0;
}
