/*
** my_printf.c for my_printf in /home/benjamin.g/delivery/PSU_2021_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Nov  7 16:30:28 2016 Benjamin GAYMAY
** Last update Mon Mar  6 20:24:02 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_fprintf.h"

int	(*fptr_funct_type[13])(va_list ap) =
{
  my_fputchar_arg,
  my_fputstr_arg,
  my_fput_nbr_arg,
  my_fput_nbr_arg,
  my_fput_unsigned_int_arg,
  my_fhexa_arg_lower,
  my_fhexa_arg_upper,
  my_foct_arg,
  my_fhexa_pointer_arg,
  my_fputstr_oct_arg,
  my_fbin_arg,
  my_faff_modulo_arg,
  my_faff_atsign_arg
};

int	(*fptr_funct_flag[3])(va_list ap, char *s, int i) =
{
  my_fhash,
  my_fplus,
  my_fspace
};

int		my_fprintf(char *s, ...)
{
  va_list	ap;
  char		flag_list[] = "#+ \0";
  char		type_list[] = "csdiuxXopSb%\0";
  int		i;

  i = 0;
  if (s == 0)
    return (0);
  va_start(ap, s);
  while (s[i] != '\0')
    {
      if (s[i] == '%')
	{
	  i = my_fflag(flag_list, s, i, ap);
	  i = my_ftype(type_list, s, i, ap);
	}
      else
	my_fputchar_printf(s[i]);
      i++;
    }
  va_end(ap);
  return (0);
}

int	my_fflag(char *flag_list, char *s, int i, va_list ap)
{
  int	flag;

  flag = 0;
  while (flag_list[flag] != s[i + 1] && flag < 4)
    flag++;
  if (flag < 3)
    i = fptr_funct_flag[flag](ap, s, i + 1);
  return (i);
}

int	my_ftype(char *type_list, char *s, int i, va_list ap)
{
  int	type;

  type = 0;
  while (type_list[type] != s[i + 1] && type < 14)
    type++;
  if (type < 13)
    {
      fptr_funct_type[type](ap);
      i++;
    }
  return (i);
}
