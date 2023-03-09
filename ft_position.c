/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:20:49 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 17:28:29 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_pos(t_stack **pile)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = (*pile);
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}
