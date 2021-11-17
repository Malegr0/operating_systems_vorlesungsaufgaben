// Main program

#include "os.h"

int main (void)
{
	char x = ',';
	
	init();
	
	gotoXY(0,22);
	printf("This is a test for threads");
	gotoXY(1,23);
	printf("Another message");
	
	
	x = getch();  // input without ENTER
	printf("Ihre Eingabe ist %c", x);
	
	finish();
	return 0;
}

