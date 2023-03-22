/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:18:29 by victor            #+#    #+#             */
/*   Updated: 2023/03/22 17:30:02 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "push_swap.h"

#include <stdio.h>

void	execute_instruction(t_stack **stack_a, t_stack **stack_b, char *instruc)
{
	if (ft_strncmp(instruc, "sa\n", 3) == 0)
		ft_swap_a2(stack_a);
	else if (ft_strncmp(instruc, "sb\n", 3) == 0)
		ft_swap_b2(stack_b);
	else if (ft_strncmp(instruc, "ss\n", 3) == 0)
		ft_swap_s2(stack_a, stack_b);
	else if (ft_strncmp(instruc, "pa\n", 3) == 0)
		ft_push_a2(stack_a, stack_b);
	else if (ft_strncmp(instruc, "pb\n", 3) == 0)
		ft_push_b2(stack_a, stack_b);
	else if (ft_strncmp(instruc, "ra\n", 3) == 0)
		ft_rotate_a2(stack_a);
	else if (ft_strncmp(instruc, "rb\n", 3) == 0)
		ft_rotate_b2(stack_b);
	else if (ft_strncmp(instruc, "rr\n", 3) == 0)
		ft_rotate_both2(stack_a, stack_b);
	else if (ft_strncmp(instruc, "rra\n", 4) == 0)
		ft_reverse_rotate_a2(stack_a);
	else if (ft_strncmp(instruc, "rrb\n", 4) == 0)
		ft_reverse_rotate_b2(stack_b);
	else if (ft_strncmp(instruc, "rrr\n", 4) == 0)
		ft_reverse_rotate_both2(stack_a, stack_b);
	else
		jaideserreurs(stack_a, stack_b, instruc);
}

void	ft_boucle_read(t_stack *pile_a, t_stack *pile_b)
{
	char	*line;
	int		last_size;

	line = "test";
	last_size = 1;
	while (line && last_size)
	{
		line = get_next_line(0, 0);
		if (!line)
			break ;
		last_size = ft_strlen(line);
		if (last_size == 0)
			break ;
		execute_instruction(&pile_a, &pile_b, line);
		free(line);
	}
	if (ft_check_croissant(pile_a) == 0 && ft_pilesize(pile_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*pile_a;
	t_stack	*pile_b;
	t_stack	*new;
	int		i;

	i = 1;
	pile_a = NULL;
	pile_b = NULL;
	new = NULL;
	if (ac <= 2)
		return (0);
	if (ft_master_checker(av, ac) == 1)
		return (0);
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		if (new == NULL)
			return (1);
		ft_pileadd_back(&pile_a, new);
		i++;
	}
	ft_boucle_read(pile_a, pile_b);
	ft_free_list(pile_a);
	ft_free_list(pile_b);
	return (0);
}

// int	main(int ac, char **av)
// {	
// 	t_stack	*pile_a;
// 	t_stack	*pile_b;
//     t_stack *new;

// 	char 	*str;
//     int i = 1;
// 	if (ac <= 2)
// 		return (0);
// 	if (ft_master_checker(av, ac) == 1)
//         return (0);
// 	str = get_next_line(0);
// 	pile_b = NULL;
// 	while (i < ac)
// 	{
// 		new = ft_pilenew(ft_atol(av[i]));
// 		if (new == NULL)
// 			return (1);
// 		ft_pileadd_back(&pile_a, new);
// 		i++;
// 	}
// 	boucle_read(pile_a, pile_b, str);
//     free(pile_a);
//     free(pile_b);
// 	return (0);
// }