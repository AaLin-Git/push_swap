/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 15:30:21 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <stdbool.h>

void	print_stack(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = get_stack_size(stack);
	if (!stack)
	{
		ft_printf("(empty)\n");
		return;
	}
	while (i < size)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
		i++;
	}
	ft_printf("\n");
}

void	sort(t_data *data)
{
	if (!data->stack_a || is_sorted(&data->stack_a))
	{
		free_stack(&data->stack_a);
		exit (0); //false
	}
	//ft_printf("sort start");
	if (data->stack_a->size == 2 && data->stack_a->value > data->stack_a->next->value)
	{
		//ft_printf("check 2");
		ra(&data->stack_a);
	}
	else if (data->stack_a->size == 3)
		sort_three(data);
	else if (data->stack_a->size <= 5)
		sort_five(data, data->stack_a->size);
	else
		chunk_sort(data);
	ft_printf("stack_a->");
	print_stack(data->stack_a);
	ft_printf("stack_b->");
	print_stack(data->stack_b);
	//ft_printf("min-> %i", data->min);
	//ft_printf("max-> %i", data->max);
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	//ft_printf("sort end");
}

bool init_data(t_data *data, int argc, char **argv)
{	
	t_stack *smallest;
	t_stack *biggest;
	
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->chunk_size = 0;
	if (is_valid(argc, argv))
	{
		if (!fill_stack(data, argc, argv))
		{
			free_stack(&data->stack_a);
			return (false);
		}
		data->stack_a->capacity = argc - 1;
		data->stack_a->size = argc - 1;
		find_smallest_node(&data->stack_a, &smallest);
		find_biggest_node(&data->stack_a, &biggest);
		data->min = smallest->value;
		data->max = biggest->value;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc < 2)
		exit(0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	if (!init_data(data, argc, argv))
	{
		free(data);
		return (EXIT_FAILURE);
	}
	sort(data);
	free(data);
	return (EXIT_SUCCESS);
}
