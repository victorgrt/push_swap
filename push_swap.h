/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:32:25 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 17:25:06 by vgoret           ###   ########.fr       */
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

void	ft_rotate_a(t_stack **pile);
void	ft_rotate_b(t_stack **pile);
void	ft_reverse_rotate_b(t_stack **pile);
void	ft_reverse_rotate_a(t_stack **pile);
void	ft_rotate_both(t_stack **pile_a, t_stack **pile_b);
void	ft_reverse_rotate_both(t_stack **pile_a, t_stack **pile_b);
void	ft_push_a(t_stack **pile_a, t_stack **pile_b);
void	ft_push_b(t_stack **pile_a, t_stack **pile_b);
void	ft_swap_a(t_stack **pile);
void	ft_swap_b(t_stack **pile);
void	ft_swap_s(t_stack **pile_a, t_stack **pile_b);
void	algo3(t_stack **pile);
void	ft_print_pile(t_stack *pile_a);
void	ft_print_piles(t_stack *pile_a, t_stack *pile_b);
void	ft_atol_error_print(char *str);
void	algo_big(t_stack **pile_a, t_stack **pile_b);
void	ft_push_low_cost(t_stack **pile_a, t_stack **pile_b);
void	ft_set_cmd(t_stack **pile);
void	ft_cmd_to_top(t_stack *pile);
void	ft_fill_b_high(t_stack **pile_a, t_stack **pile_b);
void	ft_fill_b_low(t_stack **pile_a, t_stack **pile_b);
int		ft_check_args(char **av, int ac);
int		ft_master_checker(char **av, int ac);
int		algo5(t_stack **pile_a, t_stack **pile_b);
int		ft_pilefind_min(t_stack *pile);
int		ft_pilefind_max(t_stack *pile);
int		ft_check_croissant(t_stack *pile);
int		ft_check_decroissant(t_stack *pile);
int		ft_atol_check(char *str);
int		ft_strokesa_to_top(t_stack **pile_a, t_stack **pile_b);
int		ft_find_mediane(t_stack *pile);
int		ft_size_tab(int *tab);
int		*ft_trier(int *tab);
int		*ft_action(t_stack *pile, t_stack *temp, int *tab);
void	ft_swap_int(int *tab, int indice);

long	ft_atol(char *str);

t_stack	*ft_pilereturn_min(t_stack *pile);

void	ft_under(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next);
void	ft_upper(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next);
void	ft_both(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next);
void	ft_both2(t_stack **pile_a, t_stack *next);
void	ft_2ndpart(t_stack **a, t_stack **b, t_stack *cheap, t_stack *next);
t_stack	*find_next_highest(int ref, t_stack *pile_a);
t_stack	*cheapest(t_stack *pile_a, t_stack *pile_b);
void	ft_set_pos(t_stack **pile);
int		ft_size_comp(t_stack *pile);
void	ft_put_cheap_top(t_stack **pile_b, t_stack *cheap);
void	ft_put_next_top(t_stack **pile_a, t_stack *next);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen2(char *str);
char	*recupfile(char *save, int fd);
char	*recupline(char *save);
char	*trimming_static(char *save);
char	*get_next_line(int fd);

#endif