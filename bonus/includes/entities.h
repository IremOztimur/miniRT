/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:05:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 22:32:26 by iremoztimur      ###   ########.fr       */
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
 * @param tokens string array with common shape information, like
 * shininess and specular ratio
 * @return t_shape struct with shape information
 */
t_shape	*shape_new(void	*data, t_shape_type type, int id, char **tokens);

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

//! Planes
/**
 * @brief function that will create a plane and store it's information
 * from a string array
 *
 * @param pl Plane struct with plane information
 * @param tokens string array with plane information
 * @return true if the plane was created correctly, false otherwise
 */
bool		plane_from_strings(Plane *pl, char **tokens);

/**
 * @brief this function will check if the ray intersects with the plane,
 * using the dot product of the ray direction and the plane normal. If the
 * dot product is not 0, then the ray intersects with the plane. If not, then
 * the ray is parallel to the plane and doesn't intersect with it.
 *
 * @param pl Plane struct with plane information
 * @param ray Ray struct with ray information
 * @param inter t_hit struct with intersection information
 * @return true if the ray intersects with the plane, false otherwise
 */
bool	plane_intersect(Plane *pl, Ray *ray, t_hit *hit_info);

/**
 * @brief this function will create a plane with the correponding information
 *
 * @param point point in the plane
 * @param normal normal of the plane
 * @param color color of the plane
 * @return Plane struct with plane information
 */
Plane		plane_from_numbers(Vector point, Vector normal, Color color);

//! Cylinders
/**
 * @brief this function will create a cylinder and store it's information
 * from a string array
 *
 * @param cy Cylinder struct with cylinder information
 * @param tokens string array with cylinder information
 * @return true if the cylinder was created correctly, false otherwise
 */
bool		cylinder_from_strings(Cylinder *cy, char **tokens);

/**
 * @brief this function will check if the ray intersects with the cylinder,
 * using the quadratic equation (solve function) to discover the intersection
 * with the "walls" of the cylinder and the distance between the ray origin.
 * And then, using the dot product of the ray direction and the cylinder
 * normal, it will check if the ray intersects with the "caps" of the cylinder.
 *
 * @param cy Cylinder struct with cylinder information
 * @param ray Ray struct with ray information
 * @param hit_info t_hit struct with intersection information
 * @return true if the ray intersects with the cylinder, false otherwise
 */
bool	cylinder_intersect(Cylinder *cy, Ray *ray, t_hit *hit_info);


/**
 * @brief this function will calculate the 4 possible intersections of the
 * ray with the cylinder and store them in the equation struct. Then, it will
 * check if the ray intersects with the "walls" and "caps" of the cylinder and
 * store the closest intersection point in the intersection struct.
 *
 * @param cy Cylinder struct with cylinder information
 * @param ray Ray struct with ray information
 * @param equation t_equation struct with intersection information
 * @param hit_info t_hit struct with intersection information
 * @return "t" value of the closest intersection point found
 */
double	verify_intersections(Cylinder *cy, Ray *ray, \
	t_equation *eq, t_hit *hit_info);

/**
 * @brief this function will check if the ray intersects with the "caps" of
 * the cylinder, using the plane_from_number function.
 *
 * @param cy t_cylinder struct with cylinder information
 * @param ray t_ray struct with ray information
 * @param cap vector with the cap center point
 * @return "t" value of the intersection point with the "cap" of the cylinder
 */
double	cap_intersection(Cylinder *cy, Ray *ray, Vector cap);

/**
 * @brief this function will check if the ray intersects with the "walls" of
 * the cylinder. Using the "t" value we will check if the intersection point
 * is inside the cylinder, comparing with the height and radius.
 *
 * @param cy Cylinder struct with cylinder information
 * @param inter t_hit struct with intersection information
 * @param t "t" value of the intersection point
 * @return true if the ray intersects with the "walls" of the cylinder and "t"
 * value is lower than the one found until now, false otherwise
 */
bool	check_walls(Cylinder *cy, t_hit *inter, double t);

/**
 * @brief this function will check if the ray intersects with the "caps" of
 * the cylinder. Using the "t" value we will check if the intersection point
 * is inside on the cap of the cylinder, comparing its distance with the radius.
 *
 * @param cy Cylinder struct with cylinder information
 * @param cap center point of the cap
 * @param inter t_hit struct with intersection information
 * @param t "t" value of the intersection point
 * @return true if the ray intersects with the "caps" of the cylinder and "t"
 * value is lower than the one found until now, false otherwise
 */
bool		check_caps(Cylinder *cy, Vector cap, t_hit *inter, double t);

/**
 * @brief this function will calculate the normal of the cylinder in the
 * intersection point
 *
 * @param inter t_hit struct with intersection information
 * @param ray Ray struct with ray information
 * @return Vector vector with the normal of the cylinder in the intersection
 * point
 */
Vector	cylinder_normal(t_hit *inter, Ray *ray);

//! Cone

bool	cone_intersect(Cone *cone, Ray *ray, t_hit *inter);

/**
 * @brief this function will create a cone and store it's information
 * from a string array.
 *
 * @param co The Cone struct to work with to fill
 * @param tokens The string array with cone information
 * @return true If the cone was created correctly
 * @return false Otherwise
 */
bool		cone_from_strings(Cone *cone, char **tokens);

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
