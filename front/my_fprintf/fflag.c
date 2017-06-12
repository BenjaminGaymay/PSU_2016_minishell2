/*
** flag.c for flag in /home/benjamin.g/delivery/PSU_2016_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Nov 17 09:37:42 2016 Benjamin GAYMAY
** Last update Mon Mar  6 20:23:38 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my_fprintf.h"

int		my_fplus(va_list ap, char *s, int i)
{
  va_list	aq;

  va_copy(aq, ap);
  if (s[i + 1] == 'i' || s[i + 1] == 'd')
    {
      if (va_arg(aq, int) >= 0)
	my_fputchar_printf('+');
    }
  else if (s[i + 1] == 'p')
    {
      if (va_arg(aq, long int) >= 0)
	my_fputchar_printf('+');
    }
  else
    my_fputstr_printf("%+");
  va_end(aq);
  return (i);
}

int		my_fspace(va_list ap, char *s, int i)
{
  va_list	aq;
  int		f;

  f = i;
  va_copy(aq, ap);
  while (s[f] == ' ' && s[f] != '\0')
    f++;
  if (s[f] == 'i' || s[f] == 'd')
    {
      if (va_arg(aq, int) >= 0)
	my_fputchar_printf(' ');
    }
  else if (s[f] == 'p')
    {
      if (va_arg(aq, int) >= 0)
	my_fputchar_printf(' ');
    }
  f--;
  va_end(aq);
  return (f);
}

int		my_fhash(va_list ap, char *s, int i)
{
  ap = ap;
  if (s[i + 1] == 'x')
    my_fputstr_printf("0x");
  else if (s[i + 1] == 'X')
    my_fputstr_printf("0X");
  else if (s[i + 1] == 'o')
    my_fputchar_printf('0');
  else if (s[i + 1] == 'b')
    my_fputchar_printf('b');
  return (i);
}
