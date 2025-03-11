/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/11 12:16:04 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int is_sorted(int arr[], int size)
// {
// 	int i;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		if (arr[i] > arr[i + 1])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int find_the_closest(t_stack **stack, int start, int end)
{
	t_stack *head;
	t_stack *tail;

	head = *stack;
	tail = (*stack)->prev;

	while (head != *stack || tail != *stack)
	{
		if (head->index >= start && head->index <= end)
			return (1);
		if (tail->index >= start && tail->index <= end)
			return (-1);
		head = head->next;
		tail = tail->prev;
	}
	return (0);
}

int return_direction(t_stack **stack, int biggest)
{
	t_stack *head;
	t_stack *tail;

	head = *stack;
	tail = (*stack)->prev;

	while (head != *stack || tail != *stack)
	{
		if (head->index == biggest)
			return (1);
		if (tail->index == biggest)
			return (-1);
		head = head->next;
		tail = tail->prev;
	}
	return (0);
}

int return_index(t_stack **stack)
{
	t_stack *biggest;
	
	biggest = NULL;
	find_biggest_num(stack, &biggest);
	return (biggest->index);
}

void push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int start;
	int end;
	int direction;
	int count;
	int size;

	start = 0;
	end = chunk_size - 1;
	size = get_stack_size(*stack_a);
	while (start < size)
	{
		count = 0;
		while (count < chunk_size && *stack_a)
		{
			direction = find_the_closest(stack_a, start, end);
			if (direction > 0)
			{
				while (!((*stack_a)->index >= start && (*stack_a)->index <= end))
					ra(stack_a);
			}
			else if (direction < 0)
			{
				while (!((*stack_a)->index >= start && (*stack_a)->index <= end))
					rra(stack_a);
			}
			pb(stack_a, stack_b);
			count++;
		}
		start += chunk_size;
		end += chunk_size;
	}
}

void insert_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int biggest;
	int direction;
	int size;

	while (*stack_b)
	{
		biggest = return_index(stack_b);
		direction = return_direction(stack_b, biggest);
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
	t_stack *head;
	t_stack *tail;
	int chunk_size;
	
	if (size <= 100)
		chunk_size = size / 5;
	else if (size <= 300)
		chunk_size = size / 8;
	else
		chunk_size = size / 11;
	head = *stack_a;
	tail =(*stack_a)->prev;
	init_sort_index(stack_a);
	push_chunks(stack_a, stack_b, 20);
	init_sort_index(stack_b);
	insert_chunks(stack_a, stack_b);
}