/*
** my_putchar.c for my_putchar in /home/benjamin.g/save_lib
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct 13 08:26:21 2016 Benjamin GAYMAY
** Last update Mon Mar  6 20:24:37 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my_fprintf.h"

void	my_fputchar_printf(char c)
{
  write(2, &c, 1);
}

int	my_fputchar_arg(va_list ap)
{
  my_fputchar_printf(va_arg(ap, int));
  return (0);
}

int	my_faff_modulo_arg(va_list ap)
{
  ap = ap;
  my_fputchar_printf('%');
  return (0);
}

int	my_faff_atsign_arg(va_list ap)
{
  ap = ap;
  my_fputstr_printf("%@");
  return (0);
}
