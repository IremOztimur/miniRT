/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:08:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 16:13:35 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	cylinder_from_strings(Cylinder *cy, char **tokens)
{
	char		**coords;
	char		**n;
	char		**cl;

	coords = ft_split(tokens[1], ',');
	n = ft_split(tokens[2], ',');
	cl = ft_split(tokens[5], ',');

	cy->radius = ft_atod(tokens[3]) / 2.0;
	cy->center = Vector_from_string(coords);
	cy->height = ft_atod(tokens[4]);
	cy->color = Color_from_strings(cl);
	cy->normal = Vector_from_string(n);

	ft_matrix_delete(coords, &free);
	ft_matrix_delete(n, &free);
	ft_matrix_delete(cl, &free);

	if (Vector_magnitude(cy->normal) < 1.0 - EPSILON \
		|| cy->radius < EPSILON || cy->height < EPSILON)
		return (false);
	cy->normal = Vector_normalize(cy->normal);
	cy->cap_base = Vector_add(cy->center, Vector_scale(cy->normal,\
	 -cy->height / 2.0));
	cy->cap_top = Vector_add(cy->center, Vector_scale(cy->normal,\
	 cy->height / 2.0));
	return (true);
}
