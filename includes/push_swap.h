/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:53 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/26 12:44:58 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"

typedef struct s_stack
{
    int				data;
	int				index;
    struct s_stack	*next;
	struct s_stack	*prev;
}	t_llist;

int	is_number(char *str);
void add_node(t_list **stack, char *str);
void free_stack(t_list **stack);

#endif