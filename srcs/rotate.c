/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:33 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 12:13:45 by akovalch         ###   ########.fr       */
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
		return;
	rotate(stack);
}

void	rb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	rotate(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
