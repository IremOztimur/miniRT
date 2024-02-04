/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:46:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 23:02:16 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/renderer.h"

void	init_viewport(Scene *s)
{
	//TO-DO: parse camera fov from the scene
	s->wview = tan(RADIANS(s->camera.fov / 2.0));
	s->hview = s->wview / RATIO;
	s->right = Vector_normalize(Vector_cross(s->camera.normal, UPGUIDE));
	s->up = Vector_normalize(Vector_cross(s->camera.normal, s->right));
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

// TO-DO: Write a function that formulates ray equation
