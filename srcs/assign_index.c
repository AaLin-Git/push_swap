/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:27:20 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/27 13:04:05 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_to_arr(t_stack **stack, int arr[])
{
	int		i;
	t_stack	*current;

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

void	bubble_sort(int arr[], int size)
{
	int	i;
	int	j;
	int	temp;

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

void	set_index(t_stack **stack, int arr[], int size)
{
	int		i;
	t_stack	*current;

	current = (*stack);
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (current->data == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
		if (current == *stack)
			break ;
	}
}

void	init_sort_index(t_stack **stack)
{
	int	*arr;
	int	size;

	if (!stack || !(*stack))
		return ;
	size = get_stack_size(*stack);
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		free_stack(stack);
		exit(EXIT_FAILURE) ;
	}
	stack_to_arr(stack, arr);
	bubble_sort(arr, size);
	set_index(stack, arr, size);
	free(arr);
}
