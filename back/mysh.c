/*
** mysh.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 21 20:04:59 2017 Benjamin GAYMAY
** Last update Thu Apr  6 15:58:23 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "back.h"
#include "use_array.h"
#include "my_fprintf.h"
#include "minishell2.h"

static int	check_tab0(char **envp, char **tab, int *ret)
{
  char		*pwd;

  pwd = NULL;
  if (my_strcmp(tab[0], "env") == 0)
    *ret = my_showtab(envp);
  else if (my_strcmp(tab[0], "cd") == 0)
    {
      pwd = getcwd(pwd, 0);
      if ((*ret = my_cd(envp, tab)) == 0)
	my_setenv(envp, "OLDPWD", pwd);
      free(pwd);
    }
  else if (my_strcmp(tab[0], "setenv") == 0)
    {
      *ret = FAILURE;
      if (tab[2] != NULL && tab[3] != NULL)
	my_fprintf("setenv: Too many arguments.\n");
      else
	*ret = my_setenv(envp, tab[1], tab[2]);
    }
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    *ret = my_unsetenv(envp, tab);
  else
    *ret = parent(envp, tab);
  return (SUCCESS);
}

static char	**get_cmd(char *command, char separator)
{
  static int	i;
  static int	save;
  int		f;
  char		*cmd;
  char		**tab;

  f = 0;
  if (i == 0)
    save = my_strlen(command);
  if (i >= save)
    {
      i = 0;
      return (NULL);
    }
  if ((cmd = my_calloc(my_strlen(command) + 1, sizeof(char))) == NULL)
    return (NULL);
  while (command[i] != '\0' && command[i] != separator)
    cmd[f++] = command[i++];
  if (command[i] != '\0')
    i += 1;
  if ((tab = create_array(cmd, ' ')) == NULL)
    return (NULL);
  return (tab);
}

int	check_exit(char **new_envp, char **tab, int my_var_exit, int *ret)
{
  if (check_redirect(tab, ret) == SUCCESS)
    {
      new_envp = my_get_env(NULL, 1);
      if (my_strcmp(tab[0], "exit") == SUCCESS)
	{
	  if ((*ret = my_exit(tab)) == SUCCESS)
	    {
	      *ret = (tab[1] == NULL ? SUCCESS : my_getnbr(tab[1]));
	      my_var_exit = *ret;
	    }
	}
      else
	if (check_tab0(new_envp, tab, ret) == ERROR)
	  {
	    *ret = ERROR;
	    return (ERROR);
	  }
    }
  free_array(tab);
  return (my_var_exit);
}

int	check_my_tab(char **new_envp, char **tab, int my_exit, int *ret)
{
  my_dup(1);
  if (nb_pipe(tab) == 0)
    my_exit = check_exit(new_envp, tab, my_exit, ret);
  else if (nb_pipe(tab) != -1)
    my_exit = exec_pipe(new_envp, tab, my_exit, ret);
  else
    {
      *ret = 1;
      if (is_redir(tab, ret, 0) == SUCCESS)
	my_fprintf("Invalid null command.\n");
    }
  my_dup(0);
  return (my_exit);
}

int	start_mysh(char **new_envp)
{
  int	ret;
  int	my_exit;
  char	*command_list;
  char	*command;
  char	**tab;

  ret = 0;
  my_exit = -1;
  while (my_exit == -1)
    {
      if ((command_list = prompt()) == NULL)
	return (ret);
      if ((command = super_str(command_list)) == NULL)
	return (ERROR);
      while ((tab = get_cmd(command, ';')) != NULL)
	my_exit = check_my_tab(new_envp, tab, my_exit, &ret);
      free(command);
    }
  my_putstr(isatty(0) == 1 ? "exit\n" : "\0");
  return (ret);
}
