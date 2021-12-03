// thread functions
#include "prog.h"

void* ThrdFunc(void *arg)
{
	int* id = (int*) arg;
	
	int length = snprintf(NULL, 0, "%d", id); 	// get length of id
	char* id_str = malloc(length + 1);		// allocate memory for the id as string
	snprintf(id_str, length + 1, "%d", id);	// cast id to string
	
	Node* current = gNodeFirst;
	char log_out[MAX_FN_LEN];
	FILE* out;
	strcpy(log_out, DIR_LOG);
	strcat(log_out, id_str);
	out = fopen(log_out, "wb");
	
	while(current != NULL)
	{
		if(current->tID == 0) // check if file is not copied yet
		{
			if((pthread_mutex_lock(&current->mutex)) == 0) // locks mutex and checks if it was successfull
			{
				current->tID = (pthread_t) id;
				pthread_mutex_unlock(&current->mutex);
				Cpy(current->file_name);
				fprintf(out, "\nFile %s was copied by thread %d.", current->file_name, *id);
			}
			else
			{
				printf("\nFile %s can not be locked for thread %d. This thread goes to the next file.", current->file_name, *id);
				fprintf(out, "\nFile %s can not be locked for thread %d. This thread goes to the next file.", current->file_name, *id);
			}
		}
		else
		{
			printf("\nFile %s is currently in copy process by thread %d.", current->file_name, current->tID);
			fprintf(out, "\nFile %s is currently in copy process by thread %d.", current->file_name, current->tID);
		}
		current = current->next;
	}
	fclose(out);
	free(id_str);
	return 0;
}