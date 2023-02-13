/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:12:58 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/13 12:58:06 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. Push 2 number to STACK_A
2. Find the cheapest number -> calculer combien d'operations pour mettre dans la 
bonne position dans B. 1 Fonction pour calculer le nombre d'operations et push 
dans b quand c'est le cheapest.
3. Last three elements -> algo3.
4. Time to push back to STACK_A. On push tout dans A en checkant avant de push si
il va etre dans la bonne position (on check si pile_a->content est inf et si pile_a->next->content est supp?)
Si c'est pas le cas on rotate a jusqu'a que ce soit dans la bonne position.
5. Final arrangement -> reverse rotate jusqu'a que ce soit dans le bon ordre.
*/

p_list	*ft_nextlowest(int ref, p_list *pile_b)
{
	p_list	*current;
	int	min;

	current = pile_b;
	min = ft_pilefind_min(pile_b);
	while (pile_b)
	{
		if ((pile_b->content < ref) && (pile_b->next->content > min))
			min = pile_b->content;
		pile_b = pile_b->next;
	}
	if (min > ref)
	{
		while (current->content != min)
			current = current->next;
		return (current);
	}
	return (pile_b);
}

int	ft_chose_rotate(p_list *maillon, p_list *pile_b)
{
	int rr;
	int r;

	rr = 0;
	r = ft_pilesize(pile_b);
	while (maillon->next != NULL)
	{
		rr++;
		r--;
		maillon = maillon->next;
	}
	if (rr > r)
		return (r);
	else
		return (rr * (-1));
}

int	algo500(p_list **pile_a, p_list **pile_b)
{
	p_list	*current;
	int		move;
	//on envoit les deux premiers 
	ft_push_b(pile_a, pile_b);
	ft_push_b(pile_a, pile_b);
	//find cheapest number.
	current = *pile_a;
	move = 0;
	while (current != NULL)
	{
		move = ft_chose_rotate(ft_nextlowest(5, *pile_b), *pile_b);
		if (move > 0)
		{
			
		}
	}
	//last 3 elements
	algo3(pile_a);
	while (pile_b != NULL)
	{
		if (((*pile_b)->content > (*pile_a)->content) && 
			((*pile_b)->content < (*pile_a)->next->content))
			ft_push_a(pile_a, pile_b);
		else
			ft_rotate(pile_a);
	}
	return (1);
}

// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	p_list *pile_a;
// 	p_list *pile_b;
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
// 	//ft_print_pile(pile_a);
// 	//ft_printf("\n");
// //	ft_print_piles(pile_a, pile_b);
// 	//algo500(&pile_a, &pile_b);
// 	//ft_print_piles(pile_a, pile_b);
// 	printf("ici%d\n", ft_chose_rotate(pile_a, pile_b));
// 		ft_print_piles(pile_a, pile_b);
// 	//printf("ici %d", ft_find_pivot(pile_a));
// 	return (0);
// }