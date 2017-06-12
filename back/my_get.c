/*
** my_get.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2/back
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 21 19:04:51 2017 Benjamin GAYMAY
** Last update Sat Apr  8 12:13:05 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>

char		**my_get_env(char **envp, const int i)
{
  static char	**save_envp;

  if (i == 0)
    {
      if (save_envp != NULL)
	free(save_envp);
      save_envp = envp;
    }
  else
    return (save_envp);
  return (NULL);
}

int		*my_dup(int save_it)
{
  static int	save[2];

  if (save_it == 1)
    {
      save[0] = dup(0);
      save[1] = dup(1);
    }
  else
    {
      dup2(save[0], 0);
      dup2(save[1], 1);
    }
  return (save);
}
