/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:59:37 by victor            #+#    #+#             */
/*   Updated: 2023/03/18 14:05:03 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

void	freetout(t_stack **stack_a, t_stack **stack_b, char *str)
{
	freelastack(stack_a);
	freelastack(stack_b);
	free(str);
}

void	jaideserreurs(t_stack **stack_a, t_stack **stack_b, char *str)
{
	ft_putstr_fd("Error\n", 2);
	freetout(stack_a, stack_b, str);
	get_next_line(0, 1);
	exit(0);
}

void	freelastack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}