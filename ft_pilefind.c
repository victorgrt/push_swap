/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilefind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:30:36 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/27 16:42:36 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pilefind_max(p_list *pile)
{
	int	max;

	if (pile)
	{
		max = pile->content;
		while (pile)
		{
			if (max < pile->content)
				max = pile->content;
			pile = pile->next;
		}
	}
	return (max);
}

p_list	*ft_pilereturn_min(p_list *pile)
{
	p_list	*min;

	if (pile)
	{
		min = pile;
		while (pile)
		{
			if (pile->content < min->content)
				min = pile;
			else
				pile = pile->next;
		}
	}
	return (min);
}

int	ft_pilefind_min(p_list *pile)
{
	int	min;

	if (pile)
	{
		min = pile->content;
		while (pile)
		{
			if (pile->content < min)
				min = pile->content;
			else
				pile = pile->next;
		}
	}
	return (min);
}

/*int	main(int ac, char **av)
{
	int i = 1;
	int min;
	p_list	*pile_a;
	p_list	*new;

	if (ac < 2)
	{
		ft_printf("Erreur");
		return (1);
	}
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_front(&pile_a, new);
		i++;
	}
	ft_print_pile(pile_a);
	min = ft_pilefind_min(pile_a);
	ft_printf("\nMin:%d\n", min);
	return (0);
}*/

/*int	main(int ac, char **av)
{
	int	i = 1;
	int max;
	p_list	*new;
	p_list	*pile_a;

	pile_a = 0;
	if (ac < 2)
	{
		ft_printf("Erreur");
		return (1);
	}
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_front(&pile_a, new);
		i++;	
	}
	ft_print_pile(pile_a);
	max = ft_pilefind_max(pile_a);
	ft_printf("\n%d\n", max);
	return (0);
}*/