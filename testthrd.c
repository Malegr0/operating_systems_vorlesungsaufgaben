#include <stdio.h>
#include <pthread.h>

void* ThrdFunc(void *arg)
{
	int* numb = (int*) arg;
	// myTyp* P = (myTyp*) arg; // damit lässt sich Struktur übergeben (also mehrere)
	printf("\nThread number = %2d", *numb);
	//return 0;
}

void main(void)
{
	//int j = 7;
	pthread_t ID = 0;
	
	pthread_create (&ID, NULL, &ThrdFunc, &ID); 	// &ID -> fortlaufende Nummer startet mit 1
												// NULL -> Initialisierungsparameter, hier Standardparameter
												// &ThrdFunc -> Funktion, die übergeben wird, die ausgeführt wird
												// Adresse
	printf("\naus main(): %d", ID);
	pthread_join(ID, NULL);						// wartet bis Thread mit der jeweiligen ID fertig ist
}