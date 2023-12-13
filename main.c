#include "main.h"
#include <stdio.h>
#include <string.h>

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
	char *lineptr = NULL, *lineptr_cpy = NULL;
	char *token;
	const char *dlm = " \n";
	size_t n = 0;
	ssize_t nchars_read;
	int num_tokens = 0;
	int i;

	/* declaring void variables for no error*/
	(void)ac;
	/*create infinite loop*/
	while (1)
	{
		printf("%s", prmpt);
		nchars_read = getline(&lineptr, &n, stdin);
		/* check the getline function*/
		if (nchars_read == -1)
		{
			printf("Bye Bye Shell\n");
			return (-1);
		}
		/*allocate space for a copy of the lineptr */
		lineptr_cpy = malloc(sizeof(char) * nchars_read);
		if (lineptr_cpy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		/*copy lineptr*/
		strcpy(lineptr_cpy, lineptr);

		token = strtok(lineptr, dlm);

		while (token != NULL){
			num_tokens++;
			token = strtok(NULL, dlm);
		}
		num_tokens++;

		/* Allocate space to hold the array */
		argv = malloc(sizeof(char *) * num_tokens);

		/*Store each token in the argv array*/
		token = strtok(lineptr_cpy, dlm);
		
		for(i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, dlm);
		}
		argv[i] = NULL;
		/*execute command*/
		execmd(argv);
	}
	free(lineptr);
	free(lineptr_cpy);

	return (0);
}
