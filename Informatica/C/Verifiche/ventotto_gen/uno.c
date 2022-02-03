/*
	Autore: Paolo Bianchessi 3ic
	Data: 28.01.2022

	soluzione: rec1 = 2, rec2 = 2
*/

#include <stdio.h>

int volteRec1 = 0, volteRec2 = 0;

int rec1(int a, int b);
int rec2(int a, int b);

int main()
{
	volteRec1++;
	rec1(4, 6);
	printf("rec1 = %d, rec2 = %d", volteRec1, volteRec2);
}
int rec2(int a, int b)
{
	int d = b - 3 * a;
	if (d % 27 == 0)
		return 0;
	volteRec1++;
	return rec1(b, d);
}

int rec1(int a, int b)
{
	int c = a * b;
	if (c == 0)
		return 0;
	volteRec2++;
	return rec2(a, c);
}
