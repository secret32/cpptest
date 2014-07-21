#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "filehelper.h"

int fileCopy(const char* source, const char* dest)
{
	FILE* psource = fopen(source, "r");
	if (!psource)
		return -1;
	FILE* pdest = fopen(dest, "w");
	char* buf= malloc(BUFFER_SIZE);
	while ((buf = fgets(buf, sizeof(BUFFER_SIZE), psource)) != NULL)
	{
		fputs(buf, pdest);
	}
	free(buf);
	fclose(pdest);
	fclose(psource);
	return 0;
}

int deleteBlankLine(const char* filename)
{
	FILE *preader;
	FILE *pwriter;
	preader = fopen(filename, "r");
	if (!preader)
		return -1;
	char* tmp = ".tmp";
	char temp[strlen(filename) + strlen(tmp)];
	strcpy(temp, filename);
	strcat(temp, tmp);
	pwriter = fopen(temp, "w");
	char* buf= malloc(BUFFER_SIZE);
	while ((buf = fgets(buf, sizeof(BUFFER_SIZE), preader)) != NULL)
	{
		BOOL isNotBlankLine = FALSE;
		for (int i = 0; i < BUFFER_SIZE; i++)
		{
			if(isgraph(buf[i]))
			{
				isNotBlankLine = TRUE;
				break;
			}
		}
		if (isNotBlankLine)
			fputs(buf, pwriter);
	}
	free(buf);
	fclose(pwriter);
	fclose(preader);
	return 0;
}
