/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:24:04 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 12:56:51 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

Color Color_create(int r, int g, int b)
{
	Color color;

	color.r = ft_clamp(r, 0, 255);
	color.g = ft_clamp(g, 0, 255);
	color.b = ft_clamp(b, 0, 255);

	return (color);
}

Color Color_add(Color c1, Color c2)
{
	Color color;

	color.r = ft_clamp(c1.r + c2.r, 0, 255);
	color.g = ft_clamp(c1.g + c2.g, 0, 255);
	color.b = ft_clamp(c1.b + c2.b, 0, 255);

	return (color);
}

Color Color_mult(Color col, double k)
{
	Color color;

	color.r = ft_clamp(col.r * k, 0, 255);
	color.g = ft_clamp(col.g * k, 0, 255);
	color.b = ft_clamp(col.b * k, 0, 255);

	return (color);
}

Color color_from_strings(char **rgb)
{
	Color color;

	color.r = ft_clamp(ft_atoi(rgb[R]), 0, 255);
	color.g = ft_clamp(ft_atoi(rgb[G]), 0, 255);
	color.b = ft_clamp(ft_atoi(rgb[B]), 0, 255);

	return (color);
}
