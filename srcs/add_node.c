/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:18:15 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/04 12:01:56 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack	*create_new_node(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	add_node(t_stack **stack, char *arg)
{
	t_stack	*new_node;
	t_stack	*tail;
	int		data;

	data = ft_atoi(arg);
	new_node = create_new_node(data);
	if (!new_node)
		return ;
	if (*stack == NULL)
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
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	if (stack == NULL)
		return (0);
	temp = stack;
	temp = temp->next;
	i = 1;
	while (temp != stack)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
