/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/26 12:05:14 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include "../libs/Libft/libft.h"
#include <stdlib.h>

int add_node(t_list **a, int index, char **argv)
{
	int *num;
	t_list *new_node;
	
	while (index > 0)
	{
		if (!is_number(argv[index]))
			return (ft_printf("error"), 0);
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(argv[index]);
		new_node = ft_lstnew(num);
		if (!new_node)
		{
			free(num);
			return (0);
		}
		new_node->next = *a;
		*a = new_node;
		index--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list *a = NULL;
	int index;
	

	index = argc - 1;
	if (!add_node(&a, index, argv))
		return (ft_printf("failed to create a node"), 1); //return error here
	t_list *temp = a;
	while (temp)
	{
		ft_printf("node = %i\n", *(int *)temp->content);
		temp = temp->next;
	}
	while (a)
	{
		t_list *next = a->next;
		free(a->content);
		free(a);
		a = next;
	}
	return (0);
}
