/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:10 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 23:12:14 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool intersects(t_shape *shape, Ray *ray, t_hit *hit_info)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, hit_info));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, hit_info));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray, hit_info));
	return (false);
}
