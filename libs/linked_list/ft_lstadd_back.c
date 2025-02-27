/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:13:14 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:39:42 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastnode;

	if (!lst || !new)
        return;
	lastnode = ft_lstlast(*lst);
	if (!lastnode)
		*lst = new;
	else
	{
		lastnode->next = new;
		new->prev = lastnode;
	}
}
