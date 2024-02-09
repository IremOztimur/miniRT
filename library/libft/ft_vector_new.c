/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:58:31 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:58:31 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_vector	*ft_vector_new(void *(*cpy)(), void (*del)(void *),\
	void (*print)(void *))
{
	t_vector	*vector;

	vector = ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->array = ft_calloc(1, sizeof(void *));
	if (!vector->array)
	{
		free(vector);
		return (NULL);
	}
	vector->cpy = cpy;
	vector->del = del;
	vector->print = print;
	return (vector);
}
