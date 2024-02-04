/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:58:49 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 15:28:42 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
 * @brief Casts an infinite ray in space from the camera with the direction
 * of one of the viewport's point.
 *
 * @param s The Scene struct
 * @param factors The viewport factors
 * @return Ray The casted ray
 */
Ray	cast_ray(Scene *s, Vector factors);
