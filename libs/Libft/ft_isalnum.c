/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:05:32 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/17 18:35:35 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < '0' || c > '9') && (c < 'A' || (c > 'Z' && c < 'a') || c > 'z'))
	{
		return (0);
	}
	return (1);
}
