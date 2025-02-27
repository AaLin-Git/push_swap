/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:30 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/27 09:57:52 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;
	int		index;

	index = argc - 1;
	a = NULL;
	if (argc < 2)
    {
        printf("Use at least 2 arg\n");
        return (1);
    }
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
		ft_printf("node = %i\n", temp->data);
		temp = temp->next;
	}
	free_stack(&a);
	return (0);
}
