##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SDIR		=	./sfml/

NDIR		=	./ncurses/

SFML_SRC	=	$(SDIR)SFML.cpp		\

SFML_OBJ	=	$(SFML_SRC:.cpp=.o)

NCURSES_SRC	=	$(NDIR)Ncurses.cpp		\

NCURSES_OBJ	=	$(NCURSES_SRC:.cpp=.o)

CC			=	g++

RM			=	rm -f

CPPFLAGS	=	-Wall -std=c++14 -fPIC -I../include -shared

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

SFML_NAME	=	lib_arcade_sfml.so

NCURSES_NAME	=	lib_arcade_ncurses.so

NCURSESFLAGS	=	-lncurses

all: $(NCURSES_NAME) $(SFML_NAME)

$(NCURSES_NAME):	$(NCURSES_OBJ)
	$(CC) $(NCURSES_OBJ) -o $(NCURSES_NAME) $(CPPFLAGS) $(LDFLAGS) $(NCURSESFLAGS)

$(SFML_NAME):	$(SFML_OBJ)
	$(CC) $(SFML_OBJ) -o $(SFML_NAME) $(CPPFLAGS) $(LDFLAGS) $(SFMLFLAGS)

clean:
	$(RM) $(SFML_OBJ) $(NCURSES_OBJ)

fclean: clean
	$(RM) $(SFML_NAME) $(NCURSES_NAME)

re: fclean all

.PHONNY: all clean fclean re
