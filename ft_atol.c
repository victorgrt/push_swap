/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:20:22 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/30 14:45:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		len;
	int		signe;
	long	resultat;

	len = 0;
	signe = 1;
	i = 0;
	resultat = 0;
	if (!str)
		return (2147483648);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - 48;
		if (str[i] != '0')
			len++;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
			resultat = 2147483649;
	}
	if (len > 10)
		return (2147483650);
	return (resultat * signe);
}
