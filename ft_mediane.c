/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 14:05:19 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *tab, int indice)
{
	int	temp;

	temp = tab[indice];
	tab[indice] = tab[indice + 1];
	tab[indice + 1] = temp;
}

int	ft_find_mediane(p_list *pile)
{
	int			*tab;
	int			i;
	int			j;
	int			mediane;
	p_list		*temp;

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
	temp = pile;
	i = 0;
	while (i < ft_pilesize(temp) - 1)
	{
		j = i + 1;
		while (j < ft_pilesize(temp))
		{
			if (tab[i] > tab[j])
				ft_swap_int(tab, i);
			j++;
		}
		i++;
	}
	if (ft_pilesize(temp) % 2 == 0)
		mediane = tab[ft_size_comp(temp) + 1];
    else
		mediane = tab[ft_size_comp(temp)];
	free(tab);
	return (mediane);
}

void	ft_fill_b_high(p_list **pile_a, p_list **pile_b)
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

void	ft_fill_b_low(p_list **pile_a, p_list **pile_b)
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

/*int	main(int ac, char **av)
{
	int i = 1;	
	p_list *pile_a;
	p_list	*pile_b;
	p_list	*new;

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
	printf("Max : %d\nMediane : %d\n", ft_pilefind_max(pile_a), ft_find_mediane(pile_a));
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