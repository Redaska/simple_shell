#include "main.h"
#include <stdio.h>
#include <unistd.h>

void execmd(char **argv)
{
    char *command = NULL, *actl_cmd = NULL;

    if(argv)
    {
        command = argv[0];

        actl_cmd = get_location(command);

        /* execute the actual command with execve */
        if (execve(actl_cmd, argv, NULL) == -1)
        {
            perror("Error: ");
        }
    }
}