/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/13 14:29:31 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

p_list	*ft_find_mediane(p_list *pile)
{
	p_list	*sorted;
	p_list	*start;

	sorted = pile;
	start = sorted;
	while (sorted->next)
	{
		
		if (sorted->content > sorted->next->content)
		{
			ft_swap(&sorted);
		}
		sorted = sorted->next;
	}
	return (start);
}

int	main(int ac, char **av)
{
	int i = 1;
	p_list *pile_a;
	p_list	*new;

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
	//ft_print_pile(pile_a);
	//ft_printf("\n");
	//ft_print_piles(pile_a, pile_b);
	//ft_find_mediane(pile_a);
	ft_print_pile(ft_find_mediane(pile_a));
	//ft_print_piles(pile_a, pile_b);
	//printf("ici %d", ft_find_pivot(pile_a));
	return (0);
}