/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:22:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/22 13:33:05 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algo_three(p_list **lst_a)
{
        if (ft_check_croissant((*lst_a)) == 1) //si la chaine n est ni dans l ordre croissant ni decroissant
        {

                if ((*lst_a)->content < (*lst_a)->next->content && (*lst_a)->next->content > (*lst_a)->next->next->content && (*lst_a)->content < (*lst_a)->next->next->content)
                { //si a<b>c & a<c
                        ft_reverse_rotate_a(lst_a);
                        ft_swap(lst_a);
                } //
                else if ((*lst_a)->content < (*lst_a)->next->content && (*lst_a)->next->content > (*lst_a)->next->next->content && (*lst_a)->content >(*lst_a)->next->next->content)
                {
                        ft_reverse_rotate_a(lst_a);
                }
                else if ((*lst_a)->content > (*lst_a)->next->content && (*lst_a)->next->content < (*lst_a)->next->next->content && (*lst_a)->content < (*lst_a)->next->next->content)
                {
                        ft_swap(lst_a);
                }
                else if ((*lst_a)->content > (*lst_a)->next->content && (*lst_a)->next->content < (*lst_a)->next->next->content && (*lst_a)->content > (*lst_a)->next->next->content)
                {
                        ft_rotate_a(lst_a);
                }
        }
}