/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:31:03 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 20:31:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_clear(t_vector *vector)
{
	uint32_t	size;

	if (!vector)
		return ;
	size = vector->size + 1;
	while (--size)
		ft_vector_pop(vector);
}
