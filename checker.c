/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:18:29 by victor            #+#    #+#             */
/*   Updated: 2023/03/17 14:44:21 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int execute_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
    if (ft_strncmp(instruction, "sa\n", 3) == 0)
        ft_swap_a(stack_a);
    else if (ft_strncmp(instruction, "sb\n", 3) == 0)
        ft_swap_b(stack_b);
    // else if (ft_strncmp(instruction, "ss\n", 3) == 0)
    //     ft_swap_s(stack_a, stack_b);
    else if (ft_strncmp(instruction, "pa\n", 3) == 0)
        ft_push_a(stack_a, stack_b);
    else if (ft_strncmp(instruction, "pb\n", 3) == 0)
        ft_push_b(stack_b, stack_a);
    else if (ft_strncmp(instruction, "ra\n", 3) == 0)
        ft_rotate_a(stack_a);
    else if (ft_strncmp(instruction, "rb\n", 3) == 0)
        ft_rotate_b(stack_b);
    else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		ft_rotate_both(stack_a, stack_b);
    else if (ft_strncmp(instruction, "rra\n", 4) == 0)
        ft_reverse_rotate_a(stack_a);
    else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
        ft_reverse_rotate_b(stack_b);
    else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
        ft_reverse_rotate_both(stack_a, stack_b);
    else
        return (0);
    return (1);
}


// int main(int ac, char **av)
// {
// 	t_stack	*pile_a;
// 	// t_stack	*pile_b;
// 	t_stack	*new;	
//     char	*line;
// 	int		i;
// 	int		fd;

// 	pile_a = NULL;
// 	// pile_b = NULL;
// 	new = NULL;
// 	if (ac == 1)
// 		return (0);
// 	if (ft_master_checker(av, ac) == 1)
// 		return (0);
// 	i = 1;
// 	while (i < ac)
// 	{
// 		new = ft_pilenew(ft_atol(av[i]));
// 		if (new == NULL)
// 			return (1);
// 		ft_pileadd_back(&pile_a, new);
// 		i++;
// 	}
// 	fd = open(av)
//     while ((line = get_next_line(1)))
//     {
// 		printf("%s\n", line);
//         // if (!execute_instruction(&pile_a, &pile_b, line))
//         // {
//         //     free(line);
//         //     // return (print_error());
// 		// 	printf("ici");
//         // }
//         free(line);
//     }
//     if (ft_check_croissant(pile_a) == 0)
//         ft_putstr("OK\n");
//     else
//         ft_putstr("KO\n");
//     return (0);
// }

typedef struct s_instruction
{
    char *instr;
    struct s_instruction *next;
} t_instruction;


// int main(void)
// {
//     t_instruction *head = NULL;
//     t_instruction *curr = NULL;

//     char *line;
//     while ((line = get_next_line(0)) != NULL)
//     {
//         if (head == NULL)
//         {
//             head = malloc(sizeof(t_instruction));
//             curr = head;
//         }
//         else
//         {
//             curr->next = malloc(sizeof(t_instruction));
//             curr = curr->next;
//         }
//         curr->instr = line;
//         curr->next = NULL;
//         printf("Instruction lue : %s\n", line);
//     }

//     // Affichage des instructions stockées dans la liste chaînée
//     curr = head;
//     printf("Instructions stockées :\n");
//     while (curr != NULL)
//     {
//         printf("%s\n", curr->instr);
//         curr = curr->next;
//     }

//     // Libération de la mémoire allouée pour la liste chaînée
//     curr = head;
//     while (curr != NULL)
//     {
//         t_instruction *next = curr->next;
//         free(curr->instr);
//         free(curr);
//         curr = next;
//     }

//     return 0;
// }
