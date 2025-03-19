/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 13:02:50 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	return_node_direction(t_stack **stack, int start)
{
	t_stack	*head;
	t_stack	*tail;

	//ft_printf("return_node_direction start\n");
	head = *stack;
	tail = return_last_node(stack);
	while (head != NULL || tail != NULL)
	{
		if (head->index == start)
		{
			//ft_printf("direction = 1\n");
			return (1);
		}
		if (tail->index == start)
		{
			//ft_printf("direction = -1\n");
			return (-1);
		}
		//ft_printf("iterated head and tail\n");
		head = head->next;
		tail = tail->prev;
	}
	//ft_printf("direction = 0\n");
	return (0);
}

int	return_chunk_direction(t_stack **stack, int start, int end)
{
	t_stack *head;
	t_stack	*tail;
	int count_from_head;
	int count_from_tail;

	//ft_printf("return_chunk_direction start\n");
	head = *stack;
	tail = return_last_node(stack);
	count_from_head = 0;
	count_from_tail = 0;
	while (head != NULL && !(head->index >= start && head->index <= end))
	{
		//ft_printf("count from head = %i\n", count_from_head);
		count_from_head++;
		head = head->next;
	}
	while (tail != NULL && !(tail->index >= start && tail->index <= end))
	{
		//ft_printf("count from tail = %i\n", count_from_tail);
		count_from_tail++;
		tail = tail->prev;
	}
	if (count_from_head < count_from_tail)
	{
		//ft_printf("head count = %i, tail count = %i, direction = 1\n", count_from_head, count_from_tail);
		return (1);
	}
	else if (count_from_head > count_from_tail)
	{
		//ft_printf("head count = %i, tail count = %i, direction = -1\n", count_from_head, count_from_tail);
		return (-1);
	}
	else
	{
		//ft_printf("head count = %i, tail count = %i, direction = 0\n", count_from_head, count_from_tail);
		return (0);
	}
}

void	move_node(t_stack **stack_a, t_stack **stack_b, int ch_size, int start, int end)
{
	int	count;
	int	direction;

	//ft_printf("move_node start\n");
	count = 0;
	while (count < ch_size && *stack_a)
	{
		//ft_printf("count = %i, chunk size = %i\n", count, ch_size);
		direction = return_chunk_direction(stack_a, start, end);
		while (!((*stack_a)->index >= start && (*stack_a)->index <= end))
		{
			//ft_printf("index = %i", (*stack_a)->index);
			if (direction > 0)
				ra(stack_a);
			else
				rra(stack_a);
		}
		//ft_printf("push from a to b\n");
		pb(stack_a, stack_b);
		count++;
	}
}

void	push_chunks(t_stack **st_a, t_stack **st_b, int ch_size, int size)
{
	int	start;
	int	end;

	//ft_printf("push_chunks start\n");
	start = 0;
	end = ch_size - 1;
	while (start < size)
	{
		//ft_printf("start = %i, end = %i, size = %i\n", start, end, size);
		move_node(st_a, st_b, ch_size, start, end);
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

	//ft_printf("insert_chunks start\n");
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

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;

	//ft_printf("chunk_sort started\n");
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
	init_sort_index(stack_a);
	push_chunks(stack_a, stack_b, chunk_size, size);
	//init_sort_index(stack_b);
	insert_chunks(stack_a, stack_b);
}
