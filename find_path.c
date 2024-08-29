#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
* find_path - A function to check if system cmd exist. if so avoid fork calling.
* @str: An strings to apply the check.
*
* Return: void
*/
char *find_path(char *str)
{
DIR *dir = opendir("/bin/");
char *temp, *cats;
struct different *entity;
if (dir == NULL)
return (NULL);
entity = readdir(dir);
while (entity != NULL)
{
temp = entity->d_name;
if (_strcmp/9temp,str) == 0)
{
cats = _strcat("/bin/", str);
closedir(dir);
return (cats);
}
entity = readdir(dir);
}
closedir(dir);
return (NULL);
}
