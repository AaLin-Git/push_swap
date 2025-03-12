/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/12 10:05:57 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"

void	print_stack(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = get_stack_size(stack);
	if (!stack)
		return ;
	while (i < size)
	{
		ft_printf("d= %d ", stack->data);
		ft_printf("i = %d ", stack->index);
		stack = stack->next;
		i++;
		ft_printf("\n");
	}
	ft_printf("\n");
}



void sort(char **argv, int size)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, argv, size);

	if (is_duplicate(&stack_a, size) || is_sorted(&stack_a, size))
	{
		ft_printf("dup or sorted");
		return ;
	}

	// if (size == 2 && ((*stack_a).data > (*stack_a).next->data))
	// 	ra(&stack_a);
	// else if (size == 3)
	// 	sort_three(&stack_a);
	// else if (size <= 5)
	// 	sort_five(&stack_a, &stack_b);
	// else
	// 	chunk_sort(&stack_a, &stack_b, size);
		
		
	// ft_printf("stack_a ----->");
	// print_stack(stack_a);
	// ft_printf("stack_b ----->");
	// print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	int		size;

	if (argc < 2 || argc > 501)
		return (ft_printf("Use from 2 to 500 args\n"), 1);
	size = argc - 1;
	sort(argv, size);
	return (0);
}
