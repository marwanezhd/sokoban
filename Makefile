##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## desc
##

SRC =	src/main.c \
	src/annexes.c \
	src/game.c \
	src/check_win_lose.c \
	src/display_map.c \
	src/init_game.c \
	src/memory_management.c \
	src/move_p.c \
	src/help.c \
	src/error.c \


NAME =	my_sokoban

CC =     cc

RM =	rm -f

CFLAGS =	-Iinclude -lncurses

OBJ =		$(SRC:.c=.o)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
