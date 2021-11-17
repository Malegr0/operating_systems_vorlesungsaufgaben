// Main program

#include "os.h"

int main (void)
{
	char x;
	printf("Tachschen!");
	x = getch();  // input without ENTER
	printf("\nIhre Eingabe ist %c", x);
	return 0;
}

