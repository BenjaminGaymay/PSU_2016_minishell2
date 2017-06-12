/*
** my_calloc.c for my_calloc in /home/benjamin.g
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar 17 08:26:29 2017 Benjamin GAYMAY
** Last update Tue Mar 21 19:59:02 2017 Benjamin GAYMAY
*/

#include <stdlib.h>

void	*my_memset(void *var, const int val, const size_t size, size_t nb)
{
  int	i;

  i = -1;
  while (nb--)
    ((char *)var)[++i * size] = val;
  return (var);
}

void	*my_calloc(const size_t nb, const size_t size)
{
  void	*ptr;

  if ((ptr = malloc(nb * size)) == NULL)
    return (NULL);
  ptr = my_memset(ptr, 0, size, nb);
  return (ptr);
}
