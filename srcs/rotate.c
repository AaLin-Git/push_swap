/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:33 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/18 12:36:15 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	rotate(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
