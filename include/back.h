/*
** back.h for back in /home/benjamin.g/delivery/PSU_2016_back/include
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 21 19:10:31 2017 Benjamin GAYMAY
** Last update Fri Apr  7 12:19:20 2017 Benjamin GAYMAY
*/

#ifndef BACK_H_
# define BACK_H_

# define ABORT    134
# define FLOATING 136
# define SEGFAULT 139

#include <fcntl.h>

int	nb_pipe(char **);
int	start_mysh(char **);
int	check_is_dir(char *);
int	clear_tab(char **, int);
int	is_redir(char **, int*, int);
int	my_cd(char **, char **);
int	parent(char **, char **);
int	my_open_safe(mode_t, char *);
int	my_unsetenv(char **, char **);
int	check_redirect(char **, int *);
int	my_putstr_failure(char *, int);
int	my_setenv(char **, char *, char *);
int	exec_pipe(char **, char **, int, int *);
int	check_exit(char **, char **, int , int*);
int	check_pipe_redir(char **, int *, int, int);
int	check_nb_redirect(char **, char *, char *, int);
int	*my_dup(int);
char	child(char **, char *, char **);
char	*super_str(char *);
char	*find_home(char **);
char	*my_add_slash(char *);
char	*find_oldpwd(char **);
char	*clear_str(char *, char);
char	*transform_char(char *, char, char);
char	**create_path(char **);
char	**my_get_env(char **, int);
char	**delete_line(char **, char *);

#endif /* !BACK_H_ */
