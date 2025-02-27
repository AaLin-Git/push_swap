/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:53 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 10:12:18 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include "../libs/linked_list/linked_list.h"

int		is_number(char *str);
void	add_node(t_stack **stack, char *str);
void	free_stack(t_stack **stack);

#endif