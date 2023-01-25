/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:38:59 by victor            #+#    #+#             */
/*   Updated: 2023/01/23 16:21:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(p_list **pile)
{
	p_list	*temp;
	p_list	*first;

	if (!pile || !*pile || !(*pile)->next)
		return ;
	first = *pile;
	temp = *pile;
	while (temp->next)
		temp = temp->next; //je fais aller temp a a fin
	temp->next = first; //je met le premier a la fin
	*pile = first->next;//je fais pointer le premier element vers le deuxieme de pile
	first->next = NULL;
}


void	ft_reverse_rotate(p_list **pile)
{
	p_list	*temp;
	p_list	*last;

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

void ft_rotate_both(p_list **pile_a, p_list **pile_b)
{
    p_list *temp;
    if (*pile_a && (*pile_a)->next)
    {
        temp = *pile_a;
        while (temp->next)
            temp = temp->next;
        temp->next = *pile_a;
        temp = (*pile_a)->next;
        (*pile_a)->next = NULL;
        *pile_a = temp;
    }
    if (*pile_b && (*pile_b)->next)
    {
        temp = *pile_b;
        while (temp->next)
            temp = temp->next;
        temp->next = *pile_b;
        temp = (*pile_b)->next;
        (*pile_b)->next = NULL;
        *pile_b = temp;
    }
}

void ft_reverse_rotate_both(p_list **pile_a, p_list **pile_b)
{
    p_list *temp;
    if (*pile_a && (*pile_a)->next)
    {
        temp = *pile_a;
        while (temp->next->next)
            temp = temp->next;
        temp->next->next = *pile_a;
        *pile_a = temp->next;
        temp->next = NULL;
    }
    if (*pile_b && (*pile_b)->next)
    {
        temp = *pile_b;
        while (temp->next->next)
            temp = temp->next;
        temp->next->next = *pile_b;
        *pile_b = temp->next;
        temp->next = NULL;
    }
}

/*int main(int argc, char **argv)
{
    p_list *pile_a = NULL;
    p_list *pile_b = NULL;
    p_list *temp = NULL;
    int i;

    if (argc != 7)
    {
        printf("Met 6 arguments");
        return 1;
    }
    for (i = 1; i <= 3; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->content = atoi(argv[i]);
        temp->next = pile_a;
        pile_a = temp;
    }

    for (i = 4; i <= 6; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
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
