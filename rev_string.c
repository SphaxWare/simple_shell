#include "main.h"
#include <string.h>

/**
 * str_rev - Reverses a string and prints it.
 * @lkm: The va_list containing the string to reverse.
 * @cnt: The count of characters printed so far.
 *
 * Return: The updated count of characters printed.
 */
int str_rev(va_list lkm, int cnt)
{
	char *string = va_arg(lkm, char *);
	int len = strlen(string);
	int k, f;

	for (k = 0, f = len - 1; k < f; k++, f--)
	{
		char cup = string[k];

		string[k] = string[f];
		string[f] = cup;
		_putchar(cup);
		cnt++;
	}

	return (cnt);
}
