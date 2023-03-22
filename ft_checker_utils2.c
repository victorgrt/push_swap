/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:19:38 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/22 17:24:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_push_a2(t_stack **pile_a, t_stack **pile_b)
{
	t_stack		*temp;

	if (!pile_b || !*pile_b)
		return ;
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	ft_pileadd_front(pile_a, temp);
}

void	ft_push_b2(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*temp;

	if (!pile_a || !*pile_a)
		return ;
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	ft_pileadd_front(pile_b, temp);
}

void	ft_rotate_a2(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*first;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	first = *pile;
	temp = *pile;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*pile = first->next;
	first->next = NULL;
}

void	ft_rotate_b2(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*first;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	first = *pile;
	temp = *pile;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*pile = first->next;
	first->next = NULL;
}

void	ft_reverse_rotate_a2(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*last;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *pile;
	*pile = last;
}
