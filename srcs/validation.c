/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/24 15:19:21 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <limits.h>

static int	is_number(char **argv, int size)
{
	int		i;
	char	*str;

	//ft_printf("is_number start");
	i = 1;
	while (i <= size)
	{
		str = argv[i];
		if (*str == '-' || *str == '+')
			str++;
		if (!(*str))
			return (0);
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (0);
			str++;
		}
		i++;
	}
	//ft_printf("is_number end");
	return (1);
}

int	is_sorted(t_stack **stack)
{
	//ft_printf("is_sorted start");
	t_stack	*current;

	current = *stack;
	while (current->next != *stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	//ft_printf("is_sorted end");
	return (1);
}

static int	is_duplicate(char **argv, int size)
{
	//ft_printf("size = %i", size);
	int	i;
	int	j;

	i = 1;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	//ft_printf("is_dup end");
	return (0);
}

static int	is_int_limit(char **argv, int size)
{
	//ft_printf("is_limit start");
	int		i;
	long	num;

	i = 1;
	while (i <= size)
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		i++;
	}
//	ft_printf("is_limit end");
	return (0);
}

int	is_valid(int argc, char **argv)
{
	//ft_printf("is_valid start");
	if (!is_number(argv, argc - 1) || is_duplicate(argv, argc - 1)
		|| is_int_limit(argv, argc - 1))
		return (print_error(ERR), 0);
	//ft_printf("is_valid end");
	return (1);
}
