// Example for creating and working with linear lists
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int z;
	struct Node* next; // address of next node
}
Node;

#define WEITER (inpt>0)
#define IN(x) scanf("%d", &x)