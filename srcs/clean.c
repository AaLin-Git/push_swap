/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:43:41 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/26 12:45:39 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void free_stack(t_list **stack)
{
	t_list *temp;

	if (!stack || !*stack)
		return;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = temp;
	}
}
