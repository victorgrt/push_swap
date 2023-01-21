/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:58:39 by victor            #+#    #+#             */
/*   Updated: 2023/01/21 15:35:00 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(p_list **pile_a)
{
	p_list	*temp;

	if (!pile_a || !*pile_a || !(*pile_a)->next)
		return ;
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	temp->next = (*pile_a)->next;
	(*pile_a)->next = temp;
}

void	ft_push_a(p_list **pile_a, p_list **pile_b)
{
	p_list	*temp;

	if (!pile_b || !*pile_b)
		return ;
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	temp->next = *pile_a;
	*pile_a = temp;
}

void	ft_rotate_a(p_list **pile_a)
{
	p_list	*temp;
	p_list	*first;

	if (!pile_a || !*pile_a || !(*pile_a)->next)
		return ;
	first = *pile_a;
	temp = *pile_a;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*pile_a = first->next;
	first->next = NULL;
}

void	ft_reverse_rotate_a(p_list **pile_a)
{
	p_list	*temp;
	p_list	*last;

	if (!pile_a || !*pile_a || !(*pile_a)->next)
		return ;
	temp = *pile_a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *pile_a;
	*pile_a = last;
}

int main()
{
    p_list *pile_a = NULL;
    p_list *temp = NULL;
    int i;
    int tab[3] = {1, 2, 3};

    for (i = 0; i < 3; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->content = tab[i];
        temp->next = pile_a;
        pile_a = temp;
    }
    printf("Pile a avant ft_reverse_rotate_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    ft_reverse_rotate_a(&pile_a);

    printf("Pile a après ft_reverse_rotate_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    return 0;
}

/*MAIN POUR FT_SWAP_A
int main()
{
    p_list *pile_a = NULL;
    p_list *temp = NULL;
    int i;
    int tab[3] = {1, 2, 3};

    for (i = 0; i < 3; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->content = tab[i];
        temp->next = pile_a;
        pile_a = temp;
    }
    printf("Pile avant ft_swap_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    ft_swap_a(&pile_a);

    printf("Pile après ft_swap_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    return 0;
}*/

/*MAIN POUR FT_PUSH_A
int main()
{
    p_list *pile_a = NULL;
    p_list *pile_b = NULL;
    p_list *temp = NULL;
    int i;
    int tab[3] = {1, 2, 3};

    for (i = 0; i < 3; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->content = tab[i];
        temp->next = pile_b;
        pile_b = temp;
    }
    printf("Pile b avant ft_push_a: ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");
    printf("Pile a avant ft_push_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    ft_push_a(&pile_a, &pile_b);

    printf("Pile b après ft_push_a: ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");
    printf("Pile a après ft_push_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    return 0;
}*/

/*MAIN POUR FT_ROTATE_A
int main()
{
    p_list *pile_a = NULL;
    p_list *temp = NULL;
    int i;
    int tab[3] = {1, 2, 3};

    for (i = 0; i < 3; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->content = tab[i];
        temp->next = pile_a;
        pile_a = temp;
    }
    printf("Pile a avant ft_rotate_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    ft_rotate_a(&pile_a);

    printf("Pile a après ft_rotate_a: ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->content);
    printf("\n");

    return 0;
}*/