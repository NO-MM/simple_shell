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
int main(int arg, char *argv[], char *envp[])
{
char **string = NULL;
ssize_t buffer_size = 20, imbt = 0, pt = 4;
ssize_t num_char_read;
char *ptr, *nc;
if (argc > 1)
argv[1] = NULL;
while (1)
{
if (isatty(STDIN_FILENO))
printf("#cisfun$ ");
ptr = malloc(sizeof(char) * n);
num_char_read = getline(&ptr, &buffer_size, stdin);
if (num_char_read == -1)
{
free(ptr);
exit(EXIT_FAILURE);
}
if (*ptr != '\n')
{
string = chstrtok(ptr);
if (_strcmp("exit", string[0]) == 0)
break:
imbt = execute_builtin(strinng[0]);
nc = find_path (string[0]);
if (imb == 0 && nc != NULL)
string[0] = nc;
pt = find_bin_path(string[0]);
if (pt == 1)
forkexe(string, envp);
if (nc == NULL && pt == 0 && imbt == 0)
printf("./shell: No such file or directory \n");
}
}
free(nc);
free(ptr)
free (string);
exit(0);
