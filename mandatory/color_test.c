/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:35:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/02 16:57:08 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

#include <stdio.h>

int main()
{
    // Test Color_create function
    Color color1 = Color_create(100, 150, 200);
    printf("Color 1: R=%d, G=%d, B=%d\n", color1.r, color1.g, color1.b);

    // Test Color_add function
    Color color2 = Color_create(50, 75, 100);
    Color sumColor = Color_add(color1, color2);
    printf("Sum Color: R=%d, G=%d, B=%d\n", sumColor.r, sumColor.g, sumColor.b);

    // Test Color_mult function
    Color multColor = Color_mult(color1, 1.5);
    printf("Multiplied Color: R=%d, G=%d, B=%d\n", multColor.r, multColor.g, multColor.b);

    return 0;
}
