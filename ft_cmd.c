/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:43:03 by victor            #+#    #+#             */
/*   Updated: 2023/02/17 13:40:31 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_cmd_to_top(p_list *pile)
{
    p_list  *temp;
    int     pos_med;

    pos_med = ((ft_pilesize(pile)/2) + ft_pilesize(pile)%2);
    temp = pile;
    ft_set_position(&pile);
    ft_set_cmd(&pile);
    while (temp)
    {
        if (temp->position <= pos_med)
            temp->cmd = temp->cmd + temp->position - 1;
        else if (temp->position > pos_med)
            temp->cmd = temp->cmd + ft_pilesize(pile) - temp->position + 1;
        temp = temp->next;
    }
}

void    ft_push_low_cost(p_list **pile_a, p_list **pile_b)
{
    p_list  *temp;
    p_list  *temp2;
    int     i;
    int     ref;
    int     size;

    i = 0;
    size = ft_pilesize(*pile_b);
    ref = INT_MAX;
    temp2 = (*pile_b);
    while (i < size)
    {
        if (ref > (temp2)->cmd)
            ref = (temp2)->cmd;
        (temp2) = (temp2)->next;
        i++;
    }
    temp = (*pile_b);
    if (ref == temp->cmd)
        ft_push_a(pile_a, pile_b);
    else if (((ft_pilesize(*pile_b)/2) + ft_pilesize(*pile_b)%2) < ref)
        ft_reverse_rotate(pile_b);
    else    
        ft_rotate(pile_b);
}

int	main(int ac, char **av)
{
	int i = 1;
	p_list *pile_a;
	p_list *pile_b;
	p_list	*new;
	p_list	*temp;
 
	pile_a = 0;
	if (ac < 2)
	{
		ft_printf("erreur");
		return (1);
	}
	while (i < ac)
	{
		new = ft_pilenew(ft_atol(av[i]));
		ft_pileadd_back(&pile_a, new);
		i++;
	}
	//ft_print_pile(&pile_a);
	// ft_printf("\n");
	// ft_print_piles(pile_a, pile_b);
	//algo100(&pile_a, &pile_b);
	//ft_print_piles(pile_a, pile_b);
    ft_fill_b_low(&pile_a, &pile_b);
    ft_fill_b_high(&pile_a, &pile_b);
    ft_cmd_to_top(pile_b);
    ft_print_piles(pile_a, pile_b);
    ft_push_low_cost(&pile_a, &pile_b);
    ft_print_piles(pile_a, pile_b);
    temp = pile_b;
    while (temp)
	{
		printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content, temp->position, temp->cmd);
		temp = temp->next;
	}
	return (0);
}
