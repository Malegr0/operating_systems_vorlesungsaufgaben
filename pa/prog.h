// definition file
// includes
#include <pthread.h>
#include <stdio.h>


// key definition
#define MAX_FN_LEN 10	// max length of filename
#define MAX_THREADS 4	// number of threads
#define DIR_A "./A/"
#define DIR_B "./B/"


// datatypes
typedef struct Node
{
	char file_name[MAX_FN_LEN];
	pthread_mutex_t mutex;
	pthread_t tID;
	Node* next;
}
Node;

// functions
void init(void);
void finish(void);
void GenList(void);
void Add2List(char fname[MAX_FN_LEN]);
void Cpy(char fname[MAX_FN_LEN]);
void ShowList(void);
void* ThrdFunc(void *arg);

// global variables
Node* gNodeFirst;
Node* gNodeLast;
int gNodeSize;
