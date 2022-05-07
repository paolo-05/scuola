/*
    Autore: Paolo Bianchessi 3ic
    Data: 06/05/2022
    Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char buf[100];
    int c = 0, v = 0;
    fp = fopen("input.txt", "r");
    if (fp != NULL)
    {
        fgets(buf, 100, fp);
        fclose(fp);
    }
    for (int i = 0; i < strlen(buf); i++)
        if (buf[i] >= 'a' && buf[i] <= 'z' || buf[i] >= 'A' && buf[i] <= 'Z' || buf[i] == ' ')
            if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u' || buf[i] == 'A' || buf[i] == 'E' || buf[i] == 'I' || buf[i] == 'O' || buf[i] == 'U')
                v++;
            else
                c++;
    if (c > 0 || v > 0)
    {
        fp = fopen("output.txt", "w");
        fprintf(fp, "Il file input.txt contiene %d consonanti e %d vocali", c, v);
        fclose(fp);
    }

    return EXIT_SUCCESS;
}
