/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_formula.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:33:34 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 13:44:34 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double determinant(t_equation *eq)
{
	double delta;

	delta = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (delta < 0)
		return (-1);
	return (delta);
}

double solve(t_equation *eq)
{
	double delta;

	//Special Case: the equation is linear
	if (eq->a == 0.0 && eq->b != 0.0)
	{
		eq->t1 = -eq->c / eq->b;
		return (0);
	}
	delta = determinant(eq);
	if (delta < 0)
		return (-1);
	eq->t1 = (-eq->b - sqrt(delta)) / (2 * eq->a);
	eq->t2 = (-eq->b + sqrt(delta)) / (2 * eq->a);
	return (delta);
}
