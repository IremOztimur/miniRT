/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/09 13:32:38 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

Vector Vector_create(double x, double y, double z)
{
	Vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;

	return (vector);
}

double Vector_magnitude(Vector self)
{
	return(sqrt(Vector_dot(self, self)));
}
