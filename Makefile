# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 13:18:09 by vgoret            #+#    #+#              #
#    Updated: 2023/03/26 13:40:40 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# ! ARGUMENTS ! #

NAME	=	push_swap
CHECKER = 	checker
CCFLAGS	=	-g -Wall -Werror -Wextra
CC		=	gcc

################################################################################
# * SRC * #

SRC = algo3.c algo5.c algo60.c ft_algo_big.c \
	algo_big_utils.c algo_big_utils2.c  ft_mediane.c ft_cmd.c ft_tab_utils.c ft_position.c \
	ft_push.c ft_rotate.c ft_rotate2.c ft_swap.c \
	ft_atol.c ft_checker.c ft_check_order.c \
	ft_print_pile.c ft_pilefind.c ft_init_pile.c \
	main.c \

CHECKER_SRC = checker.c checker_utils.c ft_checker_utils2.c ft_checker_utils3.c \
	get_next_line.c get_next_line_utils.c ft_check_order.c ft_atol.c\
	ft_checker.c\

OBJ = ${SRC:.c=.o}

CHECKER_OBJ = ${CHECKER_SRC:.c=.o}


################################################################################
# ? RULES ? #

all: ${NAME} ok_util

bonus: ${NAME} ${CHECKER} bonus_utils

${NAME}: ${OBJ}
	@make -C libft	
	@make -C ft_printf	
	@${CC} ${OBJ} libft/libft.a ft_printf/ft_printf.a -o ${NAME}

${CHECKER}: ${NAME} ${CHECKER_OBJ}
	@${CC} ${CHECKER_OBJ} libft/libft.a ft_printf/ft_printf.a -o ${CHECKER}

