/*
** my_putstr.c for my_putstr in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 15:28:00 2016 Benjamin GAYMAY
** Last update Tue Jan 24 23:04:11 2017 Benjamin GAYMAY
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

char	*my_revstr_printf(char *str)
{
  int	i;
  int	f;
  int	tmp;

  i = 0;
  while (str[i] != '\0')
    i++;
  i--;
  f = 0;
  tmp = 0;
  while (i > f)
    {
      tmp = str[f];
      str[f] = str[i];
      str[i] = tmp;
      i--;
      f++;
    }
  return (str);
}

int	my_putstr_printf(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  write(1, str, i);
  return (0);
}

int	my_putstr_arg(va_list ap)
{
  my_putstr_printf(va_arg(ap, char *));
  return (0);
}

void	my_putstr_oct(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    str = "(null)";
  while (str[i] != '\0')
    {
      if ((str[i] < ' ') || (str[i] >= 127))
	{
	  my_putchar_printf('\\');
	  my_oct(str[i]);
	}
      else
	my_putchar_printf(str[i]);
      i++;
    }
}

int	my_putstr_oct_arg(va_list ap)
{
  my_putstr_oct(va_arg(ap, char *));
  return (0);
}
