// Example for working with dirs and files

#include "exDir.h"

void main(void)
{
	char x[MAX_FN_LEN]; // string
	DIR* dir = NULL;
	struct dirent* d_pntr = NULL;
	
	dir = opendir("./a");
	if(dir != NULL)
	{
		while((d_pntr = readdir(dir)) != NULL)
		{
			strcpy(x, (*d_pntr).d_name); // string zuweisung
			printf("\nname of file: %s", x);
		}
	}
	closedir(dir);
	printf("Test");
}