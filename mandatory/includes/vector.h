/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:06:43 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 23:14:54 by iremoztimur      ###   ########.fr       */
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
Vector Vector_create(double x, double y, double z);

/**
 * @brief function to calculate the length of a vector
 *
 * @param vec vector
 * @return double
 */
double Vector_magnitude(Vector self);

/**
 * @brief function to normalize a vector
 *
 * @param self vector
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
Vector Vector_scale(Vector self, double scalar);

/**
 * @brief Divide each component of the vector by a scalar value
 *
 * @param vector vector
 * @param scaler scaler value
 * @return vector(x, y, z)
 */
Vector Vector_div(Vector vector, double scalar);

/**
 * @brief function to calculate the dot product of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
double Vector_dot(const Vector v1, const Vector v2);

/**
 * @brief function to calculate the cross product of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
Vector	Vector_cross(Vector v1, Vector v2);

/**
 * @brief function to create a new vector from a string array
 *
 * @param vec string array with the values of x, y and z coordinates
 * @return vector(x, y, z)
 */
Vector Vector_from_string(char **vec);

/**
 * @brief function to calculate the cossine of two vectors
 *
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
double	Vector_cossine(Vector v1, Vector v2);

/**
 * @brief function to comapre two vectors
 *
 * @param vec1 vector
 * @param vec2 vector
 * @return true if the vectors are equal, false otherwise
 */
bool	Vector_compare(Vector v1, Vector v2);

#endif
