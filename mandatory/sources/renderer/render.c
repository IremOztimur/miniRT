/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:10:48 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/16 15:30:56 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	obj_hit(t_vector *shapes, Ray *ray, t_hit *closest)
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
		if (!intersects(shape, ray, &tmp))
			continue ;
		if (tmp.t > closest->t)
			continue ;
		*closest = tmp;
		closest->ray = *ray;
		closest->shape = shape;
		closest->point = ray_at(ray, closest->t);
		closest->normal = Vector_normalize(shape_normal(closest, ray));
	}
	return (closest->shape != NULL);
}

int	render(Scene *s)
{
	Vector	coords;
	Vector	factors;
	Ray		ray;
	t_hit	closest;

	coords.y = -1;
	while (++coords.y < HEIGHT)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			closest.color = BLACK;
			closest.shape = NULL;
			closest.t = INFINITY;
			factors = canvas_to_viewport(coords.x, coords.y);
			ray = cast_ray(s, factors);
			if (obj_hit(s->shapes, &ray, &closest))
				illuminate(s, &closest);
			put_pixel(s, closest.color, coords.x, coords.y);
		}
	}
	mlx_put_image_to_window(s->disp.mlx, s->disp.win, s->disp.img, 0, 0);
	return (0);
}
