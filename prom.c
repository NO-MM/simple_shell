#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * prompt - This function displays a shell prompt, reads a command 
 * from user input, and executes it.
 * @av: An array of command-line arguments passed to the program.
 * @env: An array of environment variables.
 */
void prompt (char **av, char **env_vars)
{
char *string = NULL;
int i, status;
size_t buffer_size = 0;
ssize_t num_char_read;
char *argv[] = {NULL, NULL};
pid_t child_process_id;
while (1)
{
printf ("cisfun$ ");
num_char_read = getline(&string, &buffer_size, stdin);
if (num_char_read == -1)
{
free(string);
exit(EXIT_FAILURE);
}
i = 0;
while (string[i])
{
if (string[i] == '\n')
string[i] = 0;
i++;
}
argv[0] = string;
child_process_id = fork();
if (child_process_id == -1)
{
free(string);
exit(EXIT_FAILURE);
}
if (child_process_id == 0)
{
if (execve(argv[0], argv, env_vars) == -1)
printf ("%s: No such file or directory \n", av[0]);
}
else
{
wait(&status);
}
}
}
