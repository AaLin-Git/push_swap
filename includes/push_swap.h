/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:53 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/12 09:50:36 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"

typedef struct s_stack
{
    int				data;
	int				index;
    struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		is_number(char *str);
int		is_sorted(t_stack **stack, int size);
int		is_duplicate(t_stack **stack, int size);
void	add_node(t_stack **stack, char *arg);
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);
void	fill_stack(t_stack **stack, char **argv, int index);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	find_biggest_num(t_stack **stack, t_stack **biggest);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	init_sort_index(t_stack **stack);

#endif