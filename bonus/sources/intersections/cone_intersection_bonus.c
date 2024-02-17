/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:30:52 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 21:47:01 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	check_base(Cone *co, Vector cap, t_hit *inter, double t)
{
	double	len;
	Vector	point;

	point = ray_at(&inter->ray, t);
	len = Vector_magnitude(Vector_sub(point, cap));
	len -= EPSILON;
	if (len >= 0 && len <= co->radius && t > EPSILON && t < inter->t)
	{
		inter->a = co->normal;
		inter->t = t;
		inter->m = co->height;
		return (true);
	}
	return (false);
}

bool	check_sides(Cone *cone, t_hit *inter, double t)
{
	Vector	oc;
	Vector	tmp;
	Vector	point;
	double	angle;
	double	m;

	point = ray_at(&inter->ray, t);
	oc = Vector_sub(inter->ray.origin, cone->tip);
	m = Vector_dot(inter->ray.direction, cone->normal) * t + Vector_dot(oc,
			cone->normal);
	tmp = Vector_sub(point, cone->tip);
	angle = acos(Vector_cossine(cone->normal, tmp)) - 0.001;
	if (m >= 0 && m <= cone->height && angle - EPSILON <= cone->angle && t > EPSILON
		&& t < inter->t)
	{
		inter->a = Vector_add(cone->tip, Vector_scale(cone->normal, m));
		inter->m = m;
		inter->t = t;
		return (true);
	}
	return (false);
}

double	cap_intersect(Cone *cone, Ray *ray, Vector cap)
{
	Plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, cone->normal, cone->color);
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersects(Cone *cone, t_equation *equation, t_hit *inter)
{
	double	t3;

	if (!solve(equation))
		return (0);
	inter->t = INFINITY;
	t3 = cap_intersect(cone, &inter->ray, cone->base);
	check_sides(cone, inter, equation->t1);
	check_sides(cone, inter, equation->t2);
	check_base(cone, cone->base, inter, t3);
	if (inter->t == INFINITY || inter->t < 0)
		return (0);
	return (inter->t);
}

bool	cone_intersect(Cone *cone, Ray *ray, t_hit *inter)
{
	Vector		oc;
	t_equation	eq;
	double		t;

	inter->t = -1.0f;
	eq = (t_equation){0, 0, 0, 0, 0};
	oc = Vector_sub(ray->origin, cone->tip);
	eq.a = pow(Vector_dot(ray->direction, cone->normal), 2)
		- pow(cos(cone->angle), 2);
	eq.b = 2.0f * (Vector_dot(ray->direction, cone->normal) * Vector_dot(oc,
				cone->normal) - Vector_dot(ray->direction, oc) * pow(cos(cone->angle),
				2));
	eq.c = pow(Vector_dot(oc, cone->normal), 2) - Vector_dot(oc, oc)
		* pow(cos(cone->angle), 2);
	inter->ray = *ray;
	t = verify_intersects(cone, &eq, inter);
	if (t > 0.0f)
	{
		inter->t = t;
		inter->color = cone->color;
		return (true);
	}
	return (false);
}
