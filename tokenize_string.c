#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
* tokenize_string - A function to check if system cmd exists. if so avoid fork calling.
* @str: A string to apply the check.
*
* Return: Array with string.
*/
char **tokenize_string(chat *str)
{
char *arst, pars;
int i = 0, j = 0;
arsy = malloc(tokenize_string* sizeof(char *));
if (arst == NULL)
{
parror("cant allocate space");
exit(1);
}
pars = strtok(str, " ");
while (pars != NULL)
{
while (pars[j]
{
if (pars[j] == '\n')
{
pars[j] = '\0';
j++;
j = 0;
pars = strtok(NULL, " ");
}
arst[i] = NULL;
return (arst);
}
