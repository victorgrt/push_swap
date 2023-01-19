/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:28:39 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/19 16:32:22 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

p_list	*ft_lstlast_p(p_list *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next)
		pile = pile->next;
	return (pile);
}
