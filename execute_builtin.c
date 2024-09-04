#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
* execute_builtin - A function to check if the inbuilt command exists.
* @str: A string to check for an inbuilt command if present.
*
* Return: 1 if false and 0 if true.
*/
int execute_builtin(char *str)
{
char **arr;
int i = 0;
char *username;
arr = malloc(sizeof(char *) * 4);
if (arr == NULL)
return (0);
arr[0] = "cd";
arr[1] = "exit";
arr[2] = "hello";
arr[3] = NULL;
for (i = 0; i < 3; i++)
{
if (strcmp(arr[i], str) == 0)
{
switch (i)
{
case 0:
{
char *home = getenv("HOME");
if (home == NULL)
{
perror("getenv");
free(arr);
return (0);
}
if (chdir(home) != 0)
{
perror("chdir");
free(arr);
return (0);
}
}
free(arr);
return (1);
case 1: 
printf("bye\n");
free(arr);
return (2);
case 2:
username = getenv("HOSTNAME");
if (username == NULL)
username = "Unknown";
printf("Hello %s\n", username);
free(arr);
return(0);
default:
free(arr);
return (0);
}
}
}
free(arr);
return (0);
}
