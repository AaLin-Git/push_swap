/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/27 10:19:08 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"

static void	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && ((*stack_a)->data > (*stack_a)->next->data))
		ra(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b, size);
	else
		chunk_sort(stack_a, stack_b, size);
	free_stack(stack_a);
	free_stack(stack_b);
}

static bool	init(char **argv, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (is_valid(argv, size))
	{
		if (!fill_stack(&stack_a, size, argv))
		{
			free_stack(&stack_a);
			return (false);
		}
		if (is_sorted(&stack_a))
		{
			free_stack(&stack_a);
			return (true);
		}
		sort(&stack_a, &stack_b, size);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	size;

	if (argc < 2)
		exit(0);
	size = argc - 1;
	if (!init(argv, size))
		return (1);
	return (0);
}
