/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:58:26 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:58:26 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_vector_pop(t_vector *vector)
{
	if (!vector || !vector->size)
		return ;
	if (vector->del)
		(*vector->del)(vector->array[vector->size - 1]);
	vector->array[vector->size - 1] = NULL;
	--vector->size;
}
