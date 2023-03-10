SHELL	=	/bin/bash

# Variables

NAME		=	megaphone
CC			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f
ECHO		=	echo -e

# Colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Sources

SRC_FILES	=	megaphone

SRC			=	$(addsuffix .cpp, $(SRC_FILES))
OBJ			=	$(addsuffix .o, $(SRC_FILES))

###

start:
			@$(ECHO) -n "$(YELLOW)[ex_00]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make all
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"

all :		$(NAME)

$(NAME):
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)
			@$(ECHO) -n "$(BLUE)[ex_00]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(ECHO) -n "$(CYAN)[ex_00]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

re:			fclean all
			@$(ECHO) -n "\n$(GREEN)Cleaned and rebuilt everything for [ex_00]!$(DEF_COLOR)\n"

.PHONY:		all clean fclean re