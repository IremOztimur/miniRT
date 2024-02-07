/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:21:07 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 19:41:01 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	sphere_from_strings(Sphere *sp, char **tokens)
{
	char		**c;
	char		**cl;

	c = ft_split(tokens[1], ',');
	cl = ft_split(tokens[3], ',');

	sp->center = Vector_from_string(c);
	sp->color = Color_from_strings(cl);
	sp->radius = ft_atod(tokens[2]) / 2.0;

	ft_matrix_delete(c, &free);
	ft_matrix_delete(cl, &free);
	if (sp->radius < EPSILON)
		return (false);
	return (true);
}
