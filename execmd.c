#include "main.h"

/**
 * execmd - Executes a command with the provided arguments.
 *
 * @argv: array of strings
 */

void execmd(char **argv)
{
	char *cmd = NULL, *act_cmd = NULL;

	if (argv && *argv)
	{
		/*get the command*/
		cmd = argv[0];

		act_cmd = get_location(cmd);

		/*execute the actual command with execve*/
		if (execve(act_cmd, argv, NULL) == -1)
		{
			perror("Error: ");
		}
		else
		{
			printf("command not found: %s\n", argv[0]);
		}
	}
}
