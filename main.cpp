#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipi.h"

int main() {
	int const dim = 2;
	Libro lista[dim];//creo primo array di struct;
	Libro1 lista1[dim];//creo secondo array di struct;
	char csv1[500] = "";//creo contenitore per la prima stringa csv;
	char csv2[500] = "";//e per la seconda stringa csv;
	//carico il primo array di struct;
	printf("inserisci: numero di serie, autore, titolo e data di pubblicazione di due libri: \n");
	caricaArray(lista, dim);
	//visualizzo i contenuti di ogni elemento dell'array di struct;
	printf("Stampo il contenuto del primo array di struct:\n");
	visualizzaArray(lista, dim);
	//confeziono le stringhe csv;
	csvFile(csv1, lista[0], dim);
	csvFile(csv2, lista[1], dim);
	//le scrivo nel file di testo;
	scriviStrFile(csv1, csv2);
	printf("stampo le stringhe csv:\n");
	printf("%s\n", csv1);
	printf("%s\n", csv2);
	//leggo le stringhe dal file e le metto di nuovo nelle stringhe csv, ma invertite, in modo da verificare di averle effettivamente lette e modificate tramite il file;
	leggiStrFile(csv2, csv1);
	printf("stampo le stringhe csv invertite:\n");
	printf("%s\n", csv1);
	printf("%s\n", csv2);


	//Ora la parte difficile:

	//Avevo creato una funzione per fare questo passaggio ma la stringa mi risultava vuota se stampata fuori dalla funzione. quindi, non avendo ancora le conoscenze necessarie, ho effettuato l'operazione nel main() per stavolta;

	char sottostringa[500] = "";
	strcpy(sottostringa, strtok(csv1, ", ")); //ottengo il primo token, ovvero la prima sottostringa;
	strcpy(lista1[0].nSerie, sottostringa);//copio la sottostringa nella variabile nSerie;
	strcpy(sottostringa, strtok(NULL, ", "));//la funzione token, se utilizzata con un puntatore nullo (risultato della mancanza di caratteri delimitatori) come primo parametro, prosegue la ricerca dei caratteri delimitatori da dove aveva interrotto;
	strcpy(lista1[0].autore, sottostringa);
	strcpy(sottostringa, strtok(NULL, ", "));//proseguo con la stessa logica;
	strcpy(lista1[0].titolo, sottostringa);
	strcpy(sottostringa, strtok(NULL, ", "));
	strcpy(lista1[0].anno, sottostringa);
	//Generalmente si utilizza con il ciclo while, con condizione di uscita che la sottostringa sia un puntatore nullo. Ma siccome mi serviva inserire ogni sottostringa in una variabile diversa, ho pensato a questa soluzione;

	//ripeto la stessa operazione con il secondo elemento del secondo array di struct;
	strcpy(sottostringa, "");
	strcpy(sottostringa, strtok(csv2, ","));

	strcpy(lista1[1].nSerie, sottostringa);
	strcpy(sottostringa, strtok(NULL, ","));
	strcpy(lista1[1].autore, sottostringa);
	strcpy(sottostringa, strtok(NULL, ","));
	strcpy(lista1[1].titolo, sottostringa);
	strcpy(sottostringa, strtok(NULL, ","));
	strcpy(lista1[1].anno, sottostringa);

	//verifico che le stringhe siano state inserite correttamente nella seconda struct;
	printf("Stampo i dati del secondo array di struct:\n");
	visualizzaArray1(lista1, dim);








	return 0;
}