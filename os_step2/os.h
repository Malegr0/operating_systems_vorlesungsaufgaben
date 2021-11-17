// Definition file

#include <stdio.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
//#include <time.h>

// Datatypes
typedef struct PunktSTRU
{
	int x;
	int y;
}
Punkt;

// interface
void gotoXY (int x, int y);
void Cursor (int x);
int  getch  (void);
//char inkey  (void);
void init   (void);
void finish (void);
void Show   (Punkt p, char x);
void Hide   (Punkt p);
