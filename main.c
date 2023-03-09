/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:26:47 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 19:05:54 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int ac, char **av, t_stack **pile_a, t_stack *new)
{
	int	i;	

	i = 1;
	while (i < ac)
	{
		if (ft_master_checker(av, ac) == 0)
		{
			new = ft_pilenew(ft_atol(av[i]));
			ft_pileadd_back(pile_a, new);
			i++;
		}
		else if (ft_master_checker(av, ac) == 1)
			return (1);
	}
	return (0);
}

void	ft_dispache(t_stack **pile_a, t_stack **pile_b)
{
	if (ft_check_croissant(*pile_a) == 0)
		return ;
	if (ft_pilesize(*pile_a) <= 3)
		algo3(pile_a);
	else if (ft_pilesize(*pile_a) <= 5)
		algo5(pile_a, pile_b);
	else if (ft_pilesize(*pile_a) > 5)
		algo_big(pile_a, pile_b);
	ft_free_list(*pile_a);
	ft_free_list(*pile_b);
}

int	main(int ac, char **av)
{
	t_stack	*pile_a;
	t_stack	*pile_b;
	t_stack	*new;	
	int		i;

	if (ac == 1)
		return (0);
	pile_a = 0;
	pile_b = 0;
	new = 0;
	if (ft_master_checker(av, ac) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_back(&pile_a, new);
		i++;
	}
	ft_dispache(&pile_a, &pile_b);
	return (0);
}
