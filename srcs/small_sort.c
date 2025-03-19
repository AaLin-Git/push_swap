/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:07:35 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 14:14:32 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_three(t_stack **stack, int first, int second, int third)
{
	if ((first < third) && (third < second))
	{
		sa(stack);
		ra(stack);
	}
	if ((second < first) && (first < third))
		sa(stack);
	if ((third < first) && (first < second))
		rra(stack);
	if ((second < third) && (third < first))
		ra(stack);
	if ((third < second) && (second < first))
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*tail;
	int		first_node;
	int		second_node;
	int		third_node;

	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	tail = return_last_node(stack);
	first_node = (*stack)->data;
	second_node = (*stack)->next->data;
	third_node = tail->data;
	swap_three(stack, first_node, second_node, third_node);
}

static void	find_smallest_num(t_stack **stack, t_stack **smallest)
{
	t_stack	*current;

	current = *stack;
	*smallest = *stack;
	while (current != NULL)
	{
		if (current->data < (*smallest)->data)
			*smallest = current;
		current = current->next;
	}
}

void	find_biggest_num(t_stack **stack, t_stack **biggest)
{
	t_stack	*current;

	current = *stack;
	*biggest = *stack;
	while (current != NULL)
	{
		if (current->data > (*biggest)->data)
			*biggest = current;
		current = current->next;
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*smallest_num;
	t_stack	*biggest_num;

	smallest_num = NULL;
	biggest_num = NULL;
	find_smallest_num(stack_a, &smallest_num);
	find_biggest_num(stack_a, &biggest_num);
	while (size > 3)
	{
		if (biggest_num == *stack_a || smallest_num == *stack_a)
		{
			pb(stack_a, stack_b);
			size--;
		}
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_b, stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			ra(stack_a);
	}
}
