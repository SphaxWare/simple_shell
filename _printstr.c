#include "main.h"

/**
 * _print_str - A Custom function that print a string
 * @lkm: is A va_list which is contain an argument
 * as a string.
 * @cnt: It count the number of characters that's been
 * printed.
 *
 * Return: counter value.
 */
int _print_str(va_list lkm, int cnt)
{
	int cj = 0;
	char *string = va_arg(lkm, char *);

	if (string == NULL)
	{
		__putchar('(');
		__putchar('n');
		__putchar('u');
		__putchar('l');
		__putchar('l');
		__putchar(')');
		cnt += 6;
		return (cnt);
	}
	for (cj = 0; string[cj] != '\0'; cj++)
	{
		if (string[cj] == '\0')
			return (-1);

		__putchar(string[cj]);
		cnt++;
	}

	return (cnt);
}
