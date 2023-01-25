/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilelast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:28:39 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/25 14:54:34 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

p_list	*ft_pilelast(p_list *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next)
		pile = pile->next;
	return (pile);
}
