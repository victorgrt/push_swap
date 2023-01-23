/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:58:39 by victor            #+#    #+#             */
/*   Updated: 2023/01/23 15:29:56 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_a(p_list **pile_a, p_list **pile_b)
{
    p_list  *temp;

    if (!pile_b || !*pile_b)
        return ;
    temp = *pile_b;//on stock le premier element de b
    *pile_b = (*pile_b)->next;// on fait poitter le premier vers le deuxieme
    temp->next = *pile_a;//on fait pointer le suivant de temp vers le premier de A
    *pile_a = temp; //on fait pointer a vers temp pour contient le premier element de b
}

void	ft_push_b(p_list **pile_a, p_list **pile_b)
{
	p_list	*temp;

	if (!pile_a || !*pile_a)
		return ;
	temp = *pile_a; //on stock le premier el dans temp;
	*pile_a = (*pile_a)->next;//on fait avancer la pile A
	temp->next = *pile_b;//on fait pointer le suivant de temp vers elem 1 de b
	*pile_b = temp; //on assigne au premier element de b temp;
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