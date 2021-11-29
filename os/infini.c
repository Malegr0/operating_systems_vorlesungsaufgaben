#include "os.h"

void init(void)
{
	Cursor(0); // lib.c, cursor is off
	gFirstItem = NULL;
	gLastItem = NULL;
	gPCBsize = sizeof(PCB);
}

void finish(void)
{
	Cursor(1); // lib.c, cursor is on
}
