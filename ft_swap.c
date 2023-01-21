/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:52:31 by victor            #+#    #+#             */
/*   Updated: 2023/01/21 20:01:12 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void ft_swap_s(p_list **pile_a, p_list **pile_b)
{
    ft_swap(pile_a);
    ft_swap(pile_b);
}

/*int main(int argc, char **argv)
{
    p_list *pile_a = NULL;
    p_list *pile_b = NULL;
    p_list *temp = NULL;
    int i;

    if (argc < 2)
    {
        printf("Met des arguments", argv[0]);
        return 1;
    }
    for (i = 1; i < argc; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->content = atoi(argv[i]);
        temp->next = pile_a;
        pile_a = temp;
    }

    for (i = 1; i < argc; i++)
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

    ft_swap_s(&pile_a, &pile_b);

    printf("Pile a après : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    printf("Pile b après ft_swap_s: ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    return 0;
}*/
