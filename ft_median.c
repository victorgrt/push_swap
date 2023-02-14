/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/14 16:09:01 by vgoret           ###   ########.fr       */
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
	tab = malloc(sizeof(int) * size + 1);
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
	printf("Max : %d\n", max);
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
//Combien de coups pour le mettre tout en haut de la pile b -> rotate ou reverse rotate
// int	ft_cost_getup(p_list **pile)
// {
// 	int	i;

// 	i = 0;
	
// }

//Faire la diff entre contenu et closest
int	ft_cost_closestinA(p_list *pile, int contenu)
{
	int	closest;
	//int	closestval;

	closest = INT_MAX;
	while (pile != NULL)
	{
		if ((pile->content - contenu) < closest)
		{
			closest = pile->content - contenu;
			//closestval = pile->content;
		}
		pile = pile->next;
	}
	return (closest);
}

//marche pas du tout
// p_list	*ft_find_mediane(p_list *pile)
// {
// 	p_list	*sorted;
// 	p_list	*start;

// 	sorted = pile;
// 	start = sorted;
// 	while (sorted->next)
// 	{
// 		if (sorted->content > sorted->next->content)
// 		{
// 			ft_swap(&sorted);
// 		}
// 		sorted = sorted->next;
// 	}
// 	return (start);
// }

int	main(int ac, char **av)
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

	//ft_print_pile(pile_a);
	//ft_printf("\n");
	//mediane = ft_find_mediane(pile_a);
	ft_print_piles(pile_a, pile_b);
	//ft_find_mediane(pile_a);
	printf("Mediane :%d\n", ft_find_mediane(pile_a));
		printf("Closest : %d\n", ft_cost_closestinA(pile_a, 40));
	// ft_fill_b_low(&pile_a, &pile_b);
	// ft_fill_b_high(&pile_a, &pile_b);
	// ft_print_piles(pile_a, pile_b);
	//printf("ici %d", ft_find_pivot(pile_a));
	return (0);
}