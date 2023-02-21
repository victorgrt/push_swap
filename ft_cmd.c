/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:43:03 by victor            #+#    #+#             */
/*   Updated: 2023/02/21 16:36:42 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pour push le lowest :
compter le nombres de coups pour faire remonter en haut de B ft_cmd_to_top();
*/

int	ft_find_low_cost(p_list *pile_a, p_list *pile_b)
{
	int		addition;
	p_list	*temp;

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

void	ft_push_low(p_list **pile_a, p_list **pile_b)
{
	int	addition;

	addition = 0;
	ft_cmd_to_top(*pile_a);
	ft_cmd_to_top(*pile_b);
	addition = ft_find_low_cost(*pile_a, *pile_b);
	printf("Addition : %d\n", addition);
}

void	ft_cmd_to_top(p_list *pile)
{
	p_list	*temp;
	int		pos_med;

	pos_med = ((ft_pilesize(pile) / 2) + ft_pilesize(pile) % 2);
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

void	ft_push_low_cost(p_list **pile_a, p_list **pile_b)
{
	p_list	*temp;
	p_list	*temp2;
	int		i;
	int		ref;
	int		size;	

	i = 0;
	size = ft_pilesize(*pile_b);
	ref = INT_MAX;
	temp2 = (*pile_b);
	while (i < size)
	{
		if (ref < (temp2)->cmd)
			ref = (temp2)->cmd;
		(temp2) = (temp2)->next;
		i++;
	}
	temp = (*pile_b);
	if (ref == temp->cmd)
		ft_push_a(pile_a, pile_b);
	else if (((ft_pilesize(*pile_b) / 2) + ft_pilesize(*pile_b) % 2) < ref)
		ft_reverse_rotate_b(pile_b);
	else
		ft_rotate_b(pile_b);
}

int	ft_nexthighest(int ref, p_list *pile_a)
{
	p_list	*current;
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
	p_list *pile_a;
	p_list *pile_b;
	p_list	*new;
	p_list	*temp;
 
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
		printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content, temp->position, temp->cmd);
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
