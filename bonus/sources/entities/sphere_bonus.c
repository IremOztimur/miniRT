/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:21:07 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 19:24:51 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	sphere_from_strings(Sphere *sp, char **tokens)
{
	char		**coords;
	char		**cl;

	coords = ft_split(tokens[1], ',');
	cl = ft_split(tokens[3], ',');

	sp->center = Vector_from_string(coords);
	sp->color = Color_from_strings(cl);
	sp->radius = ft_atod(tokens[2]) / 2.0;

	ft_matrix_delete(coords, &free);
	ft_matrix_delete(cl, &free);
	if (sp->radius < EPSILON)
		return (false);
	return (true);
}
