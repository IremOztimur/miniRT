/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:28:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 19:20:09 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

//! Parsing macros

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define HAS_COMMAS '1'

//! Viewport and window macros

# ifdef __APPLE__
#  define WIDTH 1440
# else
#  define WIDTH 1920
# endif

# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)
# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)

//! Minilibx events

# ifdef __APPLE__
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define C 8
#  define V 9
#  define KeyPress 2
#  define KeyPressMask (1L<<0)
#  define DestroyNotify 17
#  define StructureNotifyMask (1L<<17)
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define C 99
#  define V 118
# endif

//! Math macros

# define PI 3.1415926535f
# define RADIANS(deg) ((deg * PI) / 180.0f)
# define DEGREES(rad) ((rad * 180.0f) / PI)
# define EPSILON 0.0001

//! Fixed Vector structs

# define UPGUIDE		(Vector){0.0, 1.0, 0.0}
# define VEC_MIN		(Vector){-1.0001, -1.0001, -1.0001}
# define VEC_MAX		(Vector){1.0001, 1.0001, 1.0001}
# define VEC_EPSILON	(Vector){EPSILON, EPSILON, EPSILON}

//! Fixed Color structs

# define WHITE		(Color){0, 255, 255, 255}
# define BLACK		(Color){0, 0, 0, 0}
# define BLUE		(Color){0, 0, 0, 255}
# define RED		(Color){0, 255, 0, 0}
# define GREEN		(Color){0, 0, 255, 0}
# define YELLOW		(Color){0, 255, 255, 0}
# define PINK		(Color){0, 255, 0, 255}
# define CYAN		(Color){0, 0, 255, 255}

//! Error macros

# define ERROR(m)	\
	printf("Error\n%s\n", m)
# define ERROR_NUM_ARGS(x, n)		\
	ERROR("Wrong number of args in "x" (need "n")")
# define ERROR_NUM_COMMAS(x)		\
	ERROR("Too many/few commas in "x)
# define ERROR_MISFORMAT_COLOR(x)	\
	ERROR("Colors misformatting in "x)
# define ERROR_LIGHT_BRIGHTNESS_OUT_OF_BOUNDS	\
	ERROR("Light brightness out of bounds [0.0,1.0]")
# define ERROR_SHININESS_OUT_OF_BOUNDS(x)		\
	ERROR("Shininess out of bounds in "x" [0.0,+∞[")
# define ERROR_VALUES_TOO_SMALL(x)				\
	ERROR("Values are too small in "x)
# define ERROR_KS_OUT_OF_BOUNDS(x)				\
	ERROR("Specular coefficient out of bounds in "x" [0.0,1.0]")


# define ERROR_MALLOC(str)  "Failed allocation on "str"."
# define ERROR_USAGE 		"Usage: ./miniRT <scene>.rt"
# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_OPEN_FILE	"Couldn't open requested file"
# define ERROR_NOT_RT		"File extension is not '.rt'."
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."
# define ERROR_TOO_MANY		"Found more than 1 A or C entities"

//! Useful macros

// Returns the maximum between a and b
# define MAX(a, b)	((a) * (a > b) + (b) * (b > a))
// Returns the minimum between a and b
# define MIN(a, b)	((a) * (a < b) + (b) * (b < a))
// Returns the absolute value of x
# define ABS(x) 	((x) * (x > 0) - (x) * (x < 0))

#endif
