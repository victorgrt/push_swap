/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:01:35 by victor            #+#    #+#             */
/*   Updated: 2023/03/18 13:39:32 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc2(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc2(1, 1);
	if (!s1 || !s2)
		return (free(s1), free(s2), NULL);
	new = malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!new)
		return (free(s1), free(s2), NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (free(s1), new);
}

/*#include <stdio.h>
int	main(void)
{
	char test[] = "Hello World \n Ceci est un message\n TESST";
	printf("%s", ft_strchr(test, '\n'));
	return (0);
}*/