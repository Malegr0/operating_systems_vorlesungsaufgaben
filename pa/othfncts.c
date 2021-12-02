// all other functions
#include "prog.h"

void init(void)
{
	gNodeSize = sizeof(Node);
	
	//create first list item
	
	GenList()
}

void finish(void)
{
	ShowList()
	// delete list
}

void GenList(void)
{
	char fname[MAX_FN_LEN];
	struct dirent* d_ptnr = NULL;
	
	dir = opendir(DIR_A);
	if(dir != NULL)
	{
		while((d_ptnr = readdir(dir)) != NULL)
		{
			strcpy(fname, (*d_pntr).dname);
			if(strcmp(fname, ".") != 0 && strcmp(fname, "..") != 0)
			{
				Add2List(fname);
			}
		}
	}
	if(closedir(dir) == -1)
	{
		printf("error while closing the dir to read in the filenames");
	}
}

void Add2List(char fname[MAX_FN_LEN])
{
	
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
	
}
