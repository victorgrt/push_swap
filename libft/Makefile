# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 13:54:05 by vgoret            #+#    #+#              #
#    Updated: 2023/03/22 11:02:54 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
    ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
    ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
    ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c ft_pilenew.c ft_pilesize.c ft_pileadd_front.c ft_pileadd_back.c \
	ft_pilelast.c ft_free_list.c\

PROG = libft.a

OBJ = ${SRC:.c=.o}

.c.o:
	@cc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${PROG}: ${OBJ}
	ar rc ${PROG} ${OBJ}

all: ${PROG}

clean:
	rm -f ${OBJ} 

fclean:	clean
	rm -f ${PROG} 

re : fclean all

.PHONY: all clean fclean re bonus
