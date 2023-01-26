/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:12:58 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/26 16:18:40 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
// 			ft_pileadd_front(&pile_b, 0);
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
// 	push_swap(&pile_a, &pile_b);
// 	printf("Instructions :\n");
// 	while (pile_a->next)
// 	{
// 		printf("%d\n", pile_a->content);
// 		pile_a = pile_a->next;
// 	}
// 	return (0);
// }