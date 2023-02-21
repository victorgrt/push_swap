/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:58:44 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/21 16:28:30 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

p_list	*ft_lstnew_int(long content)
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