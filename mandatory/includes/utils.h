/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:14:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:22:40 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "miniRT.h"

/**
 * @brief this function checks how many intersections the ray has with the
 * object.
 *
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double	determinant(t_equation *eq);

/**
 * @brief this function will solve the quadratic equation, store the results
 * inside the t_equation struct (t1 and t2 variables) and return the number
 * of intersections the ray has with the object.
 *
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double	solve(t_equation *eq);


/**
 * @brief funtion that prints the given error message as parameter and exits
 * the program destroying the world struct (freeing all the memory
 * previously allocated)
 *
 * @param scene Scene struct with all the information of the world
 * @param text text to be printed
 */
void	message(Scene *scene, char *text);

#endif
