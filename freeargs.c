#include "shell.h"

void freeargs(char *args[])
{
	int i;
	for (i = 0; args[i] != NULL; i++)
        {
                free(args[i]);
        }
}
