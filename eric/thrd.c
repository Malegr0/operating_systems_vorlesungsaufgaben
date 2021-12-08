#include "main.h"

void* ThrdFunc(void* arg) {
    FileElement* currentItem = gFirstItem;
    int* threadId = (int*) arg;
    while (currentItem != NULL) {
        if (currentItem->thread_id == 0) {
            int mutexPossible = pthread_mutex_trylock(&currentItem->mutex);
            if (mutexPossible == 0) {
                currentItem->thread_id = (int) threadId;
                pthread_mutex_unlock(&currentItem->mutex);
                Cpy(currentItem->file_name);
            }
        }
        currentItem = (FileElement*) currentItem->next;
    }
}