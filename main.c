#include "shell.h"
/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments passed to the program.
 * @av: An array of strings representing the command-line arguments.
 * @env: An array of strings representing the environment variables.
 *
* Return: 
 * Returns 0 to indicate successful execution of the program.
 */
int main(int ac, char **av, char ** env)
{
if (ac == 1)
prompt (av, env);
return (0);
}
