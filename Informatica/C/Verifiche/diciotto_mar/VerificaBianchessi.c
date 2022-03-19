/*
	Paolo Bianchessi 18.03.21
*/
#include <stdio.h>
#include <string.h>
#define VEN 5
#define STLEN 20

void menu(char venditori[][STLEN], double vendite[]);
void stampaScelte();

double vendTot(double vendite[]);
int cercaVen(char s[], char venditori[][STLEN]);
void stampaSt(char venditori[][STLEN], double vendite[]);
int cercaMax(double vendite[]);
void ordinaCrescente(char venditori[][STLEN], double vendite[]);

int main()
{
	char venditori[VEN][STLEN]={
		"Rossi", "Gialli", "Verdi", "Neri", "Azzurri"
		};
	double vendite[VEN]={6500.5, 3100, 9500, 4000, 3800.50};
	menu(venditori, vendite);
	
	return 0;
}


void menu(char venditori[][STLEN], double vendite[])
{
	int esci = 0, scelta, pos;
	double t = 0;
	char c[STLEN];
	do
	{
		do
		{
			stampaScelte();
			printf("\nscelta: ");
			scanf("%d", &scelta);
			if(!(scelta < 7 && scelta > 0))
				printf("\nAssicurati di aver inserito un numero corretto.\n");
		}while(!(scelta < 7 && scelta > 0));
		
		switch (scelta){
			case 1:
				 t = vendTot(vendite);
				 printf("Le vendite totali del mese scorso sono %.2lf\n", t);
				break;
			case 2:
				printf("Inserisci il nome del venditore da cercare: ");
				scanf("%s", c);
				pos = cercaVen(c, venditori);
				if(pos != -1)
					printf("Venditore %s presente in archivio\n", c);
				else
					printf("Venditore %s non presente in archivio\n", c);
				break;
			case 3:
				stampaSt(venditori, vendite);
				break;
			case 4:
				pos = cercaMax(vendite);
				printf("Il venditore con vendita massima e' in posizione %d. Nome %s", pos, venditori[pos]);
				break;
			case 5:
				ordinaCrescente(venditori, vendite);
				stampaSt(venditori, vendite);
				break;
			default:
				esci = 1;
				break;
		}
	}while(!esci);
}

void stampaScelte()
{
	printf("\nGestione venditori\n");
	printf("\n1 - vendite totali mese");
	printf("\n2 - cerca venditore");
	printf("\n3 - stampa");
	printf("\n4 - maggiori vendite");
	printf("\n5 - ordina in modo crescente per vendite");
	printf("\n6 - esci");
}

double vendTot(double vendite[])
{
	int i;
	double acc = 0;
	for (i = 0; i < VEN; i++)
		acc += vendite[i];
	return acc; // ritorno la somma delle vendite
}

int cercaVen(char s[], char venditori[][STLEN])
{
	int i;
	for (i = 0; i < VEN; i++)
		if(!strcmp(s, venditori[i])) // funzione string compare ritorna 0 se sono uguali
			return i;
	return -1; // ritorno -1 se non trovo nulla
}

void stampaSt(char venditori[][STLEN], double vendite[])
{
	int i;
	printf("\nVenditore | Vendite | Indice Array\n");
	for	(i = 0; i < VEN; i++)
		printf("%s | %2.lf | %d\n", venditori[i], vendite[i], i);
}

int cercaMax(double venditori[])
{
	int max = 0, i; // inizializzo il massimo valore a indice 0
	for (i = 0; i < VEN; i++)
		if(venditori[i] > venditori[max]) // se il numero è maggiore di max, max è il nuovo maggiore 
			max = i;
	return max;
}

void ordinaCrescente(char venditori[][STLEN], double vendite[])
{
	int i, scambi = 0;
	double t;
	char temp[STLEN];
	do // bubble sort con sentinella
	{
		scambi = 0;
		for (i = 0; i < VEN -1; i++)
		{
			if(vendite[i] < vendite[i+1])
			{
				t = vendite[i];
				strcpy(temp, venditori[i]);
				
				vendite[i] = vendite[i + 1];
				strcpy(venditori[i], venditori[i + 1]); // string copy, copia il contenuto di una stringa in un altra
				
				vendite[i + 1] = t;
				strcpy(venditori[i + 1], temp);
				scambi = 1;
			}
		}
		
	}while(scambi == 1);
}
