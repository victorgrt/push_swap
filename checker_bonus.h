/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:03:05 by victor            #+#    #+#             */
/*   Updated: 2023/03/22 17:02:13 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* 		GNL UTILS 		*/

void	*ft_calloc2(size_t nmemb, size_t size);

char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd, int flag);

int		ft_strlen2(char *str);

void	ft_push_a2(t_stack **pile_a, t_stack **pile_b);
void	ft_push_b2(t_stack **pile_a, t_stack **pile_b);
void	ft_rotate_a2(t_stack **pile);
void	ft_rotate_b2(t_stack **pile);
void	ft_reverse_rotate_a2(t_stack **pile);
void	ft_reverse_rotate_b2(t_stack **pile);
void	ft_rotate_both2(t_stack **pile_a, t_stack **pile_b);
void	ft_reverse_rotate_both2(t_stack **pile_a, t_stack **pile_b);
void	ft_swap_b2(t_stack **pile);
void	ft_swap_a2(t_stack **pile);
void	ft_swap_s2(t_stack **pile_a, t_stack **pile_b);

#endif