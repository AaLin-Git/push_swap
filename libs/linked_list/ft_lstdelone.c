/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:20:17 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:35:56 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdlib.h>

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
