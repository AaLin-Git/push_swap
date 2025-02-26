/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:41:26 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/26 12:44:21 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void add_node(t_list **stack, char *str)
{
	int *num;
	t_list *new_node;
	
	num = malloc(sizeof(int));
	if (!num)
		return ;
	*num = ft_atoi(str);
	new_node = ft_lstnew(num);
	if (!new_node)
	{
		free(num);
		return ;
	}
	new_node->next = *stack;
	*stack = new_node;
}
