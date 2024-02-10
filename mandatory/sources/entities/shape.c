/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:55:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/10 12:45:41 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_shape	*shape_copy(t_shape *shape)
{
	t_shape *copy;

	copy = ft_calloc(1, sizeof(t_shape));
	if (!copy)
		return (NULL);
	copy->id = shape->id;
	copy->type = shape->type;
	if (shape->type == SPHERE)
		copy->data.sp = shape->data.sp;
	else if (shape->type == PLANE)
		copy->data.pl = shape->data.pl;
	return (copy);
}

t_shape	*shape_new(void	*data, t_shape_type type, int id)
{
	t_shape	*shape;

	shape = ft_calloc(1, sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->id = id;
	shape->type = type;
	if (type == SPHERE)
		shape->data.sp = *(Sphere *)data;
	else if (type == PLANE)
		shape->data.pl = *(Plane *)data;
	return (shape);
}
