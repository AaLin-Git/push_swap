/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/12 10:05:02 by akovalch         ###   ########.fr       */
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

int is_sorted(t_stack **stack, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (*stack > (*stack)->next)
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(t_stack **stack, int size)
{
	t_stack *current;
	t_stack *inner_current;
	int i;
	int j;
	
	current = *stack;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		inner_current = (*stack)->next;
		while (j < size - 1)
		{
			if (inner_current->data == inner_current->next->data)
				return (1);
			inner_current = inner_current->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (0);
}
