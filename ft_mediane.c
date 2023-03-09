/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 17:20:04 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_mediane(t_stack *pile)
{
	int			*tab;
	int			i;
	int			mediane;
	t_stack		*temp;

	temp = pile;
	i = 0;
	tab = malloc(sizeof(int) * ft_pilesize(temp) + 1);
	if (!tab)
		return (0);
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	tab = ft_action(pile, temp, tab);
	if (ft_pilesize(temp) % 2 == 0)
		mediane = tab[ft_size_comp(temp) + 1];
	else
		mediane = tab[ft_size_comp(temp)];
	free(tab);
	return (mediane);
}

void	ft_fill_b_high(t_stack **pile_a, t_stack **pile_b)
{
	int	max;

	max = ft_pilefind_max(*pile_a);
	while (ft_pilesize(*pile_a) != 1)
	{
		if ((*pile_a)->content != max)
			ft_push_b(pile_a, pile_b);
		else
			ft_rotate_a(pile_a);
	}
}

void	ft_fill_b_low(t_stack **pile_a, t_stack **pile_b)
{
	int	mediane;
	int	i;

	i = 0;
	mediane = ft_find_mediane((*pile_a));
	while (i < ft_pilesize(*pile_a))
	{
		if ((*pile_a)->content <= mediane)
			ft_push_b(pile_a, pile_b);
		else
			ft_rotate_a(pile_a);
		i++;
	}
}

/*int	main(int ac, char **av){
	int i = 1;	
	t_stack *pile_a;
	t_stack	*pile_b;
	t_stack	*new;

	pile_a = 0;
	pile_b = 0;
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
	algo5000(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b);
	 ft_fill_b_low(&pile_a, &pile_b);
	 ft_print_piles(pile_a, pile_b);
	 ft_fill_b_high(&pile_a, &pile_b);
	 ft_print_piles(pile_a, pile_b);
	 while (ft_pilesize(pile_b) != 0)
	 {
	 	ft_push_next_highest(&pile_a, &pile_b);
		ft_print_piles(pile_a, pile_b);
	 }
	 ft_print_piles(pile_a, pile_b);
	return (0);
}*/