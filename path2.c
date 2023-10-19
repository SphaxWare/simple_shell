#include "shell.h"
/**
 * findcmd - code.
 * @args:...
 * @argv:...
 */
void findcmd(char *args[], char *argv[])
{
	struct stat st;

	if (check_path(args[0]) != NULL)
	{
		args[0] = check_path(args[0]);
		executer(args, argv);
	}
	else
	{
		if (stat(args[0], &st) == -1)
		{
			_printf("%s: 1: %s: not found\n", argv[0], args[0]);
			free(args);
			exit(127);
		}
	}
}
