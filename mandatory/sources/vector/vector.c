/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/02 17:11:42 by iremoztimur      ###   ########.fr       */
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
