// Main program

#include "os.h"

int main (void)
{
	char x = ',';
	gotoXY(5,7);
	printf("A");
	x = getch();  // input without ENTER
	printf("Ihre Eingabe ist %c", x);
	
	
	return 0;
}

