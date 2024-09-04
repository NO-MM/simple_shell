#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
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
struct dirent *entity;
if (dir == NULL)
return (NULL);
while  ((entity = readdir(dir)) != NULL)
{
temp = entity->d_name;
if (strcmp(temp,str) == 0)
{
cats = malloc(strlen("/bin/") + strlen(str) + 1);
if (cats == NULL)
{
closedir(dir);
return (NULL);
}
strcpy(cats, "/bin/");
strcat(cats, str);
closedir(dir);
return (cats);
}
}
closedir(dir);
return (NULL);
}
