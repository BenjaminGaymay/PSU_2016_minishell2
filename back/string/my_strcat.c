/*
** my_strcat.c for strcat in /home/benjamin.g/delivery/CPool_Day07/lib/my
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Oct 11 13:10:25 2016 Benjamin GAYMAY
** Last update Thu Jan 19 18:10:58 2017 Benjamin GAYMAY
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	f;

  i = 0;
  f = 0;
  while (dest[i] != '\0')
    i++;
  while (src[f] != '\0')
    {
      dest[i] = src[f];
      i++;
      f++;
    }
  dest[i] = '\0';
  return (dest);
}
