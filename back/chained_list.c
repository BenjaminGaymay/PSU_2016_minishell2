/*
** chained_list.c for chained_list in /home/benjamin.g/save/test
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 24 19:01:02 2017 Benjamin GAYMAY
** Last update Fri Apr  7 17:28:00 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "chained_list.h"

int		my_put_in_list(t_list **list, void *my_struct)
{
  t_list	*element;

  if ((element = malloc(sizeof(*element))) == NULL)
    return (84);
  element->my_struct = my_struct;
  element->next = *list;
  *list = element;
  return (0);
}

void		my_show_list(t_list *list, int fd)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  while (tmp != NULL)
    {
      i = -1;
      while (((char *)tmp->my_struct)[++i] != '\0');
      write(fd, tmp->my_struct, i);
      write(fd, "\n", 1);
      tmp = tmp->next;
    }
}

int		my_len_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
