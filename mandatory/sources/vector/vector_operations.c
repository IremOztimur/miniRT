/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:31 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 22:12:06 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"


float Vector_dot(const Vector v1, const Vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

Vector Vector_add(Vector v1, const Vector v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

Vector Vector_sub(Vector v1, const Vector v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

Vector Vector_scale(Vector self, float scalar)
{
	self.x *= scalar;
	self.y *= scalar;
	self.z *= scalar;
	return (self);
}

Vector Vector_div(Vector vector, float scalar)
{
	vector.x /= scalar;
	vector.y /= scalar;
	vector.z /= scalar;
	return (vector);
}

Vector Vector_normalize(Vector self)
{
	return (Vector_div(self, Vector_magnitude(self)));
}

Vector Vector_cross(Vector v1, Vector v2)
{
	Vector crossed_v;

	crossed_v.x = v1.y * v2.z - v1.z * v2.y;
	crossed_v.y = v1.z * v1.x - v1.x * v2.z;
	crossed_v.z = v1.x * v2.y - v1.y * v2.x;

	return (crossed_v);
}
