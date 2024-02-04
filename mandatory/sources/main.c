/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:18:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/03 17:50:33 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include <stdio.h>

int main()
{
    // Test Vector_create function
    Vector vector1 = Vector_create(1.0f, 2.0f, 3.0f);
    printf("Vector 1: x=%.2f, y=%.2f, z=%.2f\n", vector1.x, vector1.y, vector1.z);

    // Test Vector_magnitude function
    float magnitude = Vector_magnitude(vector1);
    printf("Magnitude of Vector 1: %.2f\n", magnitude);

    // Test Vector_add function
    Vector vector2 = Vector_create(4.0f, 5.0f, 6.0f);
    Vector sumVector = Vector_add(vector1, vector2);
    printf("Sum Vector: x=%.2f, y=%.2f, z=%.2f\n", sumVector.x, sumVector.y, sumVector.z);

    // Test Vector_sub function
    Vector subVector = Vector_sub(vector1, vector2);
    printf("Subtracted Vector: x=%.2f, y=%.2f, z=%.2f\n", subVector.x, subVector.y, subVector.z);

    // Test Vector_scale function
    Vector scaledVector = Vector_scale(vector1, 2.0f);
    printf("Scaled Vector: x=%.2f, y=%.2f, z=%.2f\n", scaledVector.x, scaledVector.y, scaledVector.z);

    // Test Vector_div function
    Vector dividedVector = Vector_div(vector1, 2.0f);
    printf("Divided Vector: x=%.2f, y=%.2f, z=%.2f\n", dividedVector.x, dividedVector.y, dividedVector.z);

    // Test Vector_normalize function
    Vector normalizedVector = Vector_normalize(vector1);
    printf("Normalized Vector: x=%.2f, y=%.2f, z=%.2f\n", normalizedVector.x, normalizedVector.y, normalizedVector.z);

    return 0;
}
