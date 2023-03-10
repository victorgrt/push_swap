/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:18:45 by victor            #+#    #+#             */
/*   Updated: 2023/03/10 12:57:18 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cmd(t_stack **pile)
{
	t_stack	*current;

	current = *pile;
	while (current)
	{
		current->cmd = 1;
		current = current->next;
	}
}

// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	t_stack *pile_a;
// 	t_stack *pile_b;
// 	t_stack	*new;
// 	t_stack	*temp;
// 	pile_a = 0;
// 	if (ac < 2)
// 	{
// 		ft_printf("erreur");
// 		return (1);
// 	}
// 	while (i < ac)
// 	{
// 		new = ft_pilenew(ft_atol(av[i]));
// 		ft_pileadd_back(&pile_a, new);
// 		i++;
// 	}
// 	//ft_print_pile(&pile_a);
// 	// ft_printf("\n");
// 	// ft_print_piles(pile_a, pile_b);
// 	//algo100(&pile_a, &pile_b);
// 	//ft_print_piles(pile_a, pile_b);
// 	ft_print_piles(pile_a, pile_b);
// 		printf("MEdiane %d\n", ft_find_mediane(pile_a));
// 	ft_fill_b_low(&pile_a, &pile_b);

// 	ft_set_cmd(&pile_b);
// 	ft_set_position(&pile_b);
// 	temp = pile_b;
// 	while (temp)
// 	{
// 		printf("Valeur : %d\tPosition : %d\tCmd : %d\n", 
//temp->content, temp->position, temp->cmd);
// 		temp = temp->next;
// 	}
// 	return (0);
// }