#include "main.h"

void init() {
    gFirstItem = NULL;
    gLastItem = NULL;
    gFileElementSize = sizeof(FileElement);
    GenList();
}

void GenList() {
    DIR* dir = NULL;
    struct dirent* d_pointer = NULL;

    dir = opendir(SOURCE_DIR);
    if (dir != NULL) {
        while ((d_pointer = readdir(dir)) != NULL) {
            printf("found: %s", (*d_pointer).d_name);
            Add2List((*d_pointer).d_name);
        }
    }
}

void Add2List(char fileName[80]) {
    FileElement* currentItem = (FileElement*) malloc(gFileElementSize);
    strcpy(currentItem->file_name, fileName);
    currentItem->thread_id = 0;
    pthread_mutex_init(&currentItem->mutex, NULL);
    currentItem->next = NULL;
    gFirstItem = currentItem;

    if (gFirstItem == NULL) {
        gFirstItem = currentItem;
    } else {
        gLastItem->next = (struct File *) currentItem;
    }
}

void ShowList() {
    FileElement* currentItem =  gFirstItem;

    while (currentItem != NULL) {
        printf("--------------------");
        printf("Dateiname: %s", currentItem->file_name);
        printf("Thread ID: %s", currentItem->thread_id);
        printf("Mutex: %s", currentItem->mutex);
        currentItem = (FileElement *) currentItem->next;
    }
}

void Cpy(char fileName[80]) {
    char sourceFilePath[80];
    char targetFilePath[80];
    char ch;
    FILE* in;
    FILE* out;

    in = fopen(strcat(strcat(sourceFilePath, SOURCE_DIR), fileName), "rb");
    out = fopen(strcat(strcat(targetFilePath, TARGET_DIR), fileName), "wb");
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }
    fclose(in);
    fclose(out);
}

void finish() {
    ShowList();
}
