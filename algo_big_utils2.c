/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:44:32 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 16:48:00 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_both2(t_stack **pa, t_stack *next)
{
	while (next->position != 1)
	{
		if (next->position <= (ft_size_comp(*pa)))
		{
			ft_rotate_a(pa);
			ft_set_pos(pa);
		}
		else if (next->position > (ft_size_comp(*pa)))
		{
			ft_reverse_rotate_a(pa);
			ft_set_pos(pa);
		}
	}
}
