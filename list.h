#ifndef LIST_H
#define LIST_H
#include <pthread.h>
#include "shelton.h"

#define DEFAULT_SIZE 10

typedef struct Element{
    void* node;
    struct Element* previous;
    struct Element* next;
} Element;

typedef struct {
    unsigned int size;
    Element* first;
    Element* current;
    pthread_mutex_t* mutex;
    BOOL useDefault;
} List;

List* initList(List*);

void addToList(List*, void*);

void destroyList(List*);


#endif // LIST_H
