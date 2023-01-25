/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:26:28 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/25 14:56:01 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pileadd_back(p_list **lst, p_list *new)
{
	p_list	*boeuf;

	if (*lst)
	{
		boeuf = ft_pilelast(*lst);
		boeuf->next = new;
	}
	else
		*lst = new;
}
