/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:59:16 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:59:18 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_matrix_size(void *matrix)
{
	size_t	i;

	i = 0;
	while (((void **)matrix)[i])
		i++;
	return (i);
}
