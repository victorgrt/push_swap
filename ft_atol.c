/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:20:22 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/30 16:11:32 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atol_error_print(char *str)
{
	if (ft_atol_check(str) == 1)
		ft_printf("Pas de string a convertir en int");
	else if (ft_atol_check(str) == 2)
		ft_printf("L'argument n'est pas un int");
	else if (ft_atol_check(str) == 3)
		ft_printf("Nombre trop petit ou trop grand");
}

int	ft_atol_check(char *str)
{
	int		i;
	int		len;
	long	resultat;

	len = 0;
	i = 0;
	resultat = 0;
	if (!str)
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - 48;
		if (str[i] != '0')
			len++;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
			return (2);
	}
	if (len > 10)
		return (3);
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	int		signe;
	long	resultat;

	if (ft_atol_check(str) != 0)
		return (2147483649);
	signe = 1;
	i = 0;
	resultat = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - 48;
		i++;
	}
	return (resultat * signe);
}

/*int	main(int ac, char **av)
{
	int i = 1;
	p_list	*pile_a;
	p_list	*new;

	pile_a = 0;
	if (ac < 2)
	{
		ft_atol_error_print(av[i]);
		return (1);
	}
	while (i < ac)
	{
		if (ft_atol(av[i]) >= INT_MAX || ft_atol_check(av[i]) != 0)
		{
			ft_atol_error_print(av[i]);
			return (1);
		}
		if (ft_check_args(av, ac) != 0)
		{
			ft_printf("Doublons");
			return (1);
		}
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_back(&pile_a, new);
		i++;
	}
	ft_print_pile(pile_a);
	return (0);
}*/