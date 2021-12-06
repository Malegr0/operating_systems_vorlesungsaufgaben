#include <stdio.h>
#include <stdlib.h>
// Eingabe von der Tastatur in main() einlesen
// und in eine Funktion zur Ausgabe übergeben.

void aus(char param[]);
char* test(void);

int main(void)
{
	char str[80]; // memory is reserved, 80 bytes
	printf("\n==> ");
	scanf("%s", str);
	aus(str);
	return 0;
}

void aus(char *param) // param[] == *param
{
	printf("\naus(): %s", param);
}

char* test(void)
{
	char* v;
	v = (char*) malloc(80);
	v[0] = 'a';
	v[1] = 'b';
	v[2] = 'c';
	v[3] = '\0';
}