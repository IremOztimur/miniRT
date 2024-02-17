/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:40:39 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/16 22:23:16 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	illuminate(Scene *scene, t_hit *closest)
{
	Color	color;
	Light	*bulb;

	bulb = ft_vector_at(scene->lights, 0);
	color = ambient(closest->color, scene->ambient.ratio);
	if (bulb && !is_shadowed(scene, closest))
		color = Color_add(color, diffuse(bulb, closest, bulb->ratio));
	closest->color = color;
}

Color	ambient(Color	color, double ratio)
{
	return (Color_mult(color, ratio));
}

bool	is_shadowed(Scene *scene, t_hit *closest)
{
	Vector	light_dir;
	Light	*light;
	Ray		ray;
	double	light_distance;

	if (!scene->lights->size)
		return (false);
	light = ft_vector_at(scene->lights, 0);
	light_dir = Vector_sub(light->center, closest->point);
	light_distance = Vector_magnitude(light_dir);
	ray.origin = Vector_add(closest->point, VEC_EPSILON);
	ray.direction = Vector_normalize(light_dir);
	return (is_obscured(scene->shapes, closest->shape, &ray, light_distance));
}

bool	is_obscured(t_vector *shapes, t_shape *self, Ray *ray, double max_t)
{
	uint32_t	i;
	t_hit		tmp;
	t_shape		*shape;

	i = -1;
	tmp.t = INFINITY;
	tmp.shape = NULL;
	while (++i < shapes->size)
	{
		shape = ft_vector_at(shapes, i);
		if (shape->id == self->id)
			continue ;
		if (intersects(shape, ray, &tmp) && tmp.t < max_t)
			return (true);
	}
	return (false);
}

Color	diffuse(Light *bulb, t_hit *inter, double i)
{
	Vector	light_dir;
	Color	diff_color;
	double	cos_angle;
	double	diffuse_ratio;
	double	attenuation;

	light_dir = Vector_sub(bulb->center, inter->point);
	attenuation = MIN(1.0, 90.0 / Vector_magnitude(light_dir));
	cos_angle = Vector_cossine(inter->normal, light_dir);
	diffuse_ratio = i * cos_angle * attenuation;
	diff_color = Color_mult(inter->color, diffuse_ratio);
	return (diff_color);
}
