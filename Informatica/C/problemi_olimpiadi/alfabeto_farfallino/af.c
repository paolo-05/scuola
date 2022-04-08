/*
    Autore: Paolo Bianchessi 3ic
    Data: 08/04/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

void offset(string s, int p)
{
    for (int i = p; i < 100 - 3; i++)
        s[i + 3] = s[i];
}

int main()
{
    string in = {0};

    printf("Stringa: ");
    scanf("%s", in);

    for (int i = 0; i < 100; i++)
        switch (in[i])
        {
        case 'a':
            printf("afa");
            break;
        case 'e':
            printf("efe");
            break;
        case 'i':
            printf("ifi");
            break;
        case 'o':
            printf("ofo");
            break;
        case 'u':
            printf("ufu");
            break;

        default:
            printf("%c", in[i]);
            break;
        }
    return 0;
}
