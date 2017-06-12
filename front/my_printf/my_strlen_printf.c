/*
** my_strlen.c for my_strlen in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 16:36:00 2016 Benjamin GAYMAY
** Last update Wed Jan  4 14:11:59 2017 Benjamin GAYMAY
*/

#include "my_printf.h"

int	my_intlen(int nb)
{
  int	i;

  i = 0;
  while (nb != 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}
