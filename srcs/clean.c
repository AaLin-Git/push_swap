/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:43:41 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/04 12:02:02 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	(*stack)->prev->next = NULL;
	while (temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	*stack = NULL;
}
