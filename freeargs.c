#include "shell.h"
/**
 * freeargs - Free memory allocated for an array of strings.
 * @args: Array of strings to free.
 */
void freeargs(char *args[])
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
