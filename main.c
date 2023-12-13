#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * tokensizeInput - function to tokensize input line
 *
 * @lineptr: line pointer
 * @argv: array of strings
 *
 * Return: number of tokens
 */

int tokensizeInput(char *lineptr, char **argv)
{
		const char *dlm = " \n";
		int num_tokens = 0;
		char *token = strtok(lineptr, dlm);
		char *lineptr_cpy = strdup(lineptr);

		if (lineptr_cpy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}

		while (token != NULL)
		{
			argv[num_tokens] = strdup(token);
			if (argv[num_tokens] == NULL)
			{
				perror("memory allocation error");
				free(lineptr_cpy);
				return (-1);
			}
			token = strtok(NULL, dlm);
			num_tokens++;
		}
		argv[num_tokens] = NULL;
		free(lineptr_cpy);

		return (num_tokens);
}

/**
 * main - entry point
 * @ac: arg count
 * @argv: arg vector
 *
 * Return: 0 when success 1 when error
 */

#include "main.h"

int main(int ac, char **argv)
{
	char *prmpt = "(NewShell) $";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	(void)ac;
	while (1)
	{
		char **args;
		int num_tokens;
		int i;

		printf("%s", prmpt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Bye Bye Shell\n");
			break;
		}
		args = malloc(sizeof(char *) * (nchars_read + 1));
		if (args == NULL)
		{
			perror("memory allocation error");
			break;
		}
		num_tokens = tokensizeInput(lineptr, args);
		argv[num_tokens] = NULL;
		if (num_tokens == -1)
		{
			free(lineptr);
			free(args);
			continue;
		}
		execmd(args);
		for (i = 0; i < num_tokens; i++)
		{
			free(args[i]);
		}
	}
	free(lineptr);
	return (0);
}
