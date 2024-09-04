#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
* forkexe - The system execution with a fork.
* @arstr: An array of strings is gotten from the line command.
* @envp: The environment variables from parent.
*
* Return: void
*/
void forkexe(char **arstr, char *envp[])
{
pid_t child_process_id;
 int status;
child_process_id = fork();
if (child_process_id < 0)
{
perror("Error: Fork issues");
return;
}
if (child_process_id == 0)
{
if (execve(arstr[0], arstr, envp) == -1)
perror("./shell: No such file or directory\n");
}
else
{
wait(&status);
}
}
