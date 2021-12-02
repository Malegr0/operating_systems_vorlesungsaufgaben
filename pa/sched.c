// thread functions
#include "prog.h"

void* ThrdFunc(void *arg)
{
	int* id = (int*) arg;
	Node* current = gNodeFirst;
	
	while(current != NULL)
	{
		if(current->tID == 0) // check if file is not copied yet
		{
			if((pthread_mutex_lock(&current->mutex)) == 0)
			{
				current->tID = (pthread_t) id;
				pthread_mutex_unlock(&current->mutex);
				Cpy(current->file_name);
			}
			else
			{
				printf("\nFile %s can not be locked for thread %d. This file goes to the next file.", current->file_name, *id);
			}
		}
		else
		{
			printf("\nFile %s is currently in copy process by thread %d.", current->file_name, current->tID);
		}
		current = current->next;
	}
	return 0;
}