/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:37:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/17 12:37:00 by victor           ###   ########.fr       */
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
	ft_print_pile(pile_a);
	ft_print_pile(pile_b);
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