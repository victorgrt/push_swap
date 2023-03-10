/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:26:47 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/10 15:42:49 by vgoret           ###   ########.fr       */
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
	if (ft_pilesize(*pile_a) == 2 && ft_check_croissant(*pile_a) == 1)
		ft_rotate_a(pile_a);
	if (ft_pilesize(*pile_a) == 3)
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

	pile_a = NULL;
	pile_b = NULL;
	new = NULL;
	if (ac == 1)
		return (0);
	if (ft_master_checker(av, ac) == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		if (new == NULL)
			return (1);
		ft_pileadd_back(&pile_a, new);
		i++;
	}
	if (ft_check_croissant(pile_a) == 0)
	{
		ft_free_list(pile_a);
		return (0);
	}
	ft_dispache(&pile_a, &pile_b);
	return (0);
}
