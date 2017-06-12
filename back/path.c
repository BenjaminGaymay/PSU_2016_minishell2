/*
** path.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Mar 22 14:03:34 2017 Benjamin GAYMAY
** Last update Wed Mar 29 16:18:19 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "back.h"
#include "use_array.h"
#include "my_fprintf.h"

char	*find_path(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "PATH=", 5) == 0)
	return (&envp[i][5]);
      i++;
    }
  return ("\0");
}

char	**create_path(char **envp)
{
  int	i;
  char	*str;
  char	*tmp;
  char	**path;

  if ((str = my_malloc_strcpy(find_path(envp))) == NULL)
    return (NULL);
  if ((path = create_array(str, ':')) == NULL)
    return (NULL);
  i = 0;
  while (path[i] != NULL)
    {
      if ((path[i] = my_add_slash(path[i])) == NULL)
	return (NULL);
      ++i;
    }
  return (path);
}

char	*find_home(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "HOME=", 5) == 0)
	return (&envp[i][5]);
      i++;
    }
  my_fprintf("cd: No home directory.\n");
  return (NULL);
}

char	*find_oldpwd(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "OLDPWD=", 7) == 0)
	return (&envp[i][7]);
      i++;
    }
  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "PWD=", 4) == 0)
	return (&envp[i][4]);
      i++;
    }
  return (NULL);
}
