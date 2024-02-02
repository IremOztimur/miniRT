/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:06:43 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/02 17:18:26 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include "miniRT.h"

Vector Vector_create(float x, float y, float z);

float Vector_magnitude(Vector self);
Vector Vector_normalize(Vector self);

Vector Vector_add(Vector v1, const Vector v2);
Vector Vector_sub(Vector v1, const Vector v2);
Vector Vector_scale(Vector self, float scalar);
Vector Vector_subt(Vector self, float scalar);
float Vector_dot_product(const Vector v1, const Vector v2);

#endif
