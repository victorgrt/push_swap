/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:39:10 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/08 15:21:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

p_list    *find_next_highest(int ref, p_list *pile_a)
{
    p_list    *current;
    int    next_highest;

    if (!pile_a)
        return (0);
    current = pile_a;
    next_highest = INT_MAX;
    while (pile_a)
    {
        if (pile_a->content > ref && pile_a->content < next_highest)
        {
            next_highest = pile_a->content;
            current = pile_a;
        }
        pile_a = pile_a->next;
    }
    return (current);
}

p_list *cheapest(p_list *pile_a, p_list *pile_b)
{
    p_list *next;
    int		min_stroke;
    p_list *temp;
    p_list *cheapest;

    cheapest = pile_b;
    ft_cmd_to_top(pile_a);
    ft_cmd_to_top(pile_b);
    next = find_next_highest(pile_b->content, pile_a);
    min_stroke = cheapest->cmd + next->cmd;
    temp = pile_b;
    while (temp)
    {
        next = find_next_highest(temp->content, pile_a);
        if (((temp->cmd + next->cmd) < min_stroke))
        {
            min_stroke = temp->cmd + next->cmd;
            cheapest = temp;
        }
        temp = temp->next;
    }
    return (cheapest);
}

//si pile_a->content == ft_nexthighest((pile_b*)->content) on push, sinon on rota, tant qu'on a pas push
// void	ft_push_next_highest_true(p_list **pile_a, p_list **pile_b)
// {
// 	int next;
// 	int	position;

