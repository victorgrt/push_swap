/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:39:10 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/23 12:29:59 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_next_highest(int ref, t_stack *pile_a)
{
	t_stack	*current;
	int		next_highest;

	if (!pile_a)
		return (0);
	current = pile_a;
	next_highest = INT_MAX;
	while (pile_a)
	{
		if (pile_a->content > ref && pile_a->content < next_highest)
		{
			next_highest = pile_a->content;
			current = pile_a;
		}
		pile_a = pile_a->next;
	}
	return (current);
}

t_stack	*cheapest(t_stack *pile_a, t_stack *pile_b)
{
	t_stack	*next;
	t_stack	*temp;
	t_stack	*cheapest;
	int		min_stroke;


	cheapest = pile_b;
	ft_cmd_to_top(pile_a);
	ft_cmd_to_top(pile_b);
	next = find_next_highest(pile_b->content, pile_a);
	min_stroke = cheapest->cmd + next->cmd;
	temp = pile_b;
	while (temp)
	{
		next = find_next_highest(temp->content, pile_a);
		if (((temp->cmd + next->cmd) < min_stroke))
		{
			min_stroke = temp->cmd + next->cmd;
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}

void	algo_big(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*cheap;
	t_stack	*next;

	ft_fill_b_low(pile_a, pile_b);
	ft_fill_b_high(pile_a, pile_b);
	ft_set_pos(pile_a);
	ft_set_pos(pile_b);
	cheap = cheapest(*pile_a, *pile_b);
	next = find_next_highest(cheap->content, *pile_a);	
	ft_push_a(pile_a, pile_b);
	ft_2ndpart(pile_a, pile_b, cheap, next);
	while (ft_check_croissant(*pile_a) == 1)
	{
		if (ft_pilereturn_min(*pile_a)->position >= ft_size_comp(*pile_a))
			ft_reverse_rotate_a(pile_a);
		else if (ft_pilereturn_min(*pile_a)->position < ft_size_comp(*pile_a))
			ft_rotate_a(pile_a);
	}
}

// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	t_stack *pile_a;
// 	t_stack	*pile_b;
// 	t_stack	*new;

// 	pile_a = 0;
// 	pile_b = 0;
// 	if (ac < 2)
// 	{
// 		ft_printf("erreur");
// 		return (1);
// 	}
// 	while (i < ac)
// 	{
// 		new = ft_pilenew(ft_atol(av[i]));
// 		ft_pileadd_back(&pile_a, new);
// 		i++;
// 	}
// 	if (ft_pilesize(pile_a) <= 3)
// 		algo3(&pile_a);
// 	else if (ft_pilesize(pile_a) <= 5)
// 		algo5(&pile_a, &pile_b);
// 	else if (ft_pilesize(pile_a) > 5)
// 		algo_big(&pile_a, &pile_b);
// 	ft_free_list(pile_a);
// 	ft_free_list(pile_b);
// 	return (0);
// }