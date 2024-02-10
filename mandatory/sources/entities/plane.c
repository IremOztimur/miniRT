/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:11:06 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/10 12:37:48 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_from_strings(Plane *pl, char **tokens)
{
	char	**coords;
	char	**n;
	char	**cl;

	coords = ft_split(tokens[1], ',');
	n = ft_split(tokens[2], ',');
	cl = ft_split(tokens[3], ',');

	pl->center = Vector_from_string(coords);
	pl->normal = Vector_from_string(n);
	pl->color = Color_from_strings(cl);

	if (Vector_magnitude(pl->normal) < 1.0 - EPSILON)
		return (false);
	pl->normal = Vector_normalize(pl->normal);
	pl->normal = Vector_add(pl->normal, VEC_EPSILON);
	ft_matrix_delete(coords, &free);
	ft_matrix_delete(n, &free);
	ft_matrix_delete(cl, &free);
	return (true);
}
