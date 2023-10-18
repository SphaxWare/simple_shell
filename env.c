#include "shell.h"
/**
 * printenv - code down below
 */
void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; ++i)
	{
		_printfstdout("%s\n", environ[i]);
	}
}

/**
 * _setenv - code below
 * @name: name of env
 * @value: value of env
 * Return: integer
 */
int _setenv(const char *name, const char *value)
{
	int i = 0;
	char *envar;

	if (name == NULL)
		_printf("Error : envirement name is missing");
	if (value == NULL)
		_printf("Error : envirement value is missing");
	envar = malloc(strlen(name) + strlen(value) + 2);
	if (envar == NULL)
	{
		perror("Error :");
		return (-1);
	}
	while (environ[i] != NULL)
	{
		char *env = _strdup(environ[i]);
		char *key = strtok(env, "=");

		if (_strcmp(key, name) == 0)
		{
			_strcat(envar, name);
			_strcat(envar, "=");
			_strcat(envar, value);
			environ[i] = envar;
			free(env);
			return (0);
		}
		else
		{
			free(env);
			i++;
		}
	}
	_strcat(envar, name);
	_strcat(envar, "=");
	_strcat(envar, value);
	environ[i] = envar;
	environ[i + 1] = NULL;
	return (0);
}
