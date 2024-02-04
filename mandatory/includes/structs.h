/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:10:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 11:20:50 by iremoztimur      ###   ########.fr       */
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

/**
 * @brief A scene's ray
 *
 * @param origin The origin of the ray
 * @param direction The direction of the ray
 */
typedef struct Ray
{
	Vector	origin;
	Vector	direction;
}	Ray;

/**
 * @brief Describes how the camera is positioned in the scene
 *
 * @param center The center of the camera
 * @param normal The direction of the camera
 * @param fov The camera's Field Of View
 */
typedef struct Camera
{
	Vector	center;
	Vector	normal;
	double	fov;
}	Camera;

/**
 * @brief Contains mlx related variables
 *
 * @param mlx The mlx pointer
 * @param win The mlx window pointer
 * @param img The mlx image frame pointer
 * @param addr The address of the first byte of the mlx image
 * @param height The image's height
 * @param width The image's width
 * @param bpp The bytes per pixel in the image pointer
 */
typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}	t_graphics;

/**
 * @brief The primary struct, contains everything needed to describe a scene
 *
 * @param camera The scene's camera
 * @param ambient The scene's ambient light
 * @param lights The scenes' light sources vector
 * @param shapes The scene's shapes vector
 * @param counters The number of A, C and L entities found when parsing
 * @param disp The mlx variables
 * @param up The viewport up vector
 * @param right The viewport right vector
 * @param map The map read from the given file
 * @param hview The height of the viewport
 * @param wview The width of the viewport
 */
typedef struct Scene
{
	Camera	camera;
	int			counters[3];
	t_graphics	disp;
	Vector		up;
	Vector		right;
	char		**map;
	double		hview;
	double		wview;
}	Scene;

#endif
