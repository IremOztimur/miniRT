/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:59:13 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:59:13 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_matrix_delete(void *matrix, void (*del)(void *))
{
	size_t	i;

	if (!matrix)
		return ;
	if (del)
	{
		i = -1;
		while (((void **)matrix)[++i])
			del(((void **)matrix)[i]);
	}
	free(matrix);
}
