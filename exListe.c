// Example for creating and working with linear lists
#include "exListe.h"

void main (void)
{
	int inpt = 0;
	Node* first = NULL; // begin of list
	Node* last = NULL; // end of list
	Node* current = NULL; // for job
	Node* x = NULL; // for deleting
	int NodeSize = sizeof(Node);
	
	printf("Hallo");
	do
	{
		printf("\nPositive Zahl eingeben (sonst=exit)");
		IN(inpt);
		if(WEITER)	// generate a new node
		{
			current = (Node*) malloc(NodeSize);	// alocate memory
			current->z = inpt;
			current->next = NULL; // property of last node
			// ... and append to the list
			if( first == NULL ) // list is empty
			{
				first = current;
			}
			else
			{
				last->next = current;
			}
			last = current;
		}
	}
	while(WEITER);
	// show the list
	current = first;
	while(current != NULL)
	{
		printf("\nDie Zahl ist %d", current->z);
		current = current->next;
	}
	// delete the list
	current = first;
	while(current != NULL)
	{
		x = current->next;
		free(current);
		current = x;
	}
}