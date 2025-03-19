/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 14:18:33 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	return_node_direction(t_stack **stack, int start)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack;
	tail = return_last_node(stack);
	while (head != NULL || tail != NULL)
	{
		if (head->index == start)
			return (1);
		if (tail->index == start)
			return (-1);
		head = head->next;
		tail = tail->prev;
	}
	return (0);
}

int	return_chunk_direction(t_stack **stack, int start, int end)
{
	t_stack	*head;
	t_stack	*tail;
	int		count_from_head;
	int		count_from_tail;

	head = *stack;
	tail = return_last_node(stack);
	count_from_head = 0;
	count_from_tail = 0;
	while (head != NULL && !(head->index >= start && head->index <= end))
	{
		count_from_head++;
		head = head->next;
	}
	while (tail != NULL && !(tail->index >= start && tail->index <= end))
	{
		count_from_tail++;
		tail = tail->prev;
	}
	if (count_from_head < count_from_tail)
		return (1);
	else if (count_from_head > count_from_tail)
		return (-1);
	else
		return (0);
}

void	move_node(t_stack **stack_a, t_stack **stack_b, int ch_size, int start)
{
	int	count;
	int	direction;
	int	end;

	count = 0;
	end = ch_size - 1;
	while (count < ch_size && *stack_a)
	{
		direction = return_chunk_direction(stack_a, start, end);
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

	start = 0;
	while (start < size)
	{
		move_node(st_a, st_b, ch_size, start);
		start += ch_size;
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
		direction = return_node_direction(stack_b, biggest);
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
