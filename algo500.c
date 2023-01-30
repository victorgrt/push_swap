/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:12:58 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/30 14:53:22 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo500(p_list **pile_a, p_list **pile_b)
{
	ft_push_b(pile_a, pile_b);
	ft_push_b(pile_a, pile_b);
	return (1);
}

/*int main(int ac, char **av)
{
	int i = 1;
	p_list	*pile_a;
	p_list	*pile_b;
	p_list	*new;

	if (ac < 2)
	{
		printf("Pas assez d'arguments");
		return (1);
	}
	while (i <= ac)
	{
		if (ft_master_checker(av, ac) == 0)
		{
			// if (i == 1)
			// 	pile_a = ft_pilenew(ft_atol(av[1]));
			new = ft_pilenew(ft_atol(av[i]));
			ft_pileadd_back(&pile_a, new);
			i++;
		}
		else if (ft_master_checker(av, ac) == 1)
		{
			printf("C'est pas un int");
			return (1);
		}
		else if (ft_master_checker(av, ac) == 2)
		{
			printf("Doublon");
			return (1);
		}
	}
	ft_printf("Pile_A avant:\n");
	ft_print_pile(pile_a);
	algo5(&pile_a, &pile_b);
	ft_printf("\n");
	ft_printf("Pile_A Apres:\n");
	ft_print_pile(pile_a);
	ft_printf("Pile_B Apres:\n");
	ft_print_pile(pile_b);

	return (0);
}*/