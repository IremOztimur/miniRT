/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:10:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/02 16:54:55 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * @brief Represents a tridimensional vector
 * @param x The x component
 * @param y The y component
 * @param z The z component
 */
typedef struct Vector {
	float x;
	float y;
	float z;
}	Vector;


/**
 * @brief Represents a color by its components
 * @param r The red component
 * @param g The green component
 * @param b The blue component
 */
typedef struct Color {
	int r;
	int g;
	int b;
} Color;

#endif