%.o : %.c
	@${CC} ${CCFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean:	clean fclean_util
	@rm -f libft/libft.a
	@rm -f libft/*.o
	@rm -f ft_printf/ft_printf.a
	@rm -f ft_printf/*.o
	@rm -f ${CHECKER}
	@rm -f ${CHECKER_OBJ}
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean all re

################################################################################
# TODO	UTILS	TODO #

RED=\033[0;31m
GREEN= \033[1;32m
BLUE= \033[1;34m
PURP= \033[1;35m
NC=\033[0m # No Color

fclean_util : 
	@echo "\\033[1;31m DELETED\\033[0;39m"
	@tput sgr0;
	@${foreach value, $(OBJ), echo "\\033[1;31m >> \\033[0;39m" ${value};}
	@${foreach value, $(NAME), echo "\\033[1;31m >> \\033[0;39m" ${value};} 
	@echo "  ⢀⣤⣶⣶⣤⣄⡀\n⠀⢀⣿⣿⣿⣿⣿⣿⣿⡆\n⠀⠸⣿⣿⣿⣿⣿⡟⡟⡗ ⣿⠉⣿⠉⣿⡏⠹⡏⢹⡏⢹⣿⣿⠉⣿⠉⣿⡟⢋⠛⣿⠉⡟⢉⡏⠹⠏⣹⣿\n⠀⠀⠙⠏⠯⠛⣉⢲⣧⠟ ⣿⠄⣿⠄⣿⡇⡄⠁⢸⡇⢸⣿⣿⠄⣿⠄⣿⠄⣿⣿⣿⠄⡀⢻⣿⡄⢠⣿⣿\n⠀⠀⠠⢭⣝⣾⠿⣴⣿⠇ ⣿⣦⣤⣴⣿⣧⣿⣤⣼⣧⣬⣭⣿⣦⣤⣴⣿⣧⣤⣤⣿⣤⣷⣤⣿⣧⣼⣿⣿\n⠀⠀⢐⣺⡿⠁⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣶⣶⣶⣶⣶⣶⠀\n⠀⠀⣚⣿⠃ ⣶⣶⣶⣶\n⢀⣿⣿⣿⣷⢒⣢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣶⣶⣄⠄\n⢰⣿⣿⡿⣿⣦⠬⢝⡄⠀⠀⠀⠀⠀⠀⢠⣿⠿⠿⠟⠛⠋⠁\n⠠⢿⣿⣷⠺⣿⣗⠒⠜⡄⠀⠀⠀⠀⣴⠟⠁\n⠀⣰⣿⣷⣍⡛⣯⣯⣙⡁⠀⠀⣠⡾⠁\n⠀⠨⢽⣿⣷⢍⣛⣶⢷⣼⣠⣾⠋\n⠀⠀⠘⢿⣿⣖⠬⣹⣶⣿⠟⠁\n⠀⠀⠀⠚⠿⠿⡒⠨⠛⠋\n⠀⠀⠀⠐⢒⣛⣷\n⠀⠀⠀⢘⣻⣭⣭\n⠀⠀⠀⡰⢚⣺⣿\n⠀⠀⢠⣿⣿⣿⣿⣦⡄\n⠀⠀⢸⡿⢿⣿⢿⡿⠃\n⠀⠀⠘⡇⣸⣿⣿⣿⣆\n⠀⠀⠀⠀⠸⣿⡿⠉⠁\n⠀⠀⠀⠀⠀⢿⡟\n"
	
ok_util :
	@clear
	@echo "${BLUE} ____  __ __  _____ __ __  _____ __    __   ____  ____\n|    \\|  |  |/ ___/|  |  |/ ___/|  |__|  | /    ||    \\ \n|  o  )  |  (   \_ |  |  (   \\_ |  |  |  ||  o  ||  o  )\n|   _/|  |  |\\__  ||  _  |\\__  ||  |  |  ||     ||   _/ \n|  |  |  :  |/  \\ ||  |  |/  \\ ||  \`  '  ||  _  ||  |   \n|  |  |     |\\    ||  |  |\\    | \\      / |  |  ||  |   \n|__|   \\__,_| \\___||__|__| \\___|  \\_/\\_/  |__|__||__|  ${NC} \n"
	@echo "\
	 ⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀⢠⠞⠉⠙⠲⡀⠀\n ⠀⠀⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀⢳⡀⠀ ⡏⠀⠀⠀⠀⢷ \n ⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀⢸⠀⠀⠀⠀⠀ ⡇ \n ⠀⠀⢸⣯⡭⠁⠸⣛⣟⠆⡴⣻⡲⣿⠀⣸  ${GREEN}OK ${NC}⡇ \n ⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀⣿⠀⢹⠀⠀⠀⠀⠀ ⡇ \n ⠀⠀⠙⢿⣯⠄ ⠘⠤⣄⣠⠞⠀⡿⠀⠀⡇⠀⠀⠀⠀⡼ \n ⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀⠀⠘⠤⣄⣠⠞⠀ \n ⠀⠀⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n ⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀ \n ⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀ \n ⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀ \n ⣿⣿⣧⣀⣿………⣀⣰⣏⣘⣆⣀⠀⠀ \n"
	
bonus_utils :
	@echo "${BLUE}Compiling bonus files into ${GREEN}CHECKER${NC}"
	@sleep 0.5
	@${foreach value, $(CHECKER_SRC), echo "${BLUE} >> \\033[0;39m" ${value};}
	@sleep 0.5
	@echo "\n${BLUE}DONE : ${GREEN}CHECKER ${BLUE} SUCCESFULLY CREATED"
	
test5 : ${NAME} ${CHECKER}
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	@echo "Liste d'arguments : ${ARG}\n${GREEN}"
	@./push_swap ${ARG} | ./checker ${ARG}
	@echo "${NC}"
	@echo -n "Nombre de coups : ${PURP}"
	@./push_swap ${ARG} | wc -l	

test10 : ${NAME} ${CHECKER}
	$(eval ARG = $(shell shuf -i 0-5000 -n 10))
	@echo "Liste d'arguments : ${ARG}\n${GREEN}"
	@./push_swap ${ARG} | ./checker ${ARG}
	@echo "${NC}"
	@echo -n "Nombre de coups : ${PURP}"
	@./push_swap ${ARG} | wc -l	

test100 : ${NAME} ${CHECKER}
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	@echo "Liste d'arguments : ${ARG}\n${GREEN}"
	@./push_swap ${ARG} | ./checker ${ARG}
	@echo "${NC}"
	@echo -n "Nombre de coups : ${PURP}"
	@./push_swap ${ARG} | wc -l	

test500 : ${NAME} ${CHECKER}
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	@echo "Liste d'arguments : ${ARG}\n${GREEN}"
	@./push_swap ${ARG} | ./checker ${ARG}
	@echo "${NC}"
	@echo -n "Nombre de coups : ${PURP}"
	@./push_swap ${ARG} | wc -l