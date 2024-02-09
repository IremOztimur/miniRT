/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:05:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/08 16:30:44 by iremoztimur      ###   ########.fr       */
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

//! Shapes
/**
 * @brief this function will create the corresponding shape given in the
 * type parameter and store it's information on the shape struct
 *
 * @param data struct with shape information
 * @param type type of the shape
 * @param id id of the shape (each shape has a unique id)
 * @return t_shape struct with shape information
 */
t_shape		*shape_new(void	*data, t_shape_type type, int id);

/**
 * @brief this function will copy the shape information from the shape
 * parameter to a new shape
 *
 * @param shape t_shape struct with the shape information
 * @return t_shape struct with shape information
 */
t_shape		*shape_copy(t_shape *shape);

/**
 * @brief this function will check if what type of shape it is and call the
 * respective function to check what is the normal of the shape in the
 * intersection point
 *
 * @param inter t_hit struct with intersection information
 * @param ray Ray struct with ray information
 * @return Vector vector with the normal of the shape in the intersection point
 */
Vector		shape_normal(t_hit *inter, Ray *ray);

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

//! Spheres
/**
 * @brief this function will create a sphere and store it's information
 * from a string array
 *
 * @param sp Sphere struct with sphere information
 * @param tokens string array with sphere information
 * @return true if the sphere was created correctly, false otherwise
 */
bool		sphere_from_strings(Sphere *sp, char **tokens);

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

/**
 * @brief this function will calculate the normal of the sphere in the
 * intersection point
 *
 * @param inter t_hit struct with intersection information
 * @param ray Ray struct with ray information
 * @return Vector vector with the normal of the sphere in the intersection
 * point
 */
Vector		sphere_normal(t_hit *inter, Ray *ray);

//! Lights
/**
 * @brief this function will create a light and store it's information
 * from a string array
 *
 * @param point string array with light position
 * @param ratio string with light ratio
 * @param color string array with light color
 * @return Light struct with light information
 */
Light		*light_new(char **point, char *ratio, char **color);

/**
 * @brief this function will copy the light information from the lightsource
 * parameter to a new lightsource
 *
 * @param lightsource Light struct with the light information
 * @return Light struct with new light information
 */
Light		*light_copy(Light *lightsource);

#endif
