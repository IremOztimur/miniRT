/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:05:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/06 22:39:26 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

#include "miniRT.h"

/**
 * @brief this function will create the scene struct and initialize
 * all members of the struct.
 *
 *
 * @return Scene struct with root information
 */
Scene		*Scene_create(void);

/**
 * @brief this function will destroy the scene struct and free all
 * members of the struct.
 *
 * @param Scene Scene struct with root information
 */
void		Scene_destroy(Scene **scene);

/**
 * @brief this function will copy the shape information from the shape
 * parameter to a new shape
 *
 * @param shape t_shape struct with the shape information
 * @return t_shape struct with shape information
 */
t_shape		*shape_copy(t_shape *shape);

/**
 * @brief this function will check what type of shape it is and call the
 * respective function to check if the ray intersects with the shape
 *
 * @param shape cylinder, sphere or plane
 * @param ray struct with ray information
 * @param hit_info struct with intersection information
 * @return true if the ray intersects with the shape, false otherwise
 */
bool intersects(t_shape *shape, Ray *ray, t_hit *hit_info);

/**
 * @brief this function will check if the ray intersects with the sphere,
 * using the quadratic equation (solve function). If the determinant is
 * greater than 0, then the ray intersects with the sphere. If not, then
 * the ray doesn't intersect with it.
 *
 * @param sp Sphere struct with sphere information
 * @param ray Ray struct with ray information
 * @param hit_info t_hit struct with intersection information
 * @return true if the ray intersects with the sphere, false otherwise
 */
bool		sphere_intersect(Sphere *sp, Ray *ray, t_hit *hit_info);

#endif
