#include "list.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

List* initList(List* list)
{
    if(!list)
    {
        list = malloc(sizeof(List));
        if(!list)
        {
            return NULL;
        }
        list->useDefault = TRUE;
    }
    list->mutex = malloc(sizeof(pthread_mutex_t));
    list->size = 0;
    pthread_mutex_init(list->mutex, NULL);
    return list;
}

void addToList(List* list, void* value)
{
    pthread_mutex_lock(list->mutex);

    Element* element = malloc(sizeof(Element));
    element->node = malloc(sizeof(void));
    memcpy(element->node, value, sizeof(void));

    if(list->size == 0)
    {
        element->previous = NULL;
        list->first = element;
        list->current = element;
    }
    else
    {
        Element* pre = list->current;
        pre->next = element;
        element->previous = pre;
        list->current = element;
    }
    list->size += 1;

    pthread_mutex_unlock(list->mutex);
}

void destroyList(List* list)
{
    free(list->mutex);
    unsigned int size = list->size;
    while(size > 0){
        Element* e = list->current;
        if(e)
        {
            list->current = e->previous;
            free(e->node);
            free(e);
        }
        size -= 1;
    }
    if(list->useDefault)
        free(list);
}
