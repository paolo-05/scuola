/*
	Autore: Paolo Bianchessi 3ic
	Data: 28.01.2022
*/

#include <stdio.h>

void treValori(int a, int b, int c)
{
	int i, max = a, min = a;

	for (i = 0; i < 12; i++)
	{
		if (max < b)
			max = b;

		if (min > b)
			min = b;

		if (max < c)
			max = c;

		if (min > c)
			min = c;

		max - (min / 2);

		printf("\n  max %d, min %d\n", max, min);
	}
}

void input(int *uno, int *due, int *tre)
{

	printf("\nInserisci tre numeri interi: ");
	scanf("%d %d %d", uno, due, tre);
}

int main()
{
	int i, a, b, c;

	input(&a, &b, &c);
	int max = a, min = a;
	treValori(a, b, c);
}
