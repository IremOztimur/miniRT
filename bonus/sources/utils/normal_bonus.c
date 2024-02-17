/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 23:15:59 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

Vector	sphere_normal(t_hit *inter, Ray *ray)
{
	Vector	point;
	Vector	normal;

	point = ray_at(ray, inter->t);
	normal = Vector_sub(point, inter->shape->data.sp.center);
	return (normal);
}

Vector	shape_normal(t_hit *inter, Ray *ray)
{
	if (inter->shape->type == SPHERE)
		return (sphere_normal(inter, ray));
	else if (inter->shape->type == PLANE)
		return (inter->shape->data.pl.normal);
	else
		return (sphere_normal(inter, ray));
}


Vector	cylinder_normal(t_hit *inter, Ray *ray)
{
	Vector	point;
	Vector	normal;

	point = ray_at(ray, inter->t);
	normal = Vector_sub(point, inter->a);
	if (Vector_compare(inter->a, inter->shape->data.cy.cap_base))
		normal = Vector_scale(inter->shape->data.cy.normal, -1);
	else if (Vector_compare(inter->a, inter->shape->data.cy.cap_top))
		normal = inter->shape->data.cy.normal;
	return (normal);
}

