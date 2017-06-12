/*
** pipe.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar 31 13:09:21 2017 Benjamin GAYMAY
** Last update Fri Apr  7 12:16:22 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"
#include "back.h"
#include "use_array.h"
#include "minishell2.h"

int	nb_pipe(char **tab)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (tab[++i] != NULL)
    {
      if (my_strcmp(tab[i], "|") == SUCCESS)
	{
	  if (tab[i + 1] == NULL || my_strcmp(tab[i + 1], "|") == 0)
	    return (-1);
	  ++nb;
	}
      else if (my_strcmp(tab[i], "||") == SUCCESS)
	return (-1);
    }
  return (nb);
}

char		**get_pipe_cmd(char **tab, char *separator)
{
  static int	i;
  static int	save;
  int		f;
  char		**new_tab;

  if (i == 0)
    save = tab_len(tab);
  if (i >= save)
    {
      i = 0;
      return (NULL);
    }
  if ((new_tab = my_calloc(save + 1, sizeof(char *))) == NULL)
    return (NULL);
  f = 0;
  while (tab[i] != NULL && my_strcmp(tab[i], separator) != 0)
    new_tab[f++] = my_malloc_strcpy(tab[i++]);
  if (tab[i] != NULL)
    i += 1;
  new_tab[f] = NULL;
  return (new_tab);
}

int	first_pipe(int fdpipe[2], int *last_read, char **envp, char **tab)
{
  int	ret;
  int	pid;
  int	status;

  if (pipe(fdpipe) == -1)
    return (ERROR);
  if ((pid = fork()) < 0)
    return (ERROR);
  if (pid == 0)
    {
      dup2(fdpipe[1], 1);
      close(fdpipe[0]);
      close(fdpipe[1]);
      ret = -1;
      exit(check_exit(envp, tab, ret, &ret));
    }
  else
    wait(&status);
  close(fdpipe[1]);
  *last_read = fdpipe[0];
  free_array(tab);
  return (WEXITSTATUS(status));
}

int	middle_pipe(int fdpipe[2], int *last_read, char **envp, char **tab)
{
  int	ret;
  int	pid;
  int	status;

  if (pipe(fdpipe) == -1)
    return (ERROR);
  if ((pid = fork()) < 0)
    return (ERROR);
  if (pid == 0)
    {
      dup2(*last_read, 0);
      dup2(fdpipe[1], 1);
      close(fdpipe[0]);
      close(fdpipe[1]);
      ret = -1;
      exit(check_exit(envp, tab, ret, &ret));
    }
  else
    wait(&status);
  close(*last_read);
  close(fdpipe[1]);
  *last_read = fdpipe[0];
  free_array(tab);
  return (WEXITSTATUS(status));
}

int	exec_pipe(char **new_envp, char **tab, int my_exit, int *ret)
{
  int	pipe_nb;
  int	last_read;
  int	fdpipe[2];
  char	**new_tab;

  pipe_nb = 0;
  while ((new_tab = get_pipe_cmd(tab, "|")) != NULL)
    {
      if (check_pipe_redir(new_tab, ret, pipe_nb, nb_pipe(tab)) == FAILURE)
	return (my_exit);
      if (pipe_nb == 0)
	*ret = first_pipe(fdpipe, &last_read, new_envp, new_tab);
      else if (pipe_nb == nb_pipe(tab))
	{
	  dup2(last_read, 0);
	  close(last_read);
	  my_exit = check_exit(new_envp, new_tab, my_exit, ret);
	}
      else
	*ret = middle_pipe(fdpipe, &last_read, new_envp, new_tab);
      ++pipe_nb;
    }
  free_array(tab);
  return (my_exit);
}
