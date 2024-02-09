/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:10 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/09 19:36:03 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool intersects(t_shape *shape, Ray *ray, t_hit *hit_info)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, hit_info));
	return (false);
}

bool	sphere_intersect(Sphere *sp, Ray *ray, t_hit *hit_info)
{
	Vector sphere_to_ray;
	t_equation	eq;

	eq.t1 = -1.0f;
	sphere_to_ray = Vector_sub(ray->origin, sp->center);
	eq.a = Vector_dot(ray->direction, ray->direction);
	eq.b = 2.0f * Vector_dot(sphere_to_ray, ray->direction);
	eq.c = Vector_dot(sphere_to_ray, sphere_to_ray) - pow(sp->radius, 2);
	if (solve(&eq) > 0 && (eq.t1 > EPSILON || eq.t2 > EPSILON))
	{
		if (eq.t1 > EPSILON)
			hit_info->t = eq.t1;
		else
			hit_info->t = eq.t2;
		hit_info->color = sp->color;
		return (true);
	}
	return (false);
}
