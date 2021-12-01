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
	Cursor(1); // lib.c, cursor is on
}
