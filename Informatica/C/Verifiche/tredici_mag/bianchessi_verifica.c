/*
	Paolo Bianchesi 3ic 13.05.2022
*/

#include <stdio.h>
#include <stdlib.h>
#define MAC 5

typedef struct acq{
	char nome[20];
	char cognome[20];
}Acq;

typedef struct macchina{
	char marca[20];
	int cilindrata;
	int anno;
	Acq acquirente;
}macchina;
typedef macchina Archivio[MAC];

void menu(Archivio a, int d);
void visualizza(Archivio a, int d);
int init(Archivio a);
int cerca(Archivio a, int d, char marca[]);
void grandeCilindrata(Archivio a, int d);
int immAnno(Archivio a, int d, int anno); 

int main(){
	Archivio a;
	int d = init(a);
	menu(a, d);
	return EXIT_SUCCESS;
}

int init(Archivio a){
	int i = 0;
	char c = 's';
	do{
		printf("Auto %d\nMarca: ", i+1);
		scanf("%s", a[i].marca);
		printf("Cilindrata: ");
		scanf("%d", &a[i].cilindrata);
		printf("Anno di immatricolazione: ");
		scanf("%d", &a[i].anno);
		printf("Cognome: ");
		scanf("%s", a[i].acquirente.cognome);
		printf("Nome: ");
		scanf("%s", a[i].acquirente.nome);
		
		printf("\nContinuare (s/n)? ");
		scanf(" %c", &c);
		i++;
	}while (c == 's' && i < MAC);
	if(i == MAC)
		printf("\nMassimo numero di dati in archivio raggiunto.\n");
	return i;
}

void menu(Archivio a, int d){
	int e = 0, scelta, anno, t = 0;
	char marca[20];
	while(!e){
		printf("\n1. ricerca di un'auto data la marca\n2. proprietari con auto di cilindrata maggiore di 1800cc\n3. numero di auto immatricolate in un anno dato\n4. esci");
		printf("\nScelta: ");
		scanf("%d", &scelta);
		switch(scelta){
			case 1:
				printf("Quale marca di auto cerchi? ");
				scanf("%s", marca);
				t = cerca(a, d, marca);
				printf("\nIl proprietario e' %s %s", a[t].acquirente.cognome, a[t].acquirente.nome);
				break;
			case 2:
				printf("\nI proprietari con auto di cilindrata superiore a 1800cc sono: ");
				grandeCilindrata(a, d);
				break;
			case 3:
				printf("\nChe anno ti interessa? ");
				scanf("%d", &anno);
				t = immAnno(a, d, anno);
				printf("Le auto nell'anno %d sono %d", anno, t);
				break;
			default:
				e = 1;
				break;
		}
	}
}

int cerca(Archivio a, int d, char nome[]){
	int i;
	for (i = 0; i < d; i++)
		if(strcmp(a[i].marca, nome) == 0)
			return i;
	return -1;
}

void grandeCilindrata(Archivio a, int d){
	int i;
	for (i = 0; i < d; i++)
		if(a[i].cilindrata > 1800)
			printf("%s %s\t", a[i].acquirente.nome, a[i].acquirente.cognome);
}

int immAnno(Archivio a, int d, int anno){
	int i, c = 0;
	for (i = 0; i < d; i++)
		if(a[i].anno == anno)
			c++;
	return c;
}
