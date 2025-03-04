/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lyssa <Lyssa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:50:44 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/04 20:17:05 by Lyssa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_stack **stack_a, t_stack **stack_b)
{
  t_stack *node_to_move;
  t_stack *second_node;
  t_stack *last_node;
  char *value;

  if (!stack_a || !stack_b || !(*stack_a))
    return;
  node_to_move = *stack_a;
  second_node = (*stack_a)->next;
  last_node = (*stack_a)->prev;
  
  if ((*stack_a)->next == *stack_a)
    *stack_a = NULL;
  else
  {
    last_node->next = second_node;
    second_node->prev = last_node;
    *stack_a = second_node;
  }
  value = ft_itoa(node_to_move->data);
  if (!value)
    return;
  add_node(stack_b, value);
  free(node_to_move);
  free(value);
}
