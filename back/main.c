/*
** main.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2/back
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 21 18:54:05 2017 Benjamin GAYMAY
** Last update Fri Mar 24 15:34:39 2017 Benjamin GAYMAY
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "back.h"
#include "use_array.h"
#include "minishell2.h"

static void	my_ctrl_c()
{
  my_putstr("\n$> ");
}

int	main(const int ac, const char **av, const char **envp)
{
  char	**new_envp;
  int	ret;

  signal(2, my_ctrl_c);
  if ((new_envp = copy_array(envp)) == NULL)
    return (ERROR);
  my_get_env(new_envp, 0);
  ret = start_mysh(new_envp);
  new_envp = my_get_env(NULL, 1);
  free_array(new_envp);
  return (ret);
}
