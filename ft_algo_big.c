/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:39:10 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/21 16:08:17 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_init_pile(p_list	**pile)
// {
// 	int		pos;
// 	p_list	*current;

// 	current = *pile;
// 	pos = 1;
// 	while (current)
// 	{
// 		current->position = pos;
// 		current->cmd = 0;
// 		current = current->next;
// 		pos++;
// 	}
// }

// void	ft_set_position(p_list **pile)
// {
// 	int		i;
// 	p_list	*current;
		
// 	i = 1;
// 	current = (*pile);
// 	while (current)
// 	{
// 		current->position = i;
// 		current = current->next;
// 		i++;
// 	}
// }

// void	ft_cmd_to_top(p_list *pile)
// {
// 	p_list	*temp;
// 	int		mediane;
// 	int		size;

// 	size = ft_pilesize(pile);
// 	ft_set_position(&pile);
// 	mediane = ((size/2) * (size%2));
// 	temp = (pile);
// 	while (temp)
// 	{
// 		if (temp->position <= mediane)
// 			temp->cmd = temp->position - 1;
// 		else if (temp->position > mediane)
// 			temp->cmd = size - ((pile)->position) + 1;
// 		temp = temp->next;
// 	}
// }

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

	tab = malloc(sizeof(int) * ft_pilesize(*pile_a));
	if (!tab)
		return ;
	temp = *pile_a;
	i = 0;
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	tab = ft_trier(tab);
	// for (int j = 0; tab[j]; j++)
	// 	printf("tab[%d] : %d\n", j, tab[j]);
	i = 0;
	temp = *pile_a;
	while (i < ft_pilesize(*pile_a) && temp)
	{
		while (temp->content != tab[i])
		{
			i++;
		}
		if (temp->content == tab[i])
		{
			temp->position = i;
			i = 0;
		}
		temp = temp->next;
	}
}

void	ft_push_good_position(p_list **pile_a, p_list **pile_b, int position)
{
	if (*pile_b == NULL || (*pile_b)->position >= position)
	{
		ft_push_a(pile_a, pile_b);
		if ((*pile_b)->position != position)
			ft_rotate_b(pile_a);
		return ;
	}
	p_list *temp = *pile_b;
	while (temp->next != NULL && temp->next->position < position)
	{
		temp = temp->next;
	}
	ft_push_b(pile_a, pile_b);
	if ((*pile_b)->position != position)
	{
		if ((*pile_b)->position > temp->position)
			ft_reverse_rotate_b(pile_b);
		else
			ft_rotate_b(pile_b);
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

//on envoi ce qui est en dessous de la mediane,
//on envoi tout ce qui n'est pas le max
//on prend celui avec le moins de cmd pour le mettre en haut, on le met en haut, 
//on trouve son next_highest 

void	algo_big(p_list **pile_a, p_list **pile_b)
{
	p_list *temp;
	// int		position;

	if (ft_pilesize(*pile_a) == 3)
		algo_three(pile_a);
	else if (ft_pilesize(*pile_a) == 5)
		algo5(pile_a, pile_b);
	else if (ft_pilesize(*pile_a) > 5)
	{
		ft_set_position_v2(pile_a);
		ft_fill_b_low(pile_a, pile_b);
		ft_fill_b_high(pile_a, pile_b);
		printf("pile_a->position %d\n", (*pile_a)->position);
		ft_cmd_to_top(*pile_b);
		temp = *pile_b;
   		while (temp)
		{
			printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content, temp->position, temp->cmd);
			temp = temp->next;
		}
		// while (ft_pilesize(*pile_b) != 1)
		// {
		// 	ft_push_good_position(pile_a, pile_b, (*pile_b)->position);
		// }
		// ft_push_a(pile_a, pile_b);
		// while (ft_check_croissant(*pile_a) == 0)
			// ft_rotate_a(pile_a);
		//ft_push_good_position(pile_a, pile_b, (*pile_b)->position);
		

		// temp = (*pile_b);
    	// while (temp)
		// {
		// 	printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content, temp->position, temp->cmd);
		// 	temp = temp->next;
		// }
	// 	position = 0;
	// 	while (ft_pilesize(*pile_b) != 0)
	// 	{
	// 		position = ft_get_position(ft_nexthighest((*pile_b)->content, *pile_a), *pile_a);
	// 		//printf("next : %d\n", ft_nexthighest((*pile_b)->content, *pile_a));
	// 		if ((*pile_a)->content == ft_nexthighest((*pile_b)->content, *pile_a))
	// 			ft_push_a(pile_a, pile_b);
	// 		else if (position > ft_pilesize(*pile_a)/2)
	// 			ft_reverse_rotate_a(pile_a);
	// 		else if (position <= ft_pilesize(*pile_a)/2)
	// 			ft_rotate_a(pile_a);
	// 	}
	// 	ft_print_piles(*pile_a, *pile_b);
	// 	while (ft_check_croissant(*pile_a) != 0)
	// 		ft_rotate_a(pile_a);
	}
}	

int	main(int ac, char **av)
{
	int i = 1;
	p_list *pile_a;
	p_list	*pile_b;
	// p_list 	*temp;
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
	// ft_set_position_v2(&pile_a);
	// temp = pile_a;
   	// while (temp)
	// {
	// 	printf("Valeur : %d\tPosition : %d\tCmd : %d\n", temp->content, temp->position, temp->cmd);
	// 	temp = temp->next;
	// }
	algo_big(&pile_a, &pile_b);
	ft_print_piles(pile_a, pile_b);
	// //ft_rotate(&pile_a);
	// ft_print_piles(pile_a, pile_b);
	return (0);
}