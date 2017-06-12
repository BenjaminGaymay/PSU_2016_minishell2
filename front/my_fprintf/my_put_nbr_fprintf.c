/*
** my_put_nbr.c for my_put_nbr in /home/benjamin.g/delivery/CPool_Day03
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 09:04:03 2016 Benjamin GAYMAY
** Last update Tue Jan 24 23:31:33 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_fprintf.h"

int	my_fput_nbr_printf(int n)
{
  if (n < 0)
    {
      my_fputchar_printf('-');
      n = (n * (-1));
    }
  if ((n >= 0) && (n <= 9))
    my_fputchar_printf(n + '0');
  if (n > 9)
    {
      my_fput_nbr_printf(n / 10);
      my_fput_nbr_printf(n % 10);
    }
  return (0);
}

int	my_fput_nbr_arg(va_list ap)
{
  my_fput_nbr_printf(va_arg(ap, int));
  return (0);
}

int	my_fput_nbr_base(int n, int base, int lower_or_upper)
{
  if (n < 0)
    {
      my_fput_nbr_base_unsigned(n, base, lower_or_upper);
      return (0);
    }
  if ((n >= 0) && (n < base))
    {
      if (base > 10)
	{
	  if (n > 9)
	    my_fputchar_printf(n + lower_or_upper);
	  else
	    my_fputchar_printf(n + '0');
	}
      else
	my_fputchar_printf(n + '0');
    }
  if (n > base - 1)
    {
      my_fput_nbr_base(n / base, base, lower_or_upper);
      my_fput_nbr_base(n % base, base, lower_or_upper);
    }
  return (0);
}
