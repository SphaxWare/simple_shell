#include "shell.h"
/**
 * display_prompt - display ($) .
 */
void print_prompt(void)
{
	char *prompt = "($) ";

	if (isatty(STDIN_FILENO))
		write(1, prompt, 4);
}

void get_in(char **buffer, size_t *size, char *argv[])
{
	int numchar = getline(buffer, size, stdin);

	if (numchar == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
			{
				write(1, "\n", 1);
				exit(0);
			}
			exit(0);
		}
		free(*buffer);
		perror(argv[0]);
	}
	if ((*buffer)[0] == '\n')
	{
		print_prompt();
		get_in(buffer, size, argv);
	}

	if ((*buffer)[numchar - 1] == '\n')
	{
		(*buffer)[numchar - 1] = '\0';
	}
}

/**
 * tokenize_input - Tokenizes a string into an array of arguments.
 * @buffer: The input string to be tokenized.
 * @args:   An array of strings to store the tokenized arguments.
 * @argv: for programme name
 */
void tokenize_in(char *buffer, char *args[], char *argv[])
{
	char *token = strtok(buffer, " \t\n");
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		if (args[i] == NULL)
		{
			perror(argv[0]);
			exit(1);
		}
		args[i + 1] = NULL;
		token = strtok(NULL, " \t\n");
		i++;
	}
	if (i > 0)
	{
		executer(args, argv);
	}
}

/**
 * execute_command - Execute a command in a new process.
 * @args: An array of strings representing the command and its arguments.
 * Return: The exit status of the executed command.
 * @argv: programme name.
 */

void executer(char *args[], char *argv[])
{
	int status;
	pid_t id;

	id = fork();
	if (id == -1)
	{
		perror(argv[0]);
	}
	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
		else
		{
			exit(0);
		}
	}
	else
		wait(&status);
}
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t size = 0;
	char **args;
	int i = 0;

	(void)argc;
	(void)argv;
	args = malloc(1024 * sizeof(char *));
	if (args == NULL)
	{
		perror(argv[0]);
	}
	while (1)
	{
		print_prompt();
		get_in(&buffer, &size, argv);
		tokenize_in(buffer, args, argv);
	}
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
	free(buffer);
	return (0);
}

