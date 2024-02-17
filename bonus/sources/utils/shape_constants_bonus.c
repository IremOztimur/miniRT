/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:15:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 22:21:33 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	compute_shapes_constants(t_vector *shapes)
{
	t_shape		*shape;
	Cylinder	*cy;
	Cone		*cone;
	uint32_t	i;

	i = -1;
	while (++i < shapes->size)
	{
		shape = ft_vector_at(shapes, i);
		if (shape->type == CYLINDER)
		{
			cy = &shape->data.cy;
			cy->cap_base = Vector_add(cy->center, Vector_scale(cy->normal,\
				-cy->height / 2.0));
			cy->cap_top = Vector_add(cy->center, Vector_scale(cy->normal,\
				cy->height / 2.0));
		}
		else if (shape->type == CONE)
		{
			cone = &shape->data.cn;
			cone->angle = atan(cone->radius / cone->height) + EPSILON;
			cone->base = Vector_add(cone->tip, Vector_scale(cone->normal, cone->height));
		}
	}
}
