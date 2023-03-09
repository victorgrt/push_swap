/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:37:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 16:39:30 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pile(t_stack *pile)
{	
	ft_printf("\nPile:\n");
	while (pile)
	{
		ft_printf("%d\n", pile->content);
		pile = pile->next;
	}
	ft_printf("\n");
}

void	ft_print_piles(t_stack *pile_a, t_stack *pile_b)
{	
	ft_print_pile(pile_a);
	ft_print_pile(pile_b);
}

/*int main(int ac, char **av)
{
	int	i = 1;
	t_stack *pile_a;
	t_stack *pile_b;
	t_stack	*new;
	
	pile_a = 0;
	if (ac == 1)
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
	//ft_print_pile(pile_a, pile_b);
	ft_print_piles(pile_a, NULL);
	algo5(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b);
	return (0);
}*/