// 	position = 0;
// 	next = ft_nexthighest((*pile_b)->content, *pile_a);
// 	printf("next : %d\n", )
// 	while ((*pile_a)->content != next)
// 	{
// 		position = (*pile_a)->position;
// 		if (position > ft_pilesize(*pile_b))
// 			ft_reverse_rotate(pile_b);
// 		else if (position <= ft_pilesize(*pile_b))
// 			ft_rotate_b(pile_b);
// 	}
// 	ft_push_a(pile_a, pile_b);
// }
int ft_size_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*ft_trier(int *tab)
{
	int	i;
	int	j;
	int temp;
	int	taille;

	taille = ft_size_tab(tab);
	i = 0;
	temp = 0;
	while (i < taille - 1)
	{
		j = 0;
		while (j < taille - i - 1)
		{	
			if (tab[j] > tab[j+1])
			{
				temp = tab[j+1];
				tab[j+1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_set_position_v2(p_list **pile_a)
{
	int	*tab;
	int i;
	p_list	*temp;

	tab = malloc(sizeof(int) * ft_pilesize(*pile_a) + 1);
	if (!tab)
		return ;
	temp = *pile_a;
	i = 1;
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	tab = ft_trier(tab);
	i = 1;
	temp = *pile_a;
	while (i < ft_pilesize(*pile_a) && temp)
	{
		while (temp->content != tab[i])
			i++;
		if (temp->content == tab[i])
		{
			temp->position = i;
			i = 1;
		}
		temp = temp->next;
	}
}

void	ft_set_pos(p_list **pile)
{
	p_list	*temp;
	int i = 1;

	temp = (*pile);
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

int	ft_get_position(int next, p_list *pile_a)
{
	int	position;
	p_list	*temp;

	position = 0;
	temp = pile_a;
	while (temp)
	{
		if (temp->content == next)
			position = temp->position;
		temp = temp->next;
	}
	return (position);
}

void	algo_big(p_list **pile_a, p_list **pile_b)
{
	p_list	*cheap;
	p_list	*next;


	ft_fill_b_low(pile_a, pile_b);
	ft_fill_b_high(pile_a, pile_b);
	ft_set_position_v2(pile_a);
	ft_set_position_v2(pile_b);
	cheap = cheapest(*pile_a, *pile_b);
	next = find_next_highest(cheap->content, *pile_a);
	ft_2ndpart(pile_a, pile_b, cheap, next);
	
		//ft_faire_remonter(pile_a, pile_b, cheap, next);
		//ft_put_cheap_top(pile_b, cheap);
		//ft_put_next_top(pile_a, next);
		// while ((*pile_a) != next && (*pile_b) != cheap)
		// {
		// 	if ((next->position >= ft_size_comp(*pile_a)) && (cheap->position) >= ft_size_comp(*pile_b))
		// 	{
		// 		ft_reverse_rotate_both(pile_a, pile_b);
		// 	}
		// 	else 
		// 		ft_rotate_both(pile_a, pile_b);
		// }
	// 	while ((*pile_a) != next)
	// 	{
	// 		if (next->position >= ft_size_comp(*pile_a))
	// 		{
	// 			ft_reverse_rotate_a(pile_a);
	// 		}
	// 		else
	// 		{	
	// 			ft_rotate_a(pile_a);
	// 		}
	// 	}
	// 	while ((*pile_b) != cheap)
	// 	{
	// 		if (cheap->position >= ft_size_comp(*pile_b))
	// 		{
	// 			ft_reverse_rotate_b(pile_b);
	// 		}	
	// 		else
	// 		{	
	// 			ft_rotate_b(pile_b);
	// 		}
	// 	}
	// 	ft_push_a(pile_a, pile_b);
	// }
	while (ft_check_croissant(*pile_a) == 1)
	{
		if (ft_pilereturn_min(*pile_a)->position >= ft_size_comp(*pile_a))
		{
			ft_reverse_rotate_a(pile_a);
		}
		else if (ft_pilereturn_min(*pile_a)->position < ft_size_comp(*pile_a))
			ft_rotate_a(pile_a);
	}
}


// void	ft_algo_big(p_list **pile_a, p_list **pile_b)
// {
// 	ft_set_position_v2(pile_a);
// 	ft_set_position_v2(pile_b);
// 	//ft_print_piles(*pile_a, *pile_b);
// 	//printf("mediane : %d\n", ft_find_mediane(*pile_a));
// 	ft_fill_b_low(pile_a, pile_b);
// 	//printf("mediane : %d\n", ft_find_mediane(*pile_a));
// 	ft_fill_b_high(pile_a, pile_b);
// 	ft_print_piles(*pile_a, *pile_b);
// 	//printf("mediane : %d\n", ft_find_mediane(*pile_b));
// 	//ft_push_a(pile_a, 	pile_b);
// 	ft_set_pos(pile_a);
// 	ft_set_pos(pile_b);
// 	ft_2ndpart(pile_a, pile_b);
// 	while ((*pile_a) != ft_pilereturn_min(*pile_a))
// 	{
// 		if (ft_pilereturn_min(*pile_a)->position >= ft_size_comp(*pile_a))
// 		{
// 			ft_reverse_rotate_a(pile_a);
// 		}
// 		else
// 		{
// 			ft_rotate_a(pile_a);
// 		}
// 	}
// 	//ft_print_piles(*pile_a, *pile_b);
// }

int	main(int ac, char **av)
{
	int i = 1;
	p_list *pile_a;
	p_list	*pile_b;
	p_list	*new;

	pile_a = 0;
	pile_b = 0;
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
	// temp = pile_b;
	// while (temp)
	// {
	// 	printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content, temp->position, temp->cmd);
	// 	temp = temp->next;
	// }
	// cheap = find_next_highest(cheap->content, pile_a);
	// printf("ici : %d\n", cheap->content;
	// ft_print_piles(pile_a, pile_b);
	if (ft_pilesize(pile_a) <= 3)
		algo3(&pile_a);
	else if (ft_pilesize(pile_a) <= 5)
		algo5(&pile_a, &pile_b);
	else if (ft_pilesize(pile_a) > 5)
		algo_big(&pile_a, &pile_b);
	//ft_print_piles(pile_a, pile_b);
	free(pile_a);
	// printf("%d\n", ft_check_croissant(pile_a));
	// //ft_rotate(&pile_a);
	// ft_print_piles(pile_a, pile_b);
	return (0);
}