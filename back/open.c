/*
** open.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Apr  3 14:20:06 2017 Benjamin GAYMAY
** Last update Tue Apr  4 13:51:14 2017 Benjamin GAYMAY
*/

#include <fcntl.h>

int	my_open_safe(mode_t flags, char *path)
{
  int	fd;

  if ((fd = open(path, flags, 0644)) == -1)
    return (-1);
  return (fd);
}
