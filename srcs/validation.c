/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by akovalch          #+#    #+#             */
/*   Updated: 2025/03/18 10:53:06 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include <limits.h>

int	is_number(char **argv, int size)
{
	int i;
	char *str;

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

int is_sorted(t_stack **stack)
{
	t_stack *current;

	current = *stack;
	while (current->next != *stack)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int is_duplicate(char **argv, int size)
{
	int i;
	int j;

	i = 1;
	while (i <= size)
	{
		//ft_printf("i = %i, size = %i\n", i, size);
		j = i + 1;
		while (j <= size)
		{
			//ft_printf("j = %i, size = %i\n", j, size);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	num;
	long	negative;

	num = 0;
	negative = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		negative = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (num > (LONG_MAX - (*nptr - '0')) / 10)
			{
				if (negative == 1)
					return (LONG_MAX);
				else
					return (LONG_MIN);
			}
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * negative);
}

int is_int_limit(char **argv, int size)
{
	int i;
	long num;
	
	i = 1;
	while (i <= size)
	{
		num = ft_atol(argv[i]);
		//ft_printf("num = %i\n", num);
		if (num < INT_MIN || num > INT_MAX)
		{
			//ft_printf("too big num");
			return (1);
		}
		i++;
	}
	return (0);
}

int is_valid(char **argv, int size)
{
	if (!is_number(argv, size))
	{
		ft_printf(ERR_NAN);
		return (0);
	}
	if (is_duplicate(argv, size))
	{
		ft_printf(ERR_DUP);
		return (0);
	}
	if (is_int_limit(argv, size))
	{
		ft_printf(ERR_INT);
		return (0);
	}
	return (1);
}
