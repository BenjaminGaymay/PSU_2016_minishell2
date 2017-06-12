/*
** chained_list.h for chained_list in /home/benjamin.g/save/test
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 24 19:05:21 2017 Benjamin GAYMAY
** Last update Wed Mar 29 12:55:34 2017 Benjamin GAYMAY
*/

#ifndef CHAINED_LIST_H_
# define CHAINED_LIST_H_

typedef struct		s_list
{
  void			*my_struct;

  struct s_list		*next;
}			t_list;

int	my_put_in_list(t_list **, void *);
void	my_show_list(t_list *, int);
int	my_len_list(t_list *);

#endif /* !CHAINED_LIST_H_ */
