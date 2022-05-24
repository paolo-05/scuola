/*
	Paolo Bianchessi 3ic

	Descrizione: L'allegato file log.txt prodotto da un server web contiene una serie di indirizzi
		IP dei computer che hanno effettuato un accesso al server stesso negli ultimi due giorni
		(oltre all'indirizzo IP � registrata anche la data e l'ora del collegamento).
		Scrivere un programma in C che a partire dai dati di log crea un file di testo di nome
		logsum.txt contenente, per ogni diverso indirizzo IP, il numero di presenze nel file di
		log (ovvero quante volte il computer con quell'indirizzo si � collegato al server in quei due giorni).
		NB: non � noto a priori quanti siano gli indirizzi presenti nel file.

	Analisi:
	apro il file log.txt, leggo il numero IP data e ora se non l'ho mai incontrato salvo l'IP, se l'ho gi� incontrato aumento le volte.


	Non va uff
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _
{
	char IP[16];
	char data[10];
	char ora[8];
} Accesso;

int main()
{
	FILE *in, *out;
	in = fopen("log.txt", "r");
	out = fopen("logsum.txt", "w");
	int trovato = 0, j = 0;
	Accesso r[1000], t;

	while (!feof(in))
	{
		fscanf(in, "%s %s %s", t.IP, t.data, t.ora);
		trovato = 0;
		for (int i = 0; i < 1000; i++)
			if (strcmp(r[i].IP, t.IP) == 0)
				trovato = 1;
		if (!trovato)
		{
			r[j] = t;
			printf("IP: %s\n", r[j].IP);
			j++;
		}
		}
	fclose(in);
	fclose(out);
	return 0;
}
