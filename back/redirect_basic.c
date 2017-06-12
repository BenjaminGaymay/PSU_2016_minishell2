/*
** redirect_basic.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Mar 29 17:37:21 2017 Benjamin GAYMAY
** Last update Thu Apr  6 16:53:31 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "back.h"
#include "use_array.h"
#include "minishell2.h"

int	clear_tab(char **tab, int i)
{
  if (tab[i] != NULL)
    tab = delete_line(tab, tab[i]);
  if (tab[i] != NULL)
    tab = delete_line(tab, tab[i--]);
  return (i);
}

int	is_redir(char **new_tab, int *ret, int redir)
{
  int	fail;

  fail = 0;
  if (redir == 0)
    {
      if (check_nb_redirect(new_tab, "<", "<<", 1) != SUCCESS ||
	  check_nb_redirect(new_tab, ">", ">>", 1) != SUCCESS)
	fail = 1;
    }
  else if (redir == 1)
    {
      if (check_nb_redirect(new_tab, ">", ">>", 1) != SUCCESS)
	fail = 1;
    }
  else
    {
      if (check_nb_redirect(new_tab, "<", "<<", 1) != SUCCESS)
	fail = 1;
    }
  if (fail == FAILURE)
    {
      free_array(new_tab);
      return ((*ret = FAILURE));
    }
  return (SUCCESS);
}

int	check_pipe_redir(char **new_tab, int *ret, int pipe_nb, int pipe_max)
{
  if (pipe_nb == 0 && is_redir(new_tab, ret, 1) == FAILURE)
    return (FAILURE);
  else if (pipe_nb == pipe_max && is_redir(new_tab, ret, 2) == FAILURE)
    return (FAILURE);
  else if (pipe_nb != 0 && pipe_nb != pipe_max &&
	   is_redir(new_tab, ret, 0) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int	check_nb_redirect(char **tab, char *s1, char *s2, int ret)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], s1) == 0 || my_strcmp(tab[i], s2) == 0)
	{
	  ++nb;
	  if (tab[i + 1] == NULL || my_strcmp(tab[i + 1], ">>") == 0 ||
	      my_strcmp(tab[i + 1], ">") == 0 ||
	      my_strcmp(tab[i + 1], "|") == 0 ||
	      my_strcmp(tab[i + 1], "<") == 0 ||
	      my_strcmp(tab[i + 1], "<<") == 0)
	    return (my_putstr_failure("Missing name for redirect.\n", 1));
	}
      ++i;
    }
  if (ret == 1 && nb != 0)
    return (my_putstr_failure("Ambiguous output redirect.\n", FAILURE));
  else if (nb <= 1)
    return (SUCCESS);
  return (my_putstr_failure("Ambiguous output redirect.\n", FAILURE));
}
