/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:23 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 20:04:48 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

#include "miniRT.h"

/**
 * @brief Returns a new color with the given component values.
 * All components are clamped between 0 and 255.
 *
 * @param r The red component
 * @param g The green component
 * @param b The blue component
 * @return Color The new color
 */
Color Color_create(int r, int g, int b);


/**
 * @brief Adds two colors by addding each components.
 * The final components are clamped between 0 and 255.
 *
 * @param c1 The first color
 * @param c2 The second color
 * @return Color The final color
 */
Color Color_add(Color c1, Color c2);

/**
 * @brief Given an existent color, it multiplies each component
 * by the parameter k, and returns the result. The final components
 * are clamped between 0 and 255.
 *
 * @param color The color to change
 * @param k The parameter to multiply with
 * @return Color The new color
 */
Color Color_mult(Color color, double k);

/**
 * @brief Given an array of strings, where each string maps to a
 * component (rgb[0] is red, rgb[1] is green and rgb[2] is blue),
 * converts the strings into a new color struct. All components
 * values are clamped between 0 and 255.
 *
 * @param rgb The string array containing the component's values
 * @return Color The new color
 */
Color Color_from_strings(char **rgb);

/**
 * @brief Given the original color and a color to mix with,
 * it blends both by multiplying each component of the original
 * color by the corresponding component of the mixer color.
 * Each mixer component is mapped to a value between 0 and 1
 * The final components are clamped between 0 and 255.
 *
 * @param color The original color
 * @param mixer The color to blend with
 * @return Color The final color
 */
Color	Color_blender(Color color, Color mixer);

#endif
