#include "os.h"

void* ProgH(void* arg) // horizontal moving
{
	// myTyp* P = (myTyp*) arg
	srand(time(0));	// random initialize
	PCB* cur = (PCB*) arg;
	Punkt p;
	int Direction = rand()%2;	// 1 to right, 0 to left
	int Delay = 1 + rand()%3;	// 1,2,3
	p.x = 1 + rand()%X_LENGTH;	// 1..60
	p.y = 1 + rand()%Y_LENGTH;	// 1..18
	
	while(cur->Continue)
	{
		if(cur->Activity)
		{
			Hide(p);
			// estimate actual position
			if((Direction && (p.x >= X_LENGTH)) || (!Direction && (p.x <= 0)))
			{
				Direction = !Direction;
			}
			// new Position
			if(Direction)
			{
				p.x++;
			}
			else
			{
				p.x--;
			}
			Show(p, cur->Face);
			sleep(Delay);
		}
	}
}

void* ProgV(void* arg) // vertical moving
{
	srand(time(0));	// random initialize
	PCB* cur = (PCB*) arg;
	Punkt p;
	int Direction = rand()%2;	// 1 to down, 0 to up
	int Delay = 1 + rand()%3;	// 1,2,3
	p.x = 1 + rand()%X_LENGTH;	// 1..60
	p.y = 1 + rand()%Y_LENGTH;	// 1..18
	
	while(cur->Continue)
	{
		if(cur->Activity)
		{
			Hide(p);
			// estimate actual position
			if((Direction && (p.y >= Y_LENGTH)) || (!Direction && (p.y <= 0)))
			{
				Direction = !Direction;
			}
			// new Position
			if(Direction)
			{
				p.y++;
			}
			else
			{
				p.y--;
			}
			Show(p, cur->Face);
			sleep(Delay);
		}
	}
}

void* ProgR(void* arg) // random moving
{
	
}
