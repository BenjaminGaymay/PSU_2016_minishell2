/*
** hexa_oct.c for hexa_oct in /home/benjamin.g/delivery/PSU_2016_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Wed Nov  9 09:12:20 2016 Benjamin GAYMAY
** Last update Mon Feb 27 12:50:03 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_fprintf.h"

void	my_fhexa(int num, int lower_or_upper)
{
  my_fput_nbr_base(num, 16, lower_or_upper);
}

int	my_fhexa_arg_upper(va_list ap)
{
  my_fhexa(va_arg(ap, int), 55);
  return (0);
}

int	my_fhexa_arg_lower(va_list ap)
{
  my_fhexa(va_arg(ap, int), 87);
  return (0);
}

void	my_fhexa_pointer(long int num)
{
  char	*hex_result;
  int	tmp;
  int	i;

  hex_result = malloc(sizeof(char) * (my_fintlen(num) + 1));
  if (hex_result == NULL)
    return;
  i = 0;
  if (num == 0)
    my_fputstr_printf("(nil)");
  else
    my_fputstr_printf("0x");
  while (num > 0)
    {
      tmp = num % 16;
      if (tmp > 9)
	tmp += 87;
      else
	tmp += '0';
      hex_result[i] = tmp;
      num /= 16;
      i++;
    }
  my_fputstr_printf(my_frevstr_printf(hex_result));
  free(hex_result);
}

int	my_fhexa_pointer_arg(va_list ap)
{
  my_fhexa_pointer(va_arg(ap, long int));
  return (0);
}
