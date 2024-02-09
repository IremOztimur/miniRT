/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:24:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/08 17:54:27 by iremoztimur      ###   ########.fr       */
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
	//for a test
	return (sphere_normal(inter, ray));
}
