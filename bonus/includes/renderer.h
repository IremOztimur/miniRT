/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:58:49 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/16 15:30:56 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief The function that renders the scene. Iterates over the scene's
 * pixels and traces a ray for each that will be used to collide with
 * the world. The pixels are painted one by one until the final image
 * is rendered.
 *
 * @param w The scene struct
 * @return int (dummy value)
 */
int		render(Scene *s);

/**
 * @brief Puts a pixel in an image with the given color and at the given
 * coordinates
 *
 * @param w The t_world struct
 * @param c The pixel's color
 * @param x The horizontal displacement
 * @param y The vertical displacement
 */
void	put_pixel(Scene *w, Color c, int x, int y);

/**
 * @brief Initializes the scene's viewport (what the camera can see). The
 * viewport will be supported by 3 vectors: up, right and forward.
 * Together, those vectors can return any point on the plane.
 *
 * @param s The Scene struct
 */
void	init_viewport(Scene *s);


/**
 * @brief Converts a pixel in x (0 to width - 1) and y (0 to height - 1) to
 * viewport x and viewport y factors (between -1 and 1). These factors are used
 * with the viewport vectors to access any point.
 *
 * @param x The pixel's x coordinate
 * @param y The pixel's y coordinate
 * @return Vector The x and y viewport factors
 */
Vector	canvas_to_viewport(int x, int y);


/**
 * @brief Casts an infinite ray in space from the camera with the direction
 * of one of the viewport's point.
 *
 * @param s The Scene struct
 * @param factors The viewport factors
 * @return Ray The casted ray
 */
Ray	cast_ray(Scene *s, Vector factors);

/**
 * @brief Returns the point in the given ray with t direction vectors. A ray's
 * equation is given by:
 *
 * 		P = O + tD
 *
 * P - The point at t direction vectors
 * O - The ray's origin
 * t - Distance factor
 * D - The ray' direction
 *
 * @param ray The casted ray
 * @param t The distance factor
 * @return Vector The point at t
 */
Vector	ray_at(Ray *ray, double t);
