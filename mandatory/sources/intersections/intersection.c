/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:10 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/10 14:52:51 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool intersects(t_shape *shape, Ray *ray, t_hit *hit_info)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, hit_info));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, hit_info));
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
