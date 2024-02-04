/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:06:43 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 22:11:42 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include "miniRT.h"

/**
 * @brief function to create a new vector with the given values
 *
 * @param x value for x coordinate
 * @param y value for y coordinate
 * @param z value for z coordinate
 * @return vector(x, y, z)
 */
Vector Vector_create(float x, float y, float z);

/**
 * @brief function to calculate the length of a vector
 *
 * @param vec vector
 * @return double
 */
float Vector_magnitude(Vector self);

/**
 * @brief function to normalize a vector
 *
 * @param vec vector
 * @return vector(x, y, z)
 */
Vector Vector_normalize(Vector self);

/**
 * @brief function to add two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
Vector Vector_add(Vector v1, const Vector v2);

/**
 * @brief function to subtract two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
Vector Vector_sub(Vector v1, const Vector v2);

/**
 * @brief function to scale a vector
 *
 * @param v1 vector to be scaled
 * @param scalar scalar value
 * @return vector(x, y, z)
 */
Vector Vector_scale(Vector self, float scalar);

/**
 * @brief Divide each component of the vector by a scalar value
 *
 * @param vector vector
 * @param scaler scaler value
 * @return vector(x, y, z)
 */
Vector Vector_div(Vector vector, float scalar);

/**
 * @brief function to calculate the dot product of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
float Vector_dot(const Vector v1, const Vector v2);

/**
 * @brief function to calculate the cross product of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
Vector	Vector_cross(Vector v1, Vector v2);

#endif
