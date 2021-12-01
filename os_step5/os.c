// Main program

#include "os.h"

int main (void)
{
	char x = ',';
	Punkt p;
	
	init();
	pthread_mutex_lock(&gScreen);
	gotoXY(0,22);
	printf("ESC - to exit");
	gotoXY(1,23);
	printf("Another message");
	pthread_mutex_unlock(&gScreen);
	do
	{
		x = getch();
		if ('a' <= x && x <= 'z')
		{
			ManageThreads(x);
		}
	}
	while ( x != K_ESC );
	
	
	finish();
	return 0;
}

