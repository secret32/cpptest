#ifndef __FILEHELPER_H__
#define __FILEHELPER_H__
#include <stdio.h>
#include "secconst.h"
#define BUFFER_SIZE 1024
int fileCopy(const char* source, const char* dest);
int deleteBlankLine(const char* filename);
#endif
