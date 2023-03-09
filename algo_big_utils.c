/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:50:34 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 16:46:20 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_comp(t_stack *pile)
{
	return ((ft_pilesize(pile) / 2) + (ft_pilesize(pile) % 2));
}

void	ft_under(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next)
{	
	while (cheap->position != 1 && next->position != 1)
	{
		ft_rotate_both(pa, pb);
		ft_set_pos(pa);
		ft_set_pos(pb);
	}
	if (cheap->position != 1)
	{
		while (cheap->position != 1)
		{
			ft_rotate_b(pb);
			ft_set_pos(pb);
		}
	}
	else if (next->position != 1)
	{
		while (next->position != 1)
		{
			ft_rotate_a(pa);
			ft_set_pos(pa);
		}
	}
}

void	ft_upper(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next)
{
	while (cheap->position != 1 && next->position != 1)
	{
		ft_reverse_rotate_both(pa, pb);
		ft_set_pos(pa);
		ft_set_pos(pb);
	}
	if (cheap->position != 1)
	{
		while (cheap->position != 1)
		{
			ft_reverse_rotate_b(pb);
			ft_set_pos(pb);
		}
	}
	else if (next->position != 1)
	{
		while (next->position != 1)
		{
			ft_reverse_rotate_a(pa);
			ft_set_pos(pa);
		}
	}
}

void	ft_both(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next)
{
	while (cheap->position != 1)
	{
		if (cheap->position <= (ft_size_comp(*pb)))
		{
			ft_rotate_b(pb);
			ft_set_pos(pb);
		}
		else if (cheap->position > (ft_size_comp(*pb)))
		{
			ft_reverse_rotate_b(pb);
			ft_set_pos(pb);
		}
	}
	ft_both2(pa, next);
}

void	ft_2ndpart(t_stack **pa, t_stack **pb, t_stack *cheap, t_stack *next)
{
	while (ft_pilesize(*pb) != 0)
	{
		cheap = cheapest(*pa, *pb);
		next = find_next_highest(cheap->content, *pa);
		ft_set_pos(pa);
		ft_set_pos(pb);
		if ((cheap->position <= (ft_size_comp(*pb)))
			&& (next->position <= (ft_size_comp(*pa))))
			ft_under(pa, pb, cheap, next);
		else if ((cheap->position > (ft_size_comp(*pb)))
			&& (next->position > (ft_size_comp(*pa))))
			ft_upper(pa, pb, cheap, next);
		else
			ft_both(pa, pb, cheap, next);
		ft_push_a(pa, pb);
	}
}
