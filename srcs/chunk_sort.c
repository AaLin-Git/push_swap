/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 16:01:33 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_node(t_stack **stack, int start, int end)
{
	ft_printf("find_node start");
	t_stack	*head;
	int count;

	head = *stack;
	count = 0;
	while (head != (*stack)->prev)
	{
		if (end == 0)
		{
			if (head->index == start)
				return (count);
		}
		else
		{
			if (head->index >= start && head->index <= end)
				return (count);
		}
		head = head->next;
		count++;
	}
	return (count);
}

void	move_node(t_data *data, int start)
{
	ft_printf("move node start\n");
	int	count;
	int	direction;
	int	end;

	if (!(data->stack_a))
		return ;
	count = 0;
	end = start + data->chunk_size - 1;
	while (count < data->chunk_size && data->stack_a)
	{
		direction = find_node(&data->stack_a, start, end);
		while (!(data->stack_a->index >= start && data->stack_a->index <= end))
		{
			if (direction < data->total_size / 2)
				ra(&data->stack_a);
			else
				rra(&data->stack_a);
		}
		pb(&data->stack_a, &data->stack_b);
		count++;
	}
	ft_printf("move node end\n");
}

void	push_chunks(t_data *data)
{
	ft_printf("push start\n");
	int	start;
	int	end;

	start = 0;
	end = data->chunk_size - 1;
	while (start < data->total_size)
	{
		move_node(data, start);
		start += data->chunk_size;
		end += data->chunk_size;
	}
	ft_printf("push end\n");
}

void	insert_chunks(t_data *data)
{
	ft_printf("insert start\n");
	t_stack	*biggest_node;
	int		biggest;
	int		direction;

	while (data->stack_b != NULL)
	{
		find_biggest_node(&data->stack_b, &biggest_node);
		if (!biggest_node)
			return ;
		biggest = biggest_node->index;
		direction = find_node(&data->stack_b, biggest, 0);
		while (data->stack_b->index != biggest)
		{
			if (data->stack_b && direction < data->total_size / 2)
				rb(&data->stack_b);
			else
				rrb(&data->stack_b);
		}
		pa(&data->stack_b, &data->stack_a);
	}
	ft_printf("insert start\n");
}

void	chunk_sort(t_data *data)
{
	if (data->total_size <= 100)
		data->chunk_size = 20;
	else
		data->chunk_size = 35;
	init_sort_index(&data->stack_a, data->total_size);
	push_chunks(data);
	//init_sort_index(&data->stack_b, data->stack_b->size);
	insert_chunks(data);
}
