// Example for working with dirs and files

#include "exDir.h"

void main(void)
{
	int ch;
	char x[MAX_FN_LEN]; // string
	char name_in[MAX_FN_LEN];
	char name_out[MAX_FN_LEN];
	DIR* dir = NULL;
	struct dirent* d_pntr = NULL;
	FILE* in;
	FILE* out;
	
	dir = opendir("./a");
	if(dir != NULL)
	{
		while((d_pntr = readdir(dir)) != NULL)
		{
			strcpy(x, (*d_pntr).d_name); // string zuweisung
			printf("\nname of file: %s", x);
			strcpy(name_in, "./a/");
			strcpy(name_out, "./b/");
			strcat(name_in, x);
			strcat(name_out, x);
			in = fopen(name_in, "rb"); // öffnen der Datei, zweiter Parameter ist der Mode
			out = fopen(name_out, "wb"); // rb -> read byte, wb -> write byte
			
			while((ch = fgetc(in)) != EOF) // liest ein char/byte aus der Datei aus, EOF end of file
			{
				fputc(ch, out); // schreibt zu out
			}
			
			fclose(in);
			fclose(out);
		}
	}
	if (closedir(dir) == -1)
		printf("Fehler beim Schliessen");
	printf("\nDone");
}

// Eine Liste mit Dateinamen aufbauen und die Knoten auf dem Bildschirm anzeigen
// Lesen Sie jeden Knoten aus der Liste aus und kopieren Sie die entsprechende Datei in ./b/
