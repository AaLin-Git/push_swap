/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:34:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 11:46:05 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack **stack)
{
	int temp;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}