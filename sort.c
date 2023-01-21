/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:04:12 by victor            #+#    #+#             */
/*   Updated: 2023/01/21 20:16:23 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_list_clear(p_list **pile)
{
    p_list *temp;
    while (*pile)
    {
        temp = *pile;
        *pile = (*pile)->next;
        free(temp);
    }
}

void ft_list_print(p_list *pile)
{
    p_list *temp;
    for (temp = pile; temp; temp = temp->next)
    {
        printf("%d ", temp->content);
    }
    printf("\n");
}

void ft_sort(p_list **pile_a, p_list **pile_b)
{
    int size = ft_lstsize_p(*pile_a);
    while (ft_lstsize_p(*pile_a) > 1)
    {
        if ((*pile_a)->content > (*pile_a)->next->content)
            ft_swap(pile_a);
        ft_push(pile_a, pile_b);
        ft_rotate(pile_b);
    }
    while (ft_lstsize_p(*pile_b) > 0)
    {
        ft_push(pile_b, pile_a);
        ft_rotate(pile_a);
    }
    while (size--)
        ft_rotate(pile_a);
}

int main(int argc, char **argv)
{
    p_list *pile_a = NULL;
    p_list *pile_b = NULL;
    int i;

    if (argc < 2)
    {
        printf("Usage: ./a.out <list of integers>\n");
        return 1;
    }
    for (i = 1; i < argc; i++)
    {
        ft_lstadd_front_p(&pile_a, atoi(argv[i]));
    }
    printf("Pile a avant tri: ");
    ft_list_print(pile_a);
    ft_sort(&pile_a, &pile_b);
    printf("Pile a après tri: ");
    ft_list_print(pile_a);
    ft_list_clear(&pile_a);
    ft_list_clear(&pile_b);
    return 0;
}