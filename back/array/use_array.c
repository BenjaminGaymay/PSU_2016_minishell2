/*
** use_array.c for use_array in /home/benjamin.g/delivery/CPE_2016_BSQ
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Dec  6 13:41:33 2016 Benjamin GAYMAY
** Last update Mon Apr  3 15:26:19 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "back.h"
#include "use_array.h"
#include "minishell2.h"

int	count_lines(char *buffer, char separator)
{
  int	i;
  int	nb_line;

  i = 0;
  nb_line = 0;
  while (buffer[i] != '\0')
    if (buffer[i++] == separator)
      nb_line++;
  return (buffer[i] != separator ? nb_line + 1 : nb_line);
}

int		count_columns(char *buffer, char separator)
{
  static int	f = 0;
  int		save_f;
  int		nb_column;

  save_f = f;
  while (buffer[f] != separator && buffer[f] != '\0')
    f++;
  nb_column = f - save_f;
  if (buffer[f] == '\0')
    f = 0;
  else
    f++;
  return (nb_column);
}

void	add_in_array(char **array, char *str, char separator)
{
  int	i;
  int	f;
  int	g;
  int	col;

  i = 0;
  f = 0;
  g = 0;
  while (i < count_lines(str, separator))
    {
      col = count_columns(str, separator);
      while (f < col)
	{
	  array[i][f] = str[g];
	  g++;
	  f++;
	}
      f = 0;
      g++;
      i++;
    }
  array[i] = NULL;
}

char	**create_array(char *str, char separator)
{
  int	i;
  int	columns;
  char	**array;

  if ((str = clear_str(transform_char(str, '\t', ' '), ' ')) == NULL)
    return (NULL);
  array = my_calloc(count_lines(str, separator) + 1, sizeof(char *));
  if (array == NULL)
    return (NULL);
  i = 0;
  while (i < count_lines(str, separator))
    {
      columns = count_columns(str, separator);
      if ((array[i] = my_calloc(columns + 1, sizeof(char))) == NULL)
	return (NULL);
      i++;
    }
  add_in_array(array, str, separator);
  free(str);
  return (array);
}

void	free_array(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      free(array[i]);
      ++i;
    }
  free(array);
}
