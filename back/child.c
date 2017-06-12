/*
** child.c<PSU_2016_minishell2> for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar 24 10:25:05 2017 Benjamin GAYMAY
** Last update Tue Apr  4 15:40:18 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell2.h"

int	child(char **envp, char *command, char **tab)
{
  execve(command, tab, envp);
  exit(255);
}

int	father(char *command, char **tab)
{
  int	status;
  int	error;

  status = 0;
  wait(&status);
  free(command);
  if ((error = put_error(status, tab[0])) != SUCCESS)
    return (error);
  else
    return (WEXITSTATUS(status));
}
