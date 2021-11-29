// Definition file

#include <stdio.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
//#include <time.h>

// Key definitions
#define K_ESC 27

// Datatypes
typedef struct PunktSTRU
{
	int x;
	int y;
}
Punkt;

typedef struct PCB
{
	pthread_t tID;
	char Face;		//letter
	int Continue;	// boolean 0/1
	int Activity;	// boolean 0/1, Bewegung auf dem Bildschirm
	int Delay;		// velocity
	char Prog;		// Horizental, Vertical, Random
	struct PCB* next;
}
PCB;

// interface
void gotoXY (int x, int y);
void Cursor (int x);
int  getch  (void);
//char inkey  (void);
void init   (void);
void finish (void);
void Show   (Punkt p, char x);
void Hide   (Punkt p);
void ManageThreads(char);	// man muss den Namen für die Parameter hier nicht angeben
PCB* InitThread(char);
void RunThread(PCB*);
void* ProgH(void* arg);

// global variables
PCB* gFirstItem;
PCB* gLastItem;
int gPCBsize;
