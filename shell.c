#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
* main - The main function that builds the shell.
* @argc: The number of arguments.
* @argv: An array of arguments.
* @envp: An array of environment variables.
* Return: Always 0.
*/
int main(int argc, char *argv[], char *envp[])
{
char **string = NULL;
size_t buffer_size = 20, imbt = 0, pt = 4;
ssize_t num_char_read;
char *ptr = NULL, *nc = NULL;
if (argc > 1)
argv[1] = NULL;
while (1)
{
if (isatty(STDIN_FILENO))
printf("#cisfun$ ");
ptr = malloc(buffer_size * sizeof(char));
if (ptr == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
num_char_read = getline(&ptr, &buffer_size, stdin);
if (num_char_read == -1)
{
free(ptr);
exit(EXIT_FAILURE);
}
if (*ptr != '\n')
{
string = strtok(ptr, "\t\n");
if (strcmp("exit", string) == 0)
break;
imbt = execute_builtin(string);
nc = find_path(string);
if (imbt == 0 && nc != NULL)
string = nc;
pt = find_bin_path(string);
if (pt == 1)
forkexe(string, envp);
if (nc == NULL && pt == 0 && imbt == 0)
printf("./shell: No such file or directory\n");
}
}
free(nc);
free(ptr);
free(string);
exit(0);
}
