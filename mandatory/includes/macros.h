/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:28:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 11:21:56 by iremoztimur      ###   ########.fr       */
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

#  define WIDTH 1440
# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)


# define ERROR_MALLOC(str)  "Failed allocation on "str"."

#endif
