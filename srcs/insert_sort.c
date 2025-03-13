/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:28:12 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/13 10:24:50 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int return_average(t_stack **stack, int size)
{
	t_stack *current;
	int mid_index;

	current = *stack;
	mid_index = size / 2;
	while (current->index != mid_index)
	{
		current = current->next;
	}
	// ft_printf("index = %d\n", current->index);
	// ft_printf("data = %d\n", current->data);
	return (current->data);
}

void push_average(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *current;
	t_stack *head_b;
	t_stack *tail_b;
	int average;

	average = return_average(stack_a, size);
	while (*stack_a)
	{
		if (!(*stack_b))
			pb(stack_a, stack_b);
		current = *stack_a;
		head_b = *stack_b;
		tail_b = (*stack_b)->prev;
		if (tail_b && current->data >= average && tail_b->data < average)
			rrb(stack_b);
		else if (head_b && current->data < average && head_b->data >= average)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
}

void push_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *biggest_node;
	int biggest;
	int direction;
	int size;

	biggest_node = NULL;
	while (*stack_b)
	{
		find_biggest_num(stack_b, &biggest_node);
		biggest = biggest_node->index;
		direction = return_node_direction(stack_b, biggest, 0);
		size = get_stack_size(*stack_b);
		if (direction > 0)
		{
			while ((*stack_b)->index != biggest)
				rb(stack_b);
		}
		else if (direction < 0)
		{
			while ((*stack_b)->index != biggest)
				rrb(stack_b);
		}
		else 
		{
			ft_printf("%d", direction);
		}
		pa(stack_b, stack_a);
	}
}

void insert_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int chunk_size;
	
	if (size <= 100)
		chunk_size = size / 5;
	else if (size <= 300)
		chunk_size = size / 8;
	else
		chunk_size = size / 11;
	init_sort_index(stack_a);
	push_average(stack_a, stack_b, size);
	init_sort_index(stack_b);
	push_back(stack_a, stack_b);
}