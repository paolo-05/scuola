/*
	Autore: Paolo Bianchessi 3ic
	Data: 28.01.2022
*/

#include <stdio.h>
#include <stdlib.h>

int metallo = 1000;

// 95kg
int linea1(int pezzi)
{
	if (metallo - (pezzi * 95) > 0)
	{
		metallo -= pezzi * 95;
		return 0;
	}
	else
	{
		return 1;
	}
}
// 16kg
int linea2(int pezzi)
{
	if (metallo - (pezzi * 16) > 0)
	{
		metallo -= pezzi * 16;
		return 0;
	}
	else
	{
		return 1;
	}
}
// 51kg
int linea3(int pezzi)
{
	if (metallo - (pezzi * 51) > 0)
	{
		metallo -= pezzi * 51;
		return 0;
	}
	else
	{
		return 1;
	}
}

void menu(int *scelta)
{
	printf("1 - prodotto A 95kg\n2 - prodotto B 16kg\n3 - prodotto C 51kg\n Altro numero: esci\n");
	printf("Scelta: ");
	scanf("%d", scelta);
}

int main()
{
	int scelta, pezzi;
	do
	{
		menu(&scelta);
		if (scelta != 1 && scelta != 2 && scelta != 3)
		{
			printf("\n\nSono rimasti %d kg di metallo\n\n", metallo);
			exit(0);
		}

		printf("Quanti pezzi vuoi: ");
		scanf("%d", &pezzi);

		switch (scelta)
		{
		case 1:
			if (linea1(pezzi) == 1)
				printf("\nNon c'e' abbastanza metallo.");
			else
				printf("\nEcco a te %d pezzi del prodotto A", pezzi);
			break;
		case 2:
			if (linea2(pezzi) == 1)
				printf("\nNon c'e' abbastanza metallo.");
			else
				printf("\nEcco a te %d pezzi del prodotto B", pezzi);
			break;
		case 3:
			if (linea3(pezzi) == 1)
				printf("\nNon c'e' abbastanza metallo.");
			else
				printf("\nEcco a te %d pezzi del prodotto C", pezzi);
			break;
		default:
			break;
		}

		printf("\nRimangono %d kg di metallo\n", metallo);
	} while (scelta == 1 || scelta == 2 || scelta == 3);
}
