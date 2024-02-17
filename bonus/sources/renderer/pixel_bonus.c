/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:06:11 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 21:42:09 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/renderer.h"

void put_pixel(Scene *w, Color c, int x, int y)
{
	char *dst;

    // Calculate the memory address of the pixel in the image buffer
	dst = w->disp.addr + (y * WIDTH + x) * (w->disp.bpp / 8);

    // Set the pixel color in the image buffer
	*(unsigned int *)dst = (c.t << 24 |c.r << 16 | c.g << 8 | c.b);
}
