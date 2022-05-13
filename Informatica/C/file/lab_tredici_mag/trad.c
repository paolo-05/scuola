#include <stdio.h>
#include <string.h>

struct parola
{
	char ita[20];
	char ing[20];
} p[20];

int menu()
{
	int s;
	printf("\n\n1 - Italiano -> Inglese\n");
	printf("2 - Inglese -> Italiano\n");
	printf("3 - Nuova voce\n");
	printf("4 - Elimina voce\n");
	printf("5 - Esci\n");
	printf("\nScelta: ");
	scanf("%d", &s);
	return s;
}

// riceve una stringa vocabolo italiano e stampa la traduzione in inglese
void itaeng(char s[])
{
	FILE *f;
	int trovato = 0;
	char ita[20];
	char eng[20];
	f = fopen("dizio.txt", "r");
	if (f != NULL)
	{
		while (!feof(f) && !trovato)
		{ // se non � finito il file e non ho ancora trovato
			fscanf(f, "%s %s", ita, eng);
			if (strcmp(s, ita) == 0)
			{
				printf("Traduzione: %s\n", eng);
				trovato = 1;
			}
		}
		if (!trovato)
			printf("NON TROVATO\n"); // vocabolo non trovato
		fclose(f);
	}
}

// riceve una stringa vocabolo inglese e stampa la traduzione in italiano
void engita(char s[])
{
	FILE *f;
	int trovato = 0;
	char ita[20];
	char eng[20];
	f = fopen("dizio.txt", "r");
	if (f != NULL)
	{
		while (!feof(f) && !trovato)
		{ // se non � finito il file e non ho ancora trovato
			fscanf(f, "%s %s", ita, eng);
			if (strcmp(s, eng) == 0)
			{
				printf("Traduzione: %s\n", ita);
				trovato = 1;
			}
		}
		if (!trovato)
			printf("NON TROVATO\n"); // vocabolo non trovato
		fclose(f);
	}
}

// aggiunge al file dizio la nuova coppia di vocaboli
void nuova(char ita[], char eng[])
{
	FILE *f;
	f = fopen("dizio.txt", "a");
	if (f != NULL)
	{
		fprintf(f, "\n%s\t%s", ita, eng);
		fclose(f);
	}
}

void elimina(char ita[], char eng[])
{
	struct parola p[20];
	int i = 0;
	FILE *f;
	f = fopen("dizio.txt", "r");
	if (f != NULL)
	{
		while (fscanf(f, "%s %s", p[i].ita, p[i].ing) != EOF)
			i++;
		for (int j = 0; j < i; j++)
		{
			if (strcmp())
			{
				/* code */
			}
		}
	}
}

int main()
{
	int s;
	char ita[20];
	char eng[20];
	do
	{
		s = menu();
		switch (s)
		{
		case 1:
			printf("Parola italiana: ");
			scanf("%s", ita);
			itaeng(ita);
			break;
		case 2:
			printf("Parola inglese: ");
			scanf("%s", eng);
			engita(eng);
			break;
		case 3:
			printf("Nuovo <ita> <eng>: ");
			scanf("%s %s", ita, eng);
			nuova(ita, eng);
			break;
		case 4:
			printf("Elimina <ita> <eng>: ");
			scanf("%s %s", ita, eng);
			elimina(ita, eng);
		}
	} while (s != 5);
}
