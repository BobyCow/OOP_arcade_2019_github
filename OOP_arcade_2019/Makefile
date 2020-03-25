##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[1;31m"
YELLOW			=		"\033[1;33m"
BLUE			=		"\033[1;34m"

GAMES	=	./game/

PACMAN	=	./game/pacman/

NCURSE	=	./lib/ncurse/

NIBBLER	=	./game/nibbler/

DIR		=	./src/

MENU	=	./src/menu/

SRC		=	$(DIR)main.cpp			\
			$(DIR)Loop.cpp			\
			$(DIR)Error.cpp			\
			$(DIR)Core.cpp			\
			$(MENU)Menu.cpp			\
			$(GAMES)IGame.cpp		\
			$(GAMES)Game.cpp		\
			$(PACMAN)Pacman.cpp		\
			$(NIBBLER)Nibbler.cpp	\

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

RM		=	rm -f

CFLAGS	=	-I./include

CPPFLAGS	= -W -Wall -Wextra -std=c++14 -I./include -g3

LDLIBS	=	-ldl

NAME	=	arcade

all:	$(NAME)
		@make -C ./lib
		@$(ECHO) $(GREEN)

title:
		@make -C lib/
		@$(ECHO) $(RED)"\n\n\
\t  _|_|    _|_|_|      _|_|_|    _|_|    _|_|_|    _|_|_|_|	\n \
\t_|    _|  _|    _|  _|        _|    _|  _|    _|  _|			\n \
\t_|_|_|_|  _|_|_|    _|        _|_|_|_|  _|    _|  _|_|_|    	\n \
\t_|    _|  _|    _|  _|        _|    _|  _|    _|  _|        	\n \
\t_|    _|  _|    _|    _|_|_|  _|    _|  _|_|_|    _|_|_|_|  \n\n" $(DEFAULT)

$(NAME):	$(OBJ)
	@echo -e "\033[01m\033[31mLinking ...\033[00m" $(YELLOW) "[OK]"
	$(CC) -o $(NAME) $(LDLIBS) $(OBJ)
	@echo -e "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

debug: $(OBJ)
	$(CC) -g3 -o $(NAME) $(LDLIBS) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@echo -e "\033[01m\033[31mRemoving objects ...\033[00m"

fclean:	clean
	$(RM) $(NAME)
	@echo -e "\033[01m\033[31mRemoving binary : [${NAME}] ...\033[00m"
	@make -C ./lib fclean

re:	fclean all title

.PHONY: all clean fclean re