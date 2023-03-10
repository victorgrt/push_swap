/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:43:03 by victor            #+#    #+#             */
/*   Updated: 2023/03/10 12:56:23 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_stack **pile)
{
	int		i;
	t_stack	*current;

	i = 1;
	current = *pile;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}

int	ft_find_low_cost(t_stack *pile_a, t_stack *pile_b)
{
	int		addition;
	t_stack	*temp;

	temp = pile_a;
	addition = INT_MAX;
	while (temp)
	{
		if ((pile_a->cmd + pile_b->cmd) < addition)
			addition = (pile_a->cmd + pile_b->cmd);
		temp = temp->next;
	}
	return (addition);
}

void	ft_cmd_to_top(t_stack *pile)
{
	t_stack	*temp;
	int		pos_med;

	pos_med = ft_size_comp(pile);
	temp = pile;
	ft_set_position(&pile);
	ft_set_cmd(&pile);
	while (temp)
	{
		if (temp->position <= pos_med)
			temp->cmd = temp->cmd + temp->position - 1;
		else if (temp->position > pos_med)
			temp->cmd = temp->cmd + ft_pilesize(pile) - temp->position + 1;
		temp = temp->next;
	}
}

int	ft_nexthighest(int ref, t_stack *pile_a)
{
	t_stack	*current;
	int		next_highest;

	if (!pile_a)
		return (0);
	current = pile_a;
	next_highest = INT16_MAX;
	while (pile_a)
	{
		if (pile_a->content > ref && pile_a->content < next_highest)
			next_highest = pile_a->content;
		pile_a = pile_a->next;
	}
	if (next_highest != INT_MAX)
		return (next_highest);
	return (ft_pilefind_max(current));
}

/*int	main(int ac, char **av)
{
	int i = 1;
	t_stack *pile_a;
	t_stack *pile_b;
	t_stack	*new;
	t_stack	*temp;
 
	pile_a = 0;
	if (ac < 2)
	{
		ft_printf("erreur");
		return (1);
	}
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_back(&pile_a, new);
		i++;
	}
	ft_print_piles(pile_a, pile_b);
    ft_fill_b_low(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b); 
    ft_fill_b_high(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b);
    ft_cmd_to_top(pile_b);
    ft_print_piles(pile_a, pile_b);
    ft_push_low_cost(&pile_a, &pile_b);
    ft_print_piles(pile_a, pile_b);
	ft_push_low(&pile_a, &pile_b);
	ft_strokesa_to_top(&pile_a, &pile_b);
		   temp = pile_b;
    while (temp)
	{
		printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content,
		 temp->position, temp->cmd);
		temp = temp->next;
	}
	// while (ft_pilesize(pile_b) != 0)
	// {
	// 	ft_print_piles(pile_a, pile_b);
	// 	printf("next : %d\n", ft_nexthighest(pile_b->content, pile_a));
	// 	if (pile_a->content == ft_nexthighest(pile_b->content, pile_a))
	// 		ft_push_a(&pile_a, &pile_b);
	// 	ft_rotate_a(&pile_a);
	// }
	// ft_reverse_rotate(&pile_a);
	// ft_reverse_rotate(&pile_a);
	// ft_reverse_rotate(&pile_a);
    // ft_print_piles(pile_a, pile_b);
	return (0);
}*/
