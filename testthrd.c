// Start an array of threads

#include <stdio.h>
#include <pthread.h>

#define COUNT 9 //eigentlich in h-Datei

void* ThrdFunc(void *arg)
{
	int* numb = (int*) arg;
	// myTyp* P = (myTyp*) arg; // damit lässt sich Struktur übergeben (also mehrere)
	printf("\nThread number = %2d", *numb);
	//sleep(3);
	//return 0;
}

void main(void)
{
	pthread_t ID[COUNT];
	int j;
	int myID[COUNT];
	for(j = 0; j < COUNT; j++)
	{
		myID[j] = j+1;
		pthread_create (&ID[j], NULL, &ThrdFunc, &myID[j]); 	// &ID -> fortlaufende Nummer startet mit 1
												// NULL -> Initialisierungsparameter, hier Standardparameter
												// &ThrdFunc -> Funktion, die übergeben wird, die ausgeführt wird
												// Adresse
		printf("\naus main(): %d", ID[j]);
	}
	for(j = 0; j < COUNT; j++)
	{
		pthread_join(ID[j], NULL);						// wartet bis Thread mit der jeweiligen ID fertig ist
	}
}