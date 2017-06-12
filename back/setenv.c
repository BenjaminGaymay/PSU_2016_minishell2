/*
** setenv.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Mar 22 13:39:55 2017 Benjamin GAYMAY
** Last update Wed Mar 29 16:24:42 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "back.h"
#include "use_array.h"
#include "my_fprintf.h"
#include "minishell2.h"

int	put_newtab(char **envp, char **new_envp, char *new_str, char *s2)
{
  int	i;
  int	found;

  i = 0;
  found = 0;
  while (envp[i] != NULL)
    {
      if ((my_strncmp(new_str, envp[i], my_strlen(new_str)) != 0) ||
	  (found == 1))
	new_envp[i] = envp[i];
      else
	{
	  found = 1;
	  free(envp[i]);
	  new_envp[i] = my_malloc_strcat(new_str, s2);
	}
      ++i;
    }
  return (found);
}

int	check_setenv_error(char *s1)
{
  int	i;

  i = 0;
  if ((s1[0] < 'A') || (s1[0] > 'Z' && s1[0] < 'a') || (s1[0] > 'z'))
    {
      my_fprintf("setenv: Variable name must begin whith a letter.\n");
      return (FAILURE);
    }
  while (s1[i] != '\0')
    {
      if ((s1[i] < '0') ||
	  (s1[i] > '9' && s1[i] < 'A') ||
	  (s1[i] > 'Z' && s1[i] < 'a') ||
	  (s1[i] > 'z'))
	{
	  my_fprintf("setenv: Variable name must contain");
	  my_fprintf(" alphanumeric characters.\n");
	  return (FAILURE);
	}
      i++;
    }
  return (SUCCESS);
}

int	my_setenv(char **envp, char *s1, char *s2)
{
  char	**new_envp;
  char	*new_str;
  int	i;

  if (s1 != NULL)
    {
      i = 0;
      if (check_setenv_error(s1) == FAILURE)
	return (FAILURE);
      new_str = my_malloc_strcat(s1, "=");
      while (envp[i] != NULL)
	i++;
      if ((new_envp = my_calloc(i + 2, sizeof(char *))) == NULL)
	return (ERROR);
      if ((put_newtab(envp, new_envp, new_str, (s2 == NULL ? "\0" : s2))) == 0)
	new_envp[i++] = my_malloc_strcat(new_str, (s2 == NULL ? "\0" : s2));
      new_envp[i] = NULL;
      free(new_str);
      my_get_env(new_envp, 0);
    }
  else
    my_showtab(envp);
  return (SUCCESS);
}

char	**delete_line(char **envp, char *tmp)
{
  int	f;

  f = 0;
  while (envp[f] != NULL &&
	 my_strncmp(tmp, envp[f], my_strlen(tmp) - 1) != 0)
    f++;
  if (envp[f] != NULL)
    free(envp[f]);
  while (envp[f] != NULL)
    {
      envp[f] = envp[f + 1];
      ++f;
    }
  return (envp);
}

int	my_unsetenv(char **envp, char **tab)
{
  char	*tmp;
  int	i;

  if (tab[1] == NULL)
    my_fprintf("unsetenv: Too few arguments.\n");
  else
    {
      i = 1;
      while (tab[i] != NULL)
	{
	  tmp = my_malloc_strcat(tab[i], "=");
	  envp = delete_line(envp, tmp);
	  free(tmp);
	  i++;
	}
      return (SUCCESS);
    }
  return (FAILURE);
}
