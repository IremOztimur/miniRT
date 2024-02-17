/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:55:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 22:11:01 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_shape	*shape_copy(t_shape *shape)
{
	t_shape	*copy;

	copy = ft_calloc(1, sizeof(t_shape));
	if (!copy)
		return (NULL);
	*copy = *shape;
	return (copy);
}

t_shape	*shape_new(void	*data, t_shape_type type, int id, char **tokens)
{
	t_shape	*shape;

	shape = ft_calloc(1, sizeof(t_shape));
	if (!shape)
		return (NULL);
	if (type == SPHERE)
		shape->data.sp = *(Sphere *)data;
	else if (type == PLANE)
		shape->data.pl = *(Plane *)data;
	else if (type == CYLINDER)
		shape->data.cy = *(Cylinder *)data;
	else if (type == CONE)
		shape->data.cn = *(Cone *)data;
	shape->id = id;
	shape->type = type;
	shape->sp_ratio = ft_atod(tokens[0]);
	shape->shininess = ft_atod(tokens[1]);
	return (shape);
}
