/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:04:50 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/09 12:43:56 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_pivot(p_list *pile)
{
	p_list	*slow;
	p_list	*fast;

	slow = pile;
	fast = pile;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow->content);
}

void	ft_popsplit(p_list **pile_a, p_list **pile_b, int pivot)
{
	while (*pile_a && (*pile_a)->content < pivot)
		ft_push_b(pile_a, pile_b);
}

int	algo100(p_list **pile_a, p_list **pile_b)
{
	p_list	*current;
	p_list	*current2;
	int	pivot;
	
	if (ft_check_croissant(*pile_a) == 0)
	{
		ft_printf("Pile deja dans l'ordre croissant");
		return (0);
	}
	pivot = ft_find_pivot(*pile_a);
	printf("pivot%d", pivot);
	current = *pile_a;
	while (current != NULL)
	{
		if (current->content <= pivot)
		{
			ft_push_b(pile_a, pile_b);
			ft_popsplit(pile_a, pile_b, pivot);
			current = current->next;
		}
		else
			current = current->next;
	}
	algo3(pile_a);
	current2 = *pile_b;
	while (current2 != NULL)
	{
		ft_push_a(pile_a, pile_b);
		current2 = current2->next;
	}
	algo5(pile_a, pile_b);
	/*current2 = *pile_b;
	while (current2 != NULL)
	{
		if (current2->content > pivot)
		{
			ft_push_a(pile_a, pile_b);
			ft_popsplit(pile_a, pile_b, pivot);
			current2 = current2->next;
		}
		else
			current2 = current2->next;
	}*/
	return (0);
}

int	main(int ac, char **av)
{
	int i = 1;
	p_list *pile_a;
	p_list *pile_b;
	p_list	*new;

	pile_a = 0;
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
	ft_print_piles(pile_a, pile_b);
	algo100(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b);
	//printf("ici %d", ft_find_pivot(pile_a));
	return (0);
}