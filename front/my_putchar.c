/*
** my_putchar.c for my_putchar in /home/benjamin.g/save_lib
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Oct 13 08:26:21 2016 Benjamin GAYMAY
** Last update Thu Jan 19 18:03:20 2017 Benjamin GAYMAY
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
