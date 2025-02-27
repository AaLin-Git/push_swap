/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:16:34 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:38:34 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <limits.h>
// # include <stdint.h>

typedef struct s_stack
{
    int				data;
	int				index;
    struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
void	ft_lstdelone(t_stack *lst);
int		ft_lstsize(t_stack *lst);

#endif