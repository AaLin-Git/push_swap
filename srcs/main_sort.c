/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:17:40 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 14:43:22 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(char **argv, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (is_valid(argv, size))
	{
		fill_stack(&stack_a, argv, size);
		if (is_sorted(&stack_a))
		{
			free_stack(&stack_a);
			return ;
		}
		if (size == 2 && ((*stack_a).data > (*stack_a).next->data))
			ra(&stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else if (size <= 5)
			sort_five(&stack_a, &stack_b, size);
		else
			chunk_sort(&stack_a, &stack_b, size);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;

	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
	init_sort_index(stack_a);
	push_chunks(stack_a, stack_b, chunk_size, size);
	insert_chunks(stack_a, stack_b);
}
