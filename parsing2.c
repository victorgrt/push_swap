/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:58:10 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/19 16:50:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	int	signe;
	long	resultat;

	signe = 1;
	i = 0;
	resultat = 0;
	if (!str)
		return (-6660006666);
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
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
			resultat = -6660006666;
	}
	resultat = resultat * signe;
	if ((resultat > INT_MAX) || (resultat < INT_MIN))
		resultat = -6660006666;
	return (resultat);
}

static int	ft_len_nb(int n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

long	ft_check_max_int(char *str)
{
	int	i;
	long	resultat;
	long	len;

	i = 0;
	len = 0;
	while (!(str[i] >= 1 && str[i] <= '9'))
		i++;
	resultat = ft_atol(&str[i]);
	len = ft_len_nb(resultat);
	return (len);
}

// int main(int ac, char **av)
// {
// 	int i = 1;

// 	while (i < ac)
// 	{
// 		printf("%ld\n", ft_check_max_int(av[i]));
// 		i++;
// 	}	
// 	return (0);
// }

int	ft_check_args(char **av, int ac)
{
	int	i;
	int j;

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
			//printf("%lld\t%lld\n", ft_atol(&av[i]), ft_atol(&av[j]));
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (i < ac)
// 	{
// 		printf("%d\n", ft_check_args(av[i], ac));
// 		i++;
// 	}
// 	return (0);
// }

int main(int ac, char **av)
{
	int i = 1;
	int j;
	p_list	*pile_a;
	//p_list	*pile_b;
	p_list	*new;

	pile_a = ft_lstnew_int(ft_atol(av[i])); 
	if (ac < 2)
	{
		printf("Pas assez d'arguments");
		return (1);
	}
	while (i < ac - 1)
	{

		j = i+1;
		if (ft_check_args(av, ac) == 1)
		{
			printf("Erreur : /!\\ Doublons /!\\");
			return (1);
		}
		if (ft_atol(av[i]) == -6660006666)
		{
			printf("Erreur : l'argument numero %d n'est pas un int", i);
			return (1);
		}

		new = ft_lstnew_int(ft_atol(av[j]));
		ft_lstadd_back_p(&pile_a, new);
		i++;
		j++;
	}
	printf("Taille de la pile_a : \033[32\033[1m%d\033[0m\n", ft_lstsize_p(pile_a));
	i = 1;
	while (i < ac)
	{
		printf("\npile_a(%d) :%d", i, pile_a->content);
		pile_a = pile_a->next;
		i++;
	}
	
	return (0);
}