/*
** my_strstr.c for my_strstr in /home/benjamin.g/delivery/CPool_Day06
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Oct 10 12:32:01 2016 Benjamin GAYMAY
** Last update Mon Mar 27 11:57:34 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"

static int	my_count_i(char *str, char *to_find)
{
  int		i;

  i = 0;
  while (str[i] != to_find[0] && str[i] != '\0')
    i++;
  return (i);
}

int	my_strstr(char *str, char *to_find)
{
  int	i;
  int	f;

  f = 0;
  i = my_count_i(str, to_find);
  while (str[i] != '\0')
    {
      while (to_find[f] == str[i] && to_find[f] != '\0')
	{
	  i++;
	  f++;
	}
      if (f == my_strlen(to_find))
	{
	  while (str[i++] != '\0')
	    {
	      to_find[f] = str[i];
	      f++;
	    }
	  return (i);
	}
      else
	i++;
    }
  return (-1);
}
