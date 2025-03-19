/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:50:44 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 11:44:40 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_move;
	t_stack	*second_node;

	node_to_move = *stack_a;
	second_node = (*stack_a)->next;
	*stack_a = second_node;
	if (second_node)
		second_node->prev = NULL;
	*stack_a = second_node;
	node_to_move->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = node_to_move;
	*stack_b = node_to_move;
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
