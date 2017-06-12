/*
** my_strlen.c for my_strlen in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 16:36:00 2016 Benjamin GAYMAY
** Last update Tue Jan 24 23:19:55 2017 Benjamin GAYMAY
*/

#include "my_fprintf.h"

int	my_fintlen(int nb)
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
