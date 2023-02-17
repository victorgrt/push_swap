/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/17 12:37:26 by victor           ###   ########.fr       */
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
	int	*tab;
	int	i;
	int	j;
	int size;
	int	temp_int;
	p_list	*temp;

	temp = pile;
	size = ft_pilesize(temp);
	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	while(temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp_int = tab[i];
				tab[i] = tab[j];
				tab[j] = temp_int;
			}
			j++;
		}
		i++;
	}
	if (size % 2 == 0)
		return (tab[(size + 1) / 2]);
	else
		return (tab[size/2]);
}

void	ft_fill_b_high(p_list **pile_a, p_list **pile_b)
{
	int max;
	
	max = ft_pilefind_max(*pile_a);
	while (ft_pilesize(*pile_a) != 1)
	{
		if ((*pile_a)->content != max)
			ft_push_b(pile_a, pile_b);
		else
			ft_rotate(pile_a);
	}
}

void	ft_fill_b_low(p_list **pile_a, p_list **pile_b)
{
	int	mediane;
	int	i;
	int	size;

	size = ft_pilesize(*pile_a);
	i = -1;
	mediane = ft_find_mediane((*pile_a));
	while (i < size)
	{
		if ((*pile_a)->content < mediane)
			ft_push_b(pile_a, pile_b);
		else
			ft_rotate(pile_a);
		i++;
	}
}

int	ft_nexthighest(int ref, p_list *pile_b)
{
	p_list	*current;
	int		max;

	if (!pile_b)
		return (0);
	current = pile_b;
	max = ft_pilefind_max(pile_b);
	while (pile_b)
	{
		if ((pile_b->content > ref) && (!pile_b->next || (pile_b->next->content < max)))
			max = pile_b->content;
		pile_b = pile_b->next;
	}
	if (max < ref)
	{
		pile_b = current;
		while (pile_b->content != max)
			pile_b = pile_b->next;
		return (pile_b->content);
	}
	return (max);
}

int	ft_cost(p_list *pile_a, p_list	*pile_b)
{
	int	rota;
	int	min_rota;
	int	i;

	if (!pile_a || !pile_b)
        return (-666666);
	min_rota = 0;
	rota = ft_chose_rotate(pile_a, pile_b);
	if (rota >= 0)
	{
		if (ft_chose_rotate(pile_b->next, pile_b) < rota)
			min_rota = ft_chose_rotate(pile_b->next, pile_b);
		pile_b = pile_b->next;
	}
	else if (rota <= 0)
	{
		if (ft_chose_rotate(pile_b->next, pile_b) > rota)
			min_rota = ft_chose_rotate(pile_b->next, pile_b);
		pile_b = pile_b->next;
	}
	i = 1;
	if (min_rota < 0)
	{
		while (i > min_rota)
			i--;
	}
	else
	{
		while (i < min_rota)
			i++;
	}
	return(min_rota);
}

void	ft_push_next_highest(p_list **pile_a, p_list **pile_b)
{
	int		ref;
	int		min_cost;
	p_list	*current_b;
	int		next_highest;

	if (!pile_a || !*pile_a || !pile_b || !*pile_b)
       return ;
	min_cost = ft_cost(*pile_a, *pile_b);
	current_b = *pile_b;
	ref = 0;
	while (current_b)
	{
		if (ft_cost(*pile_a, current_b) < min_cost)
		{
			min_cost = ft_cost(*pile_a, current_b);
			ref = current_b->content;
		}
		current_b = current_b->next;
	}
	next_highest = ft_nexthighest(ref, *pile_a);
	//printf("ttttt %d\n", next_highest);
	while ((*pile_a)->content != next_highest)
	{
		//printf("test %d\n", (*pile_a)->content);
		ft_rotate(pile_a);
	}
	ft_push_a(pile_a, pile_b);
	//printf("travail termine");
}

// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	p_list *pile_a;
// 	p_list	*pile_b;
// 	p_list	*new;

// 	pile_a = 0;
// 	pile_b = 0;
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
// 	printf("Max : %d\nMediane : %d\n", ft_pilefind_max(pile_a), ft_find_mediane(pile_a));
// 	ft_print_piles(pile_a, pile_b);
// 	//algo5000(&pile_a, &pile_b);
// 	//ft_print_piles(pile_a, pile_b);
// 	 ft_fill_b_low(&pile_a, &pile_b);
// 	 ft_print_piles(pile_a, pile_b);
// 	 ft_fill_b_high(&pile_a, &pile_b);
// 	 ft_print_piles(pile_a, pile_b);
// 	 while (ft_pilesize(pile_b) != 0)
// 	 {
// 	 	ft_push_next_highest(&pile_a, &pile_b);
// 		ft_print_piles(pile_a, pile_b);
// 	 }
// 	 ft_print_piles(pile_a, pile_b);
// 	return (0);
// }