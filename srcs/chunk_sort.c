/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/06 11:32:22 by akovalch         ###   ########.fr       */
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


void chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	init_sort_index(stack_a);
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