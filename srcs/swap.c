/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/04 13:17:32 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack)
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

void sa(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	swap(stack);
}
