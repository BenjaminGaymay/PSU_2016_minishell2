/*
** cd.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Mar 22 13:39:10 2017 Benjamin GAYMAY
** Last update Wed Mar 29 17:29:01 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"
#include "back.h"
#include "my_printf.h"
#include "my_fprintf.h"
#include "minishell2.h"

int	my_putstr_failure(char *str, int ret)
{
  my_fprintf(str);
  return (ret);
}

int		check_is_dir(char *path)
{
  struct stat	file;

  lstat(path, &file);
  if (S_ISDIR(file.st_mode) == 1)
    return (SUCCESS);
  return (FAILURE);
}

int	check_access(char *path, int i)
{
  char	*pwd;

  pwd = NULL;
  if (access(path, F_OK) != 0)
    my_fprintf((i == 0) ? "" : "%s: No such file or directory.\n", path);
  else if (access(path, R_OK) != 0)
    my_fprintf((i == 0) ? "" : "%s: Permission denied.\n", path);
  else if (check_is_dir(path) == FAILURE)
    my_fprintf((i == 0) ? "" : "%s: Not a directory.\n", path);
  else
    {
      chdir(path);
      pwd = getcwd(pwd, 0);
      my_fprintf((isatty(0) == 1 ? "Directory: %s\n" : "\0"), pwd);
      free(pwd);
      return (SUCCESS);
    }
  if (i == 0)
    my_fprintf("cd: Can't change to home directory.\n");
  return (FAILURE);
}

int	my_cd(char **envp, char **tab)
{
  char	*path;

  if (tab[1] == NULL && (path = find_home(envp)) != NULL)
    return (check_access(path, 0));
  else if (tab[1] != NULL && tab[2] != NULL)
    return (my_putstr_failure("cd : Too many arguments.\n", FAILURE));
  else if (tab[1] != NULL && my_strcmp(tab[1], "-") == 0)
    {
      if ((path = find_oldpwd(envp)) == NULL)
	return (my_putstr_failure(": No such file or directory.\n", FAILURE));
      return (check_access(path, 1));
    }
  else if (tab[1] != NULL)
    {
      path = tab[1];
      if (path[my_strlen(path) - 1] == '/')
	path[my_strlen(path) - 1] = '\0';
      return (check_access(path, 1));
    }
  return (FAILURE);
}
