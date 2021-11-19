#include <stdio.h>

int main() {
    int mese;
    printf("inserusci un mese");
    scanf("%d", &mese);

    switch (mese) {
        case 1: 
            printf("gennaio");
            break;
        case 2: 
            printf("febbraio");
            break;
        case 3:
            printf("marzo");
            break;
        case 4:
            printf("aprile");
            break;
        case 5:
            printf("maggio");
            break;
        case 6:
            printf("giungo");
            break;
        case 7:
            printf("luglio");
            break;
        case 8:
            printf("agosto");
            break;
        case 9:
            printf("settembre");
            break;
        case 10:
            printf("ottobre");
            break;
        case 11:
            printf("novembre");
            break;
        case 12:
            printf("dicembre");
            break;
    }
}