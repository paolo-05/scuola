/*
    Autore: Paolo Bianchessi 3ic
    Data: 23/11/2021
    Descrizione: 
*/

#include <stdio.h>
#define RAGGIO 1
#define ALTEZZA 2
const double PI = 3.14;

double circonferenza(double r)
{
    return 2 * PI * r;
}
double volumecilindro(double r, double h)
{
    double volume;
    volume = areacerchio(r) * h;
}
int main()
{
    return 0;
}
