/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/30 14:40:11 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.*/
void	ft_swap(p_list **pile)
{
	p_list	*temp;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
}

void	ft_swap_s(p_list **pile_a, p_list **pile_b)
{
	ft_swap(pile_a);
	ft_swap(pile_b);
}

// int main(int argc, char **argv)
// {
//     p_list *pile_a = NULL;
//     p_list *pile_b = NULL;
//     p_list *temp = NULL;
//     int i;

//     if (argc != 7)
//     {
//         printf("Met 6 arguments");
//         return 1;
//     }
//     for (i = 1; i <= 3; i++)
//     {
//         temp = (p_list *)malloc(sizeof(p_list));
//         temp->content = atoi(argv[i]);
//         temp->next = pile_a;
//         pile_a = temp;
//     }

//     for (i = 3; i < 6; i++)
//     {
//         temp = (p_list *)malloc(sizeof(p_list));
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