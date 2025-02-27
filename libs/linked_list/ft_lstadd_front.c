/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:57 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:33:34 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
        return;
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}
