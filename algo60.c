/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo60.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:02:04 by victor            #+#    #+#             */
/*   Updated: 2023/04/07 14:57:16 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo60(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*cheap;
	t_stack	*next;

	ft_fill_b_high(pile_a, pile_b);
	ft_set_pos(pile_a);
	ft_set_pos(pile_b);
	cheap = cheapest(*pile_a, *pile_b);
	next = find_next_highest(cheap->content, *pile_a);
	ft_push_a(pile_a, pile_b);
	ft_2ndpart(pile_a, pile_b, cheap, next);
	while (ft_check_croissant(*pile_a) == 1)
		ft_rotate_a(pile_a);
}
