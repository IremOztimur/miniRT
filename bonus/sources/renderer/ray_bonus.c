/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:46:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/16 15:30:56 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_viewport(Scene *s)
{
	s->wview = tan(RADIANS(s->camera.fov / 2.0));
	s->hview = s->wview / RATIO;
	s->right = Vector_normalize(Vector_cross(s->camera.normal, UPGUIDE));
	s->up = Vector_normalize(Vector_cross(s->camera.normal, s->right));
	s->right = Vector_normalize(Vector_cross(s->camera.normal, s->up));
}

Vector	canvas_to_viewport(int x, int y)
{
	Vector	converted;
	double	width;
	double	height;

	width = WIDTH;
	height = HEIGHT;
	converted.x = ((2.0f * x) / width) - 1;
	converted.y = ((2.0f * y) / height) - 1;
	converted.z = 0;
	return (converted);
}

Ray	cast_ray(Scene *s, Vector factors)
{
	Ray ray;
	Vector vertical;
	Vector horizontal;
	Vector res;

	vertical = Vector_scale(s->up, factors.y * s->hview);
	horizontal = Vector_scale(s->right, factors.x * s->wview);
	res = Vector_add(vertical, horizontal);
	res = Vector_add(res, s->camera.normal);
	res = Vector_add(res, s->camera.center);
	ray.origin = s->camera.center;
	ray.direction = Vector_normalize(Vector_sub(res, ray.origin));
	return(ray);
}

Vector ray_at(Ray *ray, double t)
{
	return (Vector_add(ray->origin, Vector_scale(ray->direction, t)));
}
