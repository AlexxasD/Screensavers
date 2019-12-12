##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Project makefile
##

SRC	=	main.c				\
		draw_things.c		\
		dvd.c				\
		globalfunc1.c		\
		kepler.c			\
		line_tracer.c		\
		math.c 				\
		randomess.c			\
		screen_launcher.c	\
		my_strcmp.c			\
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :	clean fclean re
