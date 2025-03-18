/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:36 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/18 12:39:57 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	(*stack) = (*stack)->prev;
}

void	rra(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->prev)
		return ;
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->prev)
		return ;
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->prev
		|| !stack_b || !(*stack_b) || !(*stack_b)->prev)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
