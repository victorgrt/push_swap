# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victor <victor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 13:18:09 by vgoret            #+#    #+#              #
#    Updated: 2023/01/21 20:16:47 by victor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# ! ARGUMENTS ! #

NAME	=	push_swap
CCFLAGS	=	-g -Wall -Werror -Wextra
CC		=	gcc

################################################################################
# * SRC * #

SRC = sort.c ft_swap.c ft_rotate.c ft_push.c parsing2.c push_swap.c rules.c \

OBJ = ${SRC:.c=.o}

################################################################################
# ? RULES ? #

all: ${NAME} ok_util

${NAME} : ${OBJ}
	make -C libft	
	${CC} ${OBJ} libft/libft.a -o ${NAME}


%.o : %.c
	${CC} ${CCFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean:	clean fclean_util
	@rm -f libft/libft.a
	@rm -f libft/*.o
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean all re

################################################################################
# TODO	UTILS	TODO #

fclean_util : 
	@echo "\\033[1;31m DELETED\\033[0;39m"
	@tput sgr0;
	@${foreach value, $(OBJ), echo "\\033[1;31m >> \\033[0;39m" ${value};}
	@${foreach value, $(NAME), echo "\\033[1;31m >> \\033[0;39m" ${value};} 

ok_util :
	@echo "\
	 ⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀⢠⠞⠉⠙⠲⡀⠀\n ⠀⠀⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀⢳⡀⠀ ⡏⠀⠀⠀⠀⠀⢷ \n ⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀⢸⠀⠀⠀⠀⠀ ⡇ \n ⠀⠀⢸⣯⡭⠁⠸⣛⣟⠆⡴⣻⡲⣿⠀⣸  OK  ⡇ \n ⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀⣿⠀⢹⠀⠀⠀⠀⠀ ⡇ \n ⠀⠀⠙⢿⣯⠄⠀⠀⠀⢀⡀⠀⠀⡿⠀⠀⡇⠀⠀⠀⠀⡼ \n ⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀⠀⠘⠤⣄⣠⠞⠀ \n ⠀⠀⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n ⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀ \n ⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀ \n ⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀ \n ⣿⣿⣧⣀⣿………⣀⣰⣏⣘⣆⣀⠀⠀ \n"