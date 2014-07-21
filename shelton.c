#include "shelton.h"
#include <string.h>

char* strsub(char* dest, const char* src, unsigned int start, unsigned int end)
{
    unsigned int len = strlen(src);
    if(end >= len || end < start)
        end = len - 1;
    len = end - start + 1;
    char temp[len + 1];
    strncpy(temp, &src[start], len);
    temp[len] = '\0';
    memcpy(dest, temp, sizeof(temp));
    return dest;
}
