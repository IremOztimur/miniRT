/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 22:12:51 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

Vector Vector_create(float x, float y, float z)
{
	Vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;

	return (vector);
}

float Vector_magnitude(Vector self)
{
	return(sqrt(Vector_dot(self, self)));
}
