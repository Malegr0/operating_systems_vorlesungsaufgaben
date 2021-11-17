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
	
	do
	{
		x = getch();
		p.x = 7;
		p.y = 7;
		Show(p, x);
	}
	while ( x != K_ESC );
	
	
	finish();
	return 0;
}

