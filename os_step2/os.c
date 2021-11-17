// Main program

#include "os.h"

int main (void)
{
	char x = ',';
	Punkt p;
	
	init();
	
	gotoXY(0,22);
	printf("This is a test for threads");
	gotoXY(1,23);
	printf("Another message");
	
	p.x = 11;
	p.y = 12;
	Show (p, 'W');
	sleep(1);
	Hide (p);
	p.x = 5;
	p.y = 4;
	Show (p, 'W');
	
	
	finish();
	return 0;
}

