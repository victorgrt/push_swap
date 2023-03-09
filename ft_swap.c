/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 16:39:30 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.*/
void	ft_swap_a(t_stack **pile)
{
	t_stack	*temp;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **pile)
{
	t_stack	*temp;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
	write(1, "sb\n", 3);
}

void	ft_swap_s(t_stack **pile_a, t_stack **pile_b)
{
	ft_swap_a(pile_a);
	ft_swap_b(pile_b);
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