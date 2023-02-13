/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:37:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/08 14:41:01 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pile(p_list *pile)
{	
	ft_printf("\nPile:\n");
	while (pile)
	{
		ft_printf("%d\n", pile->content);
		pile = pile->next;
	}
	ft_printf("\n");
}

void	ft_print_piles(p_list *pile_a, p_list *pile_b)
{	
	ft_printf("\nA:\n");
	while (pile_a)
	{
		ft_printf("%d\n", pile_a->content);
		pile_a = pile_a->next;
	}
	ft_printf("\nB:\n");
	while (pile_b)
	{
		ft_printf("%d\n", pile_b->content);
		pile_b = pile_b->next;
	}
	ft_printf("\n");
}

/*int main(int ac, char **av)
{
	int	i = 1;
	p_list *pile_a;
	p_list *pile_b;
	p_list	*new;
	
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