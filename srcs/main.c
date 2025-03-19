/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 11:47:54 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", stack->data);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	sort(char **argv, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (is_valid(argv, size))
	{
		fill_stack(&stack_a, argv, size);
		//int st_size = get_stack_size(stack_a);
		//ft_printf("size = %i", st_size);
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
		ft_printf("stack_a ---->");
		print_stack(stack_a);
		ft_printf("stack_b ---->");
		print_stack(stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	int	size;

	if (argc < 2 || argc > 501)
		return (print_error(ERR_ARG), 1);
	size = argc - 1;
	sort(argv, size);
	return (0);
}
