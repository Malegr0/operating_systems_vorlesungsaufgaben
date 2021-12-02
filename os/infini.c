#include "os.h"

void init(void)
{
	Cursor(0); // lib.c, cursor is off
	gFirstItem = NULL;
	gLastItem = NULL;
	gPCBsize = sizeof(PCB);
	pthread_mutex_init(&gScreen, NULL);
	srand(time(0));
}

void finish(void)
{
	PCB* cur = gFirstItem;
	PCB* n = NULL;
	
	while(cur != NULL) // wait for threads and free memory
	{
		pthread_join(cur->tID, NULL);
		n = cur->next;
		free(cur);
		cur = n;
	}
	Cursor(1); // lib.c, cursor is on
}
