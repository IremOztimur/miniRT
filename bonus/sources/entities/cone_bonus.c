/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:59:53 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 22:09:09 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	cone_from_strings(Cone *cone, char **tokens)
{
	char	**coords;
	char	**n;
	char	**cl;

	coords = ft_split(tokens[1], ',');
	n = ft_split(tokens[2], ',');
	cl = ft_split(tokens[5], ',');
	*cone = (Cone)
	{
		.radius = ft_atod(tokens[3]),
		.height = ft_atod(tokens[4]),
		.tip = Vector_from_string(coords),
		.normal = Vector_from_string(n),
		.color = Color_from_strings(cl),
	};
	ft_matrix_delete(coords, &free);
	ft_matrix_delete(n, &free);
	ft_matrix_delete(cl, &free);
	if (Vector_magnitude(cone->normal) < 1.0 - EPSILON || cone->radius < EPSILON
		|| cone->height < EPSILON)
		return (false);
	cone->normal = Vector_normalize(cone->normal);
	return (true);
}
