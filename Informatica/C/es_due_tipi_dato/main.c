/*  Autore: Paolo Bianchessi 3IC
    Data: 30/09/2021
    Descrizione: verifica dei limiti dei alcini tipi di dato
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(){
    //INT
    int val;
    printf("\nINTERI dimensione in byte: %d", sizeof(int));
    printf("\nIl valore minimo per gli int e': %d", INT_MIN);
    printf("\nIl valore massimo per gli int e': %d", INT_MAX);
    val = INT_MAX;
    printf("\n %d", val);
    val ++;
    printf("\n %d", val);

    printf("\n Tipo short int in byte: %d", sizeof(short int));
    printf("\n Tipo long int in byte: %d", sizeof(long int));
    printf("\n Tipo long long int in byte: %d", sizeof(long long int));
    printf("\n Tipo Unisgned in byte: %d", sizeof(unsigned int));
    unsigned int val2;
    val2 = pow((double)2, (double)32)-1;
    printf("\n %u", val2);
    val2++;
    printf("\n %u", val2);

    //FLOAT
    printf("\n\n Tipo float in byte: %d", sizeof(float));
    printf("\n Cifre di precisione: %d", FLT_DIG);
    printf("\n Esponente minimo:  %d", FLT_MIN_10_EXP);
    printf("\n Esponente massimo: %d", FLT_MAX_10_EXP);

    //DOUBLE
    printf("\n\n Tipo double in byte: %d", sizeof(double));
    printf("\n Cifre di precisione: %d", DBL_DIG);
    printf("\n Esponente minimo:  %d", DBL_MIN_10_EXP);
    printf("\n Esponente massimo: %d", DBL_MAX_10_EXP);

    //LONG DOUBLE
    printf("\n\n Tipo double in byte: %d", sizeof(long double));
    printf("\n Cifre di precisione: %d", LDBL_DIG);
    printf("\n Esponente minimo:  %d", LDBL_MIN_10_EXP);
    printf("\n Esponente massimo: %d", LDBL_MAX_10_EXP);

    return 0;
}
