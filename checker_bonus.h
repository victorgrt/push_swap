/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:03:05 by victor            #+#    #+#             */
/*   Updated: 2023/03/18 14:01:53 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

/* 		GNL UTILS 		*/

void	*ft_calloc2(size_t nmemb, size_t size);

char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd, int flag);

int		ft_strlen2(char *str);

#endif