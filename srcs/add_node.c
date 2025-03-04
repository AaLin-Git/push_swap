/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:18:15 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/04 09:23:44 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack	*new_node(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void add_node(t_stack **stack, char *arg)
{
    t_stack *new;

	new = new_node(ft_atoi(arg));
    if (!new)
        return;

    if (*stack == NULL)
    {
        *stack = new;
        new->next = new;
        new->prev = new;
		(*stack)->size = 1;
    }
    else
    {
        t_stack *tail = (*stack)->prev;
        tail->next = new;
        new->prev = tail;
        new->next = *stack;
        (*stack)->prev = new;
		(*stack)->size++;
    }
}
