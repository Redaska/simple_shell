#include "main.h"
#include <stdio.h>

/**
 * main - entry point
 * @ac: arg count
 * @argv: arg vector
 *
 * Return: 0 when success 1 when error
 */

int main(int ac, char **argv)
{
	char *prmpt = "(NewShell) $";
	char *lineptr;
	size_t n = 0;

	printf("%s", prmpt);
	getline(&lineptr, &n, stdin);

	free(lineptr);
	return (0);
}
