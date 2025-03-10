/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:41:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/10 14:49:28 by akovalch         ###   ########.fr       */
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

// int	is_num_in_arr(int arr[], int num)
// {
// 	int i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		if (arr[i] == num)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }


void chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	// (void)stack_b;
	(void)size;
	t_stack *head;
	t_stack *tail;
	
	head = *stack_a;
	tail =(*stack_a)->prev;
	init_sort_index(stack_a);
	// ft_printf("head = %i", head->index);
	// ft_printf("tail = %i", tail->index);
	while (1)
	{
		if (head->index < 20)
		{
			ft_printf("head = %i", head->data);
			pb(stack_a, stack_b);
			ft_printf("pb head worked\n");
		}
		if (tail->index < 20 && tail != head)
		{
			ft_printf("tail = %i", tail->data);
			pb(stack_a, stack_b);
			ft_printf("pb tail worked\n");
		}
		head = head->next;
		tail = tail->prev;
		if (head->prev == tail)
			break ;
	}
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