/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:43:41 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/18 12:13:07 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>

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

void	print_error(const char *str)
{
	write(2, str, ft_strlen(str));
}
