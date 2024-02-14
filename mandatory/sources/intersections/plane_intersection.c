/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:26:41 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 16:26:57 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_intersect(Plane *pl, Ray *ray, t_hit *hit_info)
{
	Vector		plane_to_ray;
	t_equation	equation;

	// Check if the ray is not parallel to the plane
	if (Vector_dot(ray->direction, pl->normal) != 0.0)
	{
		plane_to_ray = Vector_sub(ray->origin, pl->center);
		equation.a = 0;
		equation.b = Vector_dot(ray->direction, pl->normal);
		equation.c = Vector_dot(plane_to_ray, pl->normal);
		solve(&equation);
		if (equation.t1 > EPSILON)
		{
			hit_info->t = equation.t1;
			hit_info->color = pl->color;
			return (true);
		}
	}
	return (false);
}
