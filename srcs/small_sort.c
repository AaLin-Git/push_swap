/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:07:35 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 15:47:22 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_data *data)
{
	int	first_node;
	int	second_node;
	int	third_node;

	first_node = data->stack_a->value;
	second_node = data->stack_a->next->value;
	third_node = data->stack_a->prev->value;
	if ((first_node < third_node) && (third_node < second_node))
	{
		sa(&data->stack_a);
		ra(&data->stack_a);
	}
	if ((second_node < first_node) && (first_node < third_node))
		sa(&data->stack_a);
	if ((third_node < first_node) && (first_node < second_node))
		rra(&data->stack_a);
	if ((second_node < third_node) && (third_node < first_node))
		ra(&data->stack_a);
	if ((third_node < second_node) && (second_node < first_node))
	{
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
}

void	find_smallest_node(t_stack **stack, t_stack **smallest)
{
	//ft_printf("find smallest start");
	t_stack	*current;

	if (!stack || !*stack)
		return;
	current = (*stack)->next;
	*smallest = (*stack);
	while (current != *stack)
	{
		if (current->value < (*smallest)->value)
			*smallest = current;
		current = current->next;
	}
}

void	find_biggest_node(t_stack **stack, t_stack **biggest)
{
	ft_printf("find biggest start\n");
	t_stack	*current;

	if (!stack || !*stack)
		return;
	current = (*stack)->next;
	*biggest = (*stack);
	while (current != *stack)
	{
		if (current->value > (*biggest)->value)
			*biggest = current;
		current = current->next;
	}
}

void	sort_five(t_data *data, int size)
{
	//ft_printf("sort five start");
	//t_stack	*smallest_node;
	//t_stack	*biggest_node;

	//smallest_node = NULL;
	//biggest_node = NULL;
	//find_smallest_node(&data->stack_a, &smallest_node);
	//find_biggest_node(&data->stack_a, &biggest_node);
	while (size > 3)
	{
		if (data->max == data->stack_a->value || data->min == data->stack_a->value)
		{
			pb(&data->stack_a, &data->stack_b);
			size--;
		}
		else
			ra(&data->stack_a);
	}
	sort_three(data);
	while (data->stack_b != NULL)
	{
		pa(&data->stack_b, &data->stack_a);
		if (data->stack_a->value > data->stack_a->next->value)
			ra(&data->stack_a);
	}
}
