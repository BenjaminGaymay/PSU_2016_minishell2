/*
** octal_bin.c for octal_bin in /home/benjamin.g/delivery/PSU_2016_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Nov 17 13:10:37 2016 Benjamin GAYMAY
** Last update Tue Jan 24 23:31:54 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_fprintf.h"

int	my_foct_arg(va_list ap)
{
  my_fput_nbr_base(va_arg(ap, int), 8, 0);
  return (0);
}

int	my_fbin_arg(va_list ap)
{
  my_fput_nbr_base(va_arg(ap, int), 2, 0);
  return (0);
}

void	my_foct(int num)
{
  char	oct_result[] = "000";
  int	i;

  i = 2;
  while (num > 0)
    {
      oct_result[i] = (num % 8) + '0';
      num /= 8;
      i--;
    }
  my_fputstr_printf(oct_result);
}
