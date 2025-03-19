/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 11:46:18 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;
	*stack = second_node;
}

void	sa(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	swap(stack);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	swap(stack);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
