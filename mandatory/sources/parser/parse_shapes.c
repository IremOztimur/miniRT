/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:39:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 19:19:38 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	Sphere	sphere;
	t_shape		*shape;

	if (ft_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in sphere (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (ERROR("Misconfiguration in commas/numbers in sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misformatting in sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (ERROR("Values are too small in sphere"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}
