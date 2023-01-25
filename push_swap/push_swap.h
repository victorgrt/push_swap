/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:32:25 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/25 16:30:42 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

void	ft_rotate(p_list **pile);
void	ft_reverse_rotate(p_list **pile);
void	ft_rotate_both(p_list **pile_a, p_list **pile_b);
void	ft_reverse_rotate_both(p_list **pile_a, p_list **pile_b);

void    ft_push_a(p_list **pile_a, p_list **pile_b);
void	ft_push_b(p_list **pile_a, p_list **pile_b);

void	ft_swap(p_list **pile);
void ft_swap_s(p_list **pile_a, p_list **pile_b);

long	ft_atol(char *str);
int	ft_check_args(char **av, int ac);
int	ft_master_checker(char **av, int ac);

#endif