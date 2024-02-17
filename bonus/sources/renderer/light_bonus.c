/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:40:39 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 01:50:51 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	illuminate(Scene *scene, t_hit *closest)
{
	uint32_t i;
	Color	color;
	Light	*bulb;

	i = -1;
	color = ambient(closest->color, scene->ambient.ratio);
	while (++i < scene->lights->size)
	{
		bulb = ft_vector_at(scene->lights, i);
		if (is_shadowed(scene, bulb, closest))
			continue ;
		color = Color_add(color, diffuse(bulb, closest, bulb->ratio));
		color = Color_add(color, specular(bulb, closest));
	}
	closest->color = color;
}

Color	ambient(Color	color, double ratio)
{
	return (Color_mult(color, ratio));
}

bool	is_shadowed(Scene *scene, Light *bulb, t_hit *closest)
{
	Vector	light_dir;
	Ray	ray;
	double	light_distance;

	light_dir = Vector_sub(bulb->center, closest->point);
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
	diffuse_ratio = MAX(0.0, i * cos_angle * attenuation);
	diff_color = Color_mult(inter->color, diffuse_ratio);
	diff_color = Color_blender(diff_color, bulb->color);
	return (diff_color);
}

Color	specular(Light *bulb, t_hit *closest)
{
	double	spec_ratio;
	Vector	light_dir;
	Vector	camera_dir;
	Vector	half_vector;
	double	cosine;

	if (closest->shape->shininess < 1.0)
		return (BLACK);
	light_dir = Vector_sub(bulb->center, closest->point);
	camera_dir = Vector_scale(closest->ray.direction, -1);
	camera_dir = Vector_normalize(camera_dir);
	half_vector = Vector_normalize(Vector_add(camera_dir, light_dir));
	cosine = MAX(0.0, Vector_dot(half_vector, closest->normal));
	spec_ratio = closest->shape->sp_ratio * bulb->ratio * pow(cosine,
			closest->shape->shininess);
	return (Color_blender(Color_mult(closest->color, spec_ratio), bulb->color));
}
