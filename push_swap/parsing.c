/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:58:10 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/25 17:54:37 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

// int main(int ac, char **av)
// {
// 	int i = 1;
// 	p_list	*pile_a;
// 	p_list	*pile_b;
// 	p_list	*new;

// 	if (ac < 2)
// 	{
// 		printf("Pas assez d'arguments");
// 		return (1);
// 	}
// 	while (i < ac)
// 	{
// 		if (ft_master_checker(av, ac) == 0)
// 		{
// 			if (i == 1)
// 			{	
// 				pile_a = ft_pilenew(ft_atol(av[1]));
// 				pile_b = ft_pilenew(0);
// 			}
// 			new = ft_pilenew(ft_atol(av[i]));
// 			ft_pileadd_front(&pile_a, new);
// 			new = 0;
// 			ft_pileadd_front(&pile_b, new);
// 			i++;
// 		}
// 		else if (ft_master_checker(av, ac) == 1)
// 		{
// 			printf("C'est pas un int");
// 			return (1);
// 		}
// 		else if (ft_master_checker(av, ac) == 2)
// 		{
// 			printf("Doublon");
// 			return (1);
// 		}
// 	}
// 	while (pile_a->next)
// 	{
// 		printf("%d\t", pile_a->content);
// 		printf("%d\n", pile_b->content);
// 		pile_a = pile_a->next;
// //		pile_b = pile_b->next;
// 	}
// 	return (0);
// }

/*int main(int ac, char **av)
{
	int i = 1;
	int j;
	p_list	*pile_a;
	//p_list	*pile_b;
	p_list	*new;

	if (ft_check_args(av, ac) == 1)
	{
		printf("Erreur : /!\\ Doublons /!\\");
		return (1);
	}
	pile_a = ft_lstnew_int(ft_atol(av[1])); 
	if (ac < 2)
	{
		printf("Pas assez d'arguments");
		return (1);
	}
	while (i < ac - 1)
	{
		j = i+1;
		if (ft_atol(av[i]) == 2147483648)
		{
			printf("Erreur : l'argument numero %d n'est pas un int", i);
			return (1);
		}
		if (ft_atol(av[i]) == 2147483650)
		{
			printf("Erreur : l'argument numero %d n'est pas un int", i);
			return (1);
		}

		new = ft_lstnew_int(ft_atol(av[j]));
		ft_lstadd_back_p(&pile_a, new);
	
		i++;
		j++;
	}
	//	ft_rotate(&pile_a);
	printf("Taille de la pile_a : \033[32\033[1m%d\033[0m\n", ft_lstsize_p(pile_a));
	i = 1;
	while (i < ac)
	{
		printf("\npile_a(%d) :%d", i, pile_a->content);
		pile_a = pile_a->next;
		i++;
	}
	i = 1;

	
	
	return (0);
}*/