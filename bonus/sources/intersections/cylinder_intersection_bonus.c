/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:33:11 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 23:09:10 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_caps(Cylinder *cy, Vector cap, t_hit *inter, double t)
{
	double	len;
	Vector	point;

	point = ray_at(&inter->ray, t);
	len = Vector_magnitude(Vector_sub(point, cap));
	len += EPSILON;
	if (len <= cy->radius && t > EPSILON && t < inter->t)
	{
		inter->a = cap;
		inter->t = t;
		return (true);
	}
	return (false);
}

bool	check_walls(Cylinder *cy, t_hit *inter, double t)
{
	Vector	point;
	Vector	co;
	Vector	a;
	double	m;
	double	len;

	point = ray_at(&inter->ray, t);
	co = Vector_sub(inter->ray.origin, cy->cap_base);
	m = Vector_dot(inter->ray.direction, cy->normal) * t + \
		Vector_dot(co, cy->normal);
	a = Vector_add(cy->cap_base, Vector_scale(cy->normal, m));
	len = Vector_magnitude(Vector_sub(point, a));
	m -= EPSILON;
	len -= EPSILON;
	if (m >= 0 && m <= cy->height && len <= cy->radius \
		&& t > EPSILON && t < inter->t)
	{
		inter->a = a;
		inter->t = t;
		return (true);
	}
	return (false);
}

double	cap_intersection(Cylinder *cy, Ray *ray, Vector cap)
{
	Plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, cy->normal, BLACK);
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersections(Cylinder *cy, Ray *ray, \
	t_equation *eq, t_hit *hit_info)
{
	double	t3;
	double	t4;

	t3 = cap_intersection(cy, ray, cy->cap_base);
	t4 = cap_intersection(cy, ray, cy->cap_top);
	hit_info->t = INFINITY;
	hit_info->ray = *ray;
	check_walls(cy, hit_info, eq->t1);
	check_walls(cy, hit_info, eq->t2);
	check_caps(cy, cy->cap_base, hit_info, t3);
	check_caps(cy, cy->cap_top, hit_info, t4);
	if (hit_info->t == INFINITY)
		return (0);
	return (hit_info->t);
}

bool	cylinder_intersect(Cylinder *cy, Ray *ray, t_hit *hit_info)
{
	double		t;
	Vector		cy_to_ray;
	t_equation	eq;

	eq.t1 = -1;
	eq.t2 = -1;
	cy_to_ray = Vector_sub(ray->origin, cy->cap_base);
	eq.a = Vector_dot(ray->direction, ray->direction) - \
		pow(Vector_dot(ray->direction, cy->normal), 2);
	eq.b = 2 * (Vector_dot(ray->direction, cy_to_ray) - \
		(Vector_dot(ray->direction, cy->normal) * Vector_dot(cy_to_ray, cy->normal)));
	eq.c = Vector_dot(cy_to_ray, cy_to_ray) - pow(Vector_dot(cy_to_ray, cy->normal), 2) - \
		pow(cy->radius, 2);
	solve(&eq);
	if (eq.t1 <= 0 && eq.t2 <= 0)
		return (false);
	t = verify_intersections(cy, ray, &eq, hit_info);
	if (t > 0.0f)
	{
		hit_info->t = t;
		hit_info->color = cy->color;
		return (true);
	}
	return (false);
}
