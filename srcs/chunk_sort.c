/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/13 12:57:32 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int return_node_direction(t_stack **stack, int start, int end)
{
	t_stack *head;
	t_stack *tail;
	//int count;

	head = *stack;
	tail = (*stack)->prev;
	//count = 0;
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
		//count++;
	}
	return (0);
}

void move_node(t_stack **stack_a, t_stack **stack_b,int chunk_size, int start, int end)
{
	int count;
	int direction;
	
	count = 0;
	while (count < chunk_size && *stack_a)
		{
			direction = return_node_direction(stack_a, start, end);
			if ((*stack_a)->index >= start && (*stack_a)->index <= end)
			{
				pb(stack_a, stack_b);
				count++;
				continue ;
			}
			if (direction == 0)
				break ;
			if (direction > 0)
			{
				if ((*stack_a)->next && (*stack_a)->next->index >= start && (*stack_a)->next->index <= end)
				{
					sa(stack_a);
					pb(stack_a, stack_b);
					count++;
					continue;
				}
				while (!((*stack_a)->index >= start && (*stack_a)->index <= end))
					ra(stack_a);
			}
			else if (direction < 0)
			{
				while (!((*stack_a)->index >= start && (*stack_a)->index <= end))
					rra(stack_a);
			}
			// if (is_sorted(stack_a))
			// 	break ;
			pb(stack_a, stack_b);
			count++;
		}
}

void push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size, int size)
{
	int start;
	int end;

	start = 0;
	end = chunk_size - 1;
	while (start < size)
	{
		move_node(stack_a, stack_b, chunk_size, start, end);
		start += chunk_size;
		end += chunk_size;
		// if (is_sorted(stack_a) && !(*stack_b))
		// 	return ;
	}
}

void insert_chunks(t_stack **stack_a, t_stack **stack_b)
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
		pa(stack_b, stack_a);
	}
}

void chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int chunk_size;
	
	if (size <= 100)
		chunk_size = 20;
	else if (size <= 300)
		chunk_size = size / 8;
	else
		chunk_size = size / 11;
	init_sort_index(stack_a);
	push_chunks(stack_a, stack_b, chunk_size, size);
	init_sort_index(stack_b);
	insert_chunks(stack_a, stack_b);
}