/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:28:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 22:23:19 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

//! Parsing macros

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

//! Viewport and window macros

# ifdef __APPLE__
#  define WIDTH 1440
# else
#  define WIDTH 1920
# endif

#  define WIDTH 1440
# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)

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

# define ERROR_MALLOC(str)  "Failed allocation on "str"."

#endif
