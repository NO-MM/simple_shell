
#ifndef SHELL_H
#define SHELL_H
#include  <stdio.h>
#include <unistd.h>
void prompt(char **av, char ** env);
int main(int ac, char **av, char ** env);
int main(int arg, char *argv[], char *envp[]);
void forkexe(char **arstr, char *envp[]);
char *find_path(char *str);
char **tokenize_string(char *str);
int find_bin_path(char *str);
int execute_builtin(char *str);
#endif
