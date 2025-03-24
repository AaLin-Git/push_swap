/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:53 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 15:59:31 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack *stack_a;
	t_stack *stack_b;
	int min;
	int max;
	int total_size;
	int chunk_size;
}	t_data;

int		is_sorted(t_stack **stack);
int		is_valid(int argc, char **argv);
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);
bool	add_node(t_stack **stack, char *arg);
bool	fill_stack(t_data *data, int argc, char **argv);
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
void	sort_three(t_data *data);
void	sort_five(t_data *data, int size);
void	find_smallest_node(t_stack **stack, t_stack **smallest);
void	find_biggest_node(t_stack **stack, t_stack **biggest);
void	chunk_sort(t_data *data);
void	init_sort_index(t_stack **stack, int size);
void	print_error(const char *str);

#endif