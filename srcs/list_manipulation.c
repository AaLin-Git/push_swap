/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:41:26 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:06:33 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node(t_stack **stack, char *str)
{
	int		num;
	t_stack	*new_node;

	num = ft_atoi(str);
	new_node = ft_lstnew(num);
	if (!new_node)
		return ;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
