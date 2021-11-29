#include "os.h"

void* ProgH(void* arg)
{
	// myTyp* P = (myTyp*) arg
	PCB* cur = (PCB*) arg;
	int j;
	Punkt p;
	
	p.x = 7;
	p.y = 7;
	for(j=1; j<5; j++)
	{
		p.x++;
		//p.y++;
		Show(p, cur->Face);
		sleep(2);
		Hide(p);
	}
	printf("\nNumber of thread %d", cur->tID);
}
