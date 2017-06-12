##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
##
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
##
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Thu Apr  6 12:18:40 2017 Benjamin GAYMAY

CC	=	gcc

NAME	=	mysh

SRC	=	./front/my_printf/flag.c \
                ./front/my_printf/hexa.c \
                ./front/my_printf/octal_bin.c \
                ./front/my_printf/my_printf.c \
                ./front/my_printf/my_putstr_printf.c \
                ./front/my_printf/my_strlen_printf.c \
		./front/my_printf/my_put_nbr_printf.c \
		./front/my_printf/my_putchar_printf.c \
                ./front/my_printf/my_put_nbr_unsigned.c \
                ./front/my_fprintf/fflag.c \
                ./front/my_fprintf/fhexa.c \
                ./front/my_fprintf/my_fprintf.c \
                ./front/my_fprintf/foctal_bin.c \
                ./front/my_fprintf/my_putstr_fprintf.c \
                ./front/my_fprintf/my_strlen_fprintf.c \
		./front/my_fprintf/my_putchar_fprintf.c \
                ./front/my_fprintf/my_put_nbr_fprintf.c \
                ./front/my_fprintf/my_put_nbr_funsigned.c \
		./front/exit.c \
		./front/prompt.c \
		./front/my_putstr.c \
		./front/my_putchar.c \
		./front/my_showtab.c \
		./front/get_next_line.c \
		./back/cd.c \
		./back/pipe.c\
		./back/open.c\
		./back/main.c \
		./back/mysh.c \
		./back/path.c \
		./back/child.c \
		./back/parent.c \
		./back/setenv.c \
		./back/my_get.c \
		./back/my_calloc.c \
		./back/redirection.c \
		./back/chained_list.c \
		./back/redirect_basic.c \
		./back/array/use_array.c \
		./back/array/copy_array.c \
		./back/string/str.c \
		./back/string/my_strcat.c \
		./back/string/my_strlen.c \
		./back/string/my_getnbr.c \
		./back/string/my_strcmp.c \
		./back/string/my_strcpy.c \
		./back/string/my_strstr.c \
		./back/string/my_strncmp.c \
		./back/string/clear_my_str.c \
		./back/string/my_str_isnum.c \
		./back/string/my_add_slash.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS +=	-I./include

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
