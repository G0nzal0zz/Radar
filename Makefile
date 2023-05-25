##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make src + library
##

SRC	=	src/main.c 	\
		src/oop/new/new.c	\
		src/window/window.c 	\
		src/system/entities/entities.c 	\
		src/game/game.c 	\
		src/system/images/images.c 	\
		src/game/scene/scene.c 	\
		src/system/file/file.c	\
		src/system/entities/aircrafts/aircrafts.c	\
		src/system/entities/towers/towers.c	\
		src/window/events/events.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:		$(NAME)

$(NAME):	$(OBJ)
			make all -C lib/my/
		gcc -Wall -g3 -o $(NAME) $(OBJ) -lm -L./lib/my -lmy $(CFLAGS) -lncurses

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			make fclean -C lib/my/

re:			fclean all
