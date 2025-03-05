/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/05 09:52:54 by akovalch         ###   ########.fr       */
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
	//ft_printf("head = %d\n", stack->data);
	while (i < size)
	{
		ft_printf("%d -> ", stack->data);
		stack = stack->next;
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		index;

	if (argc < 2)
	{
		ft_printf("Use at least 2 args\n");
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	index = argc - 1;
	while (index > 0)
	{
		if (!is_number(argv[index]))
		{
			ft_printf("error, NAN\n");
			free_stack(&stack_a);
			return (1);
		}
		add_node(&stack_a, argv[index]);
		index--;
	}
	rra(&stack_a);
	ft_printf("stack_a->");
	print_stack(stack_a);
	ft_printf("stack_b->");
	print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
