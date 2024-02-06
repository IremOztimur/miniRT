/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:58:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:58:37 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_vector_delete(t_vector *vector)
{
	if (!vector)
		return ;
	ft_vector_clear(vector);
	ft_matrix_delete(vector->array, vector->del);
	free(vector);
}
