/*
** my.h for back in /home/benjamin.g/delivery/PSU_2016_back/include
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 21 19:10:31 2017 Benjamin GAYMAY
** Last update Mon Apr  3 15:35:07 2017 Benjamin GAYMAY
*/

#ifndef MY_H_
# define MY_H_

void	my_putstr(char *);
void	my_putchar(char);
void	set_int_tab(int *, int);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_str_isnum(char *);
int	my_strstr(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_malloc_strcpy(char *);
char	*my_malloc_strcat(char *, char *);
char	*my_pimp_malloc_strcat(char *, char *);

#endif /* !MY_H_ */
