##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make lib/my
##

SRC	= 	my_strcmp.c	\
		my_itoa.c	\
		my_atoi.c 	\
		my_strlen.c 	\
		my_putchar.c 	\
		my_put_str.c 	\
		my_str_to_word_array.c 	\

NAME	=	libmy.a

CFLAGS = -I./include/ -g3

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
