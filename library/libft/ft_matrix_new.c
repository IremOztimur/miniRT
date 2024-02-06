/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:33:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/06 22:33:53 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_matrix_new(size_t lines, size_t columns)
{
	void	*matrix;
	size_t	i;

	i = -1;
	matrix = ft_calloc(lines + 1, sizeof(char *));
	if (!matrix || !columns)
		return (matrix);
	while (++i < lines)
		((char **)matrix)[i] = ft_calloc(columns + 1, sizeof(char));
	return (matrix);
}
