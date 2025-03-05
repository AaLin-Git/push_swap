/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:07:35 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 10:34:48 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_three(t_stack **stack)
{
	int first_node;
	int second_node;
	int third_node;

	first_node = (*stack)->data;
	second_node = (*stack)->next->data;
	third_node = (*stack)->next->next->data;

	if ((first_node < third_node) && (third_node < second_node))
	{
		ft_printf("1. first_node < third_node && third_node < second_node");
		sa(stack);
		ra(stack);
	}
	if ((second_node < first_node) && (first_node < third_node))
	{
		ft_printf("2. second_node < first_node && first_node < third_node");
		sa(stack);
	}
	if ((third_node < first_node) && (first_node <second_node))
	{
		ft_printf("3. third_node < first_node && first_node <second_node");
		rra(stack);
	}
	if ((second_node < third_node) && (third_node < first_node))
	{
		ft_printf("4. second_node < third_node && third_node < first_node");
		ra(stack);
	}
	if ((third_node < second_node) && (second_node < first_node))
	{
		ft_printf("5. third_node < second_node) && (second_node < first_node");
		sa(stack);
		rra(stack);
	}
}
