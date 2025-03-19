/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:18:15 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 14:14:43 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <stdio.h>
#include <stdlib.h>

static t_stack	*create_new_node(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_node(t_stack **stack, char *arg)
{
	t_stack	*new_node;
	int		data;

	data = ft_atoi(arg);
	new_node = create_new_node(data);
	if (!new_node)
		return ;
	if (!(*stack))
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

int	get_stack_size(t_stack *stack)
{
	int		i;

	if (!stack)
		return (0);
	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	fill_stack(t_stack **stack, char **argv, int index)
{
	while (index > 0)
	{
		add_node(stack, argv[index]);
		index--;
	}
}

t_stack	*return_last_node(t_stack **stack)
{
	t_stack	*tail;

	if (!stack || !(*stack))
		return (NULL);
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}
