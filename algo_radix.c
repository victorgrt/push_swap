/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:09:50 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/13 14:06:25 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_max_digits(p_list *pile_a)
{
	int max_digits;
	p_list *current;
	
	max_digits = 0;
	current = pile_a;
	while (current != NULL)
	{
		int n = current->content;
		int count = 0;
		while (n != 0)
		{
			count++;
			n /= 10;
		}
		if (count > max_digits)
			max_digits = count;
		current = current->next;
	}
return (max_digits);
}

int	ft_get_digit(int n, int digit_num)
{
	int	i;

	i = 0;
	while (i < digit_num - 1)
	{
		n /= 10;
		i++;
	}
	return (n % 10);
}

void ft_sort_digit(p_list **pile_a, p_list **pile_b, int digit_num)
{
	p_list *current;

	current = *pile_a;
	while (current != NULL)
	{
		if (ft_get_digit(current->content, digit_num) == 0)
			ft_push_b(pile_a, pile_b);
		else
			ft_push_a(pile_b, pile_a);
		current = current->next;
	}
}

int	algo_radix(p_list **pile_a, p_list **pile_b)
{
	int	max;
	int	current_digit;
	p_list	*current;

	if (ft_check_croissant(*pile_a) == 0)
	{
		ft_printf("Pile deja dans l'ordre croissant");
		return (0);
	}
	max = ft_max_digits(*pile_a);
	current_digit = 1;
	while (current_digit <= max)
	{
		ft_sort_digit(pile_a, pile_b, current_digit);
		current_digit++;
	}
	current = *pile_b;
	while (current->next)
	{
		ft_push_a(pile_a, pile_b);
		current = current->next;
	}
	return (0);
}


// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	p_list *pile_a;
// 	p_list *pile_b;
// 	p_list	*new;

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
// 	ft_print_pile(pile_a);
// 	//ft_printf("\n");
// 	//ft_print_piles(pile_a, pile_b);
// 	algo_radix(&pile_a, &pile_b);
// 	ft_print_piles(pile_a, pile_b);
// 	//printf("ici %d", ft_find_pivot(pile_a));
// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	p_list *pile_a;
// 	p_list *pile_b;
// 	p_list	*new;

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
// 	//ft_print_pile(pile_a);
// 	//ft_printf("\n");
// 	//ft_print_piles(pile_a, pile_b);
// 	algo_radix(&pile_a, &pile_b);
// 	//ft_print_piles(pile_a, pile_b);
// 	//printf("ici %d", ft_find_pivot(pile_a));
// 	return (0);
// }