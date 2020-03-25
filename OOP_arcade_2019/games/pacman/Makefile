##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	Tool.cpp	\
		Pacman.cpp

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

RM	=	rm -f

CFLAGS	= 

CPPFLAGS = -W -Wall -Wextra  -std=c++14 -I./include -g3

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

NAME	=	pacman

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[01m\033[31mLinking ...\033[00m"
	$(CC) -o $(NAME) $(LDLIBS) $(OBJ)
	@echo -e "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	@$(RM) $(OBJ)
	@echo -e "\033[01m\033[31mRemoving objects ...\033[00m"

fclean:	clean
	$(RM) $(NAME)
	@echo -e "\033[01m\033[31mRemoving binary : [${NAME}] ...\033[00m"

re:	fclean all

.PHONY: all clean fclean re
