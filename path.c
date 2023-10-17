#include "shell.h"


/**
 * *_getenv - get env.
 * @name: env
 * Return: env or NULL.
 */
char *_getenv(const char *name)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		char *env = strdup(environ[i]);

		if (env != NULL)
		{
			char *key = strtok(env, "=");
			char *value = strtok(NULL, "=");

			if (strcmp(key, name) == 0)
			{
				return (value);
			}
			free(env);
		}
		i++;
	}
	return (NULL);
}

/**
 * *check_path - get cmd.
 * @cmd: command
 * Return: command or NULL.
 */
char *check_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *dir = strtok(path, ":");
	char *cmd_path;
	struct stat st;

	while (dir != NULL)
	{
		cmd_path = malloc(strlen(dir) + strlen(cmd) + 2);
		strcpy(cmd_path, dir);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
/**
 * *pathfinder - find paths.
 * @args: ..
 * @argv: ..
 */
void pathfinder(char *args[], char *argv[])
{
	struct stat st;
	int j, status;

	for (j = 0; args[j] != NULL; j++)
	{
		if (args[j] != NULL && strcmp(args[j], "exit") == 0)
		{
			if (args[j + 1] != NULL)
			{
				status = _atoi(args[j + 1]);
				if (status == -1)
					_printf("./hsh: 1: exit: Illegal number: %s\n", args[j + 1]);
				myexit(status);
			}
			else
				exit(2);
		}
	}
	if (stat(args[0], &st) == 0)
		executer(args, argv);
	else
	{
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
				exit(127);
			}
		}
	}
}

int myexit(int status)
{
	if (status == -1)
	{
		exit(2);
	}
	if (status < 0)
	{
		_printf("./hsh: 1: exit: Illegal number: %d\n", status);
		exit(2);
	}
	else
		exit(status);
	return (status);
}
