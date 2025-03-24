/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:18:15 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 15:02:48 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static t_stack	*create_new_node(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = num;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

bool	add_node(t_stack **stack, char *arg)
{
	t_stack	*new_node;
	t_stack	*tail;
	int		value;

	value = ft_atoi(arg);
	new_node = create_new_node(value);
	if (!new_node)
		return (false);
	if (!(*stack))
		*stack = new_node;
	else
	{
		tail = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = tail;
		tail->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	//ft_printf("added %i", value);
	return (true);
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	if (!stack)
		return (0);
	temp = stack->next;
	i = 1;
	while (temp != stack)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

bool	fill_stack(t_data *data, int argc, char **argv)
{
	int index;
	
	index = argc - 1;
	while (index > 0)
	{
		if (!add_node(&data->stack_a, argv[index]))
			return (false);
		index--;
	}
	return (true);
}
