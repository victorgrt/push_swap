/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:58:39 by victor            #+#    #+#             */
/*   Updated: 2023/03/09 16:39:30 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack **pile_a, t_stack **pile_b)
{
	t_stack		*temp;

	if (!pile_b || !*pile_b)
		return ;
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	ft_pileadd_front(pile_a, temp);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*temp;

	if (!pile_a || !*pile_a)
		return ;
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	ft_pileadd_front(pile_b, temp);
	write(1, "pb\n", 3);
}

// int main(int argc, char **argv)
// {
//     t_stack *pile_a = NULL;
//     t_stack *pile_b = NULL;
//     t_stack *temp = NULL;
//     int i;

//     if (argc != 7)
//     {
//         printf("Met 6 arguments");
//         return 1;
//     }
//     for (i = 1; i <= 3; i++)
//     {
//         temp = (t_stack *)malloc(sizeof(t_stack));
//         temp->content = atoi(argv[i]);
//         temp->next = pile_a;
//         pile_a = temp;
//     }

//     for (i = 3; i < 6; i++)
//     {
//         temp = (t_stack *)malloc(sizeof(t_stack));
//         temp->content = atoi(argv[i]);
//         temp->next = pile_b;
//         pile_b = temp;
//     }

//     printf("Pile a avant : ");
//     for (temp = pile_a; temp; temp = temp->next)
//         printf("%d ", temp->content);
//     printf("\n");

//     printf("Pile b avant : ");
//     for (temp = pile_b; temp; temp = temp->next)
//         printf("%d ", temp->content);
//     printf("\n");

//     ft_push_b(&pile_a, &pile_b);

//     printf("Pile a après : ");
//     for (temp = pile_a; temp; temp = temp->next)
//         printf("%d ", temp->content);
//     printf("\n");

//     printf("Pile b après : ");
//     for (temp = pile_b; temp; temp = temp->next)
//         printf("%d ", temp->content);
//     printf("\n");

//     return 0;
// }