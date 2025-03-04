/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:43:41 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/03 17:19:31 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void free_stack(t_stack **stack)
{
    if (!stack || !*stack)
        return;

    t_stack *temp = *stack;
    t_stack *next_node;
    
    (*stack)->prev->next = NULL;

    while (temp)
    {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    *stack = NULL;
}
