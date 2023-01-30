/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:54 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/30 15:04:41 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_croissant(p_list *pile)
{
	while (pile->next)
	{		
		if (pile->content > pile->next->content)
		{
			return (1);
		}
		pile = pile->next;
	}
	return (0);
}

int	ft_check_decroissant(p_list *pile)
{
	while (pile->next)
	{		
		if (pile->content < pile->next->content)
		{
			return (1);
		}
		pile = pile->next;
	}
	return (0);
}

/*int	main(int ac, char **av)
{
	int	i = 1;
	p_list	*pile;
	p_list	*new;

	if (ac < 2)
	{
		ft_printf("error");
		return (1);
	}
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_front(&pile, new);
		i++;
	}
	ft_print_pile(pile);
	ft_printf("\n%d\n", ft_check_decroissant(pile));
	return (0);
}*/