/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:06:36 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:25:21 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdlib.h>

t_stack	*ft_lstnew(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}