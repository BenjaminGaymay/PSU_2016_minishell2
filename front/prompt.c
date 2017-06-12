/*
** prompt.c for minishell2 in /home/benjamin.g/delivery/PSU_2016_minishell2
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 21 20:06:35 2017 Benjamin GAYMAY
** Last update Sat Apr  1 15:35:38 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "minishell2.h"
#include "get_next_line.h"

char	*prompt()
{
  char	*command_list;

  if (isatty(0) == 1)
    my_printf("$> ");
  if ((command_list = get_next_line(0)) == NULL)
    {
      my_putstr(isatty(0) == 1 ? "exit\n" : "\0");
      return (NULL);
    }
  return (command_list);
}
