/*
** my_putchar.c for my_putchar in /home/benjamin.g/save_lib
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct 13 08:26:21 2016 Benjamin GAYMAY
** Last update Mon Mar  6 20:28:19 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my_printf.h"

void	my_putchar_printf(char c)
{
  write(1, &c, 1);
}

int	my_putchar_arg(va_list ap)
{
  ap = ap;
  my_putchar_printf(va_arg(ap, int));
  return (0);
}

int	my_aff_modulo_arg(va_list ap)
{
  ap = ap;
  my_putchar_printf('%');
  return (0);
}

int	my_aff_atsign_arg(va_list ap)
{
  ap = ap;
  my_putstr_printf("%@");
  return (0);
}
