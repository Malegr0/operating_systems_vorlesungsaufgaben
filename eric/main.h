# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <pthread.h>

# define THREAD_COUNT 6
# define SOURCE_DIR "./A/"
# define TARGET_DIR "./B/"

typedef struct FileElement {
    char file_name[80];
    int thread_id;
    pthread_mutex_t mutex;
    struct File* next;
} FileElement;

static FileElement* gFirstItem;
static FileElement* gLastItem;
static int gFileElementSize;

void init();
void finish();
void GenList();
void Add2List(char fileName[80]);
void Cpy(char fileName[80]);
void ShowList();
void* ThrdFunc(void* arg);