/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/12 10:15:31 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!str || !(*str))
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int is_sorted(t_stack **stack)
{
	t_stack *current;

	current = *stack;
	while (current->next != *stack)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int is_duplicate(t_stack **stack)
{
	t_stack *current;
	t_stack *inner_current;
	
	current = *stack;
	while (current->next != *stack)
	{;
		inner_current = current->next;
		while (inner_current != *stack)
		{
			if (current->data == inner_current->data)
				return (1);
			inner_current = inner_current->next;
		}
		current = current->next;
	}
	return (0);
}
