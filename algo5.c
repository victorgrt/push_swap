/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:39:14 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/22 15:53:56 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo5(p_list **pile_a, p_list **pile_b)
{
	p_list *min;

	if (ft_check_croissant(*pile_a) == 0)
		return (0);
	while (ft_pilesize(*pile_a) != 3)
	{	
		ft_set_position(pile_a);
		min = ft_pilereturn_min(*pile_a);
		while ((*pile_a)->content != ft_pilefind_min(*pile_a))
		{
			if (min->position <= ft_pilesize(*pile_a) / 2)
				ft_rotate_a(pile_a);
			else
				ft_reverse_rotate_a(pile_a);
		}
		ft_push_b(pile_a, pile_b);
	}
	algo3(pile_a);
	while (*pile_b)
		ft_push_a(pile_a, pile_b);
	return (0);
}

/*int	main(int ac, char **av)
{
	int i = 1;
	p_list *pile_a;
	p_list *pile_b;
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
	ft_print_pile(pile_a);
	ft_printf("\n");
	algo5(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b);
	return (0);
}*/