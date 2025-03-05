/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 14:07:03 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted(int arr[], int size)
{
	int i;

	i = 0;
	ft_printf("is sorted start\n");
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void bubble_sort(t_stack **stack, int arr[])
{
	int i;
	//int temp;
	int size;
	t_stack *current;

	i = 0;
	size = get_stack_size(*stack);
	arr[i] = (*stack)->data;
	current = (*stack)->next;
	i++;
	ft_printf("bubble start\n");
	while (current != *stack)
	{
		arr[i] = current->data;
		i++;
		current = current->next;
	}
	// while (!is_sorted(arr, size))
	// {
	// 	if (arr[i] > arr[i + 1])
	// 	{
	// 		temp = arr[i];
	// 		arr[i] = arr[i + 1];
	// 		arr[i + 1] = temp;
	// 		i++;
	// 	}
	// }
	
}

void chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int sorted_array[500] = {0};

	(void)stack_b;
	i = 0;
	int size = get_stack_size(*stack_a);
	bubble_sort(stack_a, sorted_array);
	while (i < size - 1)
	{
		ft_printf("arr = %d", sorted_array[i]);
		i++;
	}
}