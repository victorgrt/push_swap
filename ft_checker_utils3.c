/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:24:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/22 17:25:09 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_rotate_both2(t_stack **pile_a, t_stack **pile_b)
{
	t_stack		*temp;

	if (*pile_a && (*pile_a)->next)
	{
		temp = *pile_a;
		while (temp->next)
			temp = temp->next;
		temp->next = *pile_a;
		temp = (*pile_a)->next;
		(*pile_a)->next = NULL;
		*pile_a = temp;
	}
	if (*pile_b && (*pile_b)->next)
	{
		temp = *pile_b;
		while (temp->next)
			temp = temp->next;
		temp->next = *pile_b;
		temp = (*pile_b)->next;
		(*pile_b)->next = NULL;
		*pile_b = temp;
	}
}

void	ft_reverse_rotate_both2(t_stack **pile_a, t_stack **pile_b)
{
	t_stack		*temp;

	if (*pile_a && (*pile_a)->next)
	{
		temp = *pile_a;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *pile_a;
		*pile_a = temp->next;
		temp->next = NULL;
	}
	if (*pile_b && (*pile_b)->next)
	{
		temp = *pile_b;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *pile_b;
		*pile_b = temp->next;
		temp->next = NULL;
	}
}

void	ft_swap_a2(t_stack **pile)
{
	t_stack	*temp;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
}

void	ft_swap_b2(t_stack **pile)
{
	t_stack	*temp;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
}

void	ft_swap_s2(t_stack **pile_a, t_stack **pile_b)
{
	ft_swap_a2(pile_a);
	ft_swap_b2(pile_b);
}
