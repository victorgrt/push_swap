/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:59:37 by victor            #+#    #+#             */
/*   Updated: 2023/03/22 17:26:43 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

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

void	freetout(t_stack **stack_a, t_stack **stack_b, char *str)
{
	freelastack(stack_a);
	freelastack(stack_b);
	free(str);
}

void	jaideserreurs(t_stack **stack_a, t_stack **stack_b, char *str)
{
	write(1, "Error\n", 6);
	freetout(stack_a, stack_b, str);
	exit(0);
}

void	ft_reverse_rotate_b2(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*last;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *pile;
	*pile = last;
}
