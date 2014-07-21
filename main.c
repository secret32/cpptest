#include <stdio.h>
#include "list.h"

int main(void)
{
    List* list = NULL;
    list = initList(list);
    if(list == NULL)
    {
        printf("init list error\n");
        return -1;
    }
    int i = 11;
    addToList(list, &i);
    printf("list.size=%d\n", list->size);
    destroyList(list);
    return 0;
}

