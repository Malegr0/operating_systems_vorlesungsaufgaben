#include "os.h"

void ManageThreads(char fc)
{
	PCB* cur = NULL;
	int found = 0;
	if(gFirstItem == NULL) // then list is empty
	{
		gFirstItem = InitThread(fc);
		gLastItem = gFirstItem;
	}
	else //the list in NOT empty
	{
		cur = gFirstItem;
		do
		{
			if(cur->Face == fc)
			{
				found = 1; // Face is found
				cur->Activity = !(cur->Activity);
			}
			cur = cur->next; //walking through the list
		}
		while( cur != NULL && (!found) );
		if(!found) // append a new item
		{
			cur = InitThread(fc); //address of the new item
			gLastItem->next = cur;
			gLastItem = cur;
		}
	}
	
	//printf("%c", fc);
}

PCB* InitThread(char fc)
{
	int j;
	PCB* p = (PCB*) malloc(gPCBsize); //allocate memory
	p->Face = fc;
	p->Continue = 1;
	p->Activity = 1;
	j = rand()%3; // 0,1,2
	switch (j)
	{
		case 0:
			p->Prog = 'H';
			break;
		case 1:
			p->Prog = 'V';
			break;
		case 2:
			p->Prog = 'R';
			break;
	}
	p->next = NULL;
	RunThread(p); // start the thread
	return p;
}

void RunThread(PCB* cur)
{
	pthread_t th = NULL;
	switch(cur->Prog)
	{
		case 'H':
			pthread_create(&th, NULL, ProgH, cur); 
			break;
		case 'V':
			pthread_create(&th, NULL, ProgV, cur);
			break;
		case 'R':
			pthread_create(&th, NULL, ProgR, cur);
			break;
	}
	
	cur->tID = th;
}