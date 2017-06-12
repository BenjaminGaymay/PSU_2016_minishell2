/*
** my_strncmp.c for my_strncmp in /home/benjamin.g/delivery/CPool_Day06
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Oct 10 19:45:53 2016 Benjamin GAYMAY
** Last update Thu Jan 19 18:19:55 2017 Benjamin GAYMAY
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((i < n - 1) && (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}
