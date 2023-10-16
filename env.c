#include "shell.h"

void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; ++i)
	{
		_printfstdout("%s\n", environ[i]);
	}
}

