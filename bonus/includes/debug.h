/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:46:12 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 21:32:45 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEBUG_H
# define DEBUG_H

# include "miniRT.h"

/**
 * @brief Prints in the standard output all the values that represent the
 * ambient light in the scene.
 *
 * @param s The t_light struct (representing ambient light) to debug
 */
void	ambient_print(Light *s);

/**
 * @brief Prints in the standard output all the values related to the
 * scene's camera.
 *
 * @param s The Camera struct to debug
 */
void	camera_print(Camera *s);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * light source.
 *
 * @param l The t_light struct (representing a light source) to debug
 */
void	light_print(Light *l);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * sphere.
 *
 * @param s The t_sphere struct to debug
 */
void	sphere_print(Sphere *s);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * plane.
 *
 * @param p The plane struct to work with to debug
 */
void	plane_print(Plane *p);

/**
 * @brief Prints in the standard output all the values related to a scene's
 * cylinder.
 *
 * @param c The Cylinder struct to work with to debug
 */
void	cylinder_print(Cylinder *c);

/**
 * @brief Redirects the program flow to one of the other print functions,
 * since shape represents all the possible shapes. It also prints a shapes's
 * ID.
 *
 * @param shape The t_shape struct to debug
 */
void	shape_print(t_shape *shape);

/**
 * @brief Prints in the standard output all the values related to a color.
 *
 * @param color The Color struct to debug
 */
void	color_print(Color *color);

/**
 * @brief Prints in the standard output all the values related to a 3D vector.
 *
 * @param vec The Vector struct to debug
 */
void	vector_print(Vector vec);

/**
 * @brief Prints in the standard output all the values related to the world.
 * This includes most of the other print functions, since Scene is the main
 * struct.
 *
 * @param world A pointer to the Scene struct
 */
void	scene_print(Scene *scene);

#endif
