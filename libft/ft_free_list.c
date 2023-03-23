/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:16:41 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/23 11:30:01 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_stack *list)
{
	if (!list)
		return ;
	ft_free_list(list->next);
	free(list);
}

void	ft_free_list2(t_stack *pile)
{
	t_stack	*tmp;

	while (pile != NULL)
	{
		tmp = pile;
		pile = pile->next;
		free(tmp);
	}
}
