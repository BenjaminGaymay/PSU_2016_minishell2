/*
** parent.c<PSU_2016_minishell2> for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar 24 10:24:34 2017 Benjamin GAYMAY
** Last update Fri Apr  7 17:10:34 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"
#include "back.h"
#include "my_printf.h"
#include "use_array.h"
#include "my_fprintf.h"
#include "minishell2.h"

static char	*free_return(char *command, char **path)
{
  free(command);
  free_array(path);
  return (NULL);
}

static char	*check_access(char *command, char **tab, char **path)
{
  if (access(command, F_OK) != 0)
    {
      my_fprintf("%s: Command not found.\n", tab[0]);
      return (free_return(command, path));
    }
  else if (tab[0][0] != '\0' &&
	   (access(command, X_OK) != 0 || check_is_dir(command) == SUCCESS))
    {
      my_fprintf("%s: Permission denied.\n", tab[0]);
      return (free_return(command, path));
    }
  if ((access(command, F_OK) != 0) || (access(command, X_OK) != 0))
    return (free_return(command, path));
  return (command);
}

static char	*search_path(char **path, char **tab)
{
  char		*command;
  int		i;

  i = 1;
  command = my_malloc_strcpy(tab[0]);
  if (my_strncmp(tab[0], "./", 2) != 0 && my_strncmp(tab[0], "../", 3) != 0)
    {
      free(command);
      command = my_malloc_strcat(path[0], tab[0]);
      while (access(command, F_OK) != 0 && path[i] != NULL)
	{
	  free(command);
	  command = my_malloc_strcat(path[i], tab[0]);
	  i++;
	}
    }
  if (access(command, F_OK) != 0)
    {
      free(command);
      command = my_malloc_strcpy(tab[0]);
    }
  return (check_access(command, tab, path));
}

int	put_error(int status, char *command)
{
  int	ret;

  if (status == SEGFAULT || status == 11)
    ret = my_putstr_failure("Segmentation fault", SEGFAULT);
  else if (status == FLOATING || status == 8)
    ret = my_putstr_failure("Floating exception", FLOATING);
  else if (status == ABORT || status == 9)
    ret = my_putstr_failure("Abort", ABORT);
  else if (WEXITSTATUS(status) == 255)
    {
      my_fprintf("%s: Exec format error. ", command);
      return (my_putstr_failure("Binary file not executable.\n", 1));
    }
  else
    return (SUCCESS);
  if (WCOREDUMP(status))
    my_fprintf(" (core dumped)");
  my_fprintf("\n");
  return (ret);
}

int	parent(char **envp, char **tab)
{
  pid_t	child_pid;
  char	**path;
  char	*command;

  if (my_strcmp(tab[0], "\0") == 0)
    return (SUCCESS);
  path = create_path(envp);
  if ((command = search_path(path, tab)) == NULL)
    return (FAILURE);
  free_array(path);
  if ((child_pid = fork()) == -1)
    return (ERROR);
  if (child_pid != 0)
    return (father(command, tab));
  else
    child(envp, command, tab);
}
