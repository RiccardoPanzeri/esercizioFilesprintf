#include "struct.h"
//Funzione che mi permette di caricare gli attributi dei singoli componenti dell'array di struct;
void caricaArray(Libro lista[], int dim);
//Funzione che mi permette di visualizzare tutti i dati di ogni elemento dell'array distruct;
void visualizzaArray(Libro lista[], int dim);
void visualizzaArray1(Libro1 lista1[], int dim);
//Funzione che mi permette di confezionare stringhe in formato csv partendo dalla struct;
void csvFile(char stringa[], Libro libro, int dim);
//Funzione che salva una stringa in un file;
void scriviStrFile(char csv1[], char csv2[]);
//Funzione che legge il contenuto da un file e lo salva in una stringa;
void leggiStrFile(char stringa1[], char stringa2[]);
//Funzione che spacchetta la stringa csv e la assegna alle proprietà della struct; NOTA: nonostante tutto sembri funzionare all'interno della funzione, le stringhe risultano vuote una volta stampate all'esterno.
void spacchettaCSV(char csv[], Libro1 libro);