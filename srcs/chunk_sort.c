/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/18 11:45:23 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	return_node_direction(t_stack **stack, int start, int end)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack;
	tail = (*stack)->prev;
	while (head != *stack || tail != *stack)
	{
		if (end == 0)
		{
			if (head->index == start)
				return (1);
			if (tail->index == start)
				return (-1);
		}
		else
		{
			if (head->index >= start && head->index <= end)
				return (1);
			if (tail->index >= start && tail->index <= end)
				return (-1);
		}
		head = head->next;
		tail = tail->prev;
	}
	return (0);
}

void	move_node(t_stack **stack_a, t_stack **stack_b, int ch_size, int start)
{
	int	count;
	int	direction;
	int	end;

	count = 0;
	end = start + ch_size - 1;
	while (count < ch_size && *stack_a)
	{
		direction = return_node_direction(stack_a, start, end);
		while (!((*stack_a)->index >= start && (*stack_a)->index <= end))
		{
			if (direction > 0)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		count++;
	}
}

void	push_chunks(t_stack **st_a, t_stack **st_b, int ch_size, int size)
{
	int	start;
	int	end;

	start = 0;
	end = ch_size - 1;
	while (start < size)
	{
		move_node(st_a, st_b, ch_size, start);
		start += ch_size;
		end += ch_size;
	}
}

void	insert_chunks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*biggest_node;
	int		biggest;
	int		direction;
	int		size;

	while (*stack_b)
	{
		find_biggest_num(stack_b, &biggest_node);
		if (!biggest_node)
			return ;
		biggest = biggest_node->index;
		size = get_stack_size(*stack_b);
		direction = return_node_direction(stack_b, biggest, 0);
		while ((*stack_b)->index != biggest)
		{
			if (direction > 0)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;

	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
	init_sort_index(stack_a);
	push_chunks(stack_a, stack_b, chunk_size, size);
	init_sort_index(stack_b);
	insert_chunks(stack_a, stack_b);
}
