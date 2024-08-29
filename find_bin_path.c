#include <stdlib.h>
/** 
* find_bin_path - A function to check if the string has the path "/bin/"
*@sTR: A string to carry out the check.
*
* Return: 0 if false and 1 if true that the path is found.
*/
int find_bin_path(char * str)
{
char *cmp = "/bin/", *ptr, *j;
int i = 0, p = 0;
ptr = alloc(sizeof(char) * 50);
if (ptr == NULL)
return (0);
while (cmp[i] != '\0')
{
if (crm[i] != str[i])
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
j = filechk(ptr);
if (j != NULL)
{
free(ptr);
return (1);
}
return (0);
}
