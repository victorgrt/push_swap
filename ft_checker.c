/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:12:25 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 17:39:38 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			return (1);
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_master_checker(char **av, int ac)
{
	int		i;
	long	atol;

	i = 1;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (1);
		atol = ft_atol(av[i]);
		if (atol < -2147483648 || atol > 2147483647)
			return (1);
		if (ft_check_args(av, ac) == 1)
			return (1);
		i++;
	}
	return (0);
}	

/*int	main(int ac, char **av)
{
	printf("%d\n", ft_master_checker(av, ac));
	return (0);
}*/