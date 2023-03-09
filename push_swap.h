/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:32:25 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 14:06:36 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096 
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	ft_rotate_a(p_list **pile);
void	ft_rotate_b(p_list **pile);
void	ft_reverse_rotate_b(p_list **pile);
void	ft_reverse_rotate_a(p_list **pile);
void	ft_rotate_both(p_list **pile_a, p_list **pile_b);
void	ft_reverse_rotate_both(p_list **pile_a, p_list **pile_b);
void	ft_push_a(p_list **pile_a, p_list **pile_b);
void	ft_push_b(p_list **pile_a, p_list **pile_b);
void	ft_swap_a(p_list **pile);
void	ft_swap_b(p_list **pile);
void	ft_swap_s(p_list **pile_a, p_list **pile_b);
void	algo3(p_list **pile);
void	ft_print_pile(p_list *pile_a);
void	ft_print_piles(p_list *pile_a, p_list *pile_b);
void	ft_atol_error_print(char *str);
void	algo_big(p_list **pile_a, p_list **pile_b);
void	ft_push_low_cost(p_list **pile_a, p_list **pile_b);
void	ft_set_cmd(p_list **pile);
void	ft_cmd_to_top(p_list *pile);
void	ft_set_position(p_list **pile);
void	ft_set_position_v2(p_list **pile);
void	ft_push_next_highest(p_list **pile_a, p_list **pile_b);
void	ft_fill_b_high(p_list **pile_a, p_list **pile_b);
void	ft_fill_b_low(p_list **pile_a, p_list **pile_b);
void	ft_push_next_highest_true(p_list **pile_a, p_list **pile_b);
int		ft_check_args(char **av, int ac);
int		ft_master_checker(char **av, int ac);
int		algo5(p_list **pile_a, p_list **pile_b);
int		ft_pilefind_min(p_list *pile);
int		ft_pilefind_max(p_list *pile);
int		ft_check_croissant(p_list *pile);
int		ft_check_decroissant(p_list *pile);
int		ft_atol_check(char *str);
int		ft_strokesa_to_top(p_list **pile_a, p_list **pile_b);
int		ft_find_mediane(p_list *pile);

long	ft_atol(char *str);

p_list	*ft_pilereturn_min(p_list *pile);

void	ft_under(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next);
void	ft_upper(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next);
void	ft_both(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next);
void	ft_2ndpart(p_list **a, p_list **b, p_list *cheap, p_list *next);
p_list	*find_next_highest(int ref, p_list *pile_a);
p_list	*cheapest(p_list *pile_a, p_list *pile_b);
void	ft_set_pos(p_list **pile);
int		ft_size_comp(p_list *pile);
void	ft_put_cheap_top(p_list **pile_b, p_list *cheap);
void	ft_put_next_top(p_list **pile_a, p_list *next);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen2(char *str);
char	*recupfile(char *save, int fd);
char	*recupline(char *save);
char	*trimming_static(char *save);
char	*get_next_line(int fd);

#endif