#include "main.h"

/**
 * _print_char - is a Custom function that print
 * character.
 * @lkm: is a va_list that contains the character
 * argument that need to be printed.
 * @cnt: Count the number of characters.
 *
 * Return: Counter value.
 */

int _print_char(va_list lkm, int cnt)
{
	char c;

	c = va_arg(lkm, int);
	__putchar(c);
	cnt++;

	return (cnt);
}
