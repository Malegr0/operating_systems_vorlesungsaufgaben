#include "prog.h"

void main (void)
{
	init();
	pthread_t ID[MAX_THREADS];
	int j;
	int myID[MAX_THREADS];
	for(j = 0; j < MAX_THREADS; j++)
	{
		myID[j] = j+1;
		pthread_create(&ID[j], NULL, &ThrdFunc, &myID[j]);
	}
	for(j = 0; j < MAX_THREADS; j++)
	{
		pthread_join(ID[j], NULL);
	}
	finish();
}