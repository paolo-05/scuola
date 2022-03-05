

#include <stdio.h>
#define N 10
#define MAX 1023
#define MIN 0
int main()
{
    int c = 0, j, R[N], decimale[N];
    do
    {
        printf("Inserici un numero compreso tra 0 e 1023: ");
        scanf("%d", &decimale[c]);
        if (decimale[c] >= MIN && decimale[c] <= MAX)
            c++;
    } while (c < N);
    for (int i = 0; i < N; i++)
    {
        for (j = N - 1; j >= 0; j--)
        {
            R[j] = decimale[i] % 2;
            decimale[i] = decimale[i] / 2;
        }
        for (j = 0; j < N; j++)
        {
            printf("%d ", R[j]);
        }
        printf("\n");
    }
    return 0;
}