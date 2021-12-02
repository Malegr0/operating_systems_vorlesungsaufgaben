// all other functions
#include "prog.h"

void init(void)
{
	gNodeSize = sizeof(Node);
	gNodeFirst = NULL;
	gNodeLast = NULL;
	
	GenList();
}

void finish(void)
{
	ShowList();
	
	Node* current = gNodeFirst;
	Node* n = NULL;
	while(current != NULL)
	{
		n = current->next;
		free(current);
		current = n;
	}
}

void GenList(void)
{
	char fname[MAX_FN_LEN];
	DIR* dir = NULL;
	struct dirent* d_pntr = NULL;
	
	dir = opendir(DIR_A);
	if(dir != NULL)
	{
		while((d_pntr = readdir(dir)) != NULL)
		{
			strcpy(fname, (*d_pntr).d_name);
			if(strcmp(fname, ".") != 0 && strcmp(fname, "..") != 0)
			{
				Add2List(fname);
			}
		}
	}
	if(closedir(dir) == -1)
	{
		printf("\nError while closing the dir to read in the filenames");
	}
}

void Add2List(char fname[MAX_FN_LEN])
{
	Node* current = (Node*) malloc(gNodeSize);
	strcpy(current->file_name, fname);
	current->tID = 0;
	pthread_mutex_init(&current->mutex, NULL);
	current->next = NULL;
	
	if(gNodeFirst == NULL)
	{
		gNodeFirst = current;
		gNodeLast = gNodeFirst;
	}
	else
	{
		gNodeLast->next = current;
		gNodeLast = current;
	}
}

void Cpy(char fname[MAX_FN_LEN])
{
	int ch;
	char name_in[MAX_FN_LEN];
	char name_out[MAX_FN_LEN];
	FILE* in;
	FILE* out;
	
	// create path + filename
	strcpy(name_in, DIR_A);
	strcat(name_in, fname);
	strcpy(name_out, DIR_B);
	strcat(name_out, fname);
	
	// create output file and 
	in = fopen(name_in, "rb");
	out = fopen(name_out, "wb");
	
	// copy file content
	while((ch = fgetc(in)) != EOF)
	{
		fputc(ch, out);
	}
	
	// close files
	fclose(in);
	fclose(out);
}

void ShowList(void)
{
	Node* current = gNodeFirst;
	
	while(current != NULL)
	{
		printf("\nname of file: %s | number of thread: %d", current->file_name, current->tID);
		current = current->next;
	}
}
