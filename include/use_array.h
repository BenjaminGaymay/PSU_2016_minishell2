/*
** use_array.h for use_array in /home/benjamin.g
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Jan 19 17:52:12 2017 Benjamin GAYMAY
** Last update Fri Mar 31 15:23:39 2017 Benjamin GAYMAY
*/

#ifndef USE_ARRAY_H_
# define USE_ARRAY_H_

void	free_array(char **);
int	tab_len(char **);
int	my_showtab(char **);
int	count_lines(char *, char);
int	count_columns(char *, char);
void	add_in_array(char **, char *, char);
char	**copy_array(const char **);
char	**create_array(char *, char);

#endif /* !USE_ARRAY_H_ */
