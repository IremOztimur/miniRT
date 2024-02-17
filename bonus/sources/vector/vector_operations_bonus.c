/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:31 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 23:14:18 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"


double Vector_dot(const Vector v1, const Vector v2)
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

Vector Vector_scale(Vector v1, double scalar)
{
	return (Vector_create(v1.x * scalar, v1.y * scalar, v1.z * scalar));
}

Vector Vector_div(Vector vector, double scalar)
{
	vector.x /= scalar;
	vector.y /= scalar;
	vector.z /= scalar;
	return (vector);
}

Vector Vector_normalize(Vector vec)
{
	return (Vector_scale(vec, 1.0 / Vector_magnitude(vec)));
}

Vector Vector_cross(Vector v1, Vector v2)
{
	Vector	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

Vector Vector_from_string(char **vec)
{
	Vector vector;

	vector.x = ft_atod(vec[X]);
	vector.y = ft_atod(vec[Y]);
	vector.z = ft_atod(vec[Z]);

	return (vector);
}

double	Vector_cossine(Vector v1, Vector v2)
{
	double	dot;
	double	lengths;

	dot = Vector_dot(v1, v2);
	lengths = Vector_magnitude(v1) * Vector_magnitude(v2);
	return (dot / lengths);
}

bool	Vector_compare(Vector v1, Vector v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}
