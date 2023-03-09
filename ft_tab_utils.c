/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:52:56 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/09 17:20:14 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_tab(int *tab)
{
	int	i;

	if (!tab)
		return (-666);
	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int	*ft_trier(int *tab)
{
	int	i;
	int	j;
	int	temp;
	int	taille;

	taille = ft_size_tab(tab);
	i = 0;
	temp = 0;
	while (i < taille - 1)
	{
		j = 0;
		while (j < taille - i - 1)
		{	
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	*ft_action(t_stack *pile, t_stack *temp, int *tab)
{
	int	i;
	int	j;

	temp = pile;
	i = 0;
	while (i < ft_pilesize(temp) - 1)
	{
		j = i + 1;
		while (j < ft_pilesize(temp))
		{
			if (tab[i] > tab[j])
				ft_swap_int(tab, i);
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_swap_int(int *tab, int indice)
{
	int	temp;

	temp = tab[indice];
	tab[indice] = tab[indice + 1];
	tab[indice + 1] = temp;
}
