/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:49:05 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 01:39:45 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
#define LIGHT_H

#include "miniRT.h"

/**
 * @brief Responsible to calculate the illumination in a given shape.
 * The final illumination is given by the following formula:
 *
 * 		I = Ia + Id
 *
 * Ia - ambient lighting
 * Id - diffuse lighting
 *
 * @param scene The t_world struct
 * @param closest The closest intersected shape
 */
void	illuminate(Scene *scene, t_hit *closest);

/**
 * @brief Calculates the ambient lighting in a shape. The
 * ambient lighting is calculated by the following formula:
 *
 * 		Ia = Ka * ShapeColor
 *
 * Ia - ambient color
 * Ka - ratio of ambient lighting in the scene
 * ShapeColor - the closest shape color
 *
 * @param color The closest shape's color
 * @param ratio The ambient lighting ration in the scene
 * @return Color The final color
 */
Color	ambient(Color	color, double ratio);

/**
 * @brief Calculates the diffuse lighting in a shape. The
 * diffuse lighting is calculated by the following formula:
 *
 * 		Id = Kd * cos(A) * ShapeColor
 *
 * Id - diffuse color
 * Kd - ratio of diffuse lighting in the scene
 * A - angle between the normal at the intersection point and the
 * light direction
 * cos(A) - cosine of A
 * ShapeColor - the closest shape's color
 *
 * @param color The closest shape color
 * @param ratio The ambient lighting ration in the scene
 * @param i		The intensity of the incoming light
 * @return Color The final color
 */
Color	diffuse(Light *bulb, t_hit *inter, double i);


/**
 * @brief Calculates the specular lighting in a given point
 *
 * The specular lighting in a given point is calculated given the
 * following formula
 *
 * 		Ie = Ke * Ip * (N.H)^n
 *
 * Ie - specular lighting
 * Ke - specular constant (depends on the material)
 * Ip - light source intensity
 * H - half vector (the normalized vector between the light and
 *  camera directions)
 * N - the normal vector in that surface
 * n - a value depending on the material (high for highly polished
 * surfaces)
 *
 * @param bulb The light source
 * @param closest The closest shape information
 * @return Color The final color
 */
Color	specular(Light *bulb, t_hit *closest);

/**
 * @brief Looks if any object is between the closest shape and the
 * light source at the intersection point. The closest shape is
 * disregarded in the comparisons.
 *
 * @param shapes The shapes vector
 * @param own The shape to be disregarded
 * @param ray The light direction (from the intersection point)
 * @param max_t The maximum distance, which is the light source distance
 * @return true If any object is between the light and the closest shape
 * @return false Otherwise
 */
bool	is_obscured(t_vector *shapes, t_shape *self, Ray *ray, double max_t);

/**
 * @brief Performs some calculations before calling the is_obscured function
 * like the light direction and distance
 *
 * @param world The t_world struct
 * @param bulb The light source
 * @param closest The closest shape
 * @return The is_obscured return value
 */
bool	is_shadowed(Scene *scene, Light *bulb, t_hit *closest);

#endif
