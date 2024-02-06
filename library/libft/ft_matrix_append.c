/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:59:09 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:59:09 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_matrix_append(void *matrix, void *data, void *(*copy)(void *))
{
	void	**res;
	size_t	i;

	i = -1;
	res = ft_calloc(ft_matrix_size(matrix) + 2, sizeof(void *));
	while (((void **)matrix)[++i])
	{
		if (copy)
			res[i] = (*copy)(((void **)matrix)[i]);
		else
			res[i] = ((void **)matrix)[i];
	}
	res[i] = data;
	return (res);
}
