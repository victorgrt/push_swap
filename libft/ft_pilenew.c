/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:12:50 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/30 16:12:51 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

p_list	*ft_pilenew(int content)
{
	p_list	*new;

	new = malloc(sizeof(p_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int	main(void)
{
	char	tab[] = "BABINKS";
	printf("%s\n", (char *)(ft_lstnew(tab)->content));
	return (0);
}*/