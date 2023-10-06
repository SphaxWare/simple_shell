#include "shell.h"



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
				return value;
			}
			free(env);
		}
		i++;
	}
	return NULL;
}

char *check_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *dir = strtok(path, ":");
	char *cmd_path;
	struct stat st;

	while(dir != NULL)
	{
		cmd_path = malloc(strlen(dir) + strlen(cmd) + 2);
		strcpy(cmd_path, dir);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			return(cmd_path);
		}
		free(cmd_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
