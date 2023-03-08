/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:50:34 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/08 15:20:22 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_comp(p_list *pile)
{
	return ((ft_pilesize(pile) / 2) + (ft_pilesize(pile) % 2));
}

void	ft_under(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next)
{	
	
	while (cheap->position != 1 && next->position != 1)
	{
		ft_rotate_both(pile_a, pile_b);
		ft_set_pos(pile_a);
		ft_set_pos(pile_b);
	}
	if (cheap->position != 1)
	{
		while (cheap->position != 1)
		{
			ft_rotate_b(pile_b);
			ft_set_pos(pile_b);
		}
	}
	else if (next->position != 1)
	{
		while (next->position != 1)
		{
			ft_rotate_a(pile_a);
			ft_set_pos(pile_a);
		}
	}
}

void	ft_upper(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next)
{
	while (cheap->position != 1 && next->position != 1)
	{
		ft_reverse_rotate_both(pile_a, pile_b);
		ft_set_pos(pile_a);
		ft_set_pos(pile_b);
	}
	if (cheap->position != 1)
	{
		while (cheap->position != 1)
		{
			ft_reverse_rotate_b(pile_b);
			ft_set_pos(pile_b);
		}
	}
	else if (next->position != 1)
	{
		while (next->position != 1)
		{
			ft_reverse_rotate_a(pile_a);
			ft_set_pos(pile_a);
		}
	}
}

void	ft_both(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next)
{
	while (cheap->position != 1)
	{
		if (cheap->position <= (ft_size_comp(*pile_b)))
		{
			ft_rotate_b(pile_b);
			ft_set_pos(pile_b);
		}
		else if(cheap->position > (ft_size_comp(*pile_b)))
		{
			ft_reverse_rotate_b(pile_b);
			ft_set_pos(pile_b);
		}
	}
	while (next->position != 1)
	{
		if (next->position <= (ft_size_comp(*pile_a)))
		{
			ft_rotate_a(pile_a);
			ft_set_pos(pile_a);
		}
		else if (next->position > (ft_size_comp(*pile_a)))
		{
			ft_reverse_rotate_a(pile_a);
			ft_set_pos(pile_a);
		}
	}
}

void	ft_2ndpart(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next)
{
	while (ft_pilesize(*pile_b) != 0)
	{
		cheap = cheapest(*pile_a, *pile_b);
		next = find_next_highest(cheap->content, *pile_a);
		ft_set_pos(pile_a);
		ft_set_pos(pile_b);
		if ((cheap->position <= (ft_size_comp(*pile_b))) 
			&& (next->position <= (ft_size_comp(*pile_a))))
			ft_under(pile_a, pile_b, cheap, next);
		else if ((cheap->position > (ft_size_comp(*pile_b))) 
			&& (next->position > (ft_size_comp(*pile_a))))
			ft_upper(pile_a, pile_b, cheap, next);
		else
			ft_both(pile_a, pile_b, cheap, next);
		ft_push_a(pile_a, pile_b);
	}
}

void	ft_put_cheap_top(p_list **pile_b, p_list *cheap)
{
	while ((*pile_b) != cheap)
	{
		if (cheap->position <= (ft_size_comp(*pile_b)))
		{
			ft_rotate_b(pile_b);
		}
		else 
			ft_reverse_rotate_b(pile_b);
	}
}

void	ft_put_next_top(p_list **pile_a, p_list *next)
{
	while ((*pile_a) != next)
	{
		if (next->position <= (ft_size_comp(*pile_a)))
		{
			ft_rotate_b(pile_a);
		}
		else 
			ft_reverse_rotate_b(pile_a);
	}
}


void	ft_faire_remonter(p_list **pile_a, p_list **pile_b, p_list *cheap, p_list *next)
{
	//on fait remonter les deux si ils sont dans la meme zone
	if ((*pile_a) != next && (*pile_b) != cheap)
	{
		while ((next->position <= ft_size_comp(*pile_a)) && (cheap->position) <= ft_size_comp(*pile_b))
		{
			ft_rotate_both(pile_a, pile_b);
		}
		while ((next->position > ft_size_comp(*pile_a)) && (cheap->position) > ft_size_comp(*pile_b))
			ft_reverse_rotate_both(pile_a, pile_b);
	}
	//si c'est toujours pas bon
}