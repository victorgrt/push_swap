/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:18:29 by victor            #+#    #+#             */
/*   Updated: 2023/03/18 14:17:15 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "push_swap.h"

void	*execute_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
    if (ft_strncmp(instruction, "sa\n", 3) == 0)
        ft_swap_a(stack_a);
    else if (ft_strncmp(instruction, "sb\n", 3) == 0)
        ft_swap_b(stack_b);
    else if (ft_strncmp(instruction, "pa\n", 3) == 0)
        ft_push_a(stack_a, stack_b);
    else if (ft_strncmp(instruction, "pb\n", 3) == 0)
        ft_push_b(stack_b, stack_a);
    else if (ft_strncmp(instruction, "ra\n", 3) == 0)
        ft_rotate_a(stack_a);
    else if (ft_strncmp(instruction, "rb\n", 3) == 0)
        ft_rotate_b(stack_b);
    else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		ft_rotate_both(stack_a, stack_b);
    else if (ft_strncmp(instruction, "rra\n", 4) == 0)
        ft_reverse_rotate_a(stack_a);
    else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
        ft_reverse_rotate_b(stack_b);
    else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
        ft_reverse_rotate_both(stack_a, stack_b);
	else
		jaideserreurs(stack_a, stack_b, instruction);
	return (get_next_line(0, 0));
}

// void    ft_boucle_read(t_stack **pile_a, t_stack **pile_b, char *str)
// {
//     char    *tmp;

//     while (str != 0)
//     {
//         tmp = str;
//         str = exec
//         free(tmp);
//     }
//     if (execute_instruction(&pile_a, &pile_b, str) == 0)
//         write(1, "KO\n", 3);
// }

int main(int ac, char **av)
{
	char *line;
	t_stack	*pile_a;
	t_stack	*pile_b;
    t_stack *new;
    int i = 1;
	
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
	if (ft_check_croissant(pile_a) == 0)
	{
		ft_free_list(pile_a);
		return (0);
	}
	line = get_next_line(0, 0);
	printf("1 : %s\n", line);
	ft_dispache(&pile_a, &pile_b);
	printf("2 : %s\n", line);
	line = get_next_line(0, 1);
	printf("3 : %s\n", line);
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