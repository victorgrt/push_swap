/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:45:54 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/27 16:47:01 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_both(p_list **pile_a, p_list **pile_b)
{
	p_list		*temp;

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
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate_both(p_list **pile_a, p_list **pile_b)
{
	p_list		*temp;

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
	write(1, "rrr\n", 4);
}
