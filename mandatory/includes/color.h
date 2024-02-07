/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:23 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 19:22:54 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

#include "miniRT.h"

Color Color_create(int r, int g, int b);

Color Color_add(Color c1, Color c2);
Color Color_mult(Color color, double k);
Color Color_from_strings(char **rgb);

#endif
