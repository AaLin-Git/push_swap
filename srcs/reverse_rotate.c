/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:36 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 12:13:41 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void reverse_rotate(t_stack **stack)
{
	(*stack) = (*stack)->prev;
}

void rra(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->prev)
		return ;
	reverse_rotate(stack);
}

void rrb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->prev)
		return ;
	reverse_rotate(stack);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
