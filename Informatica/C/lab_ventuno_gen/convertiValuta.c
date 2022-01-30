/*
    Autore: Paolo Bianchessi 3ic
    Data: 21/01/2022
    Descrizione: 
*/

#include <stdio.h>
#include <stdlib.h>
#define UNDOLLARO 0.88
#define UNASTERLINA 0.84

float dollaroEuro(float dollari)
{
    return dollari * UNDOLLARO;
}

float euroSterlina(float euro)
{
    return euro * UNASTERLINA;
}
float dollaroSterlina(float dollaro)
{
    return euroSterlina(dollaroEuro(dollaro));
}

int controllo(int daControllare)
{
    if (daControllare >= 0)
    {
        return 0;
    }
    return 1;
}

void input(float *daConvertire)
{
    do
    {
        printf("Inserisci la valuta da convertire: ");
        scanf("%f", &*daConvertire);
    } while (controllo(*daConvertire));
}

int menu()
{
    int scelta;
    printf("-- CONVERTITORE VALUTE --\n");
    printf(" 1 - Convertii da dollari a euro\n 2 - Converti da euro a sterline\n 3- Converti da dollari a sterline\n Altro numero: Esci\n");

    printf("Scelta: ");
    scanf("%d", &scelta);

    return scelta;
}

int main()
{
    float daConvertire, convertito;
    int scelta = menu();
    switch (scelta)
    {
    case 1:
        input(&daConvertire);
        convertito = dollaroEuro(daConvertire);
        printf("%.2f dollari convertiti in euro valgono: %.2f\n", daConvertire, convertito);
        break;
    case 2:
        input(&daConvertire);
        convertito = euroSterlina(daConvertire);
        printf("%.2f euro convertiti in sterline valgono: %.2f\n", daConvertire, convertito);
        break;
    case 3:
        input(&daConvertire);
        convertito = dollaroSterlina(daConvertire);
        printf("%.2f dollari convertiti in sterline valgono: %.2f\n", daConvertire, convertito);
        break;

    default:
        break;
    }
    return 0;
}
