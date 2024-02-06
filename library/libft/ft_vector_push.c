/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:58:22 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:58:22 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_vector_push(t_vector *vector, void *element)
{
	void	**matrix;

	if (!vector)
		return ;
	matrix = ft_matrix_append(vector->array, element, vector->cpy);
	ft_matrix_delete(vector->array, vector->del);
	vector->array = matrix;
	vector->size++;
}
