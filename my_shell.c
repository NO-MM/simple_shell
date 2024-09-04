#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_COMMAND 10
void prompt (char **av, char **env)
{
char *string = NULL;
int i, j, status;
size_t buffer_size = 0;
ssize_t num_char_read;
char *arg[MAX_COMMAND];
char *argv[MAX_COMMAND] = {NULL};
pid_t child_process_id;
while (1)
{
printf ("cisfun$");
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
j = 0;
argv[0] = strtok(string, " ");
while (arg[j])
arg[++j] = strtok (NULL, " ");
child_process_id = fork();
if (child_process_id == -1)
{
perror("Error: Fork issues");
free(string);
exit(EXIT_FAILURE);
}
if (child_process_id == 0)
{
if (execve(argv[0], argv, env) == -1)
{
printf ("%s: No such file or directory \n", av[0]);
free(string);
exit(EXIT_FAILURE);
}
}
else
{
wait (&status);
}
}
}
