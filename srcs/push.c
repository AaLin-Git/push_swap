/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:50:44 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 15:47:08 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("push start\n");
	t_stack	*node_to_move;
	t_stack *last_node_b;

	node_to_move = *stack_a;
	if (*stack_a == (*stack_a)->next)
		*stack_a = NULL;
	else
	{
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		*stack_a = (*stack_a)->next;
	}
	if (!(*stack_b))
	{
		node_to_move->next = node_to_move;
		node_to_move->prev = node_to_move;
		*stack_b = node_to_move;
	}
	else
	{
		last_node_b = (*stack_b)->prev;
		node_to_move->next = *stack_b;
		node_to_move->prev = last_node_b;
		last_node_b->next = node_to_move;
		(*stack_b)->prev = node_to_move;
		*stack_b = node_to_move;
	}
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_printf("pa start\n");
	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb start\n");
	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
