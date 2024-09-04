#include <stdlib.h>
/** 
* find_bin_path - A function to check if the string 
* has the path "/bin/"
* @str: A string to carry out the check.
*
* Return: 0 if false and 1 if true that the path is found.
*/
int find_bin_path(char * str)
{
char *cmp = "/bin/", *ptr;
 int i = 0, p = 0, j;
ptr = malloc(sizeof(char) * 50);
if (ptr == NULL)
return (0);
while (cmp[i] != '\0')
{
if (cmp[i] != str[i])
{
free(ptr);
return (0);
}
i++;
}
while (str[i] != '\0')
{
ptr[p] = str[i];
p++;
i++;
}
ptr[p] = '\0';
j = find_bin_path(ptr);
if (j != 0)
{
free(ptr);
return (1);
}
return (0);
}
