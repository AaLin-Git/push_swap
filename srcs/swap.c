/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 12:14:01 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void swap(t_stack **stack)
{
	t_stack *first_node;
	t_stack *second_node;

	first_node = *stack;
	second_node = first_node->next;
	if (second_node->next == first_node)
		*stack = second_node;
	first_node->prev->next = second_node;
	second_node->next->prev = first_node;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;
	*stack = second_node;
}

void	sa(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	swap(stack);
}

void	sb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	swap(stack);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
