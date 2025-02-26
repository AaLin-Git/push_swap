/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/26 13:48:40 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*temp;
	int		index;

	index = argc - 1;
	a = NULL;
	while (index > 0)
	{
		if (!is_number(argv[index]))
		{
			ft_printf("error, NAN");
			free_stack(&a);
			return (1);
		}
		add_node(&a, argv[index]);
		index--;
	}
	temp = a;
	while (temp)
	{
		ft_printf("node = %i\n", *(int *)temp->content);
		temp = temp->next;
	}
	free_stack(&a);
	return (0);
}
