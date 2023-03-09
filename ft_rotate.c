/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:38:59 by victor            #+#    #+#             */
/*   Updated: 2023/03/09 16:39:30 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*first;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	first = *pile;
	temp = *pile;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*pile = first->next;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*first;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	first = *pile;
	temp = *pile;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*pile = first->next;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_reverse_rotate_a(t_stack **pile)
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
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack **pile)
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
	write(1, "rrb\n", 4);
}

/*int main(int argc, char **argv)
{
    t_stack *pile_a = NULL;
    t_stack *pile_b = NULL;
    t_stack *temp = NULL;
    int i;

    if (argc != 7)
    {
        printf("Met 6 arguments");
        return 1;
    }
    for (i = 1; i <= 3; i++)
    {
        temp = (t_stack *)malloc(sizeof(t_stack));
        temp->content = atoi(argv[i]);
        temp->next = pile_a;
        pile_a = temp;
    }

    for (i = 4; i <= 6; i++)
    {
        temp = (t_stack *)malloc(sizeof(t_stack));
        temp->content = atoi(argv[i]);
        temp->next = pile_b;
        pile_b = temp;
    }

    printf("Pile a avant : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    printf("Pile b avant : ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    ft_rotate(&pile_a);
    ft_rotate(&pile_b);

    printf("Pile a après : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    printf("Pile b après : ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    return 0;
}*/
