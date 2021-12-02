// Main program

#include "os.h"

int main (void)
{
	char x = ',';
	Punkt p;
	
	init();
	pthread_mutex_lock(&gScreen);
	gotoXY(0,2+Y_LENGTH);
	printf("ESC - to exit");
	gotoXY(1,3+Y_LENGTH);
	printf("SPACE - task manager");
	pthread_mutex_unlock(&gScreen);
	do
	{
		x = getch();
		if ('a' <= x && x <= 'z')
		{
			ManageThreads(x);
		}
		if(x == K_SPACE)
		{
			TaskMan();	// show threads
		}
	}
	while ( x != K_ESC );
	StopAllThreads();
	
	finish();
	return 0;
}

