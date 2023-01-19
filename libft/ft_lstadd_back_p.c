/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:26:28 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/19 16:27:19 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_p(p_list **lst, p_list *new)
{
	p_list	*boeuf;

	if (*lst)
	{
		boeuf = ft_lstlast_p(*lst);
		boeuf->next = new;
	}
	else
		*lst = new;
}
