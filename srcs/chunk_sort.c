/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/26 10:57:24 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_node(t_stack **stack, int start, int end)
{
	//ft_printf("find_node start");
	t_stack	*head;
	int count;

	if (!stack || !*stack) // Check for empty stack
		return (-1);
	head = *stack;
	count = 0;
	while (1)
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
		if (head == *stack)
			return (-1);
	}
	return (count);
}

int find_position_b(t_data *data, int value)
{
    t_stack *current;
    t_stack *smallest_node;
    t_stack *biggest_node;
    int position = 0;
    int size;

    if (!data->stack_b || data->stack_b->next == data->stack_b)
        return (0); // Insert at the start if stack_b is empty or has one element

    size = get_stack_size(data->stack_b);
    find_smallest_node(&data->stack_b, &smallest_node);
    find_biggest_node(&data->stack_b, &biggest_node);

    // Case 1: If value is smaller than the smallest node, insert before it
    if (value < smallest_node->value)
        return find_node(&data->stack_b, smallest_node->value, 0);

    // Case 2: If value is greater than the largest node, insert after it
    if (value > biggest_node->value)
        return find_node(&data->stack_b, biggest_node->value, 0);

    // Case 3: Find correct position between two nodes
    current = data->stack_b;
    while (position < size)
    {
        if (current->value < value && current->next->value > value)
            return (position + 1); // Insert between current and current->next

        current = current->next;
        position++;
    }

    return (0); // Default to the start if no other position is found
}


int get_value(t_stack *stack, int count)
{
	while (count >= 0)
	{
		stack = stack->next;
		count--;
	}
	return (stack->value);
}

void rotate_stacks(t_data *data, int count_moves_a, int count_moves_b)
{
	int size_a = get_stack_size(data->stack_a);
	int size_b = get_stack_size(data->stack_b);

	// Both moves are in the first half (normal rotations)
	if (count_moves_a <= size_a / 2 && count_moves_b <= size_b / 2)
	{
		while (count_moves_a > 0 && count_moves_b > 0)
		{
			rr(&data->stack_a, &data->stack_b);
			count_moves_a--;
			count_moves_b--;
		}
		while (count_moves_a-- > 0)
			ra(&data->stack_a);
		while (count_moves_b-- > 0)
			rb(&data->stack_b);
	}
	// Both moves are in the second half (reverse rotations)
	else if (count_moves_a > size_a / 2 && count_moves_b > size_b / 2)
	{
		count_moves_a = size_a - count_moves_a;
		count_moves_b = size_b - count_moves_b;
		while (count_moves_a > 0 && count_moves_b > 0)
		{
			rrr(&data->stack_a, &data->stack_b);
			count_moves_a--;
			count_moves_b--;
		}
		while (count_moves_a-- > 0)
			rra(&data->stack_a);
		while (count_moves_b-- > 0)
			rrb(&data->stack_b);
	}
	// Different moves (one normal, one reverse)
	else
	{
		if (count_moves_a <= size_a / 2)
			while (count_moves_a-- > 0) ra(&data->stack_a);
		else
		{
			count_moves_a = size_a - count_moves_a;
			while (count_moves_a-- > 0) rra(&data->stack_a);
		}

		if (count_moves_b <= size_b / 2)
			while (count_moves_b-- > 0) rb(&data->stack_b);
		else
		{
			count_moves_b = size_b - count_moves_b;
			while (count_moves_b-- > 0) rrb(&data->stack_b);
		}
	}
}


void	move_node(t_data *data, int start)
{
	//ft_printf("move node start\n");
	int num_to_move;
	int	count;
	int	count_moves_a;
	int	count_moves_b;
	int	end;

	if (!(data->stack_a))
		return ;
	count = 0;
	end = start + data->chunk_size - 1;
	count_moves_a = find_node(&data->stack_a, start, end);
	while (count < data->chunk_size && data->stack_a && count_moves_a != -1)
	{
		if (count_moves_a == -1)
			break;
		num_to_move = get_value(data->stack_a, count_moves_a);
		count_moves_b = find_position_b(data, num_to_move);
		if (count_moves_b != -1)
			rotate_stacks(data, count_moves_a, count_moves_b);
		pb(&data->stack_a, &data->stack_b);
		count++;
		count_moves_a = find_node(&data->stack_a, start, end);
	}
	//ft_printf("move node end\n");
}

void	push_chunks(t_data *data)
{
	//ft_printf("push start\n");
	int	start;

	start = 0;
	while (start < data->total_size)
	{
		move_node(data, start);
		start += data->chunk_size;
	}
	//ft_printf("push end\n");
}

void	insert_chunks(t_data *data)
{
	t_stack	*biggest_node;
	int		biggest;
	int		position;
	int size;

	while (data->stack_b != NULL)
	{
		size = get_stack_size(data->stack_b);
		find_biggest_node(&data->stack_b, &biggest_node);
		if (!biggest_node)
			return ;
		biggest = biggest_node->index;
		position = find_node(&data->stack_b, biggest, 0);
		while ((data->stack_b)->index != biggest)
		{
			if (position < size / 2)
				rb(&data->stack_b);
			else
				rrb(&data->stack_b);
		}
		pa(&data->stack_b, &data->stack_a);
	}
	//ft_printf("insert start\n");
}

void	chunk_sort(t_data *data)
{
	if (data->total_size <= 100)
		data->chunk_size = 20;
	else
		data->chunk_size = 35;
	init_sort_index(&data->stack_a, data->total_size);
	push_chunks(data);
	insert_chunks(data);
}
