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
arr = malloc(sizeof(char *) * 3);
if (arr == NULL)
return (0);
arr[0] = "cd";
arr[1] = "exit";
arr[2] = "hello";
for (i =0; i < 3; i++)
{
if (strcmp(arr[i], str) == 0)
{
break;
}
i++;
switch (i)
{
case 1:
chdir(str);
free(arr);
return (1);
case 2: 
printf("bye");
free(arr);
return (2);
case 3:
username = getenv("HOSTNAME");
printf("Hello %s\n", username);
free(arr);
return(0);
}
