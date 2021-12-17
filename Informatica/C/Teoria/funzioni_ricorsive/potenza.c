/*
    Autore: Paolo Bianchessi 3ic
    Data: 16/12/2021
    Descrizione: 
*/

#include <stdio.h>

int eleva(int b, int e)
{
    if (b == 0)
        return 1;
    else
        return b * pot(b, e - 1);
}
int main()
{

    return 0;
}
