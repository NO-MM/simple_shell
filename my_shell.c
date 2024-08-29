#include "shell.h"
#define MAX_COMMAND 10
void prompt (char **av, char **env)
{
char *string *NULL;
int i,  J, status;
ssize_t buffer_size = 0;
ssize_t num_char_read
char *arg  [MAX_COMMAND];
char *argv[] - (NULL NULL);
pid_t child_process_id

while (1)
{
printf ("cisfun$");
num_char_read = gestline (&string, &buffer_size, stdin);
if (num_char_read == -1)
{
free (string);
exit (EXIT_FAILURE);
}
i = o;
while (string[i])
{
if (string[i] = = '\n')
string[i] = 0;
i++;
}
 j = 0;
argv[0] =  strtok(string, " ");
while (arg[j])
arg[++j] = strtok (NULL, " ");
}
child_pid = fork();
if (child_process_id == -1)
}
free (string);
exit (EXIT_FAILURE);
}
if (child_process_id == 0)
{
if (execve[0], argv, env) == -1)
printf ("%s: No such file or directory \n", av[0]);
}
else
wait (&status);
}
