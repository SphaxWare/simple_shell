#include "shell.h"
/**
 * print_prompt - display ($) .
 */
void print_prompt(void)
{
	char *prompt = "($) ";

	if (isatty(STDIN_FILENO))
		write(1, prompt, 4);
}
/**
 * get_in - Reads and processes input from stdin.
 * @buffer: A pointer to a pointer that will hold the input line.
 * @size: A pointer to the size of the input buffer.
 * @argv: programme name.
 * @args: arguments
 */
void get_in(char **buffer, size_t *size, char *argv[], char *args[])
{
	int numchar = getline(buffer, size, stdin);

	if (numchar == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
			{
				write(1, "\n", 1);
				free(args);
				free(*buffer);
				exit(0);
			}
			free(args);
			free(*buffer);
			exit(0);
		}
		free(*buffer);
		free(args);
		perror(argv[0]);
	}
	if ((*buffer)[0] == '\n')
	{
		print_prompt();
		get_in(buffer, size, argv, args);
	}

	if ((*buffer)[numchar - 1] == '\n')
	{
		(*buffer)[numchar - 1] = '\0';
	}
}

/**
 * tokenize_in - Tokenizes a string into an array of arguments.
 * @buffer: The input string to be tokenized.
 * @args:   An array of strings to store the tokenized arguments.
 * @argv: for programme name
 */
void tokenize_in(char *buffer, char *args[], char *argv[])
{
	char *token = strtok(buffer, " \t\n");
	int i = 0;
	static int count;

	if (!count)
		count = 0;
	if (token != NULL)
	{
		while (token != NULL)
		{
			args[i] = token;
			if (args[i] == NULL)
			{
				perror(argv[0]);
				free(args);
				free(buffer);
				exit(1);
			}
			args[i + 1] = NULL;
			token = strtok(NULL, " \t\n");
			i++, count++;
		}
		if (i > 0)
		{
			cmdexe(args, argv, i, count, buffer);
		}
	}
}

/**
 * executer - Execute a command in a new process.
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
			free(args);
			exit(1);
		}
		else
		{
			free(args);
			exit(0);
		}
	}
	else
		wait(&status);
}
/**
 * main - this is the main.
 * @argc:we dont care about it
 * @argv : w.
 * Return: 0.
 */
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
		get_in(&buffer, &size, argv, args);
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
