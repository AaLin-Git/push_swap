/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/19 14:27:08 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <limits.h>

static int	is_number(char **argv, int size)
{
	int		i;
	char	*str;

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
	return (1);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	is_duplicate(char **argv, int size)
{
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
	return (0);
}

static int	is_int_limit(char **argv, int size)
{
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
	return (0);
}

int	is_valid(char **argv, int size)
{
	if (!is_number(argv, size) || is_duplicate(argv, size)
		|| is_int_limit(argv, size))
		return (print_error(ERR), 0);
	return (1);
}
