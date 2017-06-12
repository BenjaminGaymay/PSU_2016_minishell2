/*
** my.h for my in /home/benjamin.g/delivery/PSU_2016_my_printf/include
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Nov 14 09:36:02 2016 Benjamin GAYMAY
** Last update Thu Mar 23 17:55:05 2017 Benjamin GAYMAY
*/

#ifndef MY_FPRINTF_H_
# define MY_FPRINTF_H_

#include <stdarg.h>

/*
** my_printf.c
*/
int	my_fprintf(char *s, ...);
int	my_ftype(char *type_list, char *s, int i, va_list ap);
int	my_fflag(char *flag_list, char *s, int i, va_list ap);

/*
** hexa.c
*/
void	my_fhexa(int num, int lower_or_upper);
int	my_fhexa_arg_upper(va_list ap);
int	my_fhexa_arg_lower(va_list ap);
void	my_fhexa_pointer(long int num);
int	my_fhexa_pointer_arg(va_list ap);

/*
** octal_bin.c
*/
int	my_foct_arg(va_list ap);
int	my_fbin_arg(va_list ap);
void	my_foct(int num);

/*
** my_putchar.c
*/
void	my_fputchar_printf(char c);
int	my_fputchar_arg(va_list ap);
int	my_faff_modulo_arg(va_list ap);
int	my_faff_atsign_arg(va_list ap);

/*
** my_put_nbr.c
*/
int	my_fput_nbr_arg(va_list ap);
int	my_fput_nbr_base(int num, int base, int lower_or_upper);

/*
** my_put_nbr_unsigned.c
*/
void	my_fput_unsigned_int(unsigned int n);
int	my_fput_unsigned_int_arg(va_list ap);
void	my_fput_nbr_base_unsigned(unsigned int, unsigned int, int);

/*
** my_putstr.c
*/
int	my_fputstr_printf(char *str);
char	*my_frevstr_printf(char *str);
int	my_fputstr_arg(va_list ap);
void	my_fputstr_oct(char *str);
int	my_fputstr_oct_arg(va_list ap);

/*
** my_strlen.c
*/
int	my_fintlen(int nb);

/*
** flag.c
*/
int	my_fhash(va_list ap, char *s, int i);
int	my_fplus(va_list ap, char *s, int i);
int	my_fspace(va_list ap, char *s, int i);

#endif /* !MY_FPRINTF_H_ */
