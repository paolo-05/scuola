/*
	Paolo Bianchessi 18.03.21
*/
#include <stdio.h>
#include <string.h>
#define VEN 5
#define STLEN 20

typedef struct
{
	char nome[STLEN];
	double importo;
} venditore;

void menu(venditore *);
void stampaScelte();

double vendTot(venditore *);
int cercaVen(venditore *, char *);
void stampaSt(venditore *);
int cercaMax(venditore *);
void ordinaCrescente(venditore *, int, int);

int main()
{
	venditore archivio[VEN] = {
		{"Rossi", 6500.5},
		{"Gialli", 3100},
		{"Verdi", 9500},
		{"Neri", 4000},
		{"Azzurri", 3800.5}};
	menu(archivio);

	return 0;
}

void menu(venditore venditori[])
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
			if (!(scelta < 7 && scelta > 0))
				printf("\nAssicurati di aver inserito un numero corretto.\n");
		} while (!(scelta < 7 && scelta > 0));

		switch (scelta)
		{
		case 1:
			t = vendTot(venditori);
			printf("Le vendite totali del mese scorso sono %.2lf\n", t);
			break;
		case 2:
			printf("Inserisci il nome del venditore da cercare: ");
			scanf("%s", c);
			pos = cercaVen(venditori, c);
			if (pos != -1)
				printf("Venditore %s presente in archivio\n", c);
			else
				printf("Venditore %s non presente in archivio\n", c);
			break;
		case 3:
			stampaSt(venditori);
			break;
		case 4:
			pos = cercaMax(venditori);
			printf("Il venditore con vendita massima e' in posizione %d. Nome %s", pos, venditori[pos].nome);
			break;
		case 5:
			ordinaCrescente(venditori, 0, VEN - 1);
			stampaSt(venditori);
			break;
		default:
			esci = 1;
			break;
		}
	} while (!esci);
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

double vendTot(venditore venditori[])
{
	int i;
	double acc = 0;
	for (i = 0; i < VEN; i++)
		acc += venditori[i].importo;
	return acc; // ritorno la somma delle vendite
}

int cercaVen(venditore venditori[], char s[])
{
	int estrInf = 0;	   // estremo inferiore
	int estrSup = VEN - 1; // estremo superiore
	int medio;
	while (estrInf <= estrSup) // il vettore non è finito
	{
		medio = (estrInf + estrSup) / 2;		  // nuovo valore iniziale
		if (strcmp(s, venditori[medio].nome) > 0) // se il numero è maggiore
		{
			estrInf = medio + 1; // è nella parte destra
		}
		else
		{
			if (strcmp(s, venditori[medio].nome) < 0) // se il numero è minore
				estrSup = medio - 1;				  // è nella parte sinistra
			else
				return medio; // altrimenti l'ho trovato
		}
	}
	return -1; // il numero non è presente
}

void stampaSt(venditore venditori[])
{
	int i;
	printf("\nVenditore | Vendite | Indice Array\n");
	for (i = 0; i < VEN; i++)
		printf("%s | %2.lf | %d\n", venditori[i].nome, venditori[i].importo, i);
}

int cercaMax(venditore venditori[])
{
	int max = 0, i; // inizializzo il massimo valore a indice 0
	for (i = 0; i < VEN; i++)
		if (venditori[i].importo > venditori[max].importo) // se il numero � maggiore di max, max � il nuovo maggiore
			max = i;
	return max;
}

void scambia(venditore vet[], long x, long y)
{
	venditore tmp = vet[x];
	vet[x] = vet[y];
	vet[y] = tmp;
}

int partiziona(venditore venditori[], int sx, int dx)
{
	int pivot, ipivot;				   // valore di pivot, indice posizione pivot
	ipivot = sx;					   // scegli indice per il pivot: Hoare usa il primo
	pivot = venditori[ipivot].importo; // valore_pivot <- [posizione_iniziale_pivot]
	// effettua il partizionamento in due sotto vettori individuando q (posizione_effettiva_pivot)
	while (sx < dx)
	{
		while ((venditori[sx].importo <= pivot) && (sx < dx)) // cerco elemento di sinistra > pivot
			sx++;
		while (venditori[dx].importo > pivot) // cerco elemento di destra < pivot
			dx--;
		if (sx < dx)
		{								// se non ho finito di ordinare
			scambia(venditori, sx, dx); // scambio i due elementi
		}
	}
	scambia(venditori, ipivot, dx); // posiziona il pivot nella sua cella q
	// mostraVettore();                           // visualizza un passo
	// printf("*");
	return dx;
}

void ordinaCrescente(venditore venditori[], int e_sx, int e_dx)
{
	int q; // nuovo indice  pivot
	if (e_sx < e_dx)
	{ // ctr termine vettore
		q = partiziona(venditori, e_sx, e_dx);
		// -- chiamata sui sotto vettori sinistro e destro
		ordinaCrescente(venditori, e_sx, q - 1); // vet di sinistra
		ordinaCrescente(venditori, q + 1, e_dx); // vet di destra
	}
}