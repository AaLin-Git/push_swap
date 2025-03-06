/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/06 10:10:07 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted(int arr[], int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void stack_to_arr(t_stack **stack, int arr[])
{
	int i;
	t_stack *current;

	i = 0;
	current = (*stack)->next;
	arr[i] = (*stack)->data;
	i++;
	while (current != *stack)
	{
		arr[i] = current->data;
		i++;
		current = current->next;
	}
}

void bubble_sort(t_stack **stack, int arr[], int size)
{
	int i;
	int j;
	int temp;

	stack_to_arr(stack, arr);
	i = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void set_index(t_stack **stack, int arr[], int size)
{
	int i;
	t_stack *current;

	if (!stack || !(*stack))
		return;
	current = (*stack)->next;
	while (current != *stack)
	{
		i = 0;
		while (i < size)
		{
			if (current->data == arr[i])
				current->index = i;
			i++;
		}
		current = current->next;
	}
}

void chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int sorted_array[500] = {0};

	(void)stack_b;
	i = 0;
	int size = get_stack_size(*stack_a);
	if (size > 500)
	{
		ft_printf("too many arguments");
		return ;
	}
	bubble_sort(stack_a, sorted_array, size);
	set_index(stack_a, sorted_array, size);
	// while (i < size)
	// {
	// 	ft_printf("arr = %d", sorted_array[i]);
	// 	i++;
	// }
	// while (*stack_a != NULL)
	// {
	// 	if ((*stack_a)->data == sorted_array[i] && (i >= 0 && i <= 20))
	// 		pb(stack_a, stack_b);
	// 	if ((*stack_a)->data == sorted_array[i] && (i >= 21 && i <= 40))
	// 		pb(stack_a, stack_b);
	// 	(*stack_a) = (*stack_a)->next;
	// }
}