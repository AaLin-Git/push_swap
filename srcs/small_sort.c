/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:07:35 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 12:03:56 by akovalch         ###   ########.fr       */
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
	third_node = (*stack)->prev->data;

	if ((first_node < third_node) && (third_node < second_node))
	{
		sa(stack);
		ra(stack);
	}
	if ((second_node < first_node) && (first_node < third_node))
		sa(stack);
	if ((third_node < first_node) && (first_node <second_node))
		rra(stack);
	if ((second_node < third_node) && (third_node < first_node))
		ra(stack);
	if ((third_node < second_node) && (second_node < first_node))
	{
		sa(stack);
		rra(stack);
	}
}

void find_smallest_biggest_num(t_stack **stack, t_stack **smallest, t_stack **biggest)
{
	t_stack *current;

	current = (*stack)->next;
	*smallest = (*stack);
	*biggest = (*stack);
	while (current != *stack)
	{
		if (current->data < (*smallest)->data)
			*smallest = current;
		if (current->data > (*biggest)->data)
			*biggest = current;
		current = current->next;
	}
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *smallest_num;
	t_stack *biggest_num;
	int size;

	smallest_num = NULL;
	biggest_num = NULL;
	size = get_stack_size(*stack_a);

	find_smallest_biggest_num(stack_a, &smallest_num, &biggest_num);
	//ft_printf("small = %d", smallest_num->data);
	//ft_printf("big = %d", biggest_num->data);
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